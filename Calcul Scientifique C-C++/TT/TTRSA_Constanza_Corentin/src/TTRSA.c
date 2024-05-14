/*
 ============================================================================
 Name        : TTRSA.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int p = 597689;
long long int q = 4523;
long long int e = 17;
long long int n;
long long int phi;
long long int d;


long long int puissance(long long int x,long long int N)
{
	//Fait l'operation x^N.
	//Entrée : deux int, x et N.
	//Sortie le resultat (entier) de l'operation
	long long int pow;
	pow = 1;
	while (N!=1)
	{
		if (N % 2 == 1)
		{
			pow = x*pow;
		}
		x=x*x;
		N= N/2;
	}
	pow=x*pow;
	return pow;
}

long long int exp_rapide(long long int a,long long int b,long long int N)
{
	//Fait l'operation a^N modulo b.
	//Entrée : 3 int, a, b et N.
	//Sortie le resultat (entier) de l'operation a^N modulo b.

	//allocation et initialisation des variables locales
	long long int pow;
	pow = 1;

	//boucle tant que N different 1 afin de réaliser nos calcule
	while (N!=1)
	{
		if (N % 2 == 1)
		{
			pow = (a*pow)%b;
			a=(a*a)%b;
			N=(N-1)/2;
		}
		else
		{
			a=(a*a)%b;
			N= N/2;
		}
	}
	pow=(a*pow)%b;

	//variable renvoyer
	return pow;
}

long long int inverse_modulaire(long long int a,long long int b)
{
	//Réalise l'inverse modulaire a dans Z/bZ à l'aide de l'algo d'euclide étendu

	//allocation de l'espace nécessaire aux variables locales
	long long int r;
	long long int rp;
	long long int u;
	long long int up;
	long long int v;
	long long int vp;
	long long int rtmp;
	long long int utmp;
	long long int vtmp;
	long long int q;

	//initialisation des variables locales
	r=a;
	rp=b;
	u=1;
	up=0;
	v=0;
	vp=1;

	//Réalisation de l'algo de euclide étendu
	while(rp!=0)
	{

		q =r/rp;
		rtmp = r;
		utmp = u;
		vtmp = v;
		r = rp;
		v = vp;
		u = up;
		rp = rtmp - q*rp;
		up = utmp - q*up;
		vp = vtmp - q*vp;

	}

	//Test si a et b n'était pas premier entre eux(et renvoie 0 si oui)
	if (r!=1) return 0;


	//renvoie l'inverse modulaire
	return u;
}

long long int recherche_exhaustive(long long int N)
{
	//Entrée : entier N
	//Sortie : le premier diviseur premier entre 2 et racine de N.
	// pour cela on effecte un test en forcant le type de sqrt de N (un double) en entier
	//cela revient à faire la partie entiere de sqrt(N)
	long long int i;
	for (i = 2; i<=(int)sqrt(N);i++)
	{
		if (N%i==0)
		{
			return i;
		}
	}
	return 0;
}

int est_carre(long long int N)
{
	//Entré: un entier N
	//sortie : un boolen, 1 si N est un carré 0 sinon.
	if (sqrt(N)==(int)sqrt(N))
	{
		return 1;
	}
	else return 0;
}

long long int Fermat(long long int N)
{
	//Entrée : un entier N
	//Sortie : un diviseur premier de N


	//Allocation et Initialisation
	long long int a;
	long long int b2;
	long long int diviseur_p;
	long long int diviseur_q;
	long long int r_ex_p;
	long long int r_ex_q;
	a = floor(sqrt(N)+1);
	b2=puissance(a,2) - N;

	//boucle while qui va incrementé et testé tout les entier à partir de a²-N = b²
	while (est_carre(b2) == 0)
	{
		a++;
		b2=puissance(a,2) - N;
	}

	//On regarde si p=(a-b) est premier si oui à l'aide de recherche_exaustive qui nous renvoie 0 si c'est le cas.
	//Si p est permier on return p
	diviseur_p = a-sqrt(b2);
	r_ex_p=recherche_exhaustive(diviseur_p);
	if (r_ex_p==0)
	{
		return diviseur_p;

	}
	//Sinon on regarde si q = a+b est premier.
	//Si oui on renvoie q
	diviseur_q = a+sqrt(b2);
	if (recherche_exhaustive(diviseur_q)==0)
	{
		return diviseur_q;
	}
	//sinon on renvoie le premier diviseur entier entre 0 et racine de p
	else
	{
		return r_ex_p;
	}
}

long long int pgcd(long long int a, long long int b)
{
	//entré : a,b (avec a<b)
	//sortie : pgcd de a et b

	long long int tampon;
	while ((a%b !=0) && (b!=1))
	{
		tampon=b;
		b=a%b;
		a=tampon;
	}
	return b;
}

long long int calcul_M(long long int B,long long int N)
{
	//Entre : deux entier B et N
	//sortie : entier M = produit[pour tout les nbr premiers p < B] de p^(partie entière(inf) de logB en base p)
	int i;
	long long int M;
	M=1;
	for (i=1;i<B;i++)
	{
		if (recherche_exhaustive(i)==0)
		{
			M=M*exp_rapide(i,N,floor(log(B)/log(i)));
		}
	}
	return M;
}

long long int Pollard(long long int N, int B)
{
	//entrée : deux entier B et N
	//sortie : un diviseur premiers de N
	// B est la borne sup on devra la changé suivant le resultat de l'algo

	//init
	long long int a;
	long long int x;
	long long int b;
	long long int M;
	a=2;
	M=calcul_M(B,N);
	a=exp_rapide(a,N,M);
	//pgcd(a-1,N)
	x=pgcd(a-1,N);

	//test des bornes et donc de la reussite de l'algo
	if((x==1)||(x==N))
	{
		return 0;
	}
	return x;
}

//_________________________________Fonction de test__________________________________________________

void test_exp_rapide()
{
	//valeures attendues 0 1 211

	printf("%lld ",exp_rapide(6,2,2));
	printf("%lld ",exp_rapide(5,2,2));
	printf("%lld ",exp_rapide(25,318,4459));
}

void test_inversion_modulaire()
{
	//valeures attendues 4 0
	long long int x,y;
	x=inverse_modulaire(3,11);
	y=inverse_modulaire(6,12);
	printf("%lld",x);
	printf("\n");
	printf("%lld",y);
}

void test_recherche_exhaustive()
{
	//valeures attendues 2 2 2 3
	printf("%lld ",recherche_exhaustive(4));
	printf("%lld ",recherche_exhaustive(18));
	printf("%lld ",recherche_exhaustive(44));
	printf("%lld ",recherche_exhaustive(99));

}

void Test_est_carre()
{
	//valeures attendues 0 0 1 1 1 1 1
	printf("%lld ",est_carre(15));
	printf("%lld ",est_carre(178));
	printf("%lld ",est_carre(4));
	printf("%lld ",est_carre(25));
	printf("%lld ",est_carre(9));
	printf("%lld ",est_carre(36));
	printf("%lld ",est_carre(121));

}

void Test_Fermat(long long int n)
{
	//valeures attendues 11 4523
	long long int N=99;
	printf("%lld ", Fermat(N));
	printf("\n");
	printf("%lld ", Fermat(n));
}

void Test_calcul_M()
{

	printf("%lld",calcul_M(5,12));    			//valeur attendu : 0 car 12%12 = 0
	printf("%lld",calcul_M(20,232792560));		//val attendu : 0 trouvé en utilisant la fonction pow et en n'utilisant pas le modulo
}

void Test_Pollard()
{
	//valeur attendu 0 puis q
	printf("%lld ",Pollard(p*q,19));
	printf("%lld ",Pollard(p*q,20));

	// ne marche pas (boucle infinie) même probleme que pour calcul de M viens surment de la fcontion exp rapide
	// car lorsque l'on utilisait pow de math.h, calcul M fonctionnait et avait des résulatat cohérent. Exp_rapide semnble pourtant
	//juste au vue des different test. Probleme de compilation ? mauvaise gestion des variable local/global ?
	//mauvaise gestion des calcul de modulo ?
}


//------------fonction calcul M avec pow de math.h (et sans modulo)------

long long int calcul_M_pow(long long int B)
{
	int i;
	long long int M;
	M=1;

	for (i=1;i<B;i++)
	{
		if (recherche_exhaustive(i)==0)
		{
			M=M*pow(i,floor(log(B)/log(i)));
		}
	}
	return M;
}
void Test_calcul_M_pow()
{

	printf("%lld ",calcul_M_pow(5));
	printf("%lld ",calcul_M_pow(20));
}
//_________________________________Main______________________________________________________________

int main(void) {
	n=p*q;
	phi = (p-1)*(q-1);

	//test_exp_rapide();			//OK
	//test_inversion_modulaire(); 	//OK
	//test_recherche_exhaustive();	//OK
	//Test_est_carre();				//OK
	//Test_Fermat(n);				//OK

	//Test_calcul_M();				//pas ok
	//Test_Pollard();				//pas ok

	Test_calcul_M_pow();			// OK



	return EXIT_SUCCESS;
}
