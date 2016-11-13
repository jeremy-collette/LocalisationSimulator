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

#ifndef LAST_MEASUREMENT_FILTER_H
#define LAST_MEASUREMENT_FILTER_H

#include "MeasurementFilter.hpp"

namespace LocSim
{
	/**
	 *	The LastMeasurementFilter is a MeasurementFilter which simply returns
	 *  the last supplied measurement as the estimated state of the object
	 *  being measured.
	 */
	class LastMeasurementFilter : public MeasurementFilter
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
		LastMeasurementFilter(const float inital_x, const float initial_y, const float initial_xvel, const float initial_yvel)
		{
			add_measurement({ inital_x, 0, initial_y, 0, initial_xvel, 0, initial_yvel, 0 });
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
		float x_;
		float y_;
		float x_vel_;
		float y_vel_;
	};

}

#endif // LAST_MEASUREMENT_FILTER_H