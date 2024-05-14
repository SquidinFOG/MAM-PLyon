#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "file.h"

#define VRAI 1
#define FAUX 0

#define n 5 // nombre de sommets dans le graphe
#define densite 0.3 // densité du graphe généré

void genGraph(int M[n][n]) // graphe aléatoire non orienté, M est symétrique...
{
	int i,j;
    //srand(time(NULL));
    for ( i = 0; i < n-1; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            if(rand()/(RAND_MAX+1.0) < densite)
            {
                M[i][j]=1;
                M[j][i]=1;
            }
        }
    }
}

void genGraph2(int M[n][n], double d) // graphe aléatoire non orienté, M est symétrique...
{
	int i,j;
    //srand(time(NULL));
    for ( i = 0; i < n-1; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            if(rand()/(RAND_MAX+1.0) < d)
            {
                M[i][j]=1;
                M[j][i]=1;
            }
        }
    }
}


void afficher(int M[n][n])
{
	int i,j;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int estConnexe(int M[n][n])
{   
    /* rappel code du cours du BFS ...
    enqueue(v);   
    while (queue is not empty) {
        dequeue(v);
        if (v has not yet been visited)
            mark(v); 

        for (each w adjacent to v) 
            if (w has not yet been visited) 
                enqueue(w);    
    } 
    */
	int v,j;
    int mark[n] = {0};
    file F = NULL;

    //lancer un BFS à partir d'un sommet quelconque ... on fixe le départ à 0
    inserer(&F, 0); 
    while (F != NULL)
    {
    	v=retirer(&F);
    	if( mark[v]==FAUX )
    	{
    		mark[v]=VRAI;
    	}
    	for (j = 0; j < n; j++)
    	{
    		if ((M[v][j]==1)&&(!mark[j]))
    		{
    			inserer(&F,j);
    		}
    	}
    }

    //reste à vérifier si tous les sommets on été marqués
    for (j = 0; j < n; j++)
    {
        if(!mark[j])
            return FAUX; 
    } 

    return VRAI;
}

int main()
{
	/*
    int M[n][n] = {0}; // graphe vide de n sommets
    genGraph(M);
    afficher(M);

    if(estConnexe(M))
        printf("Graphe connexe !\n");
    else
        printf("Graphe non connexe !\n");

*/

    // modifier le main pour proposer une étude de la probabilité de la connexité 
    // d'un graphe aléatoire en fonction de 'n' et de 'densite'.

	//proba pour un d et un n fixé
	/*
	double proba;
	int i,cpt;
	cpt=0;
	srand(time(NULL));
	for(i=0;i<1000;i++){
	    int M[n][n] = {0}; // graphe vide de n sommets
	    genGraph(M);

	    if(estConnexe(M))
	    {
	        cpt++;
	        //printf("Graphe connexe !\n");
	    }
	    //else
	    //    printf("Graphe non connexe !\n");
	    printf("%d \n",cpt);

	}
	proba = (double) cpt/1000;
	printf("%lf",proba);
	*/



	//proba pour d qui varie

	double proba,d;
	int i,cpt;
	cpt=0;
	srand(time(NULL));
	for(d=0;d<=1;d=d+01)
	{
		for(i=0;i<1000;i++){
		    int M[n][n] = {0}; // graphe vide de n sommets
		    genGraph2(M,d);

		    if(estConnexe(M))
		    {
		        cpt++;
		        //printf("Graphe connexe !\n");
		    }
		    //else
		    //    printf("Graphe non connexe !\n");
		    //printf("%d \n",cpt);

		}
		proba = (double) cpt/1000;
		printf("%lf \n",proba)
}
