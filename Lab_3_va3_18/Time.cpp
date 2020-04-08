#include "Time.h"
#include "Time.h"

Time::Time()
{
	hour = minute = seconds = 0;
}

Time::Time(unsigned h, unsigned m, unsigned s)
{
	setHour(h);
	setMinute(m);
	setSecond(s);
}

Time::~Time()
{
}

void Time::setHour(unsigned h)
{
	if (h < 24)
		hour = h;
	else
	{
		throw ("Error: incorrect value of hour!");
	}
}

void Time::setMinute(unsigned m)
{
	if (m < 60)
		minute = m;
	else
		throw ("Error: incorrect value of minute!");
}

void Time::setSecond(unsigned s)
{
	if (s < 60)
		seconds = s;
	else
	{
		throw ("Error: incorrect value of seconds!");
	}
}

unsigned Time::getHour()
{
	return hour;
}

unsigned Time::getMiute()
{
	return minute;
}

unsigned Time::getSecond()
{
	return seconds;
}

Time& Time::operator+=(const unsigned n)
{
	if ((n + this->minute) > 59)
	{
		this->hour += (n + this->minute) / 60;
		this->minute = (n + this->minute) % 60;
	}
	else
		this->minute += n;
	return *this;
}

ostream& operator<<(ostream& out, const Time& time)
{
	out << time.hour << ":" << time.minute << ":" << time.seconds;
	return out;
}

bool operator>(const Time& t1, const Time& t2)
{
	return t1.hour * 60 * 60 + t1.minute * 60 + t1.seconds > t2.hour * 60 * 60 + t2.minute * 60 + t2.seconds;
}
