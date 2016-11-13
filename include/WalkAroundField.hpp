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

#ifndef WALK_AROUND_FIELD_H
#define WALK_AROUND_FIELD_H

#include "WaypointWalker.hpp"

#include "SFML/Graphics.hpp"

#include <vector>

namespace LocSim
{
	/**
	 *	The WalkAroundField class simply follows a number of pre-defined 'waypoints'
	 *  around the field repeatedly.
	 */
	class WalkAroundField : public WaypointWalker
	{
	public:
		/**
		 *	Constructor
		 */
		WalkAroundField()
			: WaypointWalker(POINTS)
		{ }

	private:
		/* The points to follow */
		static const std::vector<sf::Vector2f> POINTS;
	};

}

#endif // WALK_AROUND_FIELD_H