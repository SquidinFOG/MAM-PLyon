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

#define n 10
#define min(a,b) (a<b) ? a : b
#define INF 1000


typedef struct element{
	int val;
	struct element* suiv;
}element;
typedef element* liste;

void genGraph(int **M)
{
	int i, j;
	//on mets les poids de chaque arc
	M[0][1]=10 ; 	M[0][3]=4 ; 	M[0][5]=10 ;
	M[1][4]= 5;		M[1][8]=17 ;	M[1][9]=10 ;
	M[2][0]=4 ;		M[2][3]=10 ;	M[2][4]= 16;
	M[3][5]=12 ;	M[3][6]=21 ;
	M[4][6]=4 ;
	M[5][7]=3 ;
	M[6][9]=3 ;
	M[7][6]=5 ;		M[7][9]=5 ;

	M[9][8]= 8;
	//on remplace les 0 par INF sauf dans la diagonale

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if ((M[i][j]==0)&&(i!=j))
			{
				M[i][j]=INF;
			}
		}
	}
}


liste ajoutDebut(liste l, int k){
	// renvoie la liste c à laquelle on a ajouté un élément k
	liste ajout=(liste) malloc(sizeof(element));
	ajout->val=k;
	ajout->suiv=l;
	return ajout;
}


void affiche(int **M){
    //fonction qui affiche une matrice n*n
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
        	if(M[i][j]!=INF)
        	{
        		printf(" %d ",M[i][j]);
        	}
        	else
        	{
        		printf("INF ");
        	}

        }
        printf("\n");
    }
}

void afficheListe(liste l){
	while(l!=NULL){
		printf("%d ",l->val);
		l=l->suiv;
	}
	printf("\n");
}


int cardinal(liste l)
{
	//fonction qui renvoie le cardinal de la liste chainé l
	int card=0;
	while(l!=NULL){
		card++;
		l=l->suiv;
	}
	return card;
}

int appartientaC(int k, liste c)
{
	// retourne 1 si c contient k, retourne 0 sinon
	if(c==NULL) return 0;
	while(c!=NULL)
	{
		if(c->val==k)
		{
			return 1;
		}
		c=c->suiv;
	}
		return 0;
}

int rechercheY(liste c, int d[n])
{
	//retourne y, l'indice tel que d[y]=min{d[k],pour tout sommet k qui n'est pas dans c
	int y, k=0;

	while(appartientaC(k,c)){
		k++;
	}
	y=k;

	for(k=0;k<n;k++){
		if(!appartientaC(k,c) && d[y]>d[k]) y=k;
	}
	return y;

}

void Dijkstra(int **M,int dep,int arv)
{
	//initialisation
	liste c=NULL;
	int d[n], pred[n];
	c=ajoutDebut(c,dep);
	d[dep]=0;
	int k;
	for(k=0;k<n;k++)
	{
		if(k!=dep)
		{
			d[k]=M[dep][k]; pred[k]=dep;
		}
	}


	// Construction de c
	int y;
	while(cardinal(c)<n){
		y=rechercheY(c,d);
		if(d[y]==INF)
		{
			break;
		}
		c=ajoutDebut(c,y);
		for(k=0;k<n;k++)
		{
			if ( (!appartientaC(k,c)) && (d[k]>d[y]+M[y][k]))
			{
				d[k]=d[y]+M[y][k];
				pred[k]=y;
			}
		}
	}


	// Construction du chemin le plus court
	liste ch=NULL;
	k=arv;

	while(k!=dep)
	{
		ch=ajoutDebut(ch,k);
		k=pred[k];
	}
	ch=ajoutDebut(ch,dep);
	if(d[arv]==INF)
	{
		printf("Aucun chemin entre %d et %d\n",dep,arv);
	}
	else
	{
		printf("Le chemin le plus court entre %d et %d est :\n", dep, arv);
		afficheListe(ch);
		printf("La distance est de %d",d[arv]);
	}
}

int main(void)
{



    //allocation et création d'une matrice n x n
    int ** M = calloc(n, sizeof(int*));
    int i;
    int depart, arriv;
    for (i = 0; i < n; i++)
    {
        M[i] = calloc(n, sizeof(int));
    }

    genGraph(M);
    //affiche(M);

    int dep=0 ;
    int arv=9 ;

    Dijkstra(M, dep, arv);



	return EXIT_SUCCESS;
}

