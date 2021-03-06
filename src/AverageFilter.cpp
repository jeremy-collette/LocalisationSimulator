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

#include "AverageFilter.hpp"

namespace LocSim
{
	const unsigned int AverageFilter::MAX_VARIABLE_READINGS = 5;

	std::string AverageFilter::get_filter_name() const
	{
		return{ "Average Measurement" };
	}

	void AverageFilter::add_measurement(const MeasurementData& md)
	{
		x_pos_readings.push_back(md.x_position);
		x_vel_readings.push_back(md.x_velocity);
		y_pos_readings.push_back(md.y_position);
		y_vel_readings.push_back(md.y_velocity);

		while (x_pos_readings.size() > MAX_VARIABLE_READINGS)
		{
			x_pos_readings.pop_front();
		}
		
		while (x_vel_readings.size() > MAX_VARIABLE_READINGS)
		{
			x_vel_readings.pop_front();
		}
		
		while (y_pos_readings.size() > MAX_VARIABLE_READINGS)
		{
			y_pos_readings.pop_front();
		}
		
		while (y_vel_readings.size() > MAX_VARIABLE_READINGS)
		{
			y_vel_readings.pop_front();
		}

		double avg_x = 0;
		for (const float & x : x_pos_readings)
		{
			avg_x += x;
		}
		avg_x /= x_pos_readings.size();
		avg_x_ = static_cast<float>(avg_x);

		double avg_y = 0;
		for (const float & y : y_pos_readings)
		{
			avg_y += y;
		}
		avg_y /= y_pos_readings.size();
		avg_y_ = static_cast<float>(avg_y);

		double avg_x_vel = 0;
		for (const float & x : x_vel_readings)
		{
			avg_x_vel += x;
		}
		avg_x_vel /= x_vel_readings.size();
		avg_x_vel_ = static_cast<float>(avg_x_vel);

		double avg_y_vel = 0;
		for (const float & y : y_vel_readings)
		{
			avg_y_vel += y;
		}
		avg_y_vel /= y_vel_readings.size();
		avg_y_vel_ = static_cast<float>(avg_y_vel);

	}

	StateData AverageFilter::get_state() const
	{
		return StateData{ avg_x_, avg_y_, avg_x_vel_, avg_y_vel_ };
	}

	void AverageFilter::update()
	{
		avg_x_ += avg_x_vel_;
		avg_y_ += avg_y_vel_;
	}
	
}