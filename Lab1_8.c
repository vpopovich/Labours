// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"
#include <stdio.h>

void initArray(int array[], int n);
int maxInArray(int array[], int n);		//TODO: May be better in one function?
int minInArray(int array[], int n);
void swap(int *x, int *y);
void semiSortArray(int array[], int n, double average);
void printArray(int array[], int n);

void main() 
{
	// put your code here
	const int n = 10;	//array dimension
	int array[n];
	
	initArray(array, n);
	semiSortArray(array, n, ((maxInArray(array, n) + minInArray(array, n)) / 2.0));
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
int maxInArray(int array[], int n)		//TODO: May be better in one function?
{	
	int max = array[0];
	for(int i = 0; i < n; i++)
	{
		if(array[i] > max)
		{
			max = array[i];
		}
	}
	return max;
}
int minInArray(int array[], int n)		//TODO: May be better in one function?
{	
	int min = array[0];
	for(int i = 0; i < n; i++)
	{
		if(array[i] < min)
		{
			min = array[i];
		}
	}
	return min;
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
