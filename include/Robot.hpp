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

#ifndef ROBOT_H
#define ROBOT_H

#include "Moving.hpp"

#include "SFML/Graphics.hpp"

namespace LocSim {

	/**
	 *	The Robot class is basically a coloured circle that can be moved around
	 *  the simulation window by setting its X and Y position and velocity.
	 */
	class Robot : public Moving
	{	
	public:
		/**
		 *	The radius of the circle representing a robot
		 */
		static const float ROBOT_SIZE;

		/**
		 *	The max speed at which the robot may move per instant
		 */
		static const float ROBOT_SPEED;

		/**
		 *	Constructor
		 *
		 *  @param x The initial X position of the Robot
		 *  @param y The initial Y position of the Robot
		 */
		Robot(float x, float y)
			: Moving{ x, y, 1, 1 }, circ_{ ROBOT_SIZE }
		{
			circ_.setFillColor(sf::Color::Black);
		}

		/**
		 *	Draws the Robot in the supplied window
		 *
		 *  @param window The window to draw the robot in
		 */
		virtual void draw(sf::RenderWindow& window) const override;

		/**
		 *	Updates the Robot given an instant of time has passed
		 */
		virtual void update() override;

	private:
		sf::CircleShape circ_;

	};

}

#endif //ROBOT_H