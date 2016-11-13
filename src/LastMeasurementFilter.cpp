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

#include "LastMeasurementFilter.hpp"

namespace LocSim
{
	std::string LastMeasurementFilter::get_filter_name() const
	{
		return{ "Last Measurement" };
	}

	void LastMeasurementFilter::add_measurement(const MeasurementData& md)
	{
		x_ = md.x_position;
		y_ = md.y_position;
		x_vel_ = md.x_velocity;
		y_vel_ = md.y_velocity;
	}

	StateData LastMeasurementFilter::get_state() const
	{
		return StateData{ x_, y_, x_vel_, y_vel_ };
	}

	void LastMeasurementFilter::update()
	{
		x_ += x_vel_;
		y_ += y_vel_;
	}

}