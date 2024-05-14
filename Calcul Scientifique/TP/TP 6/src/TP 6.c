/*
 ============================================================================
 Name        : TP.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10000
#define n 2
double X[N];
double Y[N];
double **F;
void Discretisation()
{
	int i;
	for (i=0;i<N;i++)
	{
		X[i]=(double)i/(N-1.);
	}
}

double u(double x){
    return x;
}

double ui(double x,double i)
{
	return pow(x,i);
}

double v(double x)
{
	return 0;
}

void solveur(double u(double),double v(double))
{
	int i;
	double eps=(double)1./(N-1.);
	for (i=0;i<N;i++)
	{
		Y[i+1]=Y[i]+ eps*(u(X[i])*Y[i]+v(X[i]));
	}
}

void Ordre1()
{
	Y[0]=1.;
	Discretisation();
	solveur(u,v);
	int i;

	for (i=0;i<N;i++)
		{
			printf("%3.5lf ",Y[i]);
			printf("\n");

		}

}

void construct_F()
{
	int i,k;
	for (i=0;i<n;i++)
	{
		for (k=0;k<N;k++)
		{
			F[i][k]=0;
		}
	}for (i=0;i<n;i++) F[i] = malloc(N*sizeof(double));
	F[0][0]=1.;
}

void resoud(double ui(double,double),double v(double))
{
	int i,k;
	double x, fn;
	double eps=(double)1./(N-1.);
	for (i=0;i<N-1;i++)
	{
		x=X[i];
		fn=v(x);
		for (k=0;k<n;k++)
				{
					fn+= F[k][i]*ui(k,x);
				}
		F[n][i] = fn;
		for (k=0;k<n;k++)
		{
			F[k][i+1]= F[k][i]+ eps*F[k+1][i];
		}
	}
}
//CF photo ya deux boucle dont une qui calcule la somme des fn bre fvoir photo 14/12/2021

void Ordre_n()
{
	int i,k;
	F = malloc(N*sizeof (double*));
	for (i=0;i<N;i++) F[i] = malloc(n*sizeof(double));
	construct_F();
	resoud(ui,v);
	for (i=0;i<n;i++)
		{
			for (k=0;k<N;k++)
			{
				printf("%3.2lf ",F[i][k]);
			}
			printf("\n");
		}
}


int main(void) {
	//Ordre1();  		OK
	Ordre_n();
	return EXIT_SUCCESS;
}
