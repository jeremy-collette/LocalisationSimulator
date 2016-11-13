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

#include "LocalisationSimulator.hpp"
#include "Simulator.hpp"

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	std::cout << "LocalisationSimulator v" << LOCSIM_VERSION_IDENTIFIER << std::endl;
	std::cout << "Copyright (C) 2016 Jeremy Collette" << std::endl << std::endl;
	std::cout << "This program comes with ABSOLUTELY NO WARRANTY." << std::endl;
	std::cout << "This is free software, and you are welcome to redistribute it under certain conditions." << std::endl;;
	std::cout << "See the GNU General Public License version 3.0 for details." << std::endl << std::endl;

	if (argc <= 1)
	{
		std::cout << "Usage: <test_name> [max_frames_per_second]\n\n";
		std::cout << "Available tests:\n";
		for (const auto &s : LocSim::Simulator::TEST_NAMES)
		{
			std::cout << "\t" << s << "\n";
		}
	}
	else
	{
		unsigned int frames_per_second = 60;
		if (argc >= 3)
		{
			frames_per_second = atoi(argv[2]);
		}

		LocSim::Simulator s{ frames_per_second };
		std::string test_name{ argv[1] };
		s.run(test_name);		
	}

	return 0;
}

