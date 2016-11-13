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

#include "RobotEstimator.hpp"
#include "Utilities.hpp"

namespace LocSim
{
	void RobotEstimator::update(const sf::Vector2f& tracking_pos)
	{
		avg_.add_measurement(Utilities::dist(get_position(), tracking_pos));		
		circ_.setPosition(get_position());
		f_->update();
		StateData s = f_->get_state();
		set_position({ s.x_pos, s.y_pos });
	}

	double RobotEstimator::get_average_dist() const
	{
		return avg_.get_average();
	}

	void RobotEstimator::reset_average_dist()
	{
		return avg_.clear();
	}


	void RobotEstimator::add_measurement(const MeasurementData& md)
	{
		f_->add_measurement(md);
	}

	void RobotEstimator::draw(sf::RenderWindow& window) const
	{
		window.draw(circ_);
	}

	sf::Color RobotEstimator::get_colour() const
	{
		return circ_.getFillColor();
	}

	void RobotEstimator::set_colour(sf::Color col)
	{
		circ_.setFillColor(col);
	}

	void RobotEstimator::set_alpha(unsigned char a)
	{
		auto colour = circ_.getFillColor();
		colour.a = static_cast<sf::Uint8>(a);
		circ_.setFillColor(colour);
	}

	std::string RobotEstimator::get_filter_name() const
	{
		return f_->get_filter_name();
	}


}