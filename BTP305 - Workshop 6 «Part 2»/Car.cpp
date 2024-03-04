//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: nov,10, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.//
#include <iomanip>
#include "Car.h"
#include <sstream>
#include <string>

namespace sdds
{
	Car::Car(std::istream& istr)
	{
		carMaker = '\0';
		carCondition = '\0';
		topspeed = 0;

		std::string tag, temp;

		std::getline(istr, temp, ',');
		auto start = temp.find_first_not_of(' ');
		auto end = temp.find_last_not_of(' ');

		//trim only if string isn't empty
		if (end >= start)
			tag = temp.substr(start, (end - start) + 1);


		if (tag == "c" || tag == "C" || tag == "r" || tag == "R")
		{
			std::getline(istr, temp, ',');

			auto start = temp.find_first_not_of(' ');
			auto end = temp.find_last_not_of(' ');

			//trim only if string isn't empty
			if (end >= start)
				carMaker = temp.substr(start, (end - start) + 1);

			std::getline(istr, carCondition, ',');
			std::stringstream sstr(carCondition);
			sstr >> carCondition;


			if (carCondition.empty() || carCondition == " ")
			{
				carCondition = "n";
			}


			try
			{
				if (carCondition != "n" && carCondition != "b" && carCondition != "u")
					throw std::string("Invalid record!");

				istr >> temp;

				//if there is a comma at the end of temp
				if (temp[temp.length() - 1] == ',')
				{
					temp[temp.length() - 1] = '\0';
					std::stringstream ss(temp);

					getline(ss, temp, ',');
				}


				if (isNumber(temp))
					topspeed = stod(temp);

				else
				{
					topspeed = 0;
					throw std::string("Invalid record!");
				}

			}
			catch (std::string msg)
			{
				std::cout << msg << std::endl;
			}

			char ig;
			if (istr)
				istr >> ig;
		}
	}

	bool Car::isNumber(std::string str)
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

	std::string Car::condition() const
	{
		std::string con = "";

		if (carCondition == "n")
			con = "new";

		else if (carCondition == "u")
			con = "used";

		else if (carCondition == "b")
			con = "broken";

		return con;
	}

	double Car::topSpeed() const
	{
		return topspeed;
	}

	void Car::display(std::ostream& out) const
	{
		out << "| " << std::right << std::setw(10) << std::setfill(' ') << carMaker << " | ";
		out << std::left << std::setw(6) << std::setfill(' ') << condition() << " | ";
		out << std::setw(6) << std::setfill(' ') << std::fixed << std::setprecision(2) << topSpeed() << " |";
	}
}