///*
//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: OCT 13, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//*/

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include <iostream>
#include <cstddef>
#include "Reservation.h"

namespace sdds
{
	class ConfirmationSender
	{
		const Reservation** m_confirmation{ nullptr };
		size_t numReservations;
		size_t max = 10;

	public:

		ConfirmationSender();
		ConfirmationSender(ConfirmationSender &src);
		ConfirmationSender& operator=(const ConfirmationSender& src);
		ConfirmationSender(ConfirmationSender &&src);
		ConfirmationSender& operator=(ConfirmationSender&& src);

		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);

		~ConfirmationSender();

		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender&);
	};

}

#endif