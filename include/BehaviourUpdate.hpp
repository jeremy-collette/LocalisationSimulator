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

#ifndef BEHAVIOUR_UPDATE_H
#define BEHAVIOUR_UPDATE_H

namespace LocSim
{
	/**
	 *	The BehaviourUpdate struct is provided to AutonomousBehaviour objects
	 *  to provide them with updates about the state of the environment.
	 */
	struct BehaviourUpdate
	{
		const float x_pos;
		const float y_pos;
		const float x_vel;
		const float y_vel;

		/**
		 *	Constructor
		 * 
		 *  @param x The current X position of something of interest - probably a Robot
		 *  @param y The current Y position of something of interest - probably a Robot
		 *  @param xvel The current X velocity of something of interest - probably a Robot
		 *  @param yvel The current Y velocity of something of interest - probably a Robot
		 */
		BehaviourUpdate(const float x, const float y, const float xvel, const float yvel)
			: x_pos{ x }, y_pos{ y }, x_vel{ xvel }, y_vel{ yvel }
		{ }
	};

}


#endif