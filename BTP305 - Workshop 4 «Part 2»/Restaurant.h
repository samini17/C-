///*
//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: OCT 13, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//*/

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <iostream>
#include <cstddef>
#include "Reservation.h"

namespace sdds
{
	class Restaurant
	{
		Reservation* m_reservations=nullptr;
		size_t m_cnt;

	public:
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(Restaurant& res);
		Restaurant& operator=(const Restaurant& res);
		Restaurant(Restaurant&& res);
		Restaurant& operator=(Restaurant&& res);

		size_t size() const;
		~Restaurant();
		friend std::ostream& operator<<(std::ostream& os, const Restaurant&);

	};

}

#endif