/*
name: Nahal Mousavi
email: nmousavi4@myseneca.ca
Student ID: 133828178
date: SEP 29, 2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "TennisLog.h"
#include <string>
#include <fstream>

using namespace std;
namespace sdds {
	ostream& operator<<(std::ostream& os, const TennisMatch& object)
	{
		if (object.tournamentID.empty() || object.tournamentName.empty() || object.winner.empty() || object.loser.empty() || object.matchID <= 0)
		{
			os << "Empty Match";
		}
		else
		{
			os << right << setw(23) << setfill('.') << "Tourney ID : "
				<< left << setw(30) << setfill('.') << object.tournamentID << endl;
			os << right << setw(23) << setfill('.') << "Match ID : " <<
				left << setw(30) << setfill('.') << object.matchID << endl;
			os << right << setw(23) << setfill('.') << "Tourney : " <<
				left << setw(30) << setfill('.') << object.tournamentName << endl;
			os << right << setw(23) << setfill('.') << "Winner : " <<
				left << setw(30) << setfill('.') << object.winner << endl;
			os << right << setw(23) << setfill('.') << "Loser : " <<
				left << setw(30) << setfill('.') << object.loser << endl;
		}
		return os;
	}

	TennisLog::TennisLog()
	{
		matches = nullptr;
		count = 0;
	}
	
	TennisLog::TennisLog(const char* filename)
	{
		size_t Count{};
		matches = nullptr;
		count = 0;
		string temp;
		fstream file;
		file.open(filename);
		if (file.is_open()) {
			while (!file.eof()) {
				getline(file, temp, '\n');
				Count++;
			}
			count = Count - 2;
			matches = new TennisMatch[count];
			file.clear();
			file.seekg(0l, ios::beg);

			getline(file, temp, '\n');
			unsigned long long i;
			for (i = 0; i < count; i++) {
				getline(file, matches[i].tournamentID, ',');
				getline(file, matches[i].tournamentName, ',');
				file >> matches[i].matchID;
				file.ignore();
				getline(file, matches[i].winner, ',');
				getline(file, matches[i].loser, '\n');
			}

		}file.close();

	}

	void TennisLog::addMatch(const TennisMatch& object)
	{
		TennisMatch* t = new TennisMatch[count + 1];
		unsigned long long i;
		for (i = 0; i < count; i++)
		{
			t[i] = matches[i];
		}
		t[count] = object;
		delete[] matches;
		matches = t;
		count++;
	}

	TennisLog TennisLog::findMatches(const char* n) const
	{
		TennisLog t;
		unsigned long long i;
		for (i = 0; i < count; i++)
		{
			if (matches[i].winner == n || matches[i].loser == n)
			{
				t.addMatch(matches[i]);
			}
		}
		return t;
	}

	TennisMatch TennisLog::operator[](size_t index) const
	{
		TennisMatch t;
		if (index < count)
		{
			return matches[index];
		}
		else
		{
			return t;
		}
	}

	TennisLog::operator size_t() const
	{
		return count;
	}

	TennisLog::~TennisLog()
	{
		deAllcoate();
	}

	void TennisLog::deAllcoate()
	{
		if (matches != nullptr)
		{
			delete[] matches;
			matches = nullptr;
		}
	}

	TennisLog::TennisLog(const TennisLog& tl)
	{

		matches = new TennisMatch[tl.count];
		unsigned long long i;
		for (i = 0; i < tl.count; i++)
		{
			matches[i] = tl.matches[i];
		}
		count = tl.count;
	}

	TennisLog& TennisLog::operator=(const TennisLog& tl)
	{
		if (this != &tl)
		{
			deAllcoate();
			matches = new TennisMatch[tl.count+1];
			count = tl.count;
			unsigned long long i;
			for ( i = 0; i < count; i++)
			{
				matches[i] = tl.matches[i];
			}
		}
		return *this;
	}

	TennisLog::TennisLog(TennisLog&& tl)
	{
		matches = tl.matches;
		count = tl.count;
		tl.matches = nullptr;
		tl.count = 0;
	}

	TennisLog& TennisLog::operator=(TennisLog&& tl)
	{
		if (this != &tl)
		{
			deAllcoate();
			count = tl.count;
			matches = tl.matches;
			tl.matches = nullptr;
			tl.count = 0;
		}
		return *this;
	}
}