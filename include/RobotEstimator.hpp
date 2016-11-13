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

#ifndef ROBOT_ESTIMATOR_H
#define ROBOT_ESTIMATOR_H

#include "AverageTracker.hpp"
#include "Drawable.hpp"
#include "MeasurementFilter.hpp"
#include "Robot.hpp"

#include <memory>

namespace LocSim
{
	/**
	 *	RobotEstimator is an object that renders a MeasurementFilter's estimated
	 *  state of an AutonomousRobot. It essentially shows the estimated position
	 *  and velocity of an AutonomousRobot given some kind of filter.
	 */
	class RobotEstimator : public Drawable
	{
	public:
		/**
		 *  Constructor
		 * 
		 *  @param filter The MeasurementFilter to use. This filter will take in state measurements
		 *  and provide an estimated state of an AutonomousRobot which will be rendered.
		 *  @param x The initial X position to draw the RobotEstimator
		 *  @param y The initial Y position to draw the RobotEstimator
		 *  @param colour The colour to render the RobotEstimator on the window
		 */
		RobotEstimator(std::shared_ptr<MeasurementFilter> filter, float x, float y, sf::Color colour)
			: Drawable{ x, y }, f_{ filter }, circ_{ Robot::ROBOT_SIZE / 2 }, avg_{}
		{
			set_colour(colour);
		}

		/**
		*  Constructor
		*
		*  @param filter The MeasurementFilter to use. This filter will take in state measurements
		*  and provide an estimated state of an AutonomousRobot which will be rendered.
		*  @param x The initial X position to draw the RobotEstimator
		*  @param y The initial Y position to draw the RobotEstimator
		*/
		RobotEstimator(std::shared_ptr<MeasurementFilter> filter, float x, float y)
			: RobotEstimator{filter, x, y, sf::Color::Blue }
		{ }

		/**
		*  Constructor
		*
		*  @param filter The MeasurementFilter to use. This filter will take in state measurements
		*  and provide an estimated state of an AutonomousRobot which will be rendered.
		*/
		RobotEstimator(std::shared_ptr<MeasurementFilter> filter)
			: RobotEstimator(filter, 0, 0)
		{ }
		
		/**
		 *	Draws the RobotEstimator at the position provided by the MeasurementFilter in the
		 *  window supplied.
		 *
		 *  @param window The window to draw the RobotEstimator in
		 */
		virtual void draw(sf::RenderWindow& window) const override;

		/**
		 *	Updates the RobotEstimator. This basically updates the MeasurementFilter and checks
		 *  the distance between the estimated position and 'tracking_pos', which is the actual
		 *  position of the AutonomousRobot being tracked. The distance is added to an
		 *  'AverageTracker', which is used to provide the average distance between the
		 *  MeasurementFilter and the actual robot (and accessed using 'get_average_dist()').
		 *
		 *  @param tracking_pos The actual position of the AutonomousRobot being tracked.
		 */
		virtual void update(const sf::Vector2f& tracking_pos);

		/**
		 *	Adds a measurement of the AutonomousRobot being tracked to the MeasurementFilter being
		 *  used.
		 *
		 *  @param md A measurement of the AutonomousRobot being tracked.
		 */
		virtual void add_measurement(const MeasurementData& md);

		/**
		 *	Sets the alpha component of the colour of the circle representing the RobotEstimator
		 * 
		 *  @param a An alpha value between 0 and 255
		 */
		virtual void set_alpha(unsigned char a);

		/** 
		 *	Sets the colour of the circle representing the RobotEstimator
		 *
		 *  @param col The new colour of the circle
		 */
		virtual void set_colour(sf::Color col);

		/**
		 *	Returns the colour of the circle representing the RobotEstimator
		 *
		 *  @return sf::Color The colour of the circle
		 */
		virtual sf::Color get_colour() const;

		/**
		 *	Returns the name of the MeasurementFilter in use.
		 *
		 *  @return std::string The name of the MeasurementFilter in use.
		 */
		std::string RobotEstimator::get_filter_name() const;

		/**
		 *	Returns the average distance between the RobotEstimators estimated position of the
		 *  AutonomousRobot being tracked and the actual position.
		 *
		 *  @return The average distance between the RobotEstimators estimated position of the
		 *  AutonomousRobot being tracked and the actual position.
		 */
		double get_average_dist() const;

		/**
		 *	Resets the AverageTracker so that new measurements can be added for the average
		 *  distance value.
		 */
		void reset_average_dist();

	private:
		sf::CircleShape circ_;
		std::shared_ptr<MeasurementFilter> f_;
		AverageTracker<double> avg_;
	};


}

#endif // ROBOT_ESTIMATOR_H