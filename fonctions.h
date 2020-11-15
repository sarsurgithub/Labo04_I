/*
  ---------------------------------------------------------------------------
  Fichier     : fonctions.h
  Nom du labo : Librairie
  Auteur.e.s  : Sarah Jallon & Florian Conti
  Date        : 05.11.20 - 15.11.20
  But         : Header de la librairie fonction.cpp
  Remarque(s) : Le fonctionnement des fonctions est expliquée dans ce fichier.
  Compilateur : MinGW-W64 g++ 8.1.0
  ---------------------------------------------------------------------------
*/

#ifndef LABO4_PROTOTYPE_FONCTIONS_H
#define LABO4_PROTOTYPE_FONCTIONS_H

#include <string>

/**
 * @param nbrUtilisateur : saisie utilisateur
 * @return booléen true si nombre paire, false si nombre impaire
 */
bool estPair (int nombreUtilisateur);

/**
 * @param nbrUtilisateur : saisie utilisateur
 * @return somme des chiffres de nbrUtilisateur
 */
int sommeChiffres (int nombreUtilisateur);

/**
 * @param nbrUtilisateur : saisie utilisateur
 * @return booléen, true si nombre premier, false sinon
 */
bool nbre1er (int nombreUtilisateur);

/**
 * @param nbrUtilisateur : saisie utilisateur
 * @return booléen true si nombre de Armstrong, false si nombre impaire
 */
bool nbreArmstrong (int nombreUtilisateur);

/**
 * @param borne1 : borne inférieure de l'intervalle
 * @param borne2 : borne supérieure de l'intervalle
 * @return nombre double aléatoire contenu dans l'intervalle définie
 */
double random(int borne1, int borne2);

/**
 * @param minuscule : char passé par référence, retourne la plus petite minuscule
 * @param majuscule : char passé par référence, retourne la plus grande majuscule
 * @param ligne     : string étant la ligne à analyser
 * @return          : un unsigned int contenant le nombre de caractères de ligne
 */
unsigned buffer(char& minuscule, char& majuscule, std::string& ligne);

/**
 * @param degre    : saisie utilisateur
 * @param sinus    : retourne le sinus de l'angle saisi, par référence
 * @param cosinus  : retourne le cosinus de l'angle saisi, par référence
 * @param tangeante: retourne la tangeante de l'angle saisi, par référence
 */
void trigo(double degre, double& sinus, double& cosinus, double& tangente);

/**
 * @param valeurNon : réponse négative à la question
 * @param valeurOui : réponse positive à la question
 * @param question  : question qui sera posée
 * @return          :un booléen true si réponse positive, false si réponse négative
 */
bool repondOui(const char& valeurNon,const char& valeurOui, const std::string& question);

#endif //LABO4_PROTOTYPE_FONCTIONS_H

