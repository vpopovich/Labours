//#include "stdafx.h"
#include <stdio.h>

void initArray(int array[], int n);
int getMaxSequence(int array[], int n);


void main() 
{
	// put your code here
	const int n = 10;	//array dimension
	int array[n];
	
	initArray(array, n);
	printf("Result is: %d\n", getMaxSequence(array, n));
}

void initArray(int array[], int n)
{
	printf("Type %d integer numbers:\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
}
int getMaxSequence(int array[], int n)
{
	int temp = array[0];
	int countTemp = 0;
	int countMax = 0;
	
	for(int i = 1; i < n; i++)
	{
		if(array[i] == temp)
		{
			countTemp++;
		}
		else
		{
			temp = array[i];
			countTemp = 0;
		}
		if(countTemp > countMax)	
		{
			countMax = countTemp;
		}
	}
	return countMax;
}
