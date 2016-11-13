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

#ifndef MEASUREMENT_FILTER_H
#define MEASUREMENT_FILTER_H

#include "MeasurementData.hpp"
#include "StateData.hpp"

#include <string>

namespace LocSim
{
	/** 
	 *	MeasurementFilter is an abstract base class for data filtering.
	 *  Derived classes should filter the data provided via 
	 *  'add_measurement' and provide a state estimate through the
	 *  'get_state' member.
	 */
	class MeasurementFilter
	{
	public:

		/**
		 *	Adds a measurement to the data filter and update the estimated state.
		 *
		 *  @param md MeasurementData representing the state being measured. This
		 *  contains X and Y position, X and Y velocity, and associated
		 *  uncertainties for each value.
		 */
		virtual void add_measurement(const MeasurementData& md) = 0;

		/**
		 *	Returns the estimated state.
		 *
		 *  @return StateData The estimated state. This contains X and Y position,
		 *  X and Y velocity.
		 */
		virtual StateData get_state() const = 0;

		/**
		 *	Update the estimated state as though one instant of time (one frame) has
		 *  passed.
		 */
		virtual void update() = 0;

		/**
		 *	Returns the name of the derived filter.
		 * 
		 *  @return std::string The name of the derived filter.
		 */
		virtual std::string get_filter_name() const = 0;
	};
}


#endif // MEASUREMENT_FILTER_H