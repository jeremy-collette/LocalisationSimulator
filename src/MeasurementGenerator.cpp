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

#include "MeasurementGenerator.hpp"

namespace LocSim
{
	float MeasurementGenerator::get_random_pos_error()
	{
		return pos_error_dist_(mt_);
	}

	float MeasurementGenerator::get_random_vel_error()
	{
		return vel_error_dist_(mt_);
	}
	
	MeasurementData MeasurementGenerator::get_measurement(const float actual_x, const float actual_y, const float actual_x_vel, const float actual_y_vel)
	{
		auto x_pos_err = get_random_pos_error();
		auto y_pos_err = get_random_pos_error();

		auto x_vel_err = get_random_vel_error();
		auto y_vel_err = get_random_vel_error();
		return MeasurementData{ actual_x + x_pos_err, abs(x_pos_err), actual_y + y_pos_err, abs(y_pos_err), actual_x_vel + x_vel_err, abs(x_vel_err), actual_y_vel + y_vel_err, abs(y_vel_err) };
	}

}