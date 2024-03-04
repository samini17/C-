//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: nov,10, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.//
#include <iomanip>
#include <sstream>
#include <string>

#include "Racecar.h"

namespace sdds
{
	Racecar::Racecar(std::istream &in) : Car::Car(in)
	{
		std::string str;

		std::getline(in, str, '\n');

		if (!str.empty())
			m_booster = std::stod(str);
		else
			m_booster = 0;
	}

	bool Racecar::valid()
	{
		return topSpeed() > 0;
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const
	{
		double ts = this->Car::topSpeed();
		if (m_booster > 0)
			ts = ts + ts * m_booster;


		return ts;
	}
}