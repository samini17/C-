/*
Student Name:Nahal Mousavi
Student Email:nmousavi4@myseneca.ca
Student ID : 133828178
section:NBB
Date: 23 oct 2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;
namespace sdds
{
	class Movie
	{
		string movieTitle{};
		size_t movieYear{ 0 };
		string movieDescription;

	public:
		Movie();
		const string& title() const;
		Movie(const std::string& strMovie);
		friend ostream& operator<<(ostream&, const Movie&);

		template <class T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(movieTitle);
			spellChecker(movieDescription);
		}
	};
}

#endif
