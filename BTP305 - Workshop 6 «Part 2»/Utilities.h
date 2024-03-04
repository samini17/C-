//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: nov,10, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.//
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>
#include <sstream>
#include <string>
#include <cstddef>
#include "Vehicle.h"
#include "Van.h"
#include "Car.h"
#include "Luxuryvan.h"
#include "Racecar.h"


namespace sdds
{
	Vehicle* createInstance(std::istream& in);
}

#endif
