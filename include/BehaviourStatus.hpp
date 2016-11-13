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

#ifndef BEHAVIOUR_STATUS_H
#define BEHAVIOUR_STATUS_H

namespace LocSim
{
	/**
	 *	BehaviourStatus is a struct which is returned by AutonomousBehaviour
	 *  objects to indicate their state.
	 */
	struct BehaviourStatus
	{
		/**
		 *	Inidicates the status of the AutonomousBehaviour. 'Done' means
		 *  that the behaviour has completed its objective. 'InProgress'
		 *  means the behaviour is still trying to achieve a goal.
		 */
		enum Status {Done, InProgress};

		Status status;
		float vel_x;
		float vel_y;

		/**
		 *  Constructor
		 *
		 *  @param sts The Status of the AutonomousBehaviour
		 *  @param velx The suggested X velocity of the AutonomousBehaviour
		 *  @param vely The suggested Y velocity of the AutonomousBehaviour
		 */
		BehaviourStatus(const Status sts, const float velx, const float vely)
			: status{ sts }, vel_x{ velx }, vel_y{ vely }
		{ }
	};

}

#endif