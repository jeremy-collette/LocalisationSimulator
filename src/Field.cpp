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

#include "Field.hpp"

#include <cassert>

namespace LocSim
{
	const float Field::FIELD_X_POS = 25;
	const float Field::FIELD_Y_POS = 25;
	const sf::Vector2f Field::FIELD_SIZE { 740, 540 };

	int Field::init()
	{
		if (!t_.loadFromFile("field.png"))
			return 1;
		s_ = sf::Sprite{ t_ };
		s_.setPosition(FIELD_X_POS, FIELD_Y_POS);
		initialised_ = true;
		return 0;
	}

	void Field::draw(sf::RenderWindow& window) const
	{
		assert(initialised_ == true);
		window.draw(s_);
	}

	sf::Vector2f Field::get_field_size()
	{
		return FIELD_SIZE;
	}
}