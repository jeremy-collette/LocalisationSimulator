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

#ifndef DATA_LOGGER_H
#define DATA_LOGGER_H

#include "Initialisable.hpp"

#include <string>
#include <vector>
#include <Windows.h>

namespace LocSim
{
	class DataLogger : public Initialisable
	{
	public:
		/**
		 *	Constructor
		 * 
		 *  @param file_name The file name to log to
		 *  @param estimator_names The names of the estimators being logged
		 */
		DataLogger(std::string file_name, std::vector<std::string> estimator_names)
			: f_name_(file_name.begin(), file_name.end()), estimator_names_( estimator_names ), initialised_{ false }
		{ }

		/**
		 *	Destructor
		 *  
		 *  Frees the open file handle.
		 */
		~DataLogger()
		{
			if (initialised_)
			{
				CloseHandle(f_);
			}
		}

		/**
		*	The 'init()' function should be called before other 
		*	members are accessed to open the log file.
		*
		*  @return int 0 indicates success. 1 indicates failure.
		*/
		virtual int init() override;

		/**
		 *	Writes a vector of measurements to the log file
		 *  in CSV format.
		 *
		 *  @param measurements The measurements to write
		 *  @return bool 0 indicates success. 1 indicates 
		 *  failure.
		 */
		bool write_to_file(const std::vector<double>& measurements);		

		/**
		 *	Writes a vector of vectors of averages to the log file
		 *  in CSV format.
		 *
		 *  @param averages A vector containing vectors of averages,
		 *  where each vector contains the averages for one estimator
		 *  @return bool 0 indicates success. 1 indicates
		 *  failure.
		 */
		bool write_to_file(const std::vector<std::vector<double>>& averages);


	private:
		/**
		 *	Attempts to write a vector of strings to the log 
		 *  file in CSV format.
		 *
		 *  @param vec The strings to write
		 *  @return bool 0 indicates success. 1 indicates
		 *  failure.
		 */
		bool write_string_vector(const std::vector<std::string> vec);

		bool initialised_;
		std::string f_name_;
		std::vector<std::string> estimator_names_;
		HANDLE f_;
		

	};
}

#endif // DATA_LOGGER_H