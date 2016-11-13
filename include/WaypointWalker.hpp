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

#ifndef WAYPOINT_WALKER_H
#define WAYPOINT_WALKER_H

#include "AutonomousBehaviour.hpp"
#include "WalkToPoint.hpp"

#include "SFML/Graphics.hpp"

#include <memory>
#include <vector>

namespace LocSim
{
	/**
	 *	The WaypointWalker class simply chains together a number of WalkToPoint
	 *  behaviours to make the AutonomousRobot follow a path.
	 */
	class WaypointWalker : public AutonomousBehaviour
	{
	public:
		/** 
		 *	Constructor
		 * 
		 *  @param walk_to A list of X, Y coordinates to walk to, in order.
		 */
		WaypointWalker(const std::vector<sf::Vector2f>& walk_to)
			: i_{ 0 }, points_{ walk_to }, w_{ std::make_shared<WalkToPoint>(WalkToPoint{ walk_to[i_].x, walk_to[i_].y }) }, s_{ BehaviourStatus::InProgress, 0, 0 }
		{ }

		/**
	  	 *  Updates the behaviour
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
		const std::vector<sf::Vector2f>& points_;
		int i_;
		std::shared_ptr<WalkToPoint> w_;
		BehaviourStatus s_;
	};

}

#endif // WAYPOINT_WALKER_H