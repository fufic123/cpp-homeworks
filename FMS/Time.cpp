#include "Time.hpp"
using namespace std;

Time::Time() : seconds(0), minutes(0), hours(0) {}
Time::Time(unsigned short seconds, unsigned short minutes, unsigned short hours) : seconds(seconds), minutes(minutes), hours(hours) {}

void Time::Show() const {
	cout << setw(2) << setfill('0') << hours << ":"
		<< setw(2) << setfill('0') << minutes << ":"
		<< setw(2) << setfill('0') << seconds << "\n";
}

void Time::Init() 
{
	char colon1, colon2;
	cout << "Enter Time in format hh:mm:ss >> ";
	cin >> seconds >> colon1 >> minutes >> colon2 >> hours;
	if (colon1 != ':' || colon2 != ':' || seconds < 0 || seconds > 59 || minutes < 0 || minutes > 59 || hours < 0 || hours > 23) 
	{
		system("cls");
		Init();
	}
}

string Time::toString() { return to_string(seconds) + ":" + to_string(minutes) + ":" + to_string(hours); }

short Time::GetSeconds() const { return seconds; }
short Time::GetMinutes() const { return minutes; }
short Time::GetHours() const { return hours; }

void Time::SetSeconds(unsigned short seconds) { this->seconds = seconds; }
void Time::SetMinutes(unsigned short minutes) { this->minutes = minutes; }
void Time::SetHours(unsigned short hours) { this->hours = hours; }

ostream& operator << (ostream& o, const Time& t) 
{
	o << setw(2) << setfill('0') << t.GetHours() << ":" 
		<< setw(2) << setfill('0') << t.GetMinutes() << ":" 
		<< setw(2) << setfill('0') << t.GetSeconds();
	return o;
}

istream& operator >> (istream& i, Time& t) 
{
	char colon1, colon2;
	unsigned short seconds, minutes, hours;
	INIT:
		cout << "Enter Time in format hh:mm:ss >> ";
		cin >> seconds >> colon1 >> minutes >> colon2 >> hours;
		if (colon1 != ':' || colon2 != ':' || seconds < 0 || seconds > 59 || minutes < 0 || minutes > 59 || hours < 0 || hours > 23) {
			system("cls");
			goto INIT;
		}
		t.SetSeconds(seconds);
		t.SetMinutes(minutes);
		t.SetHours(hours);
	return i;
}