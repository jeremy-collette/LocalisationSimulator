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

#ifndef LOCALISING_ROBOT_H
#define LOCALISING_ROBOT_H

#include "AutonomousRobot.hpp"
#include "AverageFilter.hpp"
#include "Field.hpp"
#include "KalmanFilter.hpp"
#include "LastMeasurementFilter.hpp"
#include "MeasurementData.hpp"
#include "RobotEstimator.hpp"
#include "StandStill.hpp"

namespace LocSim
{
	/**
	 *	LocalisingRobot is an AutonomousRobot that sends periodic measurements
	 *  to RobotEstimators which attempt to track the Robot. 
	 */
	class LocalisingRobot : public AutonomousRobot
	{
	public:
		
		/** 
		 *	Constructor
		 *
		 *  @param actual_x The inital X position of the LocalisingRobot.
		 *  @param actual_y The inital Y position of the LocalisingRobot.
		 */
		LocalisingRobot(std::shared_ptr<AutonomousBehaviour> behaviour, const float actual_x, const float actual_y)
			: AutonomousRobot{behaviour, actual_x, actual_y }
		{
			float initial_x = Field::FIELD_SIZE.x / 2;
			float initial_y = Field::FIELD_SIZE.y / 2;
			estimators_.push_back(RobotEstimator{ std::make_shared<KalmanFilter>(KalmanFilter{ initial_x, initial_y, 0, 0 }), initial_x, initial_y, sf::Color::Color(255, 0, 0, 150) });
			estimators_.push_back(RobotEstimator{ std::make_shared<AverageFilter>(AverageFilter{ initial_x, initial_y, 0, 0 }), initial_x, initial_y, sf::Color::Color(255, 255, 0, 150) });
			estimators_.push_back(RobotEstimator{ std::make_shared<LastMeasurementFilter>(LastMeasurementFilter{ initial_x, initial_y, 0, 0 }), initial_x, initial_y, sf::Color::Color(0, 0, 255, 150) });
		}

		LocalisingRobot(float x, float y)
			: LocalisingRobot{ std::make_shared<StandStill>(StandStill{}), x, y }
		{ }

		/**
		 *	Default Constructor
		 */
		LocalisingRobot()
			: LocalisingRobot{ 0, 0 }
		{ }

		/**
		 *	Draws the LocalisingRobot in the supplied RenderWindow at the set
		 *  position.
		 *
		 *  @param window The RenderWindow to draw on
		 */
		virtual void draw(sf::RenderWindow& window) const override;

		/**
		 *  Updates the LocalisingRobot with the given UpdateData
		 *
		 *  @param data UpdateData about the current environment state.
		 */
		virtual void update() override;

		/**
		 *	Sends the given MeasurementData to each RobotEstimator
		 *
		 *  @param md MeasurementData containing a measurement.
		 */
		virtual void send_measurement(const MeasurementData& md);

		/**
		 *   Returns the RobotEstimators being used.
		 *
		 *   @return std::vector<RobotEstimator>& The RobotEstimators currently being used.
		 */
		virtual std::vector<RobotEstimator>& get_estimators();

	private:
		static const double MERGE_DIST;
		std::vector<RobotEstimator> estimators_;
	};
}


#endif // LOCALISING_ROBOT_H