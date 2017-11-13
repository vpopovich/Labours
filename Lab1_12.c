
#include "stdafx.h"
//#include <stdio.h>

int getStartDayOfWeek();
int getDayOfWeek(int startDayOfWeek, int dd, int mm, int yy);
int countDays(int dd, int mm, int yy);
void printArrayOfBlackDays(int startDayOfWeek);

void main()
{
	const int n = 10;
	int array[n];

	printArrayOfBlackDays(getStartDayOfWeek());
}
int getStartDayOfWeek()
{
	int startDayOfWeek;
	printf("Enter the start day of week:\n");
	scanf("%d", &startDayOfWeek);
	return startDayOfWeek;
}
int getDayOfWeek(int startDayOfWeek, int dd, int mm, int yy) //TODO: wtf is current year???
{
	return (((countDays(dd, mm, yy) - countDays(1, 1, 2017)) % 7) + 7 + startDayOfWeek) % 7;
}
int countDays(int dd, int mm, int yy)
{
	int day = dd;
	int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((yy % 4 == 0) && (yy % 100 != 0) || (yy % 400 == 0))
	{
		month[1] = 29;
	}
	for (int i = 0; i < yy; i++)
	{
		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
		{
			day += 366;
		}
		else
		{
			day += 365;
		}
	}
	for (int i = 0; i < mm - 1; i++)
	{
		day += month[i];
	}
	return day;
}
void printBlackDays(int startDayOfWeek)
{
	for (int i = countDays(1, 1, 2017); i <= countDays(31, 12, 2017); i++)
	{
		
	}
}
