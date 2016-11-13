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

#ifndef STATE_DATA_H
#define STATE_DATA_H

namespace LocSim {

	/** 
	 *	Contains data about the estimated state of a MeasurementFilter
	 */
	struct StateData
	{
		float x_pos;
		float y_pos;
		float x_vel;
		float y_vel;

		/**
		 *	Constructor
		 *
		 *  @param x The current X position estimate
		 *  @param y The current Y position estimate
		 *  @param xvel The current X velocity estimate
		 *  @param yvel The current Y velocity estimate
		 */
		StateData(const float x, const float y, const float xvel, const float yvel)
			: x_pos{ x }, y_pos{ y }, x_vel{ xvel }, y_vel{ yvel }
		{ }
	};

}

#endif // STATE_DATA_H