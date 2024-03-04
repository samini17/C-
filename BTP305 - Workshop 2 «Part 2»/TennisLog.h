/*
name: Nahal Mousavi
email: nmousavi4@myseneca.ca
Student ID: 133828178
date: SEP 29, 2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_TENNISLOG_H__
#define SDDS_TENNISLOG_H__
#include <iostream>


using namespace std;
namespace sdds {
	struct TennisMatch
	{
		string tournamentID;
		string tournamentName;
		int matchID;
		string winner;
		string loser;
	};


	ostream& operator<<(std::ostream& os, const TennisMatch& object);


	class TennisLog
	{
		TennisMatch* matches;
		unsigned long long count;

	public:
		TennisLog();
		void setEmpty();
		TennisLog(const char* filename);
		void addMatch(const TennisMatch& object);
		TennisLog findMatches(const char* n) const;
		TennisMatch operator[](size_t index) const;
		operator size_t() const;
		~TennisLog();
		void deAllcoate();

		// rule of five
		TennisLog(const TennisLog& tl);
		TennisLog& operator=(const TennisLog& tl);
		TennisLog(TennisLog&& tl);
		TennisLog& operator=(TennisLog&& tl);
	};
}




#endif // !SDDS_TENNISLOG_H__
