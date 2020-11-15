/*
  ---------------------------------------------------------------------------
  Fichier     : fonctions.h
  Nom du labo : Librairie
  Auteur.e.s  : Sarah Jallon & Florian Conti
  Date        : 05.11.20 - 15.11.20
  But         : Header de la librairie fonction.cpp
  Remarque(s) : Le fonctionnement des fonctions est expliqué dans ce fichier.

  Compilateur : MinGW-W64 g++ 8.1.0
  ---------------------------------------------------------------------------
*/

#ifndef LABO4_PROTOTYPE_FONCTIONS_H
#define LABO4_PROTOTYPE_FONCTIONS_H

#include <string>

//Cette fonction permet de définir si le nombre inscrit par l'utilisateur
//est pair, ou non, et retourne un booléen.
bool     estPair (int nombreUtilisateur);

//Cette fonction permet de calculer la somme des chiffres d'un nombre entré par l'utilisateur et retourne le résultat
int      sommeChiffres (int nombreUtilisateur);

//Cette fonction permet de définir si un nombre est premier et retourne un booléen
bool     nbre1er (int nombreUtilisateur);

//Cette fonction permet de définir si un nombre est un nombre de Armstrong ou pas et retourne un booléen
bool     nbreArmstrong (int nombreUtilisateur);

//Cette fonction permet de générer un nombre aléatoire compris entre 2 bornes données en paramètres
// et retourne ce nombre aléatoire
double   random(int borne1, int borne2);

//Cette fonction permet de définir la plus petite minuscule, la plus grande majuscule et le nombre de caractère
// d'une chaine de caractère entrée par l'utilisateur (passés en paramètres par référence)
unsigned buffer(char& minuscule, char& majuscule, std::string& ligne);

//Cette fonction permet de calculer les valeurs trigonométriques d'un angle entré par l'utilisateur. Les paramètres
//tangeant, sinus et cosinus sont passé par référence.
void     trigo(double degre, double& sinus, double& cosinus, double& tangente);

//Cette fonction permet de définir si l'utilisateur a répondu oui à une question et retourne un booleen.
bool     repondOui( char valeurNon, char valeurOui, std::string question);

#endif //LABO4_PROTOTYPE_FONCTIONS_H

