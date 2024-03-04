//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: dec,03, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.//

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include "Workstation.h"


namespace sdds
{

	class LineManager
	{
		std::vector<Workstation*> m_activeLine;
		size_t m_cntCustomerOrder;
		Workstation* m_firstStation;

	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void reorderStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};
}

#endif

