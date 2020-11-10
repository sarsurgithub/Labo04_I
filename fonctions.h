//
// Created by Florian on 05.11.2020.
//

#ifndef LABO4_PROTOTYPE_FONCTIONS_H
#define LABO4_PROTOTYPE_FONCTIONS_H

#include <string>

bool     estPair (int nombreUtilisateur);
int      sommeChiffres (int nombreUtilisateur);
bool     nbre1er (int nombreUtilisateur);
bool     nbreArmstrong (int nombreUtilisateur);
double   random(int borne1, int borne2);
unsigned buffer(char& minuscule, char& majuscule, std::string ligne);
void     trigo(double degre, double& sinus, double& cosinus, double& tangente);
bool     repondOui( char valeurNon, char valeurOui, std::string question);

#endif //LABO4_PROTOTYPE_FONCTIONS_H

