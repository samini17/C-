//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: nov,10, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.//
#include <iomanip>
#include "Van.h"
#include <sstream>
#include <string>

namespace sdds
{
	Van::Van(std::istream& istr)
	{
		std::string tag, temp, type;

		std::getline(istr, temp, ',');
		auto start = temp.find_first_not_of(' ');
		auto end = temp.find_last_not_of(' ');

		//trim only if string isn't empty
		if (end >= start)
			tag = temp.substr(start, (end - start) + 1);

		if (tag == "v" || tag == "V" || tag == "l" || tag=="L")
		{
			std::getline(istr, temp, ',');

			auto start = temp.find_first_not_of(' ');
			auto end = temp.find_last_not_of(' ');

			//trim only if string isn't empty
			if (end >= start)
				vanMaker = temp.substr(start, (end - start) + 1);

			std::getline(istr, vanType, ',');
			std::stringstream sstr(vanType);
			sstr >> vanType;

			try
			{
				if (vanType == "p")
					vanType = "pickup";
				else if (vanType == "m")
					vanType = "mini-bus";
				else if (vanType == "c")
					vanType = "camper";
				else throw std::string("Invalid record!");


				std::getline(istr, vanPurpose, ',');
				std::stringstream sstr2(vanPurpose);
				sstr2 >> vanPurpose;

				if (vanPurpose == "d")
					vanPurpose = "delivery";
				else if (vanPurpose == "p")
					vanPurpose = "passenger";
				else if (vanPurpose == "c")
					vanPurpose = "camping";
				else throw std::string("Invalid record!");

				std::getline(istr, vanCondition, ',');
				std::stringstream sstr3(vanCondition);
				sstr3 >> vanCondition;

				if (vanCondition == "n")
					vanCondition = "new";
				else if (vanCondition == "b")
					vanCondition = "broken";
				else if (vanCondition == "u")
					vanCondition = "used";
				else if (vanCondition.empty())
					vanCondition = "new";
				else throw std::string("Invalid record!");

				istr >> temp;

				//if there is a comma at the end of temp
				if (temp[temp.length() - 1] == ',')
				{
					temp[temp.length() - 1] = '\0';
					std::stringstream ss(temp);

					std::getline(ss, temp, ',');
				}


				if (isNumber(temp))
					topspeed = stod(temp);

			}
			catch (std::string msg)
			{
				std::cout << msg << std::endl;
			}

			
		}
	}

	bool Van::isNumber(std::string str)
	{

		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] == '\0')
				continue;

			if (isdigit(str[i]) == 0)
				return false;

		}
		return true;
	}


	std::string Van::condition() const
	{
		return vanCondition;
	}

	double Van::topSpeed() const
	{
		return topspeed;
	}

	std::string Van::type() const
	{
		return vanType;
	}

	std::string Van::usage() const
	{
		return vanPurpose;
	}

	void Van::display(std::ostream& out) const
	{
		out << "| " << std::right << std::setw(8) << std::setfill(' ') << vanMaker << " | ";
		out << std::left << std::setw(12) << std::setfill(' ') << type() << " | " << std::left << std::setw(12) << std::setfill(' ') << usage() << " | ";
		out << std::left << std::setw(6) << std::setfill(' ') <<condition() << " | ";
		out << std::setw(6) << std::setfill(' ') << std::fixed << std::setprecision(2) << topSpeed() << " |";
	}
}