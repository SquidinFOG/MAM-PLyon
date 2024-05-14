/*
 ============================================================================
 Name        : TP4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Dichotomie(double f(double),double x,double y, int N)
{
	int i;
	double z;

	for (i=0;i<N;i++)
	{
		z= (x+y)/2.;
		if (f(x)*f(z)<=0) y=z;
		else x=z;
	}

	return z;
}

double f(double x)
{
	return exp(x)+x;
}



void newton(double f(double),double x,int N)
{
	int i;
	for (i=0; i<N; i++){
		x = -f(x)/deriv(f,x);
	}
	return x;
}

double deriv(double f(double),double x)
{
	return (f)
}



int main(void) {

double sol = Dichotomie(f,-1,0,10);
printf("%.6f et %.6f",sol,f(sol));

	return EXIT_SUCCESS;
}





