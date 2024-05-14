#ifndef _FILE_H_
    #define _FILE_H_

typedef struct tmp {
   int val;
   struct tmp *suivant;
} noeud;

typedef noeud* file;

void inserer(file *tete, int val);
int retirer(file *tete);
void afficher_file(file tete);
#endif

