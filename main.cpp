/*
  ---------------------------------------------------------------------------
  Fichier     : main.cpp
  Nom du labo : Librairie
  Auteur.e.s  : Sarah Jallon & Florian Conti
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

bool checkValeurDansBorne (int borneinf, int bornesup, int choixUtilisateur);

enum class Option {
	quitter, estPair, sommeChiffres, nombre1er, nombreArmstrong, nombreAleatoire, buffer, trigo
};

using namespace std;

int main() {

	// ----------------------------------------------------------------------------------------------
	//constantes du programme
	//todo ne surtout pas laisser ça comme ça
	const int    ALIGNEMENT_NOMBRE = 5;
   const int    ALIGNEMENT_TEXTE  = 12;
   const string TIRET             = " - ";
   const int    BORNE_INF_MENU    = 0,
   	          BORNE_SUP_MENU    = 7;

	//quitter
   bool quitter = false;
	do {
		// ----------------------------------------------------------------------------------------------
		//affichage du choix des fonctions

		cout << "\nOptions" << endl;
		cout << setw(ALIGNEMENT_NOMBRE) << (int) Option::estPair         << "    " << "est pair"            << endl;
		cout << setw(ALIGNEMENT_NOMBRE) << (int) Option::sommeChiffres   << "    " << "somme chiffres"      << endl;
		cout << setw(ALIGNEMENT_NOMBRE) << (int) Option::nombre1er       << "    " << "nombre 1er"          << endl;
		cout << setw(ALIGNEMENT_NOMBRE) << (int) Option::nombreArmstrong << "    " << "nombre de Armstrong" << endl;
		cout << setw(ALIGNEMENT_NOMBRE) << (int) Option::nombreAleatoire << "    " << "nombre aleatoire"    << endl;
		cout << setw(ALIGNEMENT_NOMBRE) << (int) Option::buffer          << "    " << "buffer"              << endl;
		cout << setw(ALIGNEMENT_NOMBRE) << (int) Option::trigo           << "    " << "trigo"               << endl;
		cout << setw(ALIGNEMENT_NOMBRE) << (int) Option::quitter         << "    " << "quitter"             << endl;

		// ----------------------------------------------------------------------------------------------
		//entrée utilisateur et déclaration et/ou initialisation des variables nécessaires à celle-ci
	   //todo controler saisie
	   //todo demander borne
		int choixUtilisateur, nombreUtilisateur;
		int intervalleMin, intervalleMax; //TODO réfléchir à ces intervalles
		bool saisieIncorrecte;

		do {
			cout << "Votre choix [" << BORNE_INF_MENU << TIRET << BORNE_SUP_MENU << "]:";
			cin >> choixUtilisateur;
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

            const int EST_PAIR_MIN = 0;
            const int EST_PAIR_MAX = 1000;

            do {
               if (cin.fail()) {
                  CLEAR_BUFFER;
                  IGNORE_BUFFER;
               }
               cout << "Entrez une valeur [" << EST_PAIR_MIN << TIRET << EST_PAIR_MAX << "] :";
               cin >> nombreUtilisateur;
               IGNORE_BUFFER;
            } while (!checkValeurDansBorne(EST_PAIR_MIN, EST_PAIR_MAX, nombreUtilisateur) or cin.fail()); //todo pas de nombres magiques

            if (estPair(nombreUtilisateur)) {
               cout << nombreUtilisateur << " est une valeur paire";
            } else {
               cout << nombreUtilisateur << " est une valeur impaire";
            }
			}break;

			// ----------------------------------------------------------------------------------------------
         // option 2 : Connaitre la somme de chiffres

			case Option::sommeChiffres: {

			   const int SOMME_CHIFFRE_MIN = 0;
            const int SOMME_CHIFFRE_MAX = 1000;

            do {
               if (cin.fail()) {
                  CLEAR_BUFFER;
                  IGNORE_BUFFER;
               }

               cout << "Entrez une valeur [" << SOMME_CHIFFRE_MIN << TIRET << SOMME_CHIFFRE_MAX << "] :";
               cin >> nombreUtilisateur;
               IGNORE_BUFFER;

            } while (nombreUtilisateur < 0 or nombreUtilisateur > 1000 or cin.fail());

            cout << "\nla somme des chiffres de " << nombreUtilisateur << " = " << sommeChiffres(nombreUtilisateur);
			}break;


         // ----------------------------------------------------------------------------------------------
         // option 3 : Connaitre les nombres premiers dans un intervalle

			case Option::nombre1er: {

			   const int NOMBRE1ER_MIN_MIN = 0,
			             NOMBRE1ER_MIN_MAX = 1000,
                      NOMBRE1ER_MAX_MIN = 20,
                      NOMBRE1ER_MAX_MAX = 1000;

            do { //todo décider si on veut faire un seul test de saisie ou deux
               //todo créer une variable saisie incorrecte et ignorer le buffer une seule fois et avoir un msg d'erreur
               if (cin.fail()) {
                  CLEAR_BUFFER;
                  IGNORE_BUFFER;
               }

               cout << "Determiner les nombres premiers compris dans un intervalle" << endl;

               cout << "   - debut  :" << setw(ALIGNEMENT_TEXTE) << "[" << " " << NOMBRE1ER_MIN_MIN << TIRET << NOMBRE1ER_MIN_MAX << "] : " ;
               cin >> intervalleMin;
               IGNORE_BUFFER;

               cout << "   - fin   :" << setw(ALIGNEMENT_TEXTE) << "[" << NOMBRE1ER_MAX_MIN << TIRET << NOMBRE1ER_MAX_MAX << "] : " ;
               cin >> intervalleMax;
               IGNORE_BUFFER;

            } while (intervalleMin < NOMBRE1ER_MIN_MIN or intervalleMin > NOMBRE1ER_MIN_MAX or intervalleMax < NOMBRE1ER_MAX_MIN or intervalleMax > NOMBRE1ER_MAX_MAX or
                     cin.fail());

            for (; intervalleMin <= intervalleMax; ++intervalleMin) {
               if (nbre1er(intervalleMin)) {
                  cout << "\nle nombre " << intervalleMin
                       << " est un nombre premier"; //todo ce retour à la ligne est pas très parlant ? à voir
               }
            }
			}break;



         // ----------------------------------------------------------------------------------------------
         // option 4 : Connaitre les nombres de Armstrong dans un intervalle donné

			case Option::nombreArmstrong: {

            const int ALEATOIRE_MIN_MIN = 0,
                      ALEATOIRE_MIN_MAX = 1000,
                      ALEATOIRE_MAX_MIN = 20,
                      ALEATOIRE_MAX_MAX = 1000;

			   do {
               if (cin.fail()) {
                  CLEAR_BUFFER;
                  IGNORE_BUFFER;
               }

               cout << "Determiner les nombres premiers compris dans un intervalle" << endl;

               cout << "   - debut  :" << setw(ALIGNEMENT_TEXTE) << "[" << " " << ALEATOIRE_MIN_MIN << TIRET << ALEATOIRE_MIN_MAX << "] : " ;
               cin >> intervalleMin;
               IGNORE_BUFFER;

               cout << "   - fin   :" << setw(ALIGNEMENT_TEXTE) << "[" << ALEATOIRE_MAX_MIN << TIRET << ALEATOIRE_MAX_MAX << "] : " ;
               cin >> intervalleMax;
               IGNORE_BUFFER;

            } while (intervalleMin < ALEATOIRE_MIN_MIN or intervalleMin > ALEATOIRE_MIN_MAX or intervalleMax < ALEATOIRE_MAX_MIN or intervalleMax > ALEATOIRE_MAX_MAX or
                     cin.fail());

            for (; intervalleMin <= intervalleMax; ++intervalleMin) {
               if (nbreArmstrong(intervalleMin)) {
                  cout << "\nle nombre " << intervalleMin << " est un nombre de Armstrong";
               }
            }


			}break;


         // ----------------------------------------------------------------------------------------------
         // option 5 : Génère 1 ou plusieurs nombres aléatoires dans un intervalle

			case Option::nombreAleatoire: {
            int min, max;
            int iterations;

            cout << setw(ALIGNEMENT_NOMBRE) << TIRET << " min [-100 - 100] :";
            cin >> min;
            cout << setw(ALIGNEMENT_NOMBRE) << TIRET << " max [ -14 - 100] :";
            cin >> max;
            cout << setw(ALIGNEMENT_NOMBRE) << TIRET << " nbre [  0 - 100] :";
            cin >> iterations;
            cout << endl;

            for (int i = 0; i < iterations; i++) {
               cout << random(min, max) << " ";
            }
			}break;

         // ----------------------------------------------------------------------------------------------
         // option 6 : Détermine différentes valeurs d'une chaine de caractère

			case Option::buffer: { //todo mettre accolades partout ou nulle part
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
			}
				break;


         // ----------------------------------------------------------------------------------------------
         // option 7 : Affiche le sinus, cosinus et tangente d'un angle donné

			case Option::trigo: {
				double nbrUtilisateur;
				double sinus, cosinus, tangente;
				cout << "entrez un nbr en degres [0 - 360]" << endl;
				cin >> nbrUtilisateur;
				trigo(nbrUtilisateur, sinus, cosinus, tangente);
				cout << "sin(" << nbrUtilisateur << ")= " << sinus << endl;
				cout << "cos(" << nbrUtilisateur << ")= " << cosinus << endl;
				cout << "tan(" << nbrUtilisateur << ")= " << tangente << endl;

			}
				break;


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

bool checkValeurDansBorne (int borneinf, int bornesup, int choixUtilisateur){

   return borneinf <= choixUtilisateur and bornesup >= choixUtilisateur;

}