/*
Student Name:Nahal Mousavi
Student Email:nmousavi4@myseneca.ca
Student ID : 133828178
section:NBB
Date: 06 Oct 2022
I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
*/
#ifndef SDDS_DICTIONARY_H__
#define SDDS_DICTIONARY_H__

#include <iostream>
#include <string>

namespace sdds
{
	class Dictionary
	{
		std::string m_term{};
		std::string m_definition{};
	public:
		const std::string& getTerm() const { return m_term; }
		const std::string& getDefinition() const { return m_definition; }
		Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition }{}

		// TODO: Code the missing prototype functions and operators
		//       that the class needs in order to work with the Queue class.
		//       Implement them in the Dictionary.cpp file.

		Dictionary(); //default constructor
		//equals operator
		bool operator==(const Dictionary&);
		void display(std::ostream& os) const; //function to display a dictionary term -definition

	};
	std::ostream& operator<<(std::ostream& ostr, const Dictionary&); //helper function - insertion operator
}
#endif




