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

#ifndef WALK_IN_STRAIGHT_LINE_H
#define WALK_IN_STRAIGHT_LINE_H

#include "WaypointWalker.hpp"

#include <SFML/Graphics.hpp>

#include <vector>

namespace LocSim
{
	/**
	 *	The WalkInStraightLine class simply walks from it's initial position
	 *  to a point really far away (and off the screen)
	 */
	class WalkInStraightLine : public WaypointWalker
	{
	public:
		/**
		 *	Constructor
		 */
		WalkInStraightLine()
			: WaypointWalker(POINTS)
		{ }

	private:
		/* The point to walk to */
		static const std::vector<sf::Vector2f> POINTS;
	};
}

#endif // WALK_IN_STRAIGHT_LINE_H