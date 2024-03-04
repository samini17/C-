//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: nov,10, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.//
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include "Car.h"
#include <iostream>
#include <string>
#include <cstddef>

namespace sdds
{
	class Racecar :public Car
	{
		//percentage to boost the car's spped
		double m_booster;

	public:
		Racecar(std::istream& in); //constructor
		bool valid();
		void display(std::ostream& out) const;
		double topSpeed() const; //returns the top speed of car including the booster

	};
}

#endif


