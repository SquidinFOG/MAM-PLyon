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
#define N 4

double **A;
double **A1;
double **C;
double B[N];
double X[N];
double Y[N];

//------------------------------fonction utiles/d'init...-----------------------------------------------
void rempli_A(double **A){
	A[0][0]= 1.; A[0][1]= 3.; A[0][2]= 4.; A[0][3]= 1.;
	A[1][0]= 2.; A[1][1]= 4.; A[1][2]= 3.; A[1][3]= 4.;
	A[2][0]= 1.; A[2][1]= 1.; A[2][2]= 2.; A[2][3]= 5.;
	A[3][0]= 1.; A[3][1]= 4.; A[3][2]= 5.; A[3][3]= 2.;
}

void rempli_B(double *B){
	B[0] = 1.;
	B[0] = 2.;
	B[0] = 3.;
	B[0] = 3.;
}

double ABS(double a){
	if (a<0) return -a;
	else return a;
}

void aff_mat(double **A){
	int i,j;
	for( i=0; i<N; i++){
		for(j = 0; j<N; j++){
			printf("%.3f ",A[i][j]);
		}
		printf("\n");
	}
}

void aff_vect(double* x){
	int i,j;
	for ( i=0;i<N;i++){
		printf("%.3f ",x[i]);
	}
	printf("\n");
}
//------------------------------fonction du TP------------------------------------------------
int Trouvemax(double **A, int i){

	int j;
	int max;
	max = i;

	for( j=i; j<N; j++){
			if (ABS(A[j][i]) > max){
				max= j ;}
			}
	return max;
}

void echange_ligne(double **A, double *B, int l1, int l2){


	double tmp = B[l1];
	B[l1]=B[l2];
	B[l2] = tmp;
	double* tmp2 = A[l1];
	A[l1]=A[l2];
	A[l2]=tmp2;
}

void mult_scal(double **A,double *B, int l1, int l2, double s){
	int i;
	B[l1]=B[l1] + s*B[l2];
	for( i=0; i<N; i++){
		A[l1][i] = A[l1][i] + s*A[l2][i];
	}
}

void pivot(double **A,double *B){
	int i, j,ipiv;
	double s;
	for( i=0; i<N; i++){
			ipiv=Trouvemax(A,i);
			echange_ligne(A, B, i, ipiv);
			for(j = i+1; j<N; j++){
				s=(double)A[j][i]/A[i][i];
				mult_scal(A,B,i,ipiv,-s);
			}
	}
}

void Gauss(double **A, double *B, double *X){
	int i,j;
	pivot(A,B);
	for(i=N-1;i>=0;i--){
		for(j=i+1;j<N;j++){
			B[i] = B[i]-A[i][j]*X[j];
			X[i]=B[i]/A[i][i];
		}
	}
}


void Mult_vec(double **A, double *x, double *y)
{

    int i,j;



    for(i=0;i<N;i++)
    {
    	y[i]=0;
    	for(j=0;j<N;j++)
    	{
    		y[i]+= A[i][j]*x[j];
    	}
    }
}


void mult_mat(double**A, double**B, double**Y)
{
    int i,j,k;

    for(i=0;i<N;i++)
    {
    	Y[i]=0;
    	for(j=0;j<N;j++)
    	{
    		Y[i][j]=0;
    		for(k=0;k<N;k++)
    		Y[i][j]+= A[i][k]*B[k][j];
    	}
    }
}

void inverse(double **A, double **A1)
{
	  int i,j,k;
	  double *Acopy;
	  double I[N];
	  double aux[N];
	  for (i=0;i<N;i++);

}

int main(void) {

	int i;


	A = malloc(N*sizeof (double*));
	for (i=0;i<N;i++) A[i] = malloc(N*sizeof(double));
	rempli_A(A);
	rempli_B(X);
	Mult_vec(A, X, Y);
	aff_vect(Y);

	return EXIT_SUCCESS;
}
