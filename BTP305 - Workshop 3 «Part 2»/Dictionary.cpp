/*
Student Name:Nahal Mousavi
Student Email:nmousavi4@myseneca.ca
Student ID : 133828178
section:NBB
Date: 06 Oct 2022
I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
*/
#include "Dictionary.h"
#include <iomanip>

namespace sdds
{
	Dictionary::Dictionary()
	{
		m_term = "";
		m_definition = "";
	}

	bool Dictionary::operator==(const Dictionary& dict)
	{
		if (this->getTerm() == dict.getTerm())
			return true;
		else return false;
	}

	std::ostream& operator<<(std::ostream& ostr, const Dictionary& dict)
	{
		dict.display(ostr);
		return ostr;
	}

	void Dictionary::display(std::ostream& os) const
	{
		os << std::setw(20) << std::right << m_term << ": " << m_definition;
	}
}