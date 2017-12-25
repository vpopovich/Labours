#include "stdafx.h"

//---- возвращается индекс скобки " {" для пары с максимальной глубиной

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
void sort(int array[], int out[], int n) 
{
	
	//int out[n];                                 // выходной массив
	for (int i = 0; i < n; i++) 
	{
		int count = 0;
		for (int j = 0; j < n; j++)              // для array[i] подсчет
		{
			if (array[j] < array[i]) 
			{ 
				count++; 
			}               // меньших его
			else                                          // а также равных ему
				if (array[j] == array[i] && j > i) 
				{ 
					count++; 
				}    // и стоящих слева
		}
		out[count] = array[i];                             // место в выходном
	}                                               // определяется счетчиком
	for (int i = 0; i < n; i++) 
	{ 
		array[i] = out[i]; 
	}
	//delete[]out;
}
void printArray(int array[], int n)
{
	printf("Result is:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
}
