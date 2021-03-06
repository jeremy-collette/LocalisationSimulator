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

#include "Robot.hpp"

namespace LocSim
{
	const float Robot::ROBOT_SIZE = 15;
	const float Robot::ROBOT_SPEED = 1;

	void Robot::draw(sf::RenderWindow& window) const
	{
		window.draw(circ_);
	}

	void Robot::update()
	{
		Moving::update();
		circ_.setPosition(get_position());
	}
}