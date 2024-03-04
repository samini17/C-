//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: nov,18, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.//
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <iostream>
#include <string>
#include <cstddef>

namespace sdds
{
	class Utilities
	{
		size_t m_widthField{ 1 };
		static char m_delimiter;

		std::string trimmer(std::string str) const;

	public:

		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};


}

#endif

