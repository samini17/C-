/*
Student Name:Nahal Mousavi
Student Email:nmousavi4@myseneca.ca
Student ID : 133828178
section:NBB
Date: 23 oct 2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Movie.h"

namespace sdds
{
	Movie::Movie()
	{
		movieTitle = "";
		movieDescription = "";
		movieYear = 0;
	}

	Movie::Movie(const std::string& strMovie)
	{
		stringstream token(strMovie);
		string temp, tmp;

		getline(token, temp, ',');
		movieTitle = temp.substr(temp.find_first_not_of(' '), (temp.find_last_not_of(' ') - temp.find_first_not_of(' ')) + 1);

		getline(token, temp, ',');
		tmp = temp.substr(temp.find_first_not_of(' '), (temp.find_last_not_of(' ') - temp.find_first_not_of(' ')) + 1);
		movieYear = stoi(tmp);

		getline(token, temp);
		movieDescription = temp.substr(temp.find_first_not_of(' '), (temp.find_last_not_of(' ') - temp.find_first_not_of(' ')) + 1);

	}

	const string& Movie::title() const
	{
		return movieTitle;
	}

	std::ostream& operator<<(std::ostream& os, const Movie& movie) {
		os << std::setw(40) << movie.movieTitle << " | " << movie.movieYear << " | " << movie.movieDescription << std::endl;
		return os;

	}
}