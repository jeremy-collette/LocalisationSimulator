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

#include "LocalisingRobot.hpp"

namespace LocSim
{
	void LocalisingRobot::draw(sf::RenderWindow& window) const
	{
		AutonomousRobot::draw(window);

		for (const auto& e : estimators_)
		{
			e.draw(window);
		}
	}

	void LocalisingRobot::update()
	{
		AutonomousRobot::update();

		for (auto&e : estimators_)
		{
			e.update(get_position());
		}

	}

	void LocalisingRobot::send_measurement(const MeasurementData& md)
	{
		for (auto&e : estimators_)
		{
			e.add_measurement(md);
		}

	}

	std::vector<RobotEstimator>& LocalisingRobot::get_estimators()
	{
		return estimators_;
	}

}