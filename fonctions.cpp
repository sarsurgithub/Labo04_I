/*
  ---------------------------------------------------------------------------
  Fichier     : fonctions.cpp
  Nom du labo : Librairie
  Auteur.e.s  : Sarah Jallon & Florian Conti
  Date        : 05.11.20 - 15.11.20
  But         : Le but de cette librairie est de mettre à disposition des fonctions qui permettent d'opérer sur
                des nombres, string et une fonction de question.
  Remarque(s) : La fonction random a été inspirée par internet, la source est citée. Il reste deux warning en
                rapport avec la fonction random, ces derniers ne sont pas dérangeant puisque cette fonction est
                assez précise pour notre utilisation.
  Compilateur : MinGW-W64 g++ 8.1.0
  ---------------------------------------------------------------------------
*/

#include "fonctions.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <ctime>

#define IGNORE_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define CLEAR_BUFFER cin.clear()

using namespace std;


bool estPair (int nombreUtilisateur) {
   return nombreUtilisateur % 2 == 0;
}

int sommeChiffres (int nombreUtilisateur) {
   int somme = 0;
   int chiffre;

   while (nombreUtilisateur > 0) {
      chiffre = nombreUtilisateur % 10;
      somme += chiffre;
      nombreUtilisateur /= 10;
   }
   return somme;
}

bool nbre1er (int nombreUtilisateur) {
   bool testNbrPremier = true;
   if (nombreUtilisateur <= 1) {
      return false;
   } else {
      for(int i = 2; pow(i,2) <= nombreUtilisateur; i++) {
         if(nombreUtilisateur % i == 0) {
            testNbrPremier = false;
            break;
         }
      }
      return testNbrPremier;
   }
}

bool nbreArmstrong (int nombreUtilisateur) {
   int somme = 0;
   int chiffre;
   int nombreUtilisateurInitial = nombreUtilisateur;

   while (nombreUtilisateur > 0) {
      chiffre = nombreUtilisateur % 10;
      somme += (int)pow(chiffre, 3);
      nombreUtilisateur /= 10;
   }
   return (somme == nombreUtilisateurInitial);
}

double random(int borne1, int borne2) {  // src https://stackoverflow.com/a/7560171
	static bool first = true;
	if (first) {
		srand( time(nullptr) ); //cette ligne est exécutée la première fois seulement
		first = false;
	}
	return borne1 + rand() % (( borne2 + 1 ) - borne1);
}

unsigned buffer(char& minuscule, char& majuscule, string& ligne) {


	for (char cara : ligne) {
		if (cara >= 65 and cara <= 90 ) {
			if ( majuscule == ' ' or majuscule < cara) {
				majuscule = cara;
			}
		} else if (cara >= 97 and cara <= 122) {
			if (minuscule == ' ' or minuscule > cara) {
				minuscule = cara;
			}
		}
	}
	return ligne.size();
}

void trigo(double degre, double& sinus, double& cosinus, double& tangente) {
	cosinus  = cos(degre * M_PI / 180.0);
	sinus    = sin(degre * M_PI / 180.0);
	tangente = tan(degre * M_PI / 180.0);
}

bool repondOui(const char& valeurNon, const char& valeurOui, const string& question) {
	char reponse;
	bool saisieIncorrecte;
	char valeurOuiMin;
	char valeurNonMin;

	do {
		cout << question << " [" << valeurOui << '/' << valeurNon << ']'<< endl;
		cin >> reponse;

		reponse      = (char)tolower(reponse);
		valeurOuiMin = (char)tolower(valeurOui);
		valeurNonMin = (char)tolower(valeurNon);

		saisieIncorrecte = !(reponse  == valeurOuiMin or reponse == valeurNonMin) or cin.fail();

		if (saisieIncorrecte) {
			cout << "/!\\ recommencer saisie" << endl;
			CLEAR_BUFFER;
		}
		IGNORE_BUFFER;
	} while (saisieIncorrecte);
	return reponse == valeurOuiMin;
}