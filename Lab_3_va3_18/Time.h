#pragma once
#include <iostream>

using namespace std;

class Time
{
private:
	unsigned hour;
	unsigned minute;
	unsigned seconds;
public:
	Time();
	Time(unsigned h, unsigned m, unsigned s);
	~Time();
	void setHour(unsigned h);
	void setMinute(unsigned m);
	void setSecond(unsigned s);
	unsigned getHour();
	unsigned getMiute();
	unsigned getSecond();
	friend ostream& operator<<(ostream& out, const Time& time);
	friend bool operator>(const Time& t1, const Time& t2);
	Time& operator+=(const unsigned n);
};