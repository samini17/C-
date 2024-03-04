//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: nov,10, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.//

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include <list>
#include <cstddef>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop
	{
		//stores all vehicles in the autoshop
		std::vector<Vehicle*> m_vehicles;

	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;

		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{
			for (size_t x = 0; x < m_vehicles.size(); x++)
			{
				if (test(m_vehicles[x]) == true)
					vehicles.push_back(m_vehicles[x]);
			}
		}
		~Autoshop();
	};
}

#endif
