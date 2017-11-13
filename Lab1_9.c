// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"
#include <stdio.h>

void initArray(int array[], int n);
int sumSubArray(int array[], int n, int a, int b);
int getMinDiffIndex(int array[], int n);
int absolute(int a);

void main() 
{
	// put your code here
	const int n = 10;	//array dimension
	int array[n];
	
	initArray(array, n);
	printf("k = %d\n", 1 + getMinDiffIndex(array, n));
}
void initArray(int array[], int n)
{
	printf("Type %d integer numbers:\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
}
int absolute(int a)
{
	if (a >= 0)
	{
		return a;
	}
	else
	{
		return -a;
	}
}
int sumSubArray(int array[], int n, int a, int b)
{
	int sumArray = 0;
	for(int i = a; i <= b; i++)
	{
		sumArray += array[i];
	}
	return sumArray;
}
int getMinDiffIndex(int array[], int n)		//TODO: k =0 and k = n + 1 do we need?
{
	int minDiff = absolute(array[0] - sumSubArray(array, n, 1, n-1));
	int minDiffIndex = 0;
	for(int k = 0; k < n; k++)
	{
		if(absolute(sumSubArray(array, n, 0, k) - sumSubArray(array, n, k + 1, n-1)) < minDiff)
		{
			minDiff = absolute(sumSubArray(array, n, 0, k) - sumSubArray(array, n, k + 1, n-1));
			minDiffIndex = k;
		}
	}
	return minDiffIndex;
}
