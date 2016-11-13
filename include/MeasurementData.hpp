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

#ifndef MEASUREMENT_DATA_H
#define MEASUREMENT_DATA_H

namespace LocSim
{
	/**
	 *	MeasurementData is a struct which contains measurements about the 
	 *  object state being estimated by the 'MeasurementFilter' class
	 *
	 *	This includes X and Y positon, X and Y velocity, and the associated
	 *  uncertainties for each.
	 */
	struct MeasurementData{
		const float x_position;
		const float x_pos_error;
		const float y_position;
		const float y_pos_error;
		const float x_velocity;
		const float x_vel_error;
		const float y_velocity;
		const float y_vel_error;

		/**
		 *	Constructor
		 *
		 *  @param x_pos The current X value of the state being measured
		 *  @param x_pos_err The uncertainty of the X position measurement
		 *  @param y_pos The current Y value of the state being measured
		 *  @param y_pos_err The uncertainty of the Y position measurement
		 *  @param x_vel The current X velocity of the state being measured
		 *  @param x_vel_err The uncertainty of the X velocity measurement
		 *  @param y_vel The current Y velocity of the state being measured
		 *  @param y_vel_err The uncertainty of the Y velocity measurement
		 */
		MeasurementData(const float x_pos, const float x_pos_err, const float y_pos, const float y_pos_err, const float x_vel, const float x_vel_err, const float y_vel, const float y_vel_err)
			: x_position{ x_pos }, x_pos_error{ x_pos_err }, y_position{ y_pos }, y_pos_error{ y_pos_err }, x_velocity{ x_vel }, x_vel_error{ x_vel_err }, y_velocity{ y_vel }, y_vel_error{ y_vel_err }
		{ }
	};
}

#endif // MEASUREMENT_DATA_H