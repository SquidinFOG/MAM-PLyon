/*
 ============================================================================
 Name        : TP.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : TP1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header"

void mult(double **A, double b[], double r[], int n){
	int i,j;
	for (i=0;i<n;i++){
		r[i]=0;
		for (j=0;i<n; i++){
			r[i]+=A[i][j]*b[j];
		}
	}
}

void jacobi(double **A, double b[], double x[],int n, int N_iter){
	int i,j,k;
	double s;
	double xtemp[N];
	for (i=0;i<n;i++){
		xtemp[i]=x[i];
	}

	for (k=0;k<N_iter;k++){
		s=0;
		for (i=0;i<n;i++){
			for (j=0;j<n;j++){
				s+=A[i][j]*x[j]; 				//inv xtemp et x
			}
		xtemp[i]=(b[i] - s - A[i][i]*x[i])/A[i][i] ;
		}
		x=xtemp;
	}

}

void GS(double **A, double b[], double x[],int n, int N_iter){
	int i,j,k;
		double s1,s2;
		double xtemp[N];
		for (i=0;i<n;i++){
				xtemp[i]=x[i];			//init de xtemp (c'est x(k+1) par la suite
			}

		for (k=0;k<N_iter;k++){
			s1=0;
			s2=0;
			for (i=0;i<n;i++){
				for (j=0;j<i;j++){
					s1+=A[i][j]*xtemp[j];
				}
				for (j=i+1;j<n;i++){
					s2+=A[i][j]*x[j];
				}
			xtemp[i]=(b[i] - s1 -s2)/A[i][i];
			}
			x=xtemp;
		}
}

void affiche2(double x[]){

	for (int i=0;i<N;i++){
		printf("%.3f ",x[i]);
	}
	printf("\n");
}

void affiche(double **A){
	for(int i=0; i<N; i++){
		for( int j = 0; j<N; j++){
			printf("%.3f ",A[i][j]);
		}
		printf("\n");
	}
}



int main(void) {

	double *A[N];
	//double Ax[N][N];
	double *x;
	double b[N];
	//int N_iter;
	int i,j;
	x = malloc(N*sizeof(double));
	//double *r;
	//r = malloc(N*sizeof(double));
	// init de b
	for (i=0;i<N;i++){
		b[i]=i;

	}
	//init de A

	for (i=0;i<N;i++){
		A[i] = malloc(N*sizeof(double));
	}
	for (i=0;i<N;i++){
			A[i][i] = 2;
			for (j=0;j<N;j++){
				if(fabs(i-j) == 1){
					A[i][j] = -1;
				}
				if(fabs(i-j) > 1){
					A[i][j] = 0;
				}
			}
		}


/*	// test affichage de A et b

	affiche(A);
	affiche2(b);
*/

	jacobi(A,b,x,N,100);
	affiche2(x);
	return EXIT_SUCCESS;
}
