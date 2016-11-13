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

#ifndef KALMAN_FILTER_H
#define KALMAN_FILTER_H

#include "MeasurementData.hpp"
#include "MeasurementFilter.hpp"
#include "StateData.hpp"

#include "Eigen/Dense"

#include <string>


namespace LocSim {

	/**
	 *	The KalmanFilter is a MeasurementFilter that uses complex
	 *  matrix operations to filter measurement data and estimate
	 *  the state of an object.
	 */
	class KalmanFilter : public MeasurementFilter
	{
	public:
		/**
		*	Constructor
		*
		*  @param x_pos The initial X position measurement
		*  @param y_pos The initial Y position measurement
		*  @param x_vel The inital X velocity measurement
		*  @param y_vel The inital Y velocity measurement
		*/
		KalmanFilter(const float x_pos, const float y_pos, const float x_vel, const float y_vel)
		{
			// State
			X_(0, 0) = x_pos;
			X_(1, 0) = y_pos;
			X_(2, 0) = x_vel;
			X_(3, 0) = y_vel;

			// Process covariance (error)
			// (Start with high error)
			P_(0, 0) = 5*5;
			P_(0, 1) = 0;
			P_(0, 2) = 0;
			P_(0, 3) = 0;

			P_(1, 0) = 0;
			P_(1, 1) = 5*5;
			P_(1, 2) = 0;
			P_(1, 3) = 0;

			P_(2, 0) = 0;
			P_(2, 1) = 0;
			P_(2, 2) = 1*1;
			P_(2, 3) = 0;

			P_(3, 0) = 0;
			P_(3, 1) = 0;
			P_(3, 2) = 0;
			P_(3, 3) = 1*1;

			// Measurement covariance (error)
			R_(0, 0) = 0;
			R_(1, 0) = 0;
			R_(2, 0) = 0;
			R_(3, 0) = 0;

			// State co-efficient
			A_(0, 0) = 1;
			A_(0, 1) = 0;
			A_(0, 2) = 1;
			A_(0, 3) = 0;

			A_(1, 0) = 0;
			A_(1, 1) = 1;
			A_(1, 2) = 0;
			A_(1, 3) = 1;

			A_(2, 0) = 0;
			A_(2, 1) = 0;
			A_(2, 2) = 1;
			A_(2, 3) = 0;
			
			A_(3, 0) = 0;
			A_(3, 1) = 0;
			A_(3, 2) = 0;
			A_(3, 3) = 1;

			// Process noise
			Q_(0, 0) = 0.01f;
			Q_(0, 1) = 0;
			Q_(0, 2) = 0;
			Q_(0, 3) = 0;
			
			Q_(1, 0) = 0;
			Q_(1, 1) = 0.01f;
			Q_(1, 2) = 0;
			Q_(1, 3) = 0;
			
			Q_(2, 0) = 0;
			Q_(2, 1) = 0;
			Q_(2, 2) = 0.01f;
			Q_(2, 3) = 0;

			Q_(3, 0) = 0;
			Q_(3, 1) = 0;
			Q_(3, 2) = 0;
			Q_(3, 3) = 0.01f;

			// Measurement co-efficient
			C_(0, 0) = 1;
			C_(0, 1) = 0;
			C_(0, 2) = 0;
			C_(0, 3) = 0;
			
			C_(1, 0) = 0;
			C_(1, 1) = 1;
			C_(1, 2) = 0;
			C_(1, 3) = 0;
			
			C_(2, 0) = 0;
			C_(2, 1) = 0;
			C_(2, 2) = 1;
			C_(2, 3) = 0;

			C_(3, 0) = 0;
			C_(3, 1) = 0;
			C_(3, 2) = 0;
			C_(3, 3) = 1;

			// State error co-efficient
			E_(0, 0) = 1;
			E_(0, 1) = 0;
			E_(0, 2) = 0;
			E_(0, 3) = 0;

			E_(1, 0) = 0;
			E_(1, 1) = 1;
			E_(1, 2) = 0;
			E_(1, 3) = 0;

			E_(2, 0) = 0;
			E_(2, 1) = 0;
			E_(2, 2) = 1;
			E_(2, 3) = 0;

			E_(3, 0) = 0;
			E_(3, 1) = 0;
			E_(3, 2) = 0;
			E_(3, 3) = 1;
		}
		
		/**
		*	Adds a new measurement to the filter
		*
		*	@param md The measurement data to be added
		*/
		void add_measurement(const MeasurementData& md) override;		

		/**
		*	Gets the estimated state of the filter
		*
		*  @return StateData The estimated state of the filter
		*/
		StateData get_state() const override;

		/**
		*	Updates the filter estimate
		*/
		void update();

		/**
		*	Returns the name of the filter
		*
		*  @return std::string The name of the filter
		*/
		virtual std::string get_filter_name() const override;
		

	private:
		Eigen::Matrix<float, 4, 1> X_;
		Eigen::Matrix<float, 4, 4> P_;
		Eigen::Matrix<float, 4, 4> A_;
		Eigen::Matrix<float, 4, 1> Y_;
		Eigen::Matrix<float, 4, 4> R_;
		Eigen::Matrix<float, 4, 4> C_;
		Eigen::Matrix<float, 4, 4> E_;
		Eigen::Matrix<float, 4, 4> Q_;
	};

}


#endif