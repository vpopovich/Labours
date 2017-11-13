// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"
#include <stdio.h>

int getUpperBound();
int checkPrime(int x);
void getArrayPrime(int array[], int upperBound, int *dimArrayPrime);
void printArray(int array[], int n);

void main() 
{
	// put your code here
	const int n = 10;	//array dimension
	int array[n];
	int dimArrayPrime;

	getArrayPrime(array, getUpperBound(), &dimArrayPrime);
	printArray(array, dimArrayPrime);
}

int getUpperBound()
{
	int upperBound;
	printf("Enter the upper bound\n");
	scanf("%d", &upperBound);
	return upperBound;
}

int checkPrime(int x)
{
	for(int i = 2; i * i <= x; i++)
	{
		if(x % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

void getArrayPrime(int array[], int upperBound, int *dimArrayPrime)
{
	int i, countPrime = 0;
	for(i = 1; i <= upperBound; i++)
	{
		if(checkPrime(i) == 1)				//TODO: How about boolean?
		{
			array[countPrime] = i;
			countPrime++;
		}
	}
	*dimArrayPrime = countPrime;
}

void printArray(int array[], int n)
{
	printf("Result is:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
}
