#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Time {
private:
	unsigned short seconds;
	unsigned short minutes;
	unsigned short hours;

public:
	Time();
	Time(unsigned short seconds, unsigned short minutes, unsigned short hours);

	void Show() const;
	void Init();
	string toString();

	short GetSeconds() const;
	short GetMinutes() const;
	short GetHours() const;

	void SetSeconds(unsigned short seconds);
	void SetMinutes(unsigned short minutes);
	void SetHours(unsigned short hours);
};

ostream& operator << (ostream& o, const Time& t);
istream& operator >> (istream& i, Time& t);