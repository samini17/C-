/*
Student Name:Nahal Mousavi
Student Email:nmousavi4@myseneca.ca
Student ID : 133828178
section:NBB
Date: 23 oct 2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Book.h"

namespace sdds {

	Book::Book()
	{
		bookAuthor = "";
		bookTitle = "";
		bookDescription = "";
		bookCountry = "";
		bookYear = 0;
		bookPrice = 0.0;
	}
	
	const string& Book::title() const
	{
		return bookTitle;
	}

	const string& Book::country() const
	{
		return bookCountry;
	}

	const size_t& Book::year() const
	{
		return bookYear;
	}

	double& Book::price()
	{
		return bookPrice;
	}

	Book::Book(const std::string& strBook)
	{
		stringstream token(strBook);
		string temp = "";

		getline(token, temp, ',');
		bookAuthor = temp.substr(temp.find_first_not_of(' '), (temp.find_last_not_of(' ') - temp.find_first_not_of(' ')) + 1);

		getline(token, temp, ',');
		bookTitle = temp.substr(temp.find_first_not_of(' '), (temp.find_last_not_of(' ') - temp.find_first_not_of(' ')) + 1);

		getline(token, temp, ',');
		bookCountry = temp.substr(temp.find_first_not_of(' '), (temp.find_last_not_of(' ') - temp.find_first_not_of(' ')) + 1);

		getline(token, temp, ',');
		string tmp = temp.substr(temp.find_first_not_of(' '), (temp.find_last_not_of(' ') - temp.find_first_not_of(' ')) + 1);
		bookPrice = stod(tmp);

		getline(token, temp, ',');
		tmp = temp.substr(temp.find_first_not_of(' '), (temp.find_last_not_of(' ') - temp.find_first_not_of(' ')) + 1);
		bookYear = stoi(tmp);

		getline(token, temp);
		bookDescription = temp.substr(temp.find_first_not_of(' '), (temp.find_last_not_of(' ') - temp.find_first_not_of(' ')) + 1);

	}

	std::ostream& operator<<(std::ostream& os, const Book& book) {
		os << std::setw(20) << book.bookAuthor << " | " << std::setw(22) << book.bookTitle << " | " << std::setw(5) << book.bookCountry << " | " << std::setw(4) << book.bookYear << " | " << std::setw(6) << std::fixed << std::setprecision(2) << book.bookPrice << " | " << book.bookDescription << std::endl;
		return os;
	}
}