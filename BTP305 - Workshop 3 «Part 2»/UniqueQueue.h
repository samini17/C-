/*
Student Name:Nahal Mousavi
Student Email:nmousavi4@myseneca.ca
Student ID : 133828178
section:NBB
Date: 06 Oct 2022
I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
*/
#ifndef SDDS_SET_H__
#define SDDS_SET_H__
#include <iostream>
#include <cmath>

#include "Queue.h"

namespace sdds
{
	template <class T, unsigned CAPACITY = 100>

	class UniqueQueue :public Queue<T, 100>
	{

	public:
		//overriding method
		bool push(const T& item)
		{
			for (unsigned i = 0; i < this->size(); i++)
			{
				if ((*this)[i] == item)
					return false;
			}

			return Queue<T, CAPACITY>::push(item);
		}


	};
	//specialization
	template<>
	bool UniqueQueue<double>::push(const double& item)
	{
		for (unsigned i = 0; i < this->size(); i++)
		{
			if (fabs((*this)[i] - item) <= 0.005)
				return false;
		}

		return Queue<double, 100>::push(item);
	}



}
#endif 


