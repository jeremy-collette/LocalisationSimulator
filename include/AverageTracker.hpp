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

#ifndef AVERAGE_TRACKER_H
#define AVERAGE_TRACKER_H

#include <deque>
#include <numeric>

namespace LocSim
{
	/**
	 *	AverageTracker is a class that calculates an average for the measurements
	 *  that are provided to it through the 'add_measurement' method.
	 *  
	 *  @param T The type to average
	 */
	template<typename T>
	class AverageTracker
	{
	public:
		/**
		 *	Constructor
		 */
		AverageTracker()
		{	}

		/**
		 *	Add a new measurement to the set of measurements to be averaged
		 *
		 *  @param to_add The measurement to add
		 */
		void add_measurement(T to_add)
		{
			to_avg_.push_back(to_add);
		}

		/**
		 *	Calculates the average value of the measurements provided.
		 *
		 *  @return T The average value of the measurements provided
		 */
		T get_average() const
		{
			return 1.0 * std::accumulate(to_avg_.begin(), to_avg_.end(), 0.0) / to_avg_.size();
		}

		/**
		 *	Clears the list of measurements
		 */
		void clear()
		{
			to_avg_.clear();
		}

	private:
		unsigned int max_elems_;
		std::deque<T> to_avg_;
		
	};
}

#endif // AVERAGE_TRACKER_H