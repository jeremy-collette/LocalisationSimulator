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

#ifndef MEASUREMENT_GENERATOR
#define MEASUREMENT_GENERATOR

#include "MeasurementData.hpp"

#include <random>

namespace LocSim
{
	/**
	 *	MeasurementGenerator is used to generate random uncertain measurement 
	 *  data from certain variables. This is used to represent uncertainty in
	 *  real life measurements.
	 */
	class MeasurementGenerator
	{
	public:

		/** 
		 *	Constructor
		 */
		MeasurementGenerator()
			: mt_{ 0 }, pos_error_dist_{ 0, 80 }, vel_error_dist_{ 0, 0.25 }
		{ }

		/**
		 *	Generates a MeasurementData struct, which contains a measurement
		 *  based on the supplied true values, with some degree of uncertainty.
		 *
		 *  @param actual_x The actual X position to base the measurement on
		 *  @param actual_y The actual Y position to base the meaurement on
		 *  @param actual_x_vel The actual X velocity to base the measurement on
		 *  @param actual_y_vel The actual Y velocity to base the measurement on
		 *
		 *  @return MeasurementData A measurement based on the supplied true values
		 *  with some added uncertainty
		 */
		virtual MeasurementData get_measurement(const float actual_x, const float actual_y, const float actual_x_vel, const float actual_y_vel);

	private:
		/**
		 *	Generates a random amount of error for a position variable (either X or Y)
		 *  within some pre-defined bound
		 *
		 *  @return float A random amount of error within some pre-defined bound
		 */
		float get_random_pos_error();

		/**
		*	Generates a random amount of error for a velocity variable (either X velocity
		*   or Y velocity) within some pre-defined bound
		*
		*  @return float A random amount of error within some pre-defined bound
		*/
		float get_random_vel_error();

		std::mt19937 mt_;
		std::normal_distribution<float> pos_error_dist_;
		std::normal_distribution<float> vel_error_dist_;
	};

}

#endif // MEASUREMENT_GENERATOR