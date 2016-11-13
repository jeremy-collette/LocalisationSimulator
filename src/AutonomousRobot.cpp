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

#include "AutonomousRobot.hpp"

namespace LocSim
{
	void AutonomousRobot::draw(sf::RenderWindow& window) const
	{
		Robot::draw(window);
	}

	void AutonomousRobot::update()
	{
		Robot::update();

		auto pos = get_position();
		b_->update(BehaviourUpdate{ pos.x, pos.y, get_velocity_x(), get_velocity_y() });
		BehaviourStatus status = b_->get_status();
		set_velocity_x(status.vel_x);
		set_velocity_y(status.vel_y);
	}
}