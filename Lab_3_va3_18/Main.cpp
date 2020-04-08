#include <iostream>
#include "Time.h"

#define MAXN 3

void printArrTime(Time* time);
void Sort(Time* time);
void addNMin(Time* time);

int main()
{
	Time time[MAXN];
	time[0] = Time(15, 6, 13);
	time[1] = Time(14, 5, 22);
	time[2] = Time(16, 19, 44);
	printArrTime(time);
	Sort(time);
	printArrTime(time);
	addNMin(time);
	printArrTime(time);
}

void printArrTime(Time* time)
{
	for (int i = 0; i < MAXN; i++)
	{
		cout << time[i] << endl;
	}
	cout << endl;
}

void Sort(Time* time)
{
	Time temp; 
	int	save;
	for (int i = 1; i < MAXN; i++)
	{
		temp = time[i];
		save = i - 1;
		while (save >= 0 && temp > time[save])
		{
			time[save + 1] = time[save];
			time[save] = temp;
			save--;
		}
	}
}

void addNMin(Time* time)
{
	unsigned n = 0;
	cout << "N = ";
	cin >> n;
	for (int i = 0; i < MAXN; i++)
	{
		time[i] += n;
	}
}