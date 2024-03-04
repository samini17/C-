/*
Student Name:Nahal Mousavi
Student Email:nmousavi4@myseneca.ca
Student ID : 133828178
section:NBB
Date: 22 Sep 2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#define _CRT_SECURE_NO_WARNINGS
#include "carads.h"
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>


double g_taxrate;
double g_discount;

namespace sdds {
	int Cars::counter = 0;

	Cars::Cars()
	{
		this->c_brand = nullptr;
		this->c_model = nullptr;
		this->c_price = -1;
		this->status = 'U';
		this->discountStatus = 'N';
		this->flag = false;
		this->c_year = -1;
	}
	
	void Cars::read(std::istream& is) {
		if (is) {

			std::string temp1;
			std::string temp2;
			is >> status;
			is.ignore();

			getline(is, temp1, ',');
			delete[] c_brand;
			c_brand = new char[strlen(temp1.c_str()) + 1];
			strcpy(c_brand, temp1.c_str());

			getline(is, temp2, ',');
			delete[] c_model;
			c_model = new char[strlen(temp2.c_str()) + 1];
			strcpy(c_model, temp2.c_str());

			is >> c_year;
			is.ignore();
			is >> c_price;
			is.ignore();
			is >> discountStatus;
			if (discountStatus == 'Y') {
				flag = true;
			}
			else
			{
				flag = false;
			}
		}
	}

	void Cars::display(bool reset)
	{
		if (reset) {

			counter = 0;
		}

		if (this->c_brand[0] != '\0')
		{
			std::cout << std::left << std::setw(2) << ++counter << ". ";

			std::cout << std::left << std::setw(10) << this->c_brand;

			std::cout << "| " << std::left << std::setw(15) << this->c_model;
			std::cout << "| " << this->c_year;
			std::cout << " |" << std::right << std::setw(12) << std::setprecision(2) << std::fixed << ((c_price * g_taxrate) + c_price) << "|";

			if (this->discountStatus == 'Y')
			{
				std::cout << std::right << std::setw(12) << std::setprecision(2) << std::fixed << ((c_price * g_taxrate) + c_price) - (((c_price * g_taxrate) + c_price) * g_discount);
			}
			std::cout << std::endl;

		}
	}

	char Cars::getStatus()
	{
		return this->status;
	}

	void listArgs(int argc, char* argv[])
	{
		std::cout << "Command Line:" << std::endl;
		std::cout << "--------------------------" << std::endl;
		for (int i = 0; i < argc; i++) {
			std::cout << "  " << i + 1 << ": " << argv[i] << std::endl;
		}
		std::cout << "--------------------------\n" << std::endl;
	}

	std::istream& operator>>(std::istream& is, Cars& car)
	{
		car.read(is);
		return is;
	}

	void operator>>(const Cars& car1, Cars& car2)
	{
		car2 = car1;
	}

	Cars::Cars(const Cars& src)
	{
		*this = src;
	}
	
	Cars& Cars::operator=(const Cars& src)
	{
		if (this != &src)
		{
			if (c_brand != nullptr)
			{
				delete[] c_brand;
				c_brand = nullptr;
			}
			c_brand = new char[strlen(src.c_brand) + 1];
			strcpy(c_brand, src.c_brand);


			if (c_model != nullptr)
			{
				delete[] c_model;
				c_model = nullptr;
			}
			c_model = new char[strlen(src.c_model) + 1];
			strcpy(c_model, src.c_model);

			c_year = src.c_year;
			c_price = src.c_price;
			status = src.status;
			discountStatus = src.discountStatus;
		}
		return *this;
	}
	
	Cars::~Cars()
	{
		if (c_brand != nullptr)
		{
			delete[] c_brand;
			c_brand = nullptr;
		}

		if (c_model != nullptr)
		{
			delete[] c_model;
			c_model = nullptr;
		}
	}
	
	Cars::operator bool() const
	{
		return this->status == 'N';
	}
}
