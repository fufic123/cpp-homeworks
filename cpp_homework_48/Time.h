#include <iostream>
using namespace std;

class Time{
private:
  int seconds;
  int minutes;
  int hours;

  Time(int seconds);
  Time(int seconds, int minutes);

public:
  Time();
  Time(int seconds, int minutes, int hours);

  int GetSeconds();
  int GetMinutes();
  int GetHours();

  void SetSeconds(int seconds);
  void SetMinutes(int minutes);
  void SetHours(int hours);

  Time operator + (int s);

  Time& operator ++ ();
  Time& operator -- ();

  Time operator ++ (int);
  Time operator -- (int);

  bool operator == (const Time& b);
  bool operator != (const Time& b);

  bool operator < (const Time& b);
  bool operator <= (const Time& b);

  bool operator > (const Time& b);
  bool operator >= (const Time& b);

  friend ostream& operator << (ostream& o, const Time& t);
  friend istream& operator >> (istream& i, Time& t);
};

Time::Time(){
  seconds = 0;
  minutes = 0;
  hours = 0;
}

Time::Time(int seconds){
    if (seconds < 0 || seconds > 59)
      this->seconds = 0;
    else
      this->seconds = seconds;
}

Time::Time(int seconds, int minutes): Time(seconds){
    if (minutes < 0 || minutes > 59)
      this->minutes = 0;
    else
      this->minutes = minutes;
}

Time::Time(int seconds, int minutes, int hours): Time(seconds, minutes){
    if (hours < 0 || hours > 23)
      this->hours = 0;
    else
      this->hours = hours;
}

int Time::GetSeconds(){
  return seconds;
}

int Time::GetMinutes(){
  return minutes;
}

int Time::GetHours(){
  return hours;
}

void Time::SetSeconds(int seconds)
{
    if (seconds < 0 || seconds > 59)
      this->seconds = this->seconds;
    else
      this->seconds = seconds;
}

void Time::SetMinutes(int minutes){
    if (minutes < 0 || minutes > 59)
      this->minutes = this->minutes;
    else
      this->minutes = minutes;
}

void Time::SetHours(int hours){
    if (hours < 0 || hours > 23)
      this->hours = this->hours;
    else
      this->hours = hours;
}

Time Time::operator + (int second){
    Time tmp(this->seconds, this->minutes, this->hours);
    seconds += second;
    if (seconds > 59)
    {
        int n = seconds % 60;
        seconds -= 60 * n;
        minutes += n;
        if (minutes > 59)
        {
            int k = minutes % 60;
            minutes -= 60 * k;
            hours += k;
            if (hours > 23)
            {
                int m = hours % 24;
                hours -= 24 * m;
            }
        }
    }
    return tmp;
}

Time& Time::operator ++ (){
    seconds += 1;
    if (seconds > 59)
    {
        minutes += 1;
        seconds = 0;
        if (minutes > 59)
        {
            hours += 1;
            minutes = 0;
            if (hours > 23)
                hours = 0;
        }
    }
    return *this;
}

Time& Time::operator -- (){
    seconds -= 1;
    if (seconds < 0)
    {
        minutes -= 1;
        seconds = 0;
        if (minutes < 0)
        {
            hours -= 1;
            minutes = 0;
            if (hours < 0)
                hours = 0;
        }
    }
    return *this;
}

Time Time::operator ++ (int){
    Time tmp(this->seconds, this->minutes, this->hours);
    seconds += 1;
    if (seconds > 59)
    {
        minutes += 1;
        seconds = 0;
        if (minutes > 59)
        {
            hours += 1;
            minutes = 0;
            if (hours > 23)
                hours = 0;
        }
    }
    return tmp;
}

Time Time::operator -- (int){
    Time tmp(this->seconds, this->minutes, this->hours);
    seconds -= 1;
    if (seconds < 0)
    {
        minutes -= 1;
        seconds = 0;
        if (minutes < 0)
        {
            hours -= 1;
            minutes = 0;
            if (hours < 0)
                hours = 0;
        }
    }
    return tmp;
}

bool Time::operator == (const Time& b){
    if (seconds == b.seconds && minutes == b.minutes && hours == b.hours)
      return true;
    return false;
}

bool Time::operator != (const Time& b){
    if (seconds == b.seconds && minutes == b.minutes && hours == b.hours)
      return false;
    return true;
}

bool Time::operator < (const Time& b){
    if (hours < b.hours)
      return true;
    else if (hours == b.hours)
    {
        if (minutes < b.minutes)
          return true;
        else if (minutes == b.minutes)
        {
            if (seconds < b.seconds)
              return true;
        }
    }
    return false;
}

bool Time::operator <= (const Time& b){
    if (hours < b.hours)
      return true;
    else if (hours == b.hours)
    {
        if (minutes < b.minutes)
            return true;
        else if (minutes == b.minutes)
        {
            if (seconds <= b.seconds)
                return true;
        }
    }
    return false;
}

bool Time::operator > (const Time& b){
    if (hours > b.hours)
      return true;
    else if (hours == b.hours)
    {
        if (minutes > b.minutes)
          return true;
        else if (minutes == b.minutes)
        {
          if (seconds > b.seconds)
            return true;
        }
    }
    return false;
}

bool Time::operator >= (const Time& b){
    if (hours > b.hours)
      return true;
    else if (hours == b.hours)
    {
        if (minutes > b.minutes)
          return true;
        else if (minutes == b.minutes)
        {
          if (seconds >= b.seconds)
            return true;
        }
    }
    return false;
}

ostream& operator << (ostream& ostream, const Time& time){
    if (time.seconds < 10 && time.minutes < 10 && time.hours < 10)
    {
      ostream << "0" << time.seconds << ":0" << time.minutes << ":0" << time.hours;
    }
    else if (time.seconds < 10 && time.minutes < 10 && time.hours >= 10)
    {
      ostream << "0" << time.seconds << ":0" << time.minutes << ":" << time.hours;
    }
    else if (time.seconds < 10 && time.minutes >= 10 && time.hours >= 10)
    {
      ostream << "0" << time.seconds << ":" << time.minutes << ":" << time.hours;
    }
    else if (time.seconds >= 10 && time.minutes < 10 && time.hours >= 10)
    {
      ostream << time.seconds << ":0" << time.minutes << ":" << time.hours;
    }
    else if (time.seconds < 10 && time.minutes >= 10 && time.hours < 10)
    {
      ostream << "0" << time.seconds << ":" << time.minutes << ":0" << time.hours;
    }
    else if (time.seconds >= 10 && time.minutes < 10 && time.hours < 10)
    {
      ostream << time.seconds << ":0" << time.minutes << ":0" << time.hours;
    }
    else if (time.seconds >= 10 && time.minutes >= 10 && time.hours < 10)
    {
      ostream << time.seconds << ":" << time.minutes << ":0" << time.hours;
    }
    else
    {
      ostream << time.seconds << ":" << time.minutes << ":" << time.hours;
    }
    return ostream;
}

istream& operator >> (istream& istream, Time& time){
    init:
        char c1, c2;
        cout << "Enter time in format ss:mm:hh: ";
        cin >> time.seconds >> c1 >> time.minutes >> c2 >> time.hours;
        if (c1 != ':' || c2 != ':' ||
            time.seconds < 0 || time.seconds > 59 ||
            time.minutes < 0 || time.minutes > 59 ||
            time.hours < 0 || time.hours > 23)
            goto init;
    return istream;
}