#include "stdafx.h"

void initArray(int array[], int n);
void printArray(int array[], int n);

void sort(int array[], int out[], int n);

void main()
{
	const int n = 10;	//array dimension
	int array[n];
	int out[n];
	for (int i = 0; i < n; i++)
	{
		out[i] = -1;
	}
	initArray(array, n);
	sort(array, out, n);
	printArray(out, n);
}

void initArray(int array[], int n)
{
	printf("Type %d integer numbers:\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
}
void sort(int array[], int out[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)              
		{
			if (array[j] < array[i] ||array[j] == array[i] && j > i)
			{
				count++;
			} 
		}
		out[count] = array[i];                            
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
