//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: nov,10, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.//
#ifndef SDDS_LUXURYVAN_H
#define SDDS_LUXURYVAN_H
#include <iostream>
#include <cstddef>
#include <iomanip>
#include <sstream>
#include <string>

#include "Van.h"

namespace sdds
{
	class Luxuryvan :public Van
	{
		std::string m_consumption; // stores the value vans which can be used electronic power.

	public:
		Luxuryvan(std::istream& in); //constructor
		void display(std::ostream& out) const;
		std::string consumption() const;
		
	};
}

#endif


