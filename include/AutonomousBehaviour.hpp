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

#ifndef AUTONOMOUS_BEHAVIOUR_H
#define AUTONOMOUS_BEHAVIOUR_H

#include "BehaviourStatus.hpp"
#include "BehaviourUpdate.hpp"

namespace LocSim
{
	/**
	*  An abstract base class that provides the interface for an
	*  AutonomousBehaviour module. An AutonomousBehaviour module
	*  takes environment updates through the 'update' member and
	*  provides state information through the 'get_status()' 
	*  member. State information may contain recommendations for
    *  the owner, e.g. new X / Y velocity values.
	*
	*  The owner may be a Robot, or another behaviour, which acts
	*  accordingly to the state provided by a derived class.
	*/
	class AutonomousBehaviour
	{
	public:

		/**
		 *	Provides an update to the behaviour. 
		 *
		 *  @param data Contains update data.
		 */
		virtual void update(const BehaviourUpdate& data) = 0;

		/**
		 *	Returns the status of the behaviour.
		 *
		 *  @return BehaviourStatus The current status of the behaviour.
		 */
		virtual BehaviourStatus get_status() const = 0;
	};
}


#endif // AUTONOMOUS_BEHAVIOUR_H