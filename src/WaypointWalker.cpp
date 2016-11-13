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

#include "WaypointWalker.hpp"

namespace LocSim
{
	void WaypointWalker::update(const BehaviourUpdate& data)
	{
		if (s_.status == BehaviourStatus::Status::Done)
		{
			return;
		}

		if (w_->get_status().status == BehaviourStatus::Status::Done)
		{
			if (++i_ >= points_.size())
			{
				i_ = 0;
			}			
			w_ = std::make_shared<WalkToPoint>(WalkToPoint{ points_[i_].x, points_[i_].y });
		}

		w_->update(data);
		BehaviourStatus walk_to_status = w_->get_status();
		s_ = { BehaviourStatus::InProgress, walk_to_status.vel_x, walk_to_status.vel_y };
	}

	BehaviourStatus WaypointWalker::get_status() const
	{
		return s_;
	}

}