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

#include "Moving.hpp"

namespace LocSim {

	void Moving::update()
	{
		const sf::Vector2f current_pos = get_position();
		sf::Vector2f new_pos{ current_pos.x + velx_, current_pos.y + vely_ };
		set_position(new_pos);
	}

	void Moving::set_velocity_x(float velx)
	{
		velx_ = velx;
	}

	void Moving::set_velocity_y(float vely)
	{
		vely_ = vely;
	}

	float Moving::get_velocity_x() const
	{
		return velx_;
	}

	float Moving::get_velocity_y() const
	{
		return vely_;
	}

}

