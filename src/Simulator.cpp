/*
 *   Copyright (C) 2016 Jeremy Collette.
 *   This file is part of LocalisationSimulator.
 *
 *   LocalisationSimulator is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   LocalisationSimulator is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with LocalisationSimulator. If not, see <http://www.gnu.org/licenses/>.
 */

#include "AutonomousBehaviour.hpp"
#include "DataLogger.hpp"
#include "Monitor.hpp"
#include "Simulator.hpp"
#include "StandStill.hpp"
#include "WalkAroundField.hpp"
#include "WalkBackAndForward.hpp"
#include "WalkInStraightLine.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <cctype>
#include <iostream>
#include <memory>
#include <string>
#include <windows.h>

namespace LocSim
{
	const unsigned int Simulator::WINDOW_WIDTH = 1280;
	const unsigned int Simulator::WINDOW_HEIGHT = 640;
	const unsigned int Simulator::FRAMES_PER_MEASUREMENT = 30;
	const unsigned int Simulator::FRAMES_PER_MONITOR_UPDATE = 20;

	
	const std::vector<std::string> Simulator::TEST_NAMES{ "WalkAroundField", "WalkInStraightLine", "WalkBackAndForward", "StandStill" };
	
	void Simulator::run(std::string test_name)
	{
		int test_num = 0;
		for (int i = 0; i < TEST_NAMES.size(); ++i)
		{
			if (test_name == TEST_NAMES[i])
			{
				test_num = i;
			}
		}
		run(test_num);
	}

	void Simulator::run(int test_number)
	{		
		sf::err().rdbuf(0);
		std::cout << "Starting simulator with " << FRAMES_PER_SECOND << " max frames per second\n";
		std::cout << "Loading test " << TEST_NAMES[test_number] << "...\n";

		if (field_.init())
		{
			std::cout << "Error initialising field!\n";
			return;
		}

		// Initialise robots / estimators
		std::shared_ptr<AutonomousBehaviour> behaviour;
		switch (test_number)
		{
		case 1:
			behaviour = std::make_shared<WalkInStraightLine>(WalkInStraightLine{});
			break;
		case 2:
			behaviour = std::make_shared<WalkBackAndForward>(WalkBackAndForward{});
			break;
		case 3:
			behaviour = std::make_shared<StandStill>(StandStill{});
			break;
		default:
			behaviour = std::make_shared<WalkAroundField>(WalkAroundField{});
			break;
		}
		robot_ = LocalisingRobot{behaviour, Field::FIELD_SIZE.x/2, Field::FIELD_SIZE.y/2};

		Monitor m{ robot_, FRAMES_PER_SECOND };
		if (m.init())
		{
			std::cout << "Error initialising monitor!\n";
			return;
		}

		std::vector<std::string> est_names;
		for (const auto& e : robot_.get_estimators())
		{
			est_names.push_back(e.get_filter_name());
		}

		// Initialise logger
		std::string log_file = TEST_NAMES[test_number] + "_" + std::to_string(FRAMES_PER_SECOND) + "FPS.csv";
		std::cout << "Openning logging file " << log_file << "...\n";
		DataLogger log{ log_file, est_names };
		if (log.init())
		{
			DWORD err = GetLastError();
			std::cout << "Error initialising logger: " << err << "\n";
			return;
		}

		// Create the main window
		sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Localisation Simulator");

		// Set framerate to FRAMES_PER_SECOND
		window.setFramerateLimit(FRAMES_PER_SECOND);

		// Keep track of the current frame number
		unsigned int frame = 0;

		// Keep track of averages
		std::vector<std::vector<double>> averages (robot_.get_estimators().size());

		// Start the game loop
		while (window.isOpen())
		{
			// Clear screen
			window.clear();

			// Update the robot
			robot_.update();

			// Update monitor
			if (frame % FRAMES_PER_MONITOR_UPDATE == 0)
			{
				m.update();
			}

			// Log once a second
			if (frame == 0)
			{
				std::vector<double> distances;
				for (auto i = 0U; i < robot_.get_estimators().size(); ++i)
				{
					auto &e = robot_.get_estimators()[i];
					averages[i].push_back(e.get_average_dist());
					e.reset_average_dist();
				}
			}

			// Provide observations to the estimators X times a second
			if (frame % FRAMES_PER_MEASUREMENT == 0)
			{
				// Provide position measurements
				const auto pos = robot_.get_position();
				robot_.send_measurement(m_gen_.get_measurement(pos.x, pos.y, robot_.get_velocity_x(), robot_.get_velocity_y()));				
			}

			// Process events
			sf::Event event;
			while (window.pollEvent(event))
			{
				// Close window: exit
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
			}

			// Draw the field
			field_.draw(window);

			// Draw the robots
			robot_.draw(window);			

			// Draw monitor
			m.draw(window);

			// Update the window
			window.display();

			// Update frame
			frame = ++frame % FRAMES_PER_SECOND;
		}

		std::cout << "Attempting to write log...\n";		
		if (!log.write_to_file(averages))
		{
			std::cout << "Logging error!\n";
		}
		else
		{
			std::cout << "Logging success!\n";
		}		
	}

}