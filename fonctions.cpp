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
      somme = somme + chiffre;
      nombreUtilisateur = nombreUtilisateur / 10;
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
      somme = somme + pow(chiffre, 3);
      nombreUtilisateur = nombreUtilisateur / 10;
   }
   return (somme == nombreUtilisateurInitial);
}

double random(int borne1, int borne2) {

}

void buffer(char& minuscule, char& majuscule, int& nbrCara) {

}

void trigo(double degre, double& sinus, double& cosinus, double& tangente) {
	cosinus  = cos(degre * M_PI / 180.0);
	sinus    = sin (degre * M_PI / 180.0);
	tangente = tan(degre * M_PI / 180.0);
}

bool repondOui(char valeurNon, char valeurOui, string question) {
	char reponse;
	bool saisieIncorrecte;
	char valeurOuiMin;
	char valeurNonMin;

	do {
		cout << question << " [" << valeurOui << '/' << valeurNon << ']'<< endl;
		cin >> reponse;
		reponse   = (char)tolower(reponse);
		valeurOuiMin = (char)tolower(valeurOui);
		valeurNonMin = (char)tolower(valeurNon);

		saisieIncorrecte = !(reponse  == valeurOuiMin || reponse == valeurNonMin) || cin.fail();

		if (saisieIncorrecte) {
			cout << "/!\\ recommencer saisie" << endl;
			CLEAR_BUFFER;
			IGNORE_BUFFER;
		}
	} while (saisieIncorrecte);
	if (reponse == valeurOuiMin) {
		return true;
	} else {
		return false;
	}
}