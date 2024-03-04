//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: nov,17, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.//
#include "CrimeStatistics.h"
#include<cstring>

namespace sdds
{
	CrimeStatistics::CrimeStatistics(std::string fname)
	{
		try
		{
			std::ifstream file(fname);

			while (file.peek() != EOF)
			{
				Crime crime;
				char temp[26];
				std::string t;

				file.get(temp, 26);
				std::string str(temp);
				crime.province = str.substr(str.find_first_not_of(' '), (str.find_last_not_of(' ') - str.find_first_not_of(' ')) + 1);

				
				file.get(temp, 26);
				std::string str2(temp);
				crime.district = str2.substr(str2.find_first_not_of(' '), (str2.find_last_not_of(' ') - str2.find_first_not_of(' ')) + 1);

				
				file.get(temp, 26);
				std::string str3(temp);
				crime.crime = str3.substr(str3.find_first_not_of(' '), (str3.find_last_not_of(' ') - str3.find_first_not_of(' ')) + 1);

				
				file.get(temp, 6);
				std::string str4(temp);

				if (str4.find_first_not_of(' ') != str4.find_last_not_of(' '))
				{
					t = str4.substr(str4.find_first_not_of(' '), (str4.find_last_not_of(' ') - str4.find_first_not_of(' ')) + 1);

					if (!t.empty())
						crime.year = stoi(t);
				}

			
				file.get(temp, 6);
				std::string str5(temp);

				if (str5.find_first_not_of(' ') != str5.find_last_not_of(' '))
				{
					t = str5.substr(str5.find_first_not_of(' '), (str5.find_last_not_of(' ') - str5.find_first_not_of(' ')) + 1);

					if (!t.empty())
						crime.totalCases = stoi(t);
				}

			
				std::string tt;
				std::getline(file, tt, '\n');

				if (tt.find_first_not_of(' ') != tt.find_last_not_of(' '))
				{
					t = tt.substr(tt.find_first_not_of(' '), (tt.find_last_not_of(' ') - tt.find_first_not_of(' ')) + 1);

					if (!t.empty())
						crime.m_resolved = stoi(t);
				}

				
				collection.push_back(crime);
			}
		}

		catch (...)
		{
			std::cout << "Error while parsing file." << std::endl;
		}
	}


	void CrimeStatistics::display(std::ostream& ostr) const
	{
		
		std::for_each(begin(collection), end(collection), [&ostr](auto theCrime) {ostr << theCrime << std::endl; });

		
		int totalCases = std::accumulate(collection.begin(), collection.end(), (int)0, [](int s, const Crime& theCrime)
		{
			return s += theCrime.totalCases;
		});

		
		int totalResolvedCases = std::accumulate(collection.begin(), collection.end(), (int)0, [](int s, const Crime& theCrime)
		{
			return s += theCrime.m_resolved;
		});

		ostr << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		ostr << "| " << std::setw(78) << std::setfill(' ') << "Total Crimes: " << std::setw(6) << std::right << totalCases << " |" << std::endl;
		ostr << "| " << std::setw(78) << std::setfill(' ') << "Total Resolved Cases: " << std::setw(6) << std::right << totalResolvedCases << " |" << std::endl;

	}

	void CrimeStatistics::sort(std::string str)
	{
		try
		{
			if (str.compare("Province") == 0)
				std::sort(begin(collection), end(collection), [](const Crime& crime1, const Crime& crime2) {return (crime1.province < crime2.province); });

			else if (str.compare("Crime") == 0)
				std::sort(begin(collection), end(collection), [](const Crime& crime1, const Crime& crime2) {return (crime1.crime < crime2.crime); });

			else if (str.compare("Cases") == 0)
				std::sort(begin(collection), end(collection), [](const Crime& crime1, const Crime& crime2) {return ( crime1.totalCases < crime2.totalCases); });

			else if (str.compare("Resolved") == 0)
				std::sort(begin(collection), end(collection), [](const Crime& crime1, const Crime& crime2) {return (crime1.m_resolved < crime2.m_resolved); });

			else
				throw std::string(str);
		}

		catch (std::string str)
		{
			std::cout << "Error: Invalid Field [" << str << "]." << std::endl;
		}

	}

	void CrimeStatistics::cleanList()
	{
		std::transform(begin(collection), end(collection), begin(collection), [](Crime theCovid)
		{
			if (theCovid.crime.compare("[None]") == 0)
				theCovid.crime = "";

			return theCovid;
		});
	}

	bool CrimeStatistics::inCollection(std::string crime) const
	{
		return std::any_of(begin(collection), end(collection), [=](const Crime& theCovid) {return (theCovid.crime.compare(crime) == 0); });
	}

	std::list<Crime> CrimeStatistics::getListForProvince(std::string province) const
	{
		std::list<Crime> temp;
		std::copy_if(begin(collection), end(collection), std::back_inserter(temp), [=](const Crime& theCrime)-> bool {return (theCrime.province.compare(province) == 0); });

		return temp;
	}


	std::ostream& operator<<(std::ostream& out, const Crime& theCrime)
	{
		out << "| " << std::setw(21) << std::left << theCrime.province << " | " << std::setw(15) << std::left << theCrime.district << " | " << std::setw(20) << theCrime.crime << " | ";

		if (theCrime.year > 0)
			out << std::setw(6) << std::right << theCrime.year << " | ";

		else
			out << std::setw(6) << std::setfill(' ') << " " << " | ";

		out << std::setw(4) << std::right << theCrime.totalCases << " | " << std::setw(3) << theCrime.m_resolved << " |";

		return out;
	}
}