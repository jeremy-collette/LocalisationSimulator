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

#ifndef AUTONOMOUS_ROBOT_H
#define AUTONOMOUS_ROBOT_H

#include "AutonomousBehaviour.hpp"
#include "Robot.hpp"

#include "SFML/Graphics.hpp"

#include <memory>

namespace LocSim
{
	/**
	 *	An AutonomousRobot is deriviation of the Robot class that
	 *	is controlled by the state of the supplied 'AutonomousBehaviour'.
	 *
	 *  The AutonomousRobot feeds the supplied AutonomousBehaviour 
	 *  state information, such as current X position and Y position. 
	 *  The supplied AutonomousBehaviour reponds with recommendations
	 *  for X velocity and Y velocity values, which are used by the
	 *  AutonomousRobot.
	 */
	class AutonomousRobot : public Robot
	{
	public:
		/**
		 *	Constructor
		 *
		 *	@param behaviour The AutonomousBehaviour to control this AutonomousRobot
		 *  @param x The initial x-position
		 *  @param y The initial y-position
		 */
		AutonomousRobot(std::shared_ptr<AutonomousBehaviour> behaviour, float x, float y)
			: Robot(x, y), b_{behaviour}
		{ }

		/**
		 *	Draws the AutonomousRobot on the supplied window
		 */
		virtual void draw(sf::RenderWindow& window) const override;

		/**
		 *  Updates the AutonomousRobot
		 */
		virtual void update() override;

	private:
		// The AutonomousBehaviour which controls the AutonomousRobot
		std::shared_ptr<AutonomousBehaviour> b_;
	};
}


#endif // AUTONOMOUS_ROBOT_H