// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

void initArray(int array[], int n);
double getArrayAverage(int array[], int n);
void swap(int *x, int *y);
void semiSortArray(int array[], int n, double average);
void printArray(int array[], int n);

void main() 
{
	// put your code here
	const int n = 10;	//array dimension
	int array[n];
	
	initArray(array, n);
	semiSortArray(array, n, getArrayAverage(array, n));
	printArray(array, n);
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
void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void semiSortArray(int array[], int n, double average)
{
	int l = 0, r = n - 1;
	while (l <= r)
	{
		while (array[l] > average)
		{
			l++;
		}
		while (array[r] < average)
		{
			r--;
		}
		if (l <= r)
		{
			swap(&array[l++], &array[r--]);
		}
	}
}
void printArray(int array[], int n)
{
	printf("Result is:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
}
