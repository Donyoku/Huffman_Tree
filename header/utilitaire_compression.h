#ifndef UTIL_C
#define UTIL_C
#include <stdlib.h>
#include <stdio.h>
#include "huffman.h"

void parcours_arbre(canonical_tree* tree, char* tableau, int profondeur);
char* tree_to_length_table(canonical_tree* tree);
int lire_symbole(FILE* f);
void afficher_arbre(noeud* tete, int niveau);

void tricroissant(int** tab, int tab_size);
noeud** tableau_noeud(int** tabCara, int nbCara);
void tricroissantNoeud(noeud** tab, int tab_size);

int traitement_caractere(int* cmp, int lg, char* octet, char* buffer,
                         FILE* dst);

/**
 * encoder_symbole : renvoit le code d'un symbole (char ascii) dans un arbre
 *quelconque On renvoit un octet (char). Le code du symbole est placé dans les
 *bits de poids faible. Le pointeur sur entier lg contient la longueur (en
 *nombre de bit) du symbole codé. Attention : Le resultat peut donc etre plus
 *court qu'un octet. Convention : le poid d'un fils_gauche est mis à 0 et celui
 *d'un fils_droit à 1.
 **/
char* encoder_symbole(huffman_tree* tree, char symbole, int* lg);

/**
* Parcours d'un arbre en recherchant un symbole (char ascii)
* fonction recursive
renvoit NULL si le symbole n'est pas trouvé
* renvoit le noeud correspondant au symbole
**/
int profondeur(tree* tree, char symbole,int p);
noeud* recherche_symbole_arbre(tree* tree, char symbole);

/* Ergi */

int nb_feuilles(huffman_tree* tree);

int tree_depth(huffman_tree* a);

void construction_par_niveau(huffman_tree* tree, int level, int longueur,
                             int* p_indice, tableau_constructif* tab);

void tri_tableau(tableau_constructif* tab, int nbf);
/* Fin Ergi */

#endif