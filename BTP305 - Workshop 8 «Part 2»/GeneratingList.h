//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: nov,24, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.//

#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList() {}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool luhnsAlgorithm(const std::string& id)
		{
			int size = static_cast<int>(id.length());
			
			int lastDigit = id[id.length() - 1] - '0';
			bool toMultiply = true;
			int sum=0;

			for (int x = size - 2; x >= 0; x--)
			{
				int digit = id[x] - '0';

				if (toMultiply)
					digit = 2 * digit;

				//sum the digits
				sum += (digit / 10 + digit % 10);

				toMultiply = !toMultiply;
			}
				
			return ((10 - sum % 10) % 10 == lastDigit);
		}


		//TODO: Overload the += operator with a smart pointer
		// as a second operand.
		void operator+=(const std::unique_ptr<T> u_ptr)
		{
			list.push_back(*u_ptr);
		}


		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator+=(const T* r_ptr)
		{
			list.push_back(*r_ptr);
		}


		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H