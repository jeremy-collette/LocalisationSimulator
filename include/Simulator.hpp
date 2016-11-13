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

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Field.hpp"
#include "LocalisingRobot.hpp"
#include "MeasurementGenerator.hpp"

#include <vector>

namespace LocSim {

	/**
	 *	Simulator
	 *
	 *	Contains the public interface for the simulator. This is where the magic happens!
	 *  The simulator class simulates robot localisation on a 2D plane by providing noisy
	 *  X and Y position / velocity mesaurements (based on true values) of a simulated
	 *  AutonomousRobot to MeasurementFilters.
	 *
	 *  These MeasurementFilters provide estimations of where they think the AutonomousRobot
	 *  is, and these estimations are compared to the true position of the robot - from which
	 *  average distances are derived. The average distance of a MeasurementFilter is the
	 *  average distance it's estimated position is from the actual position of the
	 *  AutonomousRobot over an entire second of real time.
	 *
	 *  These average distances are logged once every second in to a '.csv' file and are
	 *  available for analysis.
	 */
	class Simulator
	{
	public:		
		static const unsigned int WINDOW_WIDTH;
		static const unsigned int WINDOW_HEIGHT;
		static const unsigned int FRAMES_PER_MEASUREMENT;
		static const unsigned int FRAMES_PER_MONITOR_UPDATE;
		const unsigned int FRAMES_PER_SECOND;

		static const std::vector<std::string> TEST_NAMES;

		/**
		 *	Constructor
		 *
		 *  @param frames_per_sec The maximum FPS of the simulator window.
		 */
		Simulator(unsigned int frames_per_sec)
			: FRAMES_PER_SECOND{frames_per_sec}
		{ }

		/**
		 *	Runs the simulator with the test called 'test_name'
		 *
		 *  @param test_name The test to run.
		 */
		void run(std::string test_name);

	private:
		/**
		*	Runs the simulator with the test numbered 'test_number'
		*
		*   @param test_number The test to run.
		*/
		void run(int test_number);

		Field field_;
		MeasurementGenerator m_gen_;
		LocalisingRobot robot_;

	};

}

#endif // SIMULATOR_H