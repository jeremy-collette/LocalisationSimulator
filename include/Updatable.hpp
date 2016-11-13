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

#ifndef UPDATABLE_H
#define UPDATABLE_H

namespace LocSim {
	
	/**
	 *	The Updatable class is an abstract base class that should be derived
	 *  by classes that require an update for each instant of time that passes.
	 */
	class Updatable {
	public:

		/**
		 *	Updates the derived class as though one instant of time has passed
		 */
		virtual void update() = 0;
	};

}

#endif // UPDATABLE_H