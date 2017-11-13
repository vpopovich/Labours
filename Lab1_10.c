// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
//#include <stdio.h>

void initArray(int array[], int n);
void combineArrays(int arrayA[], int dimA, int arrayB[], int dimB, int arrayC[], int dimC);
void printArray(int array[], int n);

void main()
{
	// put your code here
	const int n = 5;	//array dimension
	int arrayA[n];
	int arrayB[n];
	int arrayC[2 * n];

	initArray(arrayA, n);
	initArray(arrayB, n);
	combineArrays(arrayA, n, arrayB, n, arrayC, 2 * n);
	printArray(arrayC, n + n);
}
void initArray(int array[], int n)
{
	printf("Type %d integer numbers:\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
}
void combineArrays(int arrayA[], int dimA, int arrayB[], int dimB, int arrayC[], int dimC)
{
	int countA = 0;
	int countB = 0;
	int i = 0;
	while ((countA < dimA || countB < dimB) && (i < dimC))
	{
		if(((arrayA[countA] <= arrayB[countB]) || (countB >= dimB)) && (countA < dimA))
		{
			arrayC[i] = arrayA[countA];
			i++;
			countA++;
		}
		if(((arrayB[countB] <= arrayA[countA]) || (countA >= dimA)) && (countB < dimB))
		{
			arrayC[i] = arrayB[countB];
			i++;
			countB++;
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
