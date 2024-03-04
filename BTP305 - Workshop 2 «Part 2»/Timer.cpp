/*
name: Nahal Mousavi
email: nmousavi4@myseneca.ca
Student ID: 133828178
date: SEP 29, 2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"Timer.h"

using namespace std;
namespace sdds {

	Timer::Timer()
	{
		start_time = 0;
		end_time = 0;
	}
	void Timer::start()
	{
		std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
		start_time = (long long) startTime.time_since_epoch().count();
	}
	
	long long Timer::stop()
	{
		std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
		end_time = (long long)endTime.time_since_epoch().count();
	    return end_time - start_time;
	}
}