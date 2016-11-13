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

#ifndef STAND_STILL_H
#define STAND_STILL_H

#include "AutonomousBehaviour.hpp"
#include "BehaviourUpdate.hpp"
#include "BehaviourStatus.hpp"

namespace LocSim
{
	/**
	 *	StandStill is a highly advanced AutonomousBehaviour that simply
	 *  stands still. Wow.
	 */
	class StandStill : public AutonomousBehaviour
	{
	public:
		/**
		 *	Constructor
		 */
		StandStill()
		{ }

		/**
		 *	Updates the StandStill behvaiour as though one instant of time has passed
		 *
		 *  @param data BehaviourUpdate data
		 */
		virtual void update(const BehaviourUpdate& data) override;

		/**
		 *	Returns the status of the StandStill behaviour
		 *  "Yup... still standing still!"
		 *
		 *  @param BehaviourStatus The status of the behaviour.
		 */
		virtual BehaviourStatus get_status() const override;
	};

}

#endif // STAND_STILL_H