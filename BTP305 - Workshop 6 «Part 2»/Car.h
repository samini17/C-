//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: nov,10, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.//
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include <string>
#include <cstddef>

#include "Vehicle.h"

namespace sdds
{
	class Car :public Vehicle
	{
		std::string carMaker;
		std::string carCondition;
		double topspeed;

		//to find out if a string is a number or not
		bool isNumber(std::string str);

	public:

		Car(std::istream& istr);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& ostr) const;
	};
}

#endif
