/*
Student Name:Nahal Mousavi
Student Email:nmousavi4@myseneca.ca
Student ID : 133828178
section:NBB
Date: 22 Sep 2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#include <istream>
#include <string>
#include <cstring>
#ifndef CARADS_H
#define CARADS_H
extern double g_taxrate;
extern double g_discount;
namespace sdds {
	void listArgs(int argc, char* argv[]);

	class Cars {
		static int counter;

		char* c_brand;
		char* c_model;
		int c_year;
		double c_price;
		char status;
		char discountStatus;
		bool flag;

	public:
		Cars();
		void read(std::istream& is);
		void display(bool reset);
		char getStatus();

		Cars(const Cars& src);
		Cars& operator=(const Cars& src);
		~Cars();

		operator bool() const;

	};

	std::istream& operator>>(std::istream& is, Cars& car);
	void operator>>(const Cars& car1, Cars& car2);
}

#endif
