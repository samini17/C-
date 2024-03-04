/*
Student Name:Nahal Mousavi
Student Email:nmousavi4@myseneca.ca
Student ID : 133828178
section:NBB
Date: 23 oct 2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>
#include <cstddef>
#include <iomanip>
#include <sstream>

using namespace std;
namespace sdds
{
	class Book {
		string bookAuthor{};
		string bookTitle{};
		string bookDescription{};
		string bookCountry{};
		size_t bookYear{ 0 };
		double bookPrice{ 0 };
		
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend ostream& operator<<(ostream& os, const Book&);

		template <class T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(bookDescription);
		}
	};
}
#endif
