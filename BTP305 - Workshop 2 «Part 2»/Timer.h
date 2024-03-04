/*
name: Nahal Mousavi
email: nmousavi4@myseneca.ca
Student ID: 133828178
date: SEP 29, 2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_TIMER_H__
#define SDDS_TIMER_H__
#include <iostream>
#include <chrono>

using namespace std;
namespace sdds {
	class Timer {
		long long start_time;
		long long end_time;

	public:
		Timer();
		void start();
		long long stop();
	};
}
#endif // !SDDS_TIMER_H__#pragma once
