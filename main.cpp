/*
  ---------------------------------------------------------------------------
  Fichier     : main.cpp
  Nom du labo : Librairie
  Auteur.e.s : Sarah Jallon & Florian Conti
  Date        : 05.11.20 - 11.11.20
  But         : Le but de ce programme est de nous proposer 7 opérations sur des nombres.... //TODO

  Remarque(s) :

  Compilateur : MinGW-W64 g++ 8.1.0
  ---------------------------------------------------------------------------
*/

#include "fonctions.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

#define IGNORE_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define CLEAR_BUFFER cin.clear()

enum class Option {
	quitter, estPair, sommeChiffres, nombre1er, nombreArmstrong, nombreAleatoire, buffer, trigo
};

using namespace std;

int main() {

	// ----------------------------------------------------------------------------------------------
	//constantes du programme

	const int    ALIGNEMENT_NOMBRE = 5;
   const int    ALIGNEMENT_TEXTE  = 12;
   const string TIRET             = " - ";

	// ----------------------------------------------------------------------------------------------
	//affichage du choix des fonctions

   cout << "Options" << endl;
   cout << setw(ALIGNEMENT_NOMBRE) << (int)Option::estPair         << "    " << "est pair"             << endl;
   cout << setw(ALIGNEMENT_NOMBRE) << (int)Option::sommeChiffres   << "    " << "somme chiffres"       << endl;
   cout << setw(ALIGNEMENT_NOMBRE) << (int)Option::nombre1er       << "    " << "nombre 1er"           << endl;
   cout << setw(ALIGNEMENT_NOMBRE) << (int)Option::nombreArmstrong << "    " << "nombre de Armstrong"  << endl;
   cout << setw(ALIGNEMENT_NOMBRE) << (int)Option::nombreAleatoire << "    " << "nombre aleatoire"     << endl;
   cout << setw(ALIGNEMENT_NOMBRE) << (int)Option::buffer          << "    " << "buffer"               << endl;
   cout << setw(ALIGNEMENT_NOMBRE) << (int)Option::trigo           << "    " << "trigo"                << endl;
   cout << setw(ALIGNEMENT_NOMBRE) << (int)Option::quitter         << "    " << "quitter"              << endl;

	// ----------------------------------------------------------------------------------------------
	//entrée utilisateur et déclaration et/ou initialisation des variables nécessaires à celle-ci

   int choixUtilisateur, nombreUtilisateur;
   int intervalleMin, intervalleMax;
   int borneInfChoix, borneSupChoix;
   bool saisieIncorrecte;

   do {
   	borneInfChoix = 0;
   	borneSupChoix = 7;
		cout << "Votre choix [" << borneInfChoix << TIRET << borneSupChoix << "]:";
		cin  >> choixUtilisateur;
		IGNORE_BUFFER;

		saisieIncorrecte = choixUtilisateur < borneInfChoix or choixUtilisateur > borneSupChoix or cin.fail();

		if (saisieIncorrecte) {
			cout << "/!\\ recommencer saisie" << endl;
			CLEAR_BUFFER;
		}

   } while (saisieIncorrecte);

	// ----------------------------------------------------------------------------------------------
   // switch allant des options 0 à 7

	switch (Option(choixUtilisateur)) {

		// ----------------------------------------------------------------------------------------------
		// option 1 : savoir si un nombre est paire, dans un intervalle donné

      case Option::estPair:
         do {
         	int borneInfChoix = 0;
         	int borneSupCHoix = 1000;
            if (cin.fail()) {
               cin.clear();
               IGNORE_BUFFER;
            }
            cout << "Entrez une valeur [0 - 1000] :"; //todo pas de nombres magiques
            cin  >> nombreUtilisateur;
            IGNORE_BUFFER;
         } while (nombreUtilisateur < 0 or nombreUtilisateur > 1000 or cin.fail()); //todo pas de nombres magiques

         if (estPair(nombreUtilisateur)) {
            cout << nombreUtilisateur << " est une valeur paire";
         } else {
            cout << nombreUtilisateur << " est une valeur impaire";
         }
         break;

      case Option::sommeChiffres:
         do {
            if (cin.fail()) {
               cin.clear();
               IGNORE_BUFFER;
            }

            cout << "Entrez une valeur [0 - 1000] :";
            cin  >> nombreUtilisateur;
            IGNORE_BUFFER;

         } while (nombreUtilisateur < 0 or nombreUtilisateur > 1000 or cin.fail());

         cout << "\nla somme des chiffres de " << nombreUtilisateur << " = " << sommeChiffres(nombreUtilisateur);
         break;


      case Option::nombre1er:

         do { //todo décider si on veut faire un seul test de saisie ou deux
         	  //todo créer une variable saisie incorrecte et ignorer le buffer une seule fois et avoir un msg d'erreur
            if (cin.fail()) {
               cin.clear();
               IGNORE_BUFFER;
            }

            cout << "Determiner les nombres premiers compris dans un intervalle" << endl;

            cout << "   - debut  :" << setw(ALIGNEMENT_TEXTE) << "[ 0 - 1000] : ";
            cin  >> intervalleMin;
            IGNORE_BUFFER;

            cout << "   - fin    :" << setw(ALIGNEMENT_TEXTE) << "[20 - 1000] : ";
            cin  >> intervalleMax;
            IGNORE_BUFFER;

         } while (intervalleMin < 0 or intervalleMin > 1000 or intervalleMax < 20 or intervalleMax > 1000 or cin.fail());

         for (; intervalleMin <= intervalleMax; ++intervalleMin) {
            if(nbre1er(intervalleMin)) {
               cout << "\nle nombre " << intervalleMin << " est un nombre premier"; //todo ce retour à la ligne est pas très parlant ? à voir
            }
         }
         break;


      case Option::nombreArmstrong:

         do {
            if (cin.fail()) {
               cin.clear();
               IGNORE_BUFFER;
            }

            cout << "Determiner les nombres premiers compris dans un intervalle" << endl;

            cout << "   - debut  :" << setw(ALIGNEMENT_TEXTE) << "[ 0 - 1000] : ";
            cin  >> intervalleMin;
            IGNORE_BUFFER;

            cout << "   - fin    :" << setw(ALIGNEMENT_TEXTE) << "[20 - 1000] : ";
            cin  >> intervalleMax;
            IGNORE_BUFFER;

         } while (intervalleMin < 0 or intervalleMin > 1000 or intervalleMax < 20 or intervalleMax > 1000 or cin.fail());

         for (; intervalleMin <= intervalleMax; ++intervalleMin) {
            if(nbreArmstrong(intervalleMin)) {
               cout << "\nle nombre " << intervalleMin << " est un nombre de Armstrong";
            }
         }

         break;

      case Option::nombreAleatoire  : cout << "test"; break;
      case Option::buffer           : cout << "test"; break;
      case Option::trigo            : cout << "test"; break;
      case Option::quitter          : cout << "test"; break;
   }

	char min = ' ';
	char maj = ' ';
	string ligne;
	buffer(min, maj, ligne);
	cout << random(8, 43) << endl;

	return EXIT_SUCCESS;
}
