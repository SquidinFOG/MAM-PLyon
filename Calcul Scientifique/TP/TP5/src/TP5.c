/*
 ============================================================================
 Name        : TP5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define N 8

double **A;
double **B;
double **C;

void affiche_mat(double **A,int k)
{
	int i,j;
	for( i=0; i<k; i++)
	{
		for(j = 0; j<k; j++)
		{
			printf("%.3f ",A[i][j]);
		}
		printf("\n");
	}
}

void genere_matrice(double **A)
{
	double x;
	int i,j;

	for( i=0; i<N; i++)
	{
		for(j = 0; j<N; j++)
		{
			double x = (double)rand(); // x entre 0 et RAND_MAX
			A[i][j]=((x*20)/RAND_MAX)- 10;
		}
		printf("\n");
	}
}

void mult_naive(double **A,double **B,double **C)
{
    int i,j,k;

    for(i=0;i<N;i++)
    {
    	for(j=0;j<N;j++)
    	{
    		C[i][j]=0;
    		for(k=0;k<N;k++)
    		C[i][j]+= A[i][k]*B[k][j];
    	}
    }
}

void add_mat(double **A,double **B,double **C,int taille)
{
	int i,j;
	for( i=0; i<taille; i++)
	{
		for(j = 0; j<taille; j++)
		{
			C[i][j]=A[i][j]+B[i][j];
		}

	}
}
void sous_mat(double **A,double **B,double **C,int taille)
{
	int i,j;
	for( i=0; i<taille; i++)
	{
		for(j = 0; j<taille; j++)
		{
			C[i][j]=A[i][j]-B[i][j];
		}

	}
}
/*
void extraire_bloc(double **A,double **Aij,int i, int j,n)
{
	int k,l;
	for(k= n/2*(i-1); k<n/2+n/2*(i-1);k++ )
	{
		for(l= n/2*(i-1); l<n/2+n/2*(i-1);l++ )
		{
			if (i == 1)
			{
				Aij[k][l]=A[k][l];
			}
			else
			{
				Aij
			}
		}
	}

}*/

void extraire_mat(double **A, double **A_aux,int deb_i,int deb_j, int taille)
{
	int i,j;
	for( i=0; i<taille; i++)
	{
		for(j = 0; j<taille; j++)
		{
			A_aux[i][j]=A[deb_i+i][deb_j+j];
		}
	}
}

void assemble_mat(double **A, double **A_aux,int deb_i,int deb_j, int taille)
{
	int i,j;
	for( i=0; i<taille; i++)
	{
		for(j = 0; j<taille; j++)
		{
			A_aux[deb_i+i][deb_j+j]=A[i][i];
		}
	}
}

void strassen_aux(double **A,double **B,double **C, int taille)    //pas oublier le cas ou les matrice sont des réels avec un if puis recop le code
{
	double **M1;
	double **M2;
	double **M3;
	double **M4;
	double **M5;
	double **M6;
	double **M7;
	int i;
	M1 = malloc(taille*sizeof (double*));
	for (i=0;i<taille;i++) M1[i] = malloc(taille*sizeof(double));
	M2 = malloc(taille*sizeof (double*));
	for (i=0;i<taille;i++) M2[i] = malloc(taille*sizeof(double));
	M3 = malloc(taille*sizeof (double*));
	for (i=0;i<taille;i++) M3[i] = malloc(taille*sizeof(double));
	M4 = malloc(taille*sizeof (double*));
	for (i=0;i<taille;i++) M4[i] = malloc(taille*sizeof(double));
	M5 = malloc(taille*sizeof (double*));
	for (i=0;i<taille;i++) M5[i] = malloc(taille*sizeof(double));
	M6 = malloc(taille*sizeof (double*));
	for (i=0;i<taille;i++) M6[i] = malloc(taille*sizeof(double));
	M7 = malloc(taille*sizeof (double*));
	for (i=0;i<taille;i++) M7[i] = malloc(taille*sizeof(double));


}

void strassen(double **A,double **B,double **C)
{
	strassen_aux(A,B,C,N);
}


int main(void)
{
	int i;
	A = malloc(N*sizeof (double*));
	for (i=0;i<N;i++) A[i] = malloc(N*sizeof(double));
	B = malloc(N*sizeof (double*));
	for (i=0;i<N;i++) B[i] = malloc(N*sizeof(double));
	C = malloc(N*sizeof (double*));
	for (i=0;i<N;i++) C[i] = malloc(N*sizeof(double));
	genere_matrice(A);
	affiche_mat(A,N);
	sous_mat(A,A,C,N);
	affiche_mat(C,N);
	return EXIT_SUCCESS;
}
