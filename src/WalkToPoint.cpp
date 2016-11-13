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
#include "Utilities.hpp"
#include "WalkToPoint.hpp"

namespace LocSim
{
	const double WalkToPoint::DIST_THRESHOLD = 10.0;

	void WalkToPoint::update(const BehaviourUpdate& data)
	{
		if (Utilities::dist({ data.x_pos, data.y_pos }, { x_dest_, y_dest_ }) <= DIST_THRESHOLD)
		{
			status_ = { BehaviourStatus::Done, 0, 0 };
		}
		else
		{
			auto x_diff = x_dest_ - data.x_pos;
			if (abs(x_diff) >= Robot::ROBOT_SPEED)
			{
				x_diff = (x_diff / abs(x_diff)) * Robot::ROBOT_SPEED;
			}
			else
			{
				x_diff = (x_diff / Robot::ROBOT_SPEED) * Robot::ROBOT_SPEED;
			}

			auto y_diff = y_dest_ - data.y_pos;
			if (abs(y_diff) >= Robot::ROBOT_SPEED)
			{
				y_diff = (y_diff / abs(y_diff)) * Robot::ROBOT_SPEED;
			}
			else
			{
				y_diff = (y_diff / Robot::ROBOT_SPEED) * Robot::ROBOT_SPEED;
			}

			status_ = { BehaviourStatus::InProgress, x_diff, y_diff };
		}
	}

	BehaviourStatus WalkToPoint::get_status() const
	{
		return status_;
	}

}