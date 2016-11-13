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

#ifndef MONITOR_H
#define MONITOR_H 

#include "Drawable.hpp"
#include "Initialisable.hpp"
#include "LocalisingRobot.hpp"
#include "RobotEstimator.hpp"
#include "Simulator.hpp"
#include "Updatable.hpp"

namespace LocSim{

	/**
	 *	The Monitor class collects and renders various information in the
	 *  simulator window regarding the simulation. Including the average
	 *  distance of each RobotEstimator from the actual AutonomousRobot
	 *  position, the actual position of the AutonomousRobot, the number
	 *  of seconds that the simulation has been running, and the maximum
	 *  FPS of the simulation.
	 */
	class Monitor : public Initialisable, public Drawable, public Updatable
	{
	public:
		/**
		 *	Constructor
		 *
		 *  @param to_monitor The LocalisingRobot that is being tracked
		 *  @param frames_per_sec The maximum frames per second of the simulation
		 */
		Monitor(LocalisingRobot& to_monitor, const unsigned int frames_per_sec)
			: Drawable{ static_cast<float>(Simulator::WINDOW_WIDTH - WIDTH), 10.0f }, r_{ to_monitor },
			initialised_{ false }, estimators_{ r_.get_estimators() }, time_running_{ 0 }, fps_{frames_per_sec}
		{ }

		/**
		 *	Attempts to load the display font to initialise the monitor. Must
		 *  be called before other members.
		 *
		 *  @return int 0 represents success. 0 represents failure.
		 */
		virtual int init();

		/**
		 *	Draws the monitor in the window provided.
		 *
		 *  @param window The window to draw in
		 */
		virtual void draw(sf::RenderWindow& window) const;

		/**
		 *	Updates the information to be displayed
		 */
		virtual void update();

	private:
		static const sf::Vector2f SQUARE_SIZE;
		static const unsigned int WIDTH;
		
		const unsigned int fps_;
		bool initialised_;
		LocalisingRobot &r_;
		sf::Font font_;
		sf::Text text_;
		std::vector<RobotEstimator>& estimators_;
		std::vector<sf::RectangleShape> sqrs_;
		double time_running_;

	};

}


#endif