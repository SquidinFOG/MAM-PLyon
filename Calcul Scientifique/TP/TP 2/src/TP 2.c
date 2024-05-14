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

int jour(float a){
	int i;
	int b = (int) a;
	int j = 0;
	float decimal = (float) (a-b);
	for (i=1; i<b;i++){
		if (i%4==0){
			j=j+366;
		}
		else{
			j=j+365;
		}
	}
	j+=decimal*365;
	return j;
}
/*int fibo(n){
	int *fibon;
	int i;
	fibon=malloc(sizeof(int)*n);
	fibon[0]=0;
	fibon[1]=1;
	for (i=2;i<=n;i++){
		fibon[i+1]=fibon[i]+fibon[i-1];
	}
	return fibon[n];
}*/
int fibo(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	return fibo(n-1)+fibo(n-2);
}


int main(void) {
int n=6;
int a=fibo(n);
printf("%d",a);
	return EXIT_SUCCESS;
}
