// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"
#include <stdio.h>

void initArray(int array[], int n);
int gcd(int a, int b);
int gcdForArray(int array[], int n);

void main() 
{
	// put your code here
	const int n = 10;	//array dimension
	int array[n];
	
	initArray(array, n);
	printf("%d\n", gcdForArray(array, n));
}
void initArray(int array[], int n)
{
	printf("Type %d integer numbers:\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
}
int gcd(int a, int b)
{
	 while (a != b) 
	 {
        if (a > b) 
		{
            int temp = a;
            a = b;
            b = temp;
        }
        b -= a;
    }
    return a;
}
int gcdForArray(int array[], int n)
{
	int tempGcd = gcd(array[0], array[1]);
	for(int i = 2; i < n ; i++)
	{
		tempGcd = gcd(tempGcd, array[i]);
	}
	return tempGcd;
}
