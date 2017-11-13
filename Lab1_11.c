// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
//#include <stdio.h>

void initStartDayOfWeek(int *startDayOfWeek);
void initDate(int *dd, int *mm, int *yy);
int getDayOfWeek(int startDayOfWeek, int dd, int mm, int yy);
int countDays(int dd, int mm, int yy);

void main()
{
	// put your code here
	int startDayOfWeek;
	int dd, mm, yy;

	initStartDayOfWeek(&startDayOfWeek);
	initDate(&dd, &mm, &yy);
	printf("%d\n", getDayOfWeek(startDayOfWeek, dd, mm, yy));
}
void initStartDayOfWeek(int *startDayOfWeek)
{
	printf("Enter start day of week:\n");
	scanf("%d", startDayOfWeek);
}
void initDate(int *dd, int *mm, int *yy)
{
	printf("Enter the date (dd-mm-yyyy)");
	scanf("%d-%d-%d", dd, mm , yy);
}
int getDayOfWeek(int startDayOfWeek, int dd, int mm, int yy) //TODO: wtf is current year???
{
		return (((countDays(dd, mm, yy) - countDays(1, 1, 2017)) % 7) + 7 + startDayOfWeek) % 7;
}
int countDays(int dd, int mm, int yy)
{
	int day = dd;
	int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
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
