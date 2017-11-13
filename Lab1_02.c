// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

void initArray(int array[], int n);
double getArrayAverage(int array[], int n);
int getClosestToX(int array[], int n, double x);
double absolute(double x);

void main()
{
	// put your code here
	const int n = 10;	//array dimension
	int array[n];

	initArray(array, n);
	printf("%d\n", getClosestToX(array, n, getArrayAverage(array, n)));
}

void initArray(int array[], int n)
{
	printf("Type %d integer numbers:\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
}
double getArrayAverage(int array[], int n)
{
	double average = 0;
	for (int i = 0; i < n; i++)
	{
		average += array[i];
	}
	return average / double(n);
}
int getClosestToX(int array[], int n, double x)
{
	double minDiff = absolute(array[0] - x);
	int minDiffIndex = 0;
	for (int i = 0; i < n; i++)
	{
		if (absolute(array[i] - x) < minDiff)
		{
			minDiff = absolute(array[i] - x);
			minDiffIndex = i;
		}
	}
	return array[minDiffIndex];
}
double absolute(double x)
{
	if (x >= 0)
	{
		return x;
	}
	else
	{
		return -x;
	}
}
