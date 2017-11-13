// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"
#include <stdio.h>

void initArray(int array[], int n);
int gcd(int a, int b);
int lcm(int a, int b);
int lcmForArray(int array[], int n);
int absolute(int a);

void main() 
{
	// put your code here
	const int n = 10;	//array dimension
	int array[n];
	
	initArray(array, n);
	printf("%d\n", lcmForArray(array, n));
}
void initArray(int array[], int n)
{
	printf("Type %d integer numbers:\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
}
int gcd(int a, int b)		//TODO: wtf with 0?
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
int lcm(int a, int b)
{
	return absolute(a * b) / gcd(a, b);
}
int lcmForArray(int array[], int n)
{
	int tempLcm = lcm(array[0], array[1]);
	for(int i = 2; i < n ; i++)
	{
		tempLcm = lcm(tempLcm, array[i]);
	}
	return tempLcm;
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
