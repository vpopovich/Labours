//#include "stdafx.h"
#include <stdio.h>
#include <math.h>

double myFunc(double x);
double libFunc(double x);
double absolute(double x);
void printResult();

void main() 
{
	// put your code here
	printResult();
}

double myFunc(double x)
{
	const double eps = 0.0001;
	const double k = -0.5;
	double s = 0;
	double sn = 1;
	double t;
	int n =0;
	while (sn * sn > eps * eps)	
	{	
		s += sn;
		t = x * (k - n)/(1 + n);
		sn *= t;
		n++;
	}	
	return s;
}
double libFunc(double x)
{
	return 1.0/(sqrt(1 + x));
}
double absolute(double x)
{
	if (x < 0) return -x;
	else return x;
}
void printResult()
{
	printf("X\t\tmyFunc\t\tlibFunc\t\tdelta\n------------------------------------------------------------\n");
	for(double x = 0.1; x < 1; x += 0.1)
	{
		printf("%lf\t%lf\t%lf\t%lf\n",x, myFunc(x), libFunc(x), absolute(myFunc(x) - libFunc(x)));
	}
}
