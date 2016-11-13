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

#ifndef MOVING_H
#define MOVING_H

#include "Drawable.hpp"
#include "Updatable.hpp"

namespace LocSim {

	/**
	 *	The Moving class provides the functionality for derived classes
	 *  to move their position by setting an X and/or Y velocity.
	 */
	class Moving : public Updatable, public Drawable
	{
	public:
		/**
		 *	Constructor
		 *
		 *  @param pos_x The inital X coordinate of the object
		 *  @param pos_y The intial Y coordinate of the object
		 *  @param velocity_x The initial X velocity of the object
		 *  @param velocity_y The initial Y velocity of the object
		 */
		Moving(float pos_x, float pos_y, float velocity_x, float velocity_y)
			: Drawable{ pos_x, pos_y }, velx_{ velocity_x }, vely_{ velocity_y }
		{ }

		/**
		 *	Default Constructor
		 */
		Moving() 
			: Moving{0, 0, 0, 0}
		{ }

		/**
		 *	Updates the Moving object as though one instant of time has passed. 
		 *  Updates the X and Y coordinates of the object based on their velocity
		 *  at the time of update.
		 */
		virtual void update() override;

		/**
		 *	Draws the Moving object in the window
		 *
		 *  @param window The window to draw in
		 */
		virtual void draw(sf::RenderWindow& window) const override = 0;

		/**
		 *	Sets the X velocity of the Moving object
		 * 
		 *  @param velx The new X velocity
		 */
		virtual void set_velocity_x(float velx);

	    /**
		 *	Sets the Y velocity of the Moving object
		 *
		 *  @param velx The newY velocity
		 */
		virtual void set_velocity_y(float vely);

		/**
		 *	Returns the current X velocity of the Moving object
		 *
		 *  @return float The current X velocity
		 */
		virtual float get_velocity_x() const;

		/**
		 *	Returns the current Y velocity of the Moving object
		 *
		 *  @return float The current Y velocity
		 */
		virtual float get_velocity_y() const;

	private:
		float velx_;
		float vely_;
	};

}

#endif	// MOVING_H