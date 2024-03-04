//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: nov,10, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//

#include "Utilities.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* vehicle = nullptr;
		std::string temp="";
		char tag = '\0';

		getline(in, temp, '\n');

		if (!temp.empty())
		{
			try
			{
				std::stringstream sstr(temp);

				int x = 0;
				while (temp[x] == ' ')
					x++;

				tag = temp[x];

				if (tag == 'c' || tag == 'C')
				{
					vehicle = new Car(sstr);

					if ((vehicle->condition() != "n" && vehicle->condition() != "u" && vehicle->condition() != "b") && vehicle->topSpeed() <= 0)
					{
						delete vehicle;
						vehicle = nullptr;
					}

				}
					
				else if (tag == 'v' || tag == 'V')
				{
					vehicle = new Van(sstr);

					if ((vehicle->condition() != "n" && vehicle->condition() != "u" && vehicle->condition() != "b") && vehicle->topSpeed() <= 0)
					{
						delete vehicle;
						vehicle = nullptr;
					}
				}
					

				else if (tag == 'r' || tag == 'R')
				{
					vehicle = new Racecar(sstr);

					if ((vehicle->condition() != "n" && vehicle->condition() != "u" && vehicle->condition() != "b") && vehicle->topSpeed() <= 0)
					{
						delete vehicle;
						vehicle = nullptr;
					}
				}
					

				else if (tag == 'l' || tag == 'L')
				{
					vehicle = new Luxuryvan(sstr);
					if ((vehicle->condition() != "n" && vehicle->condition() != "u" && vehicle->condition() != "b") && vehicle->topSpeed() <= 0)
					{
						delete vehicle;
						vehicle = nullptr;
					}
				}
					

				else
					throw tag;

				
				return vehicle;
			}
			catch (char ch)
			{
				std::cout << "Unrecognized record type: [" << ch << "]" << std::endl;
			}

		}

		return vehicle;
	}
}