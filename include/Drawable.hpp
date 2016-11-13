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

#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "SFML/Graphics.hpp"

namespace LocSim {

	/**
	 *	Drawable
	 *
	 *  Drawable is an inheritable base class that represents objects
	 *  that are 'drawn' (rendered) on the screen.
	 */
	class Drawable {
	public:
		/**
		*  Constructor
		*
		*  @param x_pos The initial x coordinate for the drawn object to reside on the screen
		*  (whether or not it is actually rendered yet)
		*  @param y_pos The initial y coordinate for the drawn object to reside on the screen
		*  (whether or not it is actually rendered yet)
		*/
		Drawable(float x_pos, float y_pos)
			: pos_{ x_pos, y_pos }
		{ }

		/**
		 *	Draws the derived object in the RenderWindow 'window'
		 */
		virtual void draw(sf::RenderWindow& window) const = 0;

		/**
		 *	Returns the position of the Drawable object.
		 *
		 *  @return The position to be drawn at in the window
		 */
		const sf::Vector2f& get_position() const;

		/**
		 *	Sets the position of the Drawable object.
		 *
		 *  @param new_pos The position to set the Drawable object to.
		 *
		 */
		void set_position(const sf::Vector2f& new_pos);

	private:
		sf::Vector2f pos_;

	};
}

#endif // DRAWABLE_H