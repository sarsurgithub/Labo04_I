/*
  ---------------------------------------------------------------------------
  Fichier     : main.cpp
  Nom du labo : Librairie
  Auteur.e.s  : Sarah Jallon & Florian Conti
  Date        : 05.11.20 - 15.11.20
  But         : Le but de ce programme est de permettre à l'utilisateur de réaliser différentes opérations sur des
                nombres qu'il choisi. Ces options sont définies dans l'enum class "Options". L'utilisateur peut
                recommencer autant de fois qu'il le souhaite ou choisir de quitter le programme. Le programme
                utilise les fonctions mises à disposition par la librairie "fonctions.cpp".
  Remarque(s) : Toutes les saisies utilisateur sont vérifiées. L'enum class est placé en dehors du main au cas où nous
  					 aimerions l'utiliser ailleurs. Certaines constantes sont déclarées dans les différentes branches du
  					 switch pour les mettre au plus proche de leur utilisation.
  Compilateur : MinGW-W64 g++ 8.1.0
  ---------------------------------------------------------------------------
*/

#include "fonctions.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

#define IGNORE_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define CLEAR_BUFFER cin.clear()

using namespace std;

double saisie (const string& question, int borneInf, int borneSup);

//Liste des différentes options du programme
enum class Option {
	quitter, estPair, sommeChiffres, nombre1er, nombreArmstrong, nombreAleatoire, buffer, trigo
};

int main() {

	// ----------------------------------------------------------------------------------------------
	//constantes du programme
	const int    ALIGN_NOMBRE    = 5;
   const int    BORNE_INF_MENU  = 0,
   	          BORNE_SUP_MENU  = 7;

   bool quitter = false;

	do {
		// ----------------------------------------------------------------------------------------------
		//affichage du choix des fonctions

		cout << "\nOptions" << endl;
		cout << setw(ALIGN_NOMBRE) << (int) Option::estPair         << "    " << "est pair"            << endl;
		cout << setw(ALIGN_NOMBRE) << (int) Option::sommeChiffres   << "    " << "somme chiffres"      << endl;
		cout << setw(ALIGN_NOMBRE) << (int) Option::nombre1er       << "    " << "nombre 1er"          << endl;
		cout << setw(ALIGN_NOMBRE) << (int) Option::nombreArmstrong << "    " << "nombre de Armstrong" << endl;
		cout << setw(ALIGN_NOMBRE) << (int) Option::nombreAleatoire << "    " << "nombre aleatoire"    << endl;
		cout << setw(ALIGN_NOMBRE) << (int) Option::buffer          << "    " << "buffer"              << endl;
		cout << setw(ALIGN_NOMBRE) << (int) Option::trigo           << "    " << "trigo"               << endl;
		cout << setw(ALIGN_NOMBRE) << (int) Option::quitter         << "    " << "quitter"             << endl;

		// ----------------------------------------------------------------------------------------------
		//entrée utilisateur et déclaration et/ou initialisation des variables nécessaires à celle-ci

		int choixOptionUtilisateur = int(saisie("Votre choix ",BORNE_INF_MENU, BORNE_SUP_MENU));

		// ----------------------------------------------------------------------------------------------
		// switch des options 0 à 7

		switch (Option(choixOptionUtilisateur)) {

			// ----------------------------------------------------------------------------------------------
			// option 1 : savoir si un nombre est paire, dans un intervalle donné
			case Option::estPair: {

            const int EST_PAIR_MIN = 0,
                      EST_PAIR_MAX = 1000;
            int saisieUtilisateur = int(saisie("Entrez une valeur ", EST_PAIR_MIN, EST_PAIR_MAX));

            if (estPair(saisieUtilisateur)) {
               cout << saisieUtilisateur << " est une valeur paire";
            } else {
               cout << saisieUtilisateur << " est une valeur impaire";
            }
			} break;

			// ----------------------------------------------------------------------------------------------
         // option 2 : Connaitre la somme de chiffres
			case Option::sommeChiffres: {

			   const int SOMME_CHIFFRE_MIN = 0,
                      SOMME_CHIFFRE_MAX = 1000;

			   int saisieUtilisateur = int(saisie("Entrez une valeur ", SOMME_CHIFFRE_MIN, SOMME_CHIFFRE_MAX));

            cout << "La somme des chiffres de " << saisieUtilisateur << " = " << sommeChiffres(saisieUtilisateur);
			} break;

         // ----------------------------------------------------------------------------------------------
         // option 3 : Connaitre les nombres premiers dans un intervalle
			case Option::nombre1er: {

			   const int NOMBRE1ER_MIN = 0,
			             NOMBRE1ER_MAX = 1000;

				cout << "Determiner les nombres premiers compris dans un intervalle" << endl;
				int intervalleMin = int(saisie("   - debut  ", NOMBRE1ER_MIN, NOMBRE1ER_MAX));
				int intervalleMax = int(saisie("   - fin    ", intervalleMin, NOMBRE1ER_MAX));

            for (; intervalleMin <= intervalleMax; ++intervalleMin) {
               if (nbre1er(intervalleMin)) {
                  cout << "Le nombre " << intervalleMin << " est un nombre premier." << endl;
               }
            }
            cout << "Il n'y a plus/pas de nombre premier dans cet intervalle." << endl;
			} break;

         // ----------------------------------------------------------------------------------------------
         // option 4 : Trouver les nombres de Armstrong dans un intervalle donné
			case Option::nombreArmstrong: {

            const int ARMSTRONG_MIN = 0,
                      ARMSTRONG_MAX = 1000;

				cout << "Determiner les nombres Armstrong compris dans un intervalle" << endl;
				int intervalleMin = int(saisie("   - debut  ", ARMSTRONG_MIN, ARMSTRONG_MAX));
				int intervalleMax = int(saisie("   - fin    ", intervalleMin, ARMSTRONG_MAX));

            for (; intervalleMin <= intervalleMax; ++intervalleMin) {
               if (nbreArmstrong(intervalleMin)) {
                  cout << "Le nombre " << intervalleMin << " est un nombre de Armstrong." << endl;
               }
            }
            cout << "Il n'y a pas/plus de nombre d'Amstrong dans l'intervalle." << endl;
			} break;

         // ----------------------------------------------------------------------------------------------
         // option 5 : Génère 1 ou plusieurs nombres aléatoires dans un intervalle
			case Option::nombreAleatoire: {

            const int ALEA_MIN  = -100,
                      ALEA_MAX  = 100,
                      ITERATION_MIN = 0,
                      ITERATION_MAX = 100;

				cout << "Choisissez deux borne et un nombre de d'itérations: " << endl;
				int min = int(saisie("min ", ALEA_MIN, ALEA_MAX));
            int max = int(saisie("max ", min, ALEA_MAX));
            int nombreIterations = int(saisie("nombre ", ITERATION_MIN, ITERATION_MAX));

            for (int i = 0; i < nombreIterations; i++) {
               cout << random(min, max) << " ";
            }
			} break;

         // ----------------------------------------------------------------------------------------------
         // option 6 : Détermine différentes valeurs d'une chaine de caractères
			case Option::buffer: {

			   char     minuscule = ' ';
				char     majuscule = ' ';
				unsigned nbrDeChar;
				string   ligne;

				cout << "Entrez une phrase : ";
				getline(cin, ligne);

				nbrDeChar = buffer(minuscule, majuscule, ligne);

				if (minuscule != ' ') cout << "La plus petite minuscule : " << minuscule  << endl;
				if (majuscule != ' ') cout << "La plus grande majuscule : " << majuscule  << endl;
				cout << "Le nombre de caractere   : " << nbrDeChar << endl;

			} break;

         // ----------------------------------------------------------------------------------------------
         // option 7 : Affiche le sinus, cosinus et tangente d'un angle donné
			case Option::trigo: {

            const int TRIGO_MIN = 0,
                      TRIGO_MAX = 360;
				double    sinus,
				          cosinus,
				          tangente;

				double nombreUtilisateur = saisie("Entrez un nombre en degres ",TRIGO_MIN,TRIGO_MAX);

				trigo(nombreUtilisateur, sinus, cosinus, tangente);

				cout << "sin(" << nombreUtilisateur << ")= " << sinus    << endl;
				cout << "cos(" << nombreUtilisateur << ")= " << cosinus  << endl;
				cout << "tan(" << nombreUtilisateur << ")= " << tangente << endl;
			} break;

         // ----------------------------------------------------------------------------------------------
         // option 8 : Permet de quitter, ou non, le programme
			case Option::quitter: {
			   const string QUESTION  =  "Voulez-vous quitter?";
			   const char VALEUR_OUI  = 'O';
			   const char VALEUR_NON  = 'N';
				quitter = repondOui(VALEUR_NON, VALEUR_OUI,QUESTION);
			}
			break;
		}
	} while(!quitter);
	return EXIT_SUCCESS;
}

// saisie et vérification de celle-ci par rapport aux bornes données ainsi qu'au type demandé.
double saisie (const string& question, int borneInf, int borneSup) {
	bool saisieIncorrecte;
	double variableUtilisateur;
	do {
		cout << question << "[" << borneInf << "-" << borneSup << "] : ";
		cin  >> variableUtilisateur;
		saisieIncorrecte = !(borneInf <= variableUtilisateur and borneSup >= variableUtilisateur) or cin.fail();
		if (saisieIncorrecte) {
			CLEAR_BUFFER;
			cout << "/!\\ recommencer saisie" << endl;
		}
		IGNORE_BUFFER;
	} while (saisieIncorrecte);
	return variableUtilisateur;
}