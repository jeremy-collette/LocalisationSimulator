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

#include "DataLogger.hpp"

#include <cassert>

namespace LocSim
{
	bool DataLogger::write_string_vector(const std::vector<std::string> vec)
	{
		assert(initialised_);
		std::string to_write;
		for (const std::string &s : vec)
		{
			to_write += s + ",";
		}
		to_write[to_write.length() - 1] = '\n';

		DWORD written;
		WriteFile(f_,
			to_write.c_str(),
			static_cast<DWORD>(to_write.size()),
			&written,
			NULL);

		return (written == to_write.size());
	}

	int DataLogger::init()
	{
		f_ = CreateFile(f_name_.c_str(),
			GENERIC_READ | GENERIC_WRITE,
			0,
			NULL,
			CREATE_ALWAYS,
			FILE_ATTRIBUTE_NORMAL,
			NULL);

		if (f_ != INVALID_HANDLE_VALUE)
		{
			initialised_ = true;
			return !(write_string_vector(estimator_names_));
		}
		else
		{			
			return 1;
		}
	}

	bool DataLogger::write_to_file(const std::vector<double>& measurements)
	{
		std::vector<std::string> str_vec;
		for (const auto &d : measurements)
		{
			str_vec.push_back(std::to_string(d));
		}
		return write_string_vector(str_vec);
	}

	bool DataLogger::write_to_file(const std::vector<std::vector<double>>& averages)
	{
		for (int i = 0; i < averages[0].size(); ++i)
		{
			std::vector<double> to_write;
			for (int j = 0; j < averages.size(); ++j)
			{
				to_write.push_back(averages[j][i]);
			}
			if (!write_to_file(to_write))
			{
				return false;
			}
		}
		return true;
	}
}