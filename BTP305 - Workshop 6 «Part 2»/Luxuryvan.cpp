//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: nov,10, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.//
#include "Luxuryvan.h"

namespace sdds
{
	Luxuryvan::Luxuryvan(std::istream &in) : Van::Van(in)
	{
		std::string str;
		in >> str;

		if (str=="e")
			m_consumption = str;
		else if(str=="g")
			throw std::string("Invalid record!\n");
	}

	
	void Luxuryvan::display(std::ostream& out) const
	{
		Van::display(out);
		out << " electric van  *";
	}

	std::string Luxuryvan::consumption() const
	{
		if (m_consumption == "e")
			return "electric van";
		else
			return "gas consumed van";
	}

}