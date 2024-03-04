
//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: nov,17, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.//
#ifndef SDDS_CRIMESTATISTICS_H
#define SDDS_CRIMESTATISTICS_H
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iomanip>

namespace sdds
{
	struct Crime
	{
	
		std::string province = "";
		std::string district = "";
		std::string crime = "";
		int totalCases = 0;
		int m_resolved = 0;
		int year = 0;
	};

	class CrimeStatistics
	{

		std::vector<Crime> collection;

	public:
		CrimeStatistics(std::string);
		void display(std::ostream& ostr) const;

		
		void sort(std::string);
		void cleanList();
		bool inCollection(std::string) const;
		std::list<Crime> getListForProvince(std::string) const;
		
	};

	std::ostream& operator<<(std::ostream& out, const Crime& theCovid);
}

#endif



