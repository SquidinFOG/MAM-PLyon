/*
 ============================================================================
 Name        : TT_SUDOKU.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int grille1[9][9] = {
    {7,8,0,4,0,0,1,2,0},
    {6,0,0,0,7,5,0,0,9},
    {0,0,0,6,0,1,0,7,8},
    {0,0,7,0,4,0,2,6,0},
    {0,0,1,0,5,0,9,3,0},
    {9,0,4,0,6,0,0,0,5},
    {0,7,0,3,0,0,0,1,2},
    {1,2,0,0,0,7,4,0,0},
    {0,4,9,2,0,6,0,0,7}
	};

int grille2[9][9] = {
 {0, 0, 0, 7, 0, 0, 0, 0, 0},
 {1, 0, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 4, 3, 0, 2, 0, 0},
 {0, 0, 0, 0, 0, 0, 0, 0, 6},
 {0, 0, 0, 5, 0, 9, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 4, 1, 8},
 {0, 0, 0, 0, 8, 1, 0, 0, 0},
 {0, 0, 2, 0, 0, 0, 0, 5, 0},
 {0, 4, 0, 0, 0, 0, 3, 0, 0}
};

int grille3[9][9] = {
 {1, 0, 0, 0, 0, 7, 0, 9, 0},
 {0, 3, 0, 0, 2, 0, 0, 0, 8},
 {0, 0, 9, 6, 0, 0, 5, 0, 0},
 {0, 0, 5, 3, 0, 0, 9, 0, 0},
 {0, 1, 0, 0, 8, 0, 0, 0, 2},
 {6, 0, 0, 0, 0, 4, 0, 0, 0},
 {3, 0, 0, 0, 0, 0, 0, 1, 0},
 {0, 4, 0, 0, 0, 0, 0, 0, 7},
 {0, 0, 7, 0, 0, 0, 3, 0, 0}
};

void affiche(int grille[9][9]){
    //fonction affiche une grille de sudoku
    int i,j;
    for(i=0;i<9;i++){
        printf("|");
        for(j=0;j<9;j++){
            printf("%d",grille[i][j]);
            if (j%3==2)printf("|");
        }
        printf("\n");
        if(i%3==2)printf(" --- --- ---\n");
    }
}

bool absent_Ligne(int k, int grille[9][9], int i)
{
	//fonction qui test si un entier k est absent sur l'ensemble de la ligne i.
	//Renvoie 1 si si k est absent 0 sinon
	int j;
    for (j=0; j < 9; j++)
    {
        if (grille[i][j] == k)
        	return false;
    }
    return true;
}

bool absent_Colonne(int k, int grille[9][9],int j)
{
	//fonction qui test si un entier k est absent sur l'ensemble de la colonne j.
	//Renvoie 1 si si k est absent 0 sinon
	int i;
	for (i=0; i < 9; i++)
	{
		if (grille[i][j]==k)
			return false;
	}
	return true;
}

bool absent_Bloc(int k, int grille[9][9], int i, int j)
{
	//fonction qui test si un entier k est absent sur l'ensemble dans le bloc de taille 3*3 de
	//la case [i,j].
	//Renvoie 1 si si k est absent 0 sinon
	int _i=3*(i/3); // _i=i-(i%3)
	int _j=3*(j/3); // _j=j-(i%3)
	int l;
	int m;
	for (l=_i; l < _i+3; l++)
	{
		for (m=_j; m < _j+3; m++ )
		{
			if (grille[l][m] == k)
				return false;
		}
	}
	return true;
}

/*
bool Unique_colonne(int grille[9][9],int i, int j, int nbr_test)
{
	int _i;

	for (_i=0;_i<9;_i++)
	{
		if ((_i!=i)&&(grille[_i][j]==0))
		{
			if ((absent_Ligne( nbr_test,  grille, _i))&&(absent_Colonne(nbr_test,  grille, j))&&(absent_Bloc(nbr_test,  grille,_i, j)))
			{
				return true;
			}
		}
	}
	return false;
}

bool Unique_ligne(int grille[9][9],int i, int j, int nbr_test)
{
	int _j;

	for (_j=0;_j<9;_j++)
	{
		if ((_j!=j)&&(grille[i][_j]==0))
		{
			if ( (absent_Ligne( nbr_test,  grille, i)) && (absent_Colonne(nbr_test,  grille, _j)) && (absent_Bloc(nbr_test,  grille,i, _j)) )
			{
				return false;
			}
		}
	}
	return true;
}

bool Unique_bloc(int grille[9][9],int i, int j, int nbr_test)
{
	int _i=3*(i/3); // _i=i-(i%3)
	int _j=3*(j/3); // _j=j-(i%3)
	int l;
	int m;
	for (l=_i; l < _i+3; l++)
	{
		for (m=_j; m < _j+3; m++ )
		{
			if ((m!=i)&&(l!=j)&&(grille[l][m]==0))
			{
				if ( (absent_Ligne(nbr_test, grille, l)) && (absent_Colonne(nbr_test,  grille, m))&&(absent_Bloc(nbr_test,  grille,l, m)) )
				{
					return true;
				}
			}
		}
	}
	return false;
}*/

int recherche_position_ligne(int nbr_test, int grille[9][9],int i )
{
	//fonction qui recherche si dans une ligne donné il existe une unique position pour l'entier nbr_test
	//renvoie l'indice de la colonne si cette unique position existe, -1 si elle n'existe pas ou n'est pas unique.
	int j,cpt,possib;
	cpt=0;
	for(j=0;j<9;j++)
	{
		if (grille[i][j]==0)
		{
			if( (absent_Ligne(nbr_test,grille,i))&&(absent_Colonne(nbr_test,grille,j))&&(absent_Bloc(nbr_test,grille,i,j)) )
			{
				cpt++;
				possib=j;
			}
		}
	}

	if (cpt==1)
	{
		return possib;
	}
	return -1;
}

int recherche_position_colonne(int nbr_test, int grille[9][9],int j )
{
	//fonction qui recherche si dans une colonne donné il existe une unique position pour l'entier nbr_test
	//renvoie l'indice de la ligne si cette unique position existe, -1 si elle n'existe pas ou n'est pas unique.
	int i,cpt,possib;
	cpt=0;
	for(i=0;i<9;i++)
	{
		if (grille[i][j]==0)
		{
			if( (absent_Ligne(nbr_test,grille,i))&&(absent_Colonne(nbr_test,grille,j))&&(absent_Bloc(nbr_test,grille,i,j)) )
			{
				cpt++;
				possib=i;
			}
		}
	}


	if (cpt==1)
	{
		return possib;
	}
	return -1;
}

int recherche_position_bloc(int nbr_test, int grille[9][9],int i, int j)
{
	//fonction qui recherche si dans le bloc associer à la position [i][j]
	//donné il existe une unique position pour l'entier nbr_test
	//renvoie l'indice de la case si cette unique position existe, -1 si elle n'existe pas ou n'est pas unique.
	int cpt,possib;
	int _i=3*(i/3); // _i=i-(i%3)
	int _j=3*(j/3); // _j=j-(i%3)
	int l;
	int m;
	cpt=0;

	for (l=_i; l < _i+3; l++)
	{
		for (m=_j; m < _j+3; m++ )
		{
			if (grille[l][m] == 0)
			{
				if( (absent_Ligne(nbr_test,grille,l))&&(absent_Colonne(nbr_test,grille,m))&&(absent_Bloc(nbr_test,grille,l,m)) )
				{
					cpt++;
					possib=l*9 +m;
					//if (cpt==1){
					//printf("!%d %d %d \n",nbr_test,(l), (m) );}
				}
			}
		}
	}

	if (cpt==1)
	{
		return possib;
	}
	return -1;
}


int nbr_possible(int grille[9][9], int i, int j)
{
	//fonction qui recherche si un unique nombre est possible pour une case donnée.
	//Renvoie ce nombre si il existe, 0 sinon.
	int k;
	int cpt=0;
	int nbr=0;
	for (k=1; k <= 9; k++)
	{
		if ( absent_Ligne(k,grille,i) && absent_Colonne(k,grille,j) && absent_Bloc(k,grille,i,j) )
			{
			cpt++;
			nbr=k;
			}
	}
	if (cpt==1)
		{
		return nbr;
		}
	return 0;
}

void Unique_chiffre(int grille[9][9])
{
	//fonction qui applique la méthode de l'unique chiffre possible à chaque
	//case de notre grille une par une.

    int i,j,nbr;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
        	if (grille[i][j]==0)
        	{

        		nbr=nbr_possible(grille,i,j);
        		if (nbr!=0)
        		{
        			(grille[i][j]=nbr);
        		}
        	}
        }
    }

}

/*
void Unique_position(int grille[9][9])
{
    int i,j,k,c;
	for (k=1;k<=9;k++)
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				if (grille[i][j]==0)
				{
					if( (Unique_ligne(grille,i,j,k)) && (Unique_colonne(grille,i,j,k)) && (Unique_bloc(grille,i,j,k)) )
					{
						grille[i][j]=k;
					}
				}
			}
		}
	}
}*/
void Unique_position(int grille[9][9])
{
	//fonction qui applique la méthode de l'unique position possible à chaque
	//case de notre grille une par une.

    int i,j,k,position;
    for (k=1;k<=9;k++)
    {
    	for (i=0;i<9;i++)
    	{
    		position=recherche_position_ligne(k,grille,i);
    		if (position!=-1)
    		{
    			grille[i][(position)]=k;
    		}
    		position=recherche_position_colonne(k,grille,i);
    		if (position!=-1)
    		{

    		   	grille[position][(i)]=k;
    		}

    		for (j=0;j<9;j++)
    		{
    			position=recherche_position_bloc(k,grille,i,j);
    			if (position !=-1)
    			{

    				grille[((position)/9)][(position%9)]=k;

    			}
    		}
    	}


    }
}

int cpt_0(int grille[9][9])
{
	//fonction qui compte le nombre de 0 dans notre grille, autrement dit le nombre
	//de chiffre qu'il nous reste à trouver.
	//Renvoie ce nombre.
	int cpt,i,j;
	cpt=0;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
        	if (grille[i][j]==0)
        	{
        		cpt++;
        	}
        }
    }
    return cpt;
}


void Solveur(int grille[9][9])
{
	//fonction Solveur alternant la méthode tant qu'il reste des 0 dans notre grille

	int i,nb_0;
	nb_0 = cpt_0(grille);
	while (nb_0!=0)
	{
		Unique_chiffre(grille);
		Unique_position(grille);
		nb_0 = cpt_0(grille);

	}
	affiche(grille);


}


//-----------------------Tests des fonctions--------------------------

void test_abs_ligne()
{
	printf("%d", absent_Ligne(1,grille1,0) );
	printf("%d", absent_Ligne(2,grille1,0) );
	printf("%d", absent_Ligne(3,grille1,0) );
	printf("%d", absent_Ligne(4,grille1,0) );
	printf("%d", absent_Ligne(5,grille1,0) );
	printf("%d", absent_Ligne(6,grille1,0) );
	printf("%d", absent_Ligne(7,grille1,0) );
	printf("%d", absent_Ligne(8,grille1,0) );
	printf("%d", absent_Ligne(9,grille1,0) );
}

void test_abs_col()
{
	printf("%d", absent_Colonne(1,grille1,0) );
	printf("%d", absent_Colonne(2,grille1,0) );
	printf("%d", absent_Colonne(3,grille1,0) );
	printf("%d", absent_Colonne(4,grille1,0) );
	printf("%d", absent_Colonne(5,grille1,0) );
	printf("%d", absent_Colonne(6,grille1,0) );
	printf("%d", absent_Colonne(7,grille1,0) );
	printf("%d", absent_Colonne(8,grille1,0) );
	printf("%d", absent_Colonne(9,grille1,0) );
}

void test_abs_bloc()
{
	printf("%d", absent_Bloc(1,grille1,1,3) );
	printf("%d", absent_Bloc(2,grille1,1,3) );
	printf("%d", absent_Bloc(3,grille1,1,3) );
	printf("%d", absent_Bloc(4,grille1,1,3) );
	printf("%d", absent_Bloc(5,grille1,1,3) );
	printf("%d", absent_Bloc(6,grille1,1,3) );
	printf("%d", absent_Bloc(7,grille1,1,3) );
	printf("%d", absent_Bloc(8,grille1,1,3) );
	printf("%d", absent_Bloc(9,grille1,1,3) );
}

void Test_Unique_chiffre()
{
	int nb_0;
	nb_0=cpt_0(grille1);
	printf("iteration 1 : \n");
	Unique_chiffre(grille1);
	affiche(grille1);
	printf("\n");

	printf("iteration 2 : \n");
	Unique_chiffre(grille1);
	affiche(grille1);

	printf("iteration 3 : \n");
	Unique_chiffre(grille1);
	affiche(grille1);

	printf("iteration 4 : \n");
	Unique_chiffre(grille1);
	affiche(grille1);
}

void Test_Unique_position()
{
	int nb_0;
	nb_0=cpt_0(grille1);
	Unique_position(grille1);
	Unique_position(grille1);
	Unique_position(grille1);
	affiche(grille1);
}

int main()
{
	int i,k;
	//test_abs_ligne();					//OK
	//test_abs_col();					//OK
	//test_abs_bloc();					//OK
	//Test_Mthd_Unique_chiffre();		//OK
	//Test_Unique_position();			//OK
	printf("resolution de la grille 1 : \n");
	Solveur(grille1);					// OK
	printf("resolution de la grille 2 : \n");
	Solveur(grille2);					//OK


    return 0;
}
