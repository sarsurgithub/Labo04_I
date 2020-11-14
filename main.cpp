/*
  ---------------------------------------------------------------------------
  Fichier     : main.cpp
  Nom du labo : Librairie
  Auteur.e.s  : Sarah Jallon & Florian Conti
  Date        : 05.11.20 - 15.11.20
  But         : Le but de ce programme est de mettre à disposition une librairie permettant à l'utilisateur de


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

bool checkValeurDansBorne (int borneinf, int bornesup, int choixUtilisateur);
void verifBuffer ();

//Liste des différentes options du programme
enum class Option {
	quitter, estPair, sommeChiffres, nombre1er, nombreArmstrong, nombreAleatoire, buffer, trigo
};

using namespace std;

int main() {

	// ----------------------------------------------------------------------------------------------
	//constantes du programme
	const int    ALIGN_NOMBRE    = 5;
   const string TIRET           = " - ";
   const int    BORNE_INF_MENU  = 0,
   	          BORNE_SUP_MENU  = 7;

	//quitter
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

		int choixUtilisateur, nombreUtilisateur;
		int intervalleMin, intervalleMax;
		bool saisieIncorrecte;

		do {
			cout << "Votre choix [" << BORNE_INF_MENU << TIRET << BORNE_SUP_MENU << "]:";
			cin  >> choixUtilisateur;
			IGNORE_BUFFER;

			saisieIncorrecte = choixUtilisateur < BORNE_INF_MENU or choixUtilisateur > BORNE_SUP_MENU or cin.fail();

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

			case Option::estPair: {

            const int EST_PAIR_MIN = 0,
                      EST_PAIR_MAX = 1000;

            do {
               verifBuffer();

               cout << "Entrez une valeur [" << EST_PAIR_MIN << TIRET << EST_PAIR_MAX << "] :";
               cin  >> nombreUtilisateur;
               IGNORE_BUFFER;

            } while (!checkValeurDansBorne(EST_PAIR_MIN, EST_PAIR_MAX, nombreUtilisateur) or cin.fail());

            if (estPair(nombreUtilisateur)) {
               cout << nombreUtilisateur << " est une valeur paire";
            } else {
               cout << nombreUtilisateur << " est une valeur impaire";
            }
			} break;

			// ----------------------------------------------------------------------------------------------
         // option 2 : Connaitre la somme de chiffres

			case Option::sommeChiffres: {

			   const int SOMME_CHIFFRE_MIN = 0,
                      SOMME_CHIFFRE_MAX = 1000;

            do {
               verifBuffer();

               cout << "Entrez une valeur [" << SOMME_CHIFFRE_MIN << TIRET << SOMME_CHIFFRE_MAX << "] :";
               cin  >> nombreUtilisateur;
               IGNORE_BUFFER;

            } while (!checkValeurDansBorne(SOMME_CHIFFRE_MIN, SOMME_CHIFFRE_MAX, nombreUtilisateur) or cin.fail());

            cout << "\nla somme des chiffres de " << nombreUtilisateur << " = " << sommeChiffres(nombreUtilisateur);
			} break;


         // ----------------------------------------------------------------------------------------------
         // option 3 : Connaitre les nombres premiers dans un intervalle

			case Option::nombre1er: {

			   const int NOMBRE1ER_MIN_MIN = 0,
			             NOMBRE1ER_MIN_MAX = 1000,
                      NOMBRE1ER_MAX_MIN = 20,
                      NOMBRE1ER_MAX_MAX = 1000;

            do {
               verifBuffer();

               cout << "Determiner les nombres premiers compris dans un intervalle" << endl;

               cout << "   - debut  :" << "[" << " " << NOMBRE1ER_MIN_MIN << TIRET << NOMBRE1ER_MIN_MAX << "] : " ;
               cin  >> intervalleMin;
               IGNORE_BUFFER;

               cout << "   - fin    :" << "[" << NOMBRE1ER_MAX_MIN << TIRET << NOMBRE1ER_MAX_MAX << "] : " ;
               cin  >> intervalleMax;
               IGNORE_BUFFER;

            } while (!checkValeurDansBorne(NOMBRE1ER_MIN_MIN, NOMBRE1ER_MIN_MAX, intervalleMin) or
                     !checkValeurDansBorne(NOMBRE1ER_MAX_MIN, NOMBRE1ER_MAX_MAX, intervalleMax) or cin.fail());

            for (; intervalleMin <= intervalleMax; ++intervalleMin) {
               if (nbre1er(intervalleMin)) {
                  cout << "\nle nombre " << intervalleMin << " est un nombre premier";
               }
            }
			} break;



         // ----------------------------------------------------------------------------------------------
         // option 4 : Connaitre les nombres de Armstrong dans un intervalle donné

			case Option::nombreArmstrong: {

            const int ARMSTRONG_MIN_MIN = 0,
                      ARMSTRONG_MIN_MAX = 1000,
                      ARMSTRONG_MAX_MIN = 20,
                      ARMSTRONG_MAX_MAX = 1000;

			   do {
               verifBuffer();

               cout << "Determiner les nombres Armstrong compris dans un intervalle" << endl;

               cout << "   - debut  :" << "[" << " " << ARMSTRONG_MIN_MIN << TIRET << ARMSTRONG_MIN_MAX << "] : " ;
               cin  >> intervalleMin;
               IGNORE_BUFFER;

               cout << "   - fin    :" << "[" << ARMSTRONG_MAX_MIN << TIRET << ARMSTRONG_MAX_MAX << "] : " ;
               cin  >> intervalleMax;
               IGNORE_BUFFER;

            } while (!checkValeurDansBorne(ARMSTRONG_MIN_MIN, ARMSTRONG_MIN_MAX, intervalleMin) or
                     !checkValeurDansBorne(ARMSTRONG_MAX_MIN, ARMSTRONG_MAX_MAX, intervalleMax) or cin.fail());

            for (; intervalleMin <= intervalleMax; ++intervalleMin) {
               if (nbreArmstrong(intervalleMin)) {
                  cout << "\nle nombre " << intervalleMin << " est un nombre de Armstrong";
               }
            }
			} break;


         // ----------------------------------------------------------------------------------------------
         // option 5 : Génère 1 ou plusieurs nombres aléatoires dans un intervalle

			case Option::nombreAleatoire: {

            const int ALEA_MIN_MIN  = -100,
                      ALEA_MIN_MAX  = 100,
                      ALEA_MAX_MIN  = -14,
                      ALEA_MAX_MAX  = 100,
                      ITERATION_MIN = 0,
                      ITERATION_MAX = 100;

            int min, max;
            int iterations;

            do {

               verifBuffer();

               cout << setw(ALIGN_NOMBRE) << TIRET << " min ["    << ALEA_MIN_MIN  << TIRET << ALEA_MIN_MAX  << "] : ";
               cin >> min;
               cout << setw(ALIGN_NOMBRE) << TIRET << " max [ "   << ALEA_MAX_MIN  << TIRET << ALEA_MAX_MAX  << "] : ";
               cin >> max;
               cout << setw(ALIGN_NOMBRE) << TIRET << " nbre [  " << ITERATION_MIN << TIRET << ITERATION_MAX << "] : ";
               cin >> iterations;
               cout << endl;

            } while (!checkValeurDansBorne(ALEA_MIN_MIN, ALEA_MIN_MAX, min) or
                     !checkValeurDansBorne(ALEA_MAX_MIN, ALEA_MAX_MAX, max) or cin.fail());

            if (iterations > 100)
            {
               iterations = 100;
            }

            for (int i = 0; i < iterations; i++) {
               cout << random(min, max) << " ";
            }
			} break;

         // ----------------------------------------------------------------------------------------------
         // option 6 : Détermine différentes valeurs d'une chaine de caractère

			case Option::buffer: {

			   char minuscule = ' ';
				char majuscule = ' ';
				unsigned nbrDeChara;
				string ligne;

				cout << "Entrez une phrase : ";
				getline(cin, ligne);

				nbrDeChara = buffer(minuscule, majuscule, ligne);
				cout << "la plus petite minuscule : " << minuscule  << endl;
				cout << "la plus grande majuscule : " << majuscule  << endl;
				cout << "le nombre de caractere   : " << nbrDeChara << endl;

			} break;


         // ----------------------------------------------------------------------------------------------
         // option 7 : Affiche le sinus, cosinus et tangente d'un angle donné

			case Option::trigo: {

            const int TRIGO_MIN = 0,
                      TRIGO_MAX = 360;

				double sinus, cosinus, tangente;


				do {
               cout << "entrez un nombre en degres [" << TRIGO_MIN << TIRET << TRIGO_MAX << "] : ";
               cin  >> nombreUtilisateur;
				} while (!checkValeurDansBorne(TRIGO_MIN, TRIGO_MAX, nombreUtilisateur) or cin.fail());

				trigo(nombreUtilisateur, sinus, cosinus, tangente);
				cout << "\nsin(" << nombreUtilisateur << ")= " << sinus;
				cout << "\ncos(" << nombreUtilisateur << ")= " << cosinus;
				cout << "\ntan(" << nombreUtilisateur << ")= " << tangente;

			} break;


         // ----------------------------------------------------------------------------------------------
         // option 8 : Permet de quitter, ou non, le programme

			case Option::quitter: {
				quitter = repondOui('N', 'O', "Voulez-vous quitter?");
			}
				break;
		}

	} while(!quitter);

	return EXIT_SUCCESS;
}

//Permet de vérifier si la valeur entrée par l'utilisateur est dans les bornes choisies
bool checkValeurDansBorne (int borneinf, int bornesup, int choixUtilisateur) {

   return borneinf <= choixUtilisateur and bornesup >= choixUtilisateur;

}

//Permet de vider le buffer si une erreur a été detecté
void verifBuffer () {

   if (cin.fail()) {
      CLEAR_BUFFER;
      IGNORE_BUFFER;
   }

}