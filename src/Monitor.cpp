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

#include "Monitor.hpp"

#include <cassert>

namespace LocSim
{
	const sf::Vector2f Monitor::SQUARE_SIZE { 60, 60 };
	const unsigned int Monitor::WIDTH = 400;

	int Monitor::init()
	{
		if (!font_.loadFromFile("Gravity-Regular.otf"))
		{
			return 1;
		}
		text_.setFont(font_);
		text_.setCharacterSize(24);
		initialised_ = true;
		return 0;
	}

	void Monitor::draw(sf::RenderWindow& window) const
	{
		assert(initialised_);
		window.draw(text_);

		for (const auto &s : sqrs_)
		{
			window.draw(s);
		}
	}

	void Monitor::update()
	{
		assert(initialised_);
		
		sqrs_.clear();
		std::string str = "=== Estimators ===\n";
		
		std::vector<const RobotEstimator> to_sort;
		for (auto &e : estimators_)
		{
			to_sort.push_back(e);
		}
		
		std::sort(to_sort.begin(), to_sort.end(), 
			[&](const RobotEstimator& e1, const RobotEstimator &e2)
			{
				return e1.get_average_dist() < e2.get_average_dist();
			});

		int i = 0;
		for (auto &e : to_sort)
		{
			str += "\n  " + e.get_filter_name();
			str += "\n\tAverage dist: " + std::to_string(e.get_average_dist()) + "\n\n";
			
			sf::RectangleShape rs{ SQUARE_SIZE };
			rs.setFillColor(e.get_colour());
			auto pos = get_position();
			pos.x -= (SQUARE_SIZE.x);
			pos.y += 65 + (i++ * (SQUARE_SIZE.y + 55));
			rs.setPosition(pos);
			sqrs_.push_back(rs);
		}

		str += "\n\n=== Information ===\n";
		str += "FPS limit: " + std::to_string(fps_);
		str += "\nSeconds running: " + std::to_string(static_cast<int>(time_running_));
		str += "\nActual position: " + std::to_string(static_cast<int>(r_.get_position().x)) + ", " + std::to_string(static_cast<int>(r_.get_position().y));
		
		time_running_ += static_cast<double>(Simulator::FRAMES_PER_MONITOR_UPDATE) / static_cast<double>(fps_);
		text_.setString(str);
		text_.setPosition(get_position());
	}


}