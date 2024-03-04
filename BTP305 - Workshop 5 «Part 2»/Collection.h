/*
Student Name:Nahal Mousavi
Student Email:nmousavi4@myseneca.ca
Student ID : 133828178
section:NBB
Date: 23 oct 2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstddef>

using namespace std;

namespace sdds
{
	template <typename T>
	class Collection
	{
		string m_name;
		size_t m_size;
		T* m_collection;

		void(*functionPtr)(const Collection<T>&, const T&);

	public:
		Collection()
		{
			m_name = "";
			m_size = 0;
			m_collection = nullptr;
			functionPtr = nullptr;
		}
		Collection(const std::string& name)
		{
			m_name = name;
			m_size = 0;
			m_collection = nullptr;
			functionPtr = nullptr;
		}
		~Collection()
		{
			delete[] m_collection;
		}
		const std::string& name() const {
			return m_name;
		}
		size_t size() const {
			return m_size;
		}
		void setObserver(void(*observer)(const Collection<T>&, const T&))
		{
			functionPtr = observer;
		}

		Collection<T>& operator+=(const T& item)
		{
			bool isExist = false;
			for (size_t i = 0; i < m_size && !isExist; i++)
			{
				if (m_collection[i].title() == item.title())
					isExist = true;
			}
			if (!isExist)
			{
				Collection temp;
				temp.m_size = m_size + 1;
				temp.m_collection = new T[temp.m_size];
				for (size_t i = 0; i < m_size; i++)
				{
					temp.m_collection[i] = m_collection[i];
				}
				temp.m_collection[m_size] = item;

				if (m_collection != nullptr)
				{
					delete[] m_collection;
					m_collection = nullptr;
				}
				m_size++;
				m_collection = new T[m_size];
				for (size_t i = 0; i < m_size; i++)
				{
					m_collection[i] = temp.m_collection[i];
				}
				delete[] temp.m_collection;
				temp.m_collection = nullptr;

				if (functionPtr != nullptr)
				{
					functionPtr(*this, item);
				}
			}
			return *this;
		}

		T& operator[](size_t idx) const
		{
			if (idx >= m_size)
			{
				throw std::out_of_range("Bad index [" + to_string(idx) + "]. Collection has [" + to_string(m_size) + "] items.");
			}

			return m_collection[idx];
		}
		T* operator[](const std::string& title) const
		{
			for (size_t x = 0; x < m_size; x++)
			{
				if (m_collection[x].title() == title)
					return &m_collection[x];
			}

			return nullptr;
		}
		Collection(const Collection&) = delete; 
		Collection<T>& operator=(const Collection&) = delete;
	};
	template <typename T>
	ostream& operator<<(ostream& ostr, const Collection<T>& collection)
	{
		for (size_t x = 0; x < collection.size(); x++)
			ostr << collection[x];
		return ostr;
	}
}

#endif
