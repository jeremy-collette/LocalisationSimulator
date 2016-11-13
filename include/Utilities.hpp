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

#ifndef UTILITIES_H
#define UTILITIES_H

namespace LocSim
{
	/**
	 *	The Utilities class provides some general static functionality that
	 *  is useful thoughout the solution.
	 */
	class Utilities
	{
	public:
		/**
		 *	Returns the distance between two points on a 2D plane.
		 *
		 *  @param a One point to compare
		 *  @param b The second point to compare
		 *	@return double The distance between 'a' and 'b' on a 2D plane.
		 */
		static double dist(sf::Vector2f a, sf::Vector2f b)
		{
			return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
		}

	};
}

#endif // UTILITIES_H