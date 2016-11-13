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

#ifndef WALK_BACK_AND_FORWARD_H
#define WALK_BACK_AND_FORWARD_H

#include "WaypointWalker.hpp"

#include <SFML/Graphics.hpp>

#include <vector>

namespace LocSim
{
	/**
	 *	The WalkBackAndForward class simply walks repeatedly from one end of the 
	 *  field to the other.
	 */
	class WalkBackAndForward : public WaypointWalker
	{
	public:
		/**
		 *	Constructor
		 */
		WalkBackAndForward()
			: WaypointWalker(POINTS)
		{ }

	private:
		/* The points to follow */
		static const std::vector<sf::Vector2f> POINTS;
	};

}

#endif // WALK_BACK_AND_FORWARD_H