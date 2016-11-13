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

#ifndef AVERAGE_FILTER_H
#define AVERAGE_FILTER_H

#include "MeasurementData.hpp"
#include "MeasurementFilter.hpp"
#include "StateData.hpp"

#include <deque>
#include <string>

namespace LocSim
{
	/**
	 *	The AverageFilter class provides an estimated X, Y position and X, Y 
	 *  velocity of a Robot given measurements over time. Each measurement has
	 *  an associated uncertainty.
	 *
	 *  The AverageFilter simply takes the average of the last 
	 *  MAX_VARIABLE_READINGS readings for each variable being estimated.
	 */
	class AverageFilter : public MeasurementFilter
	{
	public:
		/**
		 *	Constructor
		 *
		 *  @param initial_x The initial X position measurement
		 *  @param initial_y The initial Y position measurement
		 *  @param initial_xvel The inital X velocity measurement
		 *  @param initial_yvel The inital Y velocity measurement
		 */
		AverageFilter(const float initial_x, const float initial_y, const float initial_xvel, const float initial_yvel)
		{
			add_measurement({ initial_x, 0, initial_y, 0, initial_xvel, 0, initial_yvel, 0 });
		}

		/**
		 *	Adds a new measurement to the filter
		 *
		 *  @param md The measurement data to be added
		 */
		virtual void add_measurement(const MeasurementData& md) override;

		/**
		 *	Gets the estimated state of the filter
		 *
		 *  @return StateData The estimated state of the filter
		 */
		virtual StateData get_state() const override;

		/**
		 *	Updates the filter estimate
		 */
		virtual void update() override;

		/**
		 *	Returns the name of the filter
		 *
		 *  @return std::string The name of the filter
		 */
		virtual std::string get_filter_name() const override;

	private:
		const static unsigned int MAX_VARIABLE_READINGS;

		std::deque<float> x_pos_readings;
		std::deque<float> y_pos_readings;
		std::deque<float> x_vel_readings;
		std::deque<float> y_vel_readings;

		float avg_x_;
		float avg_y_;
		float avg_x_vel_;
		float avg_y_vel_;
	};
}

#endif // AVERAGE_FILTER_H
