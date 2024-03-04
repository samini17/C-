//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: nov,10, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.//
#ifndef SDDS_VAN_H
#define SDDS_VAN_H
#include <iostream>
#include <string>
#include <cstddef>

#include "Vehicle.h"

namespace sdds
{

	class Van :public Vehicle
	{
		std::string vanMaker;
		std::string vanType;
		std::string vanCondition;
		std::string vanPurpose;
		double topspeed;

		//to find out if a string is a number or not
		bool isNumber(std::string str);

	public:

		Van(std::istream& istr);
		std::string condition() const;
		double topSpeed() const;
		std::string type() const;
		std::string usage() const;
		void display(std::ostream& ostr) const;
	};
}

#endif
#pragma once
