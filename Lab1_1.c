// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

void initArray(int array[], int n);
int getMaxCount(int array[], int n);

void main() 
{
	// put your code here
	const int n = 10;	//array dimension
	int array[n];
	
	initArray(array, n);
	printf("%d\n", getMaxCount(array, n));
}

void initArray(int array[], int n)
{
	printf("Type %d integer numbers:\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
}
int getMaxCount(int array[], int n)
{
	int maxCount = 0, maxCountIndex = 0;
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (array[j] == array[i])
			{
				count++;
			}
		}
		if (count > maxCount)
		{
			maxCount = count;
			maxCountIndex = i;
		}
	}
	return array[maxCountIndex];
}
