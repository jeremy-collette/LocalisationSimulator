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

#ifndef INITIALISABLE_H
#define INITIALISABLE_H

namespace LocSim {

	/**
	 *	An abstract base class which specifies that derived classes
	 *  should be initialised using the 'init()' member before other
	 *  members are used.
	 *
	 *  This is usually for derived classes that need to perform
	 *  some kind of failure-prone task before they are used, such
	 *  as loading an image. 
	 */
	class Initialisable {
	public:
		/**
		 *	The 'init()' function should be called on derived classes
		 *  before other members are accessed.
		 * 
		 *  @return int 0 indicates success. 1 indicates failure.
		 */
		virtual int init() = 0;
	};

}

#endif // INITIALISABLE_H