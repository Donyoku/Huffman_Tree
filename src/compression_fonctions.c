#include "huffman.h"
#include <stdlib.h>
//COMPRESSION//
//1C prétraitement optionel des données : MTF
/**
 * A faire une fois la suite réalisée
 **/


//2C prétraitement optionel des données : RLE
/**
 * A faire une fois la suite réalisée
 **/



//3C analyse statique : calcul + tri des fréquences de symboles
/**
 * prend un nom de fichier en paramètre, l'ouvre en lecture.
 *  alloue (malloc) un tableau "frequences" de taille 256 -- si et seulement si on considere que tous les char ascii sont utilisés.
 * Sinon  on fait un tableau a deux dimensions avec le caractere ascii, suivit de sa frequence --
 * incrémente frequences[caractère_lu] a chaque caractere lu.
 * ferme le fichier précedement ouvert.
 * retourne le tableau frequence.
 */
int* frequencies_of_occurences(char* file_name, int symbole_number);





//4C détermination des longueurs des codes des symboles
//  -- Il faut préalablement crere la structure de donnée huffman_tree
/**
 * Prend en entrée un tableau de frequences, tableaux donnée par la fonction frequencies_of_occurences
 * construit et store dans une structure de donnée (malloc) l'arbre résultat
 **/
huffman_tree* build_huffman_tree(int* frequencies){
  int nbCara = 0;

  for(int i=0; i < NBSYMBOLE ; i++){
    if(frequencies[i] != 0){
      nbCara ++;
    }
  }

  int** tabCara = malloc(nbCara * sizeof(int*));
  int y=0;
  for(int i=0; i < NBSYMBOLE ; i++){
    if(frequencies[i] != 0){
      tabCara[y][0] = i;
      tabCara[y][1] = frequencies[i];
      y++;
    }
  }


}






//5C génération de arbre/codes canoniques des symboles
//  -- Il faut préalablement creer la structure de donnée canonical_tree
/**
 * Prend un arbre de Huffman en entrée (donné par la fonction build_huffman_tree)
 * Construit l'arbre canonique correspondant.
 * Alloue (malloc) et store dans une structure canonical_tree l'abre canonique créé
 * retourne cet arbre canonique
 **/
canonical_tree* normal_tree_to_canonical_tree(huffman* tree);






//6C écriture de table des longueurs (après compression RLEoptionnelle)
// -- Il faut préalablement choisir le format d'écriture des longueur
/**
 * Ecrit dans le fichier dst_file_name la table des longueurs
 * de l'arbre canonique donné en paramètre (donné par la fonction normal_tree_to_canonical_tree)
 * Le fichier est ouvert en ecriture avec effacement préalable du contenu
 * Le fichier doit etre ouvert et fermé dans la fonction
 * le format d'écriture doit etre reflechi (potentiellement avec le groupe)
 **/
void write_compressed_huffman_code(char* dst_file_name,canonical_tree* tree);




//7C transcodage + écriture, symbole par symbole.
// -- Il faut absolument encapsuler le code pour qu'il n'y ai pas de traitement bas niveau
// ex: - lire_symbole qui va lrie un caractere ascii dans le fichier source
//	   - encoder_symbole qui va chercher la correspondance dans l'arbe canonique d'un symbole ( le resultat peut etre plus court qu'un octet)
//	   - ecrire_octet qui ecrit un octet de donnée
// Il faut donc faire  attention a ne pas ecrire les symbole un par un, puisqu'il peut y avoir deux symbole dans un octet
// Il n'y pas de moyen en C d'ecrire bit par bit
/**
 * Ecrit dans le fichier dst_file_name les caractère lu dans le fichier src_file_name
 * Les caractère lus sont encodé selon le code donné par l'arbre canonique "tree"
 * Tout les caractère lu et encodé sont directement écrit dans le fichier de destination sans caractère de séparation
 * Le fichier de destination est ouvert en "écriture a la suite"
 * le fichier source est ouvert en lecture seule.
 * Tout les fichiers sont fermé a la fin de la fonction.
 **/
void write_compressed_file(char* src_file_name, char* dst_file_name, canonical_tree* tree);