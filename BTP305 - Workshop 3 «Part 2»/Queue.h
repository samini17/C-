/*
Student Name:Nahal Mousavi
Student Email:nmousavi4@myseneca.ca
Student ID : 133828178
section:NBB
Date: 06 Oct 2022
I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
*/
#ifndef SDDS_QUEUE_H__
#define SDDS_QUEUE_H__
#include <iostream>

#include "Dictionary.h"

namespace sdds
{
	template <class T, unsigned CAPACITY>

	class Queue
	{
		unsigned currElements = 0;
		T m_elements[CAPACITY];
		static T m_temporaryObj; //class member

	public:
		unsigned size() const
		{
			return currElements;
		}

		void display(std::ostream& ostr = std::cout)
		{
			ostr << "----------------------\n";
			ostr << "| Dictionary Content |\n";
			ostr << "----------------------\n";

			for (unsigned i = 0; i < currElements; i++)
				ostr << m_elements[i] << std::endl;
			ostr << "----------------------\n";
		}

		virtual bool push(const T& item)
		{
			if (currElements < CAPACITY)
			{
				m_elements[currElements] = item;
				currElements++;
				return true;
			}
			return false;
		}

		T pop()
		{
			T removed = m_elements[0];

			for (unsigned int x = 1; x < size(); x++)
			{
				m_elements[x - 1] = m_elements[x];
			}

			currElements -= 1;

			return removed;
		}

		T operator[](unsigned index) const
		{
			if (index < 0 || index >= currElements)
				return m_temporaryObj;

			else return m_elements[index];
		}
		virtual ~Queue() {}
	};

	template <class T, unsigned CAPACITY>
	std::ostream& operator<<(std::ostream& ostr, const Queue<T, CAPACITY>& queue)
	{
		queue.display(ostr);
		return ostr;
	}

	template<class T, unsigned CAPACITY>
	T Queue<T, CAPACITY>::m_temporaryObj{};

	template<>
	Dictionary Queue<Dictionary, 100>::m_temporaryObj{ "Empty Term", "Empty Substitute" };
}
#endif 
