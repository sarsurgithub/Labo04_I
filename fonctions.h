#ifndef LABO4_PROTOTYPE_FONCTIONS_H
#define LABO4_PROTOTYPE_FONCTIONS_H

#include <string>

//todo documenter les fonctions

//Cette fonction permet de définir si le nombre inscrit par l'utilisateur
//est pair, ou non, et retourne une valeur booleene
bool     estPair (int nombreUtilisateur);

//Cette fonction permet de calculer la somme des chiffres d'un nombre entré par l'utilisateur et retourne le résultat
int      sommeChiffres (int nombreUtilisateur);

//Cette fonction permet de définir si un nombre est premier et retourne le résultat en booleen
bool     nbre1er (int nombreUtilisateur);

//Cette fonction permet de définir si un nombre est un nombre de Armstrong ou pas et retourne un booleen
bool     nbreArmstrong (int nombreUtilisateur);

//Cette fonction permet de générer un nombre aléatoire compris entre 2 bornes et retourne ce nombre aléatoire
double   random(int borne1, int borne2);

//Cette fonction permet de définir la plus petite minuscule, la plus grande majuscule et le nombre de caractère
//d'une chaine de caractère entrée par l'utilisateur
unsigned buffer(char& minuscule, char& majuscule, std::string& ligne);

//Cette fonction permet de calculer les valeurs trigonométriques d'un angle entré par l'utilisateur
void     trigo(double degre, double& sinus, double& cosinus, double& tangente);

//Cette fonction permet de définir si l'utilisateur a inscrit "o" et retourne un booleen de ce résultat
bool     repondOui( char valeurNon, char valeurOui, std::string question);

#endif //LABO4_PROTOTYPE_FONCTIONS_H

