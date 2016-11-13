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

#ifndef WALK_TO_POINT_H
#define WALK_TO_POINT_H

#include "AutonomousBehaviour.hpp"

namespace LocSim
{
	/**
	 *	The WalkToPoint behaviour simply walks to a supplied X, Y coordinate
	 *  on the field.
	 */
	class WalkToPoint : public AutonomousBehaviour
	{
	public:
		/**
		 *	Constructor
		 *
		 *  @param x_dest The x-coordinate of the destination point
		 *  @param y_dest The y-coordinate of the destination point
		 */
		WalkToPoint(const float x_dest, const float y_dest)
			: x_dest_{ x_dest }, y_dest_{ y_dest }, status_{BehaviourStatus::Status::InProgress, 0, 0}
		{ }

		/**
		 *	Updates the behaviour
		 *
		 *  @param data Contains BehaviourUpdate information
		 */
		virtual void update(const BehaviourUpdate& data) override;

		/**
		 *	Gets the state of the behaviour
		 *
		 *  @return BehaviourState Contains information about the state of the behaviour
		 */
		virtual BehaviourStatus get_status() const override;

	private:
		const static double DIST_THRESHOLD;
		const float x_dest_;
		const float y_dest_;
		BehaviourStatus status_;

	};

}


#endif // WALK_TO_POINT_H