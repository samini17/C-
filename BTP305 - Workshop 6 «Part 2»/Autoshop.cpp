//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: nov,10, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.//
#include <iomanip>
#include "Vehicle.h"
#include "Autoshop.h"

namespace sdds
{
	Autoshop& Autoshop::operator +=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const
	{
		std::vector<Vehicle*>::const_iterator x = m_vehicles.begin();

		while (x != m_vehicles.end())
		{
			(*x)->display(out);
			out << std::endl;
			x++;
		}

	}

	Autoshop::~Autoshop()
	{
		for (size_t x = 0; x < m_vehicles.size(); x++)
			delete m_vehicles[x];
	}
}