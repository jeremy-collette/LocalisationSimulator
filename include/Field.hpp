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

#ifndef FIELD_H
#define FIELD_H

#include "Drawable.hpp"
#include "Initialisable.hpp"

namespace LocSim {

	/**
	 *	Field
	 *
	 *	A class that represents a RoboCup SPL field, using the supplied
	 *  image asset. Must be initialised before use to load the image.
	 */
	class Field : public Initialisable, public Drawable {
	public:
		/**
		 *  The size of the field image being loaded and rendered
		 */
		static const sf::Vector2f FIELD_SIZE;

		/**
		 *	Constructor
		 *
		 *	Instantiates a field object.
		 */
		Field()
			: Drawable{ FIELD_X_POS, FIELD_Y_POS }, initialised_{ 0 }
		{ }

		/**
		 *	Attempts to load the field image to render.
		 *
		 *  @return An integer indicating if initialisation was successful or not.
		 *  Returns 0 for success, and 1 for failure.
		 */
		virtual int init() override;

		/**
		 *	Draws the loaded field image to the supplied RenderWindow at the set
		 *  position.
		 *
		 *  @param window The RenderWindow to draw on
		 */
		virtual void draw(sf::RenderWindow& window) const override;

		/**
		 *	Returns the size of the field image stored in FIELD_SIZE.
		 *
		 *  @return The size of the field image.
		 */
		static sf::Vector2f get_field_size();

	private:
		static const float FIELD_X_POS;
		static const float FIELD_Y_POS;
		bool initialised_;
		sf::Texture t_;
		sf::Sprite s_;
	};

}

#endif // FIELD_H