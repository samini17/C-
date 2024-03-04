/*
Student Name:Nahal Mousavi
Student Email:nmousavi4@myseneca.ca
Student ID : 133828178
section:NBB
Date: 23 oct 2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <cstddef>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"

namespace sdds
{
	SpellChecker::SpellChecker(const char* filename)
	{
		size_t m_count = 0;
		ifstream fin(filename);

		try {
			if (fin)
			{
				while (fin)
				{
					fin >> m_badWords[m_count];
					fin >> m_goodWords[m_count];

					m_count++;
				}
			}
			else
				throw("** EXCEPTION: Bad file name!\n");
		}
		catch (const char* msg)
		{
			cout << msg;
		}

	}

	void SpellChecker::operator()(std::string& text)
	{
		size_t ret = 0;
		size_t x = 0;

		while (x < 6)
		{
			if (m_goodWords[x] != "" && m_badWords[x] != "")
			{
				while ((ret = text.find(m_badWords[x])) != string::npos)
				{
					size_t len = m_badWords[x].length();
					text.replace(ret, len, m_goodWords[x]);
					replacements[x] += 1;
				}
				x++;
			}
			else
				return;
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const
	{
		if (m_badWords[0] != "")
		{
			cout << "Spellchecker Statistics\n";
			size_t x = 0;

			while (x < 6)
			{
				if (m_badWords[x] != "")
				{
					out << setw(15) << setfill(' ') << right << m_badWords[x];
					out << ": " << replacements[x] << " replacements" << endl;
				}
				x++;

			}
		}

	}

}