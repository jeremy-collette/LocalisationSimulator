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

#include "KalmanFilter.hpp"

namespace LocSim
{
	std::string KalmanFilter::get_filter_name() const
	{
		return{ "Kalman Filter" };
	}

	void KalmanFilter::update()
	{
		X_ = A_ * X_;
		P_ = E_ * P_ + Q_;
		
	}

	void KalmanFilter::add_measurement(const MeasurementData& md)
	{
		const float x_pos = md.x_position;
		const float x_pos_err = md.x_pos_error;
		const float y_pos = md.y_position;
		const float y_pos_err = md.y_pos_error;
		const float x_vel = md.x_velocity;
		const float x_vel_err = md.x_vel_error; 
		const float y_vel = md.y_velocity;
		const float y_vel_err = md.y_vel_error;
		
		Eigen::Matrix<float, 4, 1> M = { x_pos, y_pos, x_vel, y_vel };
		R_(0, 0) = x_pos_err*x_pos_err;
		R_(0, 1) = 0; 
		R_(0, 2) = 0;
		R_(0, 3) = 0;

		R_(1, 0) = 0; 
		R_(1, 1) = y_pos_err*y_pos_err;
		R_(1, 2) = 0;
		R_(1, 3) = 0;

		R_(2, 0) = 0;
		R_(2, 1) = 0;
		R_(2, 2) = x_vel_err*x_vel_err;
		R_(2, 3) = 0; 
		
		R_(3, 0) = 0;
		R_(3, 1) = 0;
		R_(3, 2) = 0;
		R_(3, 3) = y_vel_err*y_vel_err;

		// Get the measurments we want
		Y_ = C_ * M;

		// Get the bottom of the KG formula
		Eigen::Matrix<float, 4, 4> bot { P_ + R_ };
		
		// Find the Kalman gain
		Eigen::Matrix<float, 4, 4> K = P_ * (bot.inverse()).transpose();


		// Update the state matrix proportionate to the Kalman gain
		X_ = X_ + K*(Y_ - X_);

		// Update the process error proportionate to the Kalman gain
		P_ = (P_.Identity() - K) * P_;
		
	}

	StateData KalmanFilter::get_state() const
	{
		return{ X_(0, 0), X_(1, 0), X_(2, 0), X_(3, 0) };
	}

}