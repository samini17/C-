///*
//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: OCT 13, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//*/

#include "ConfirmationSender.h"

namespace sdds
{
	ConfirmationSender::ConfirmationSender()
	{
		m_confirmation = nullptr;
		numReservations = 0;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender &src)
	{
		max = src.max;
		numReservations = src.numReservations;

		m_confirmation = new const Reservation*[max];

		for (size_t i = 0; i < numReservations; i++)
			m_confirmation[i] = src.m_confirmation[i];

	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src)
	{
		if (this != &src)
		{
			if (src.m_confirmation)
			{
				delete[] this->m_confirmation;

				max = src.max;
				numReservations = src.numReservations;

				m_confirmation = new const Reservation*[max];
				for (size_t i = 0; i < numReservations; i++)
				{
					m_confirmation[i] = src.m_confirmation[i];
				}

			}
		}
		return *this;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src)
	{
		m_confirmation = src.m_confirmation;
		numReservations = src.numReservations;
		src.m_confirmation = nullptr;
		src.numReservations = 0;
	}
	
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src)
	{
		if (this != &src)
		{
			if (src.m_confirmation)
			{
				delete[] m_confirmation;
			}
			numReservations = src.numReservations;
			m_confirmation = src.m_confirmation;
			src.m_confirmation = nullptr;
			src.numReservations = 0u;
		}

		return *this;
	}

	ConfirmationSender::~ConfirmationSender()
	{
		delete[] m_confirmation;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool ifExists = false;

		if (m_confirmation)
		{
			for (size_t i = 0; i < numReservations; i++)
			{
				if (m_confirmation[i] == &res)
				{
					ifExists = true;
					break;
				}

			}
		}
		else
			m_confirmation = new const Reservation*[max];

		if (!ifExists)
		{

			if (numReservations >= max)
			{
				const Reservation** temp = new const Reservation*[numReservations];
				for (size_t i = 0; i < numReservations; i++)
					temp[i] = m_confirmation[i];

				delete[] m_confirmation;
				m_confirmation = new const Reservation*[numReservations + 1];

				m_confirmation = temp;
				max = numReservations + 1;

				delete[] temp;
			}

			m_confirmation[numReservations++] = &res;
		}

		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		for (size_t i = 0; i < numReservations; i++)
		{
			if (m_confirmation[i] == &res)
				m_confirmation[i] = nullptr;
		}

		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs)
	{
		os << "--------------------------\nConfirmations to Send\n--------------------------\n";

		if (!cs.m_confirmation)
			os << "There are no confirmations to send!\n";
		else
		{
			for (size_t i = 0; i < cs.numReservations; i++)
			{
				if (cs.m_confirmation[i])
					os << *(cs.m_confirmation[i]);
			}
		}

		os << "--------------------------\n";

		return os;
	}

}