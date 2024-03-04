///*
//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: OCT 13, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//*/

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <iostream>
#include <cstddef>
#include <string>

namespace sdds
{
	class Reservation {
		char m_id[15];
		std::string m_name;
		std::string m_email;
		size_t m_people;
		unsigned m_day;
		unsigned m_hour;
		std::string trimmer(std::string&) const;

	public:
		Reservation();
		void update(int day, int time);
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& rs);
	};


}

#endif