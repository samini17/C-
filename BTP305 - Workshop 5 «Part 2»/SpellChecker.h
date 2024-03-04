/*
Student Name:Nahal Mousavi
Student Email:nmousavi4@myseneca.ca
Student ID : 133828178
section:NBB
Date: 23 oct 2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>
#include <cstddef>
#include <string>
using namespace std;


namespace sdds
{
	class SpellChecker {
		string m_badWords[6];
		string m_goodWords[6];
		int replacements[6]{ 0 };

	public:

		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;

	};


}

#endif
