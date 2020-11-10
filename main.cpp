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
	//todo ne surtout pas laisser ça comme ça
	const int    ALIGNEMENT_NOMBRE = 5;
   const int    ALIGNEMENT_TEXTE  = 12;
   const string TIRET             = " - ";
   const int BORNE_INF_MENU = 0,
   	       BORNE_SUP_MENU = 7;
   const int BORNE_PRINCIPALE_INF    = 0,
             BORNE_PRINCIPALE_SUP    = 1000;
   const int BORNE_SECONDAIRE_INF    = 20; //réfléchir
   const int BORNE_ALEATOIRE_MIN_INF = -100;
	const int BORNE_ALEATOIRE_MIN_SUP = 100;
	const int BORNE_ALEATOIRE_MAX_INF = -14;
	const int BORNE_ALEATOIRE_MAX_SUP = 100,
	BORNE_ANGLE_INF= 0, BORNE_ANGLE_SUP = 360;


	//quitter
   bool quitter = false;
	do {
		// ----------------------------------------------------------------------------------------------
		//affichage du choix des fonctions

		cout << "Options" << endl;
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

			case Option::estPair:
				do {
					int borneInfChoix = 0;
					int borneSupCHoix = 1000;
					if (cin.fail()) {
						cin.clear();
						IGNORE_BUFFER;
					}
					cout << "Entrez une valeur [0 - 1000] :"; //todo pas de nombres magiques
					cin >> nombreUtilisateur;
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
					cin >> nombreUtilisateur;
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
					cin >> intervalleMin;
					IGNORE_BUFFER;

					cout << "   - fin    :" << setw(ALIGNEMENT_TEXTE) << "[20 - 1000] : ";
					cin >> intervalleMax;
					IGNORE_BUFFER;

				} while (intervalleMin < 0 or intervalleMin > 1000 or intervalleMax < 20 or intervalleMax > 1000 or
							cin.fail());

				for (; intervalleMin <= intervalleMax; ++intervalleMin) {
					if (nbre1er(intervalleMin)) {
						cout << "\nle nombre " << intervalleMin
							  << " est un nombre premier"; //todo ce retour à la ligne est pas très parlant ? à voir
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
					cin >> intervalleMin;
					IGNORE_BUFFER;

					cout << "   - fin    :" << setw(ALIGNEMENT_TEXTE) << "[20 - 1000] : ";
					cin >> intervalleMax;
					IGNORE_BUFFER;

				} while (intervalleMin < 0 or intervalleMin > 1000 or intervalleMax < 20 or intervalleMax > 1000 or
							cin.fail());

				for (; intervalleMin <= intervalleMax; ++intervalleMin) {
					if (nbreArmstrong(intervalleMin)) {
						cout << "\nle nombre " << intervalleMin << " est un nombre de Armstrong";
					}
				}

				break;

			case Option::nombreAleatoire  :
				int min, max;
				int iterations;

				cout << "borneinf [-100,100], bornesup [-14,100]" << endl;
				cout << "min:" << endl;
				cin >> min;
				cout << "max:" << endl;
				cin >> max;
				cout << "combien de fois ?";
				cin >> iterations;

				for (int i = 0; i < iterations; i++) {
					cout << random(min, max) << endl;
				}
				break;
			case Option::buffer           : { //todo mettre accolades partout ou nulle part
				char minuscule = ' ';
				char majuscule = ' ';
				unsigned nbrDeChara;
				string ligne;
				cout << "Entrez une phrase: " << endl;
				getline(cin, ligne);
				nbrDeChara = buffer(minuscule, majuscule, ligne);
				cout << "maj: " << majuscule << " min: " << minuscule << " nbrChar: " << nbrDeChara << endl;
			}
				break;
			case Option::trigo            : {
				double nbrUtilisateur;
				double sinus, cosinus, tangente;
				cout << "entrez un nbr en degres [0-360]" << endl;
				cin >> nbrUtilisateur;
				trigo(nbrUtilisateur, sinus, cosinus, tangente);
				cout << "sin(" << nbrUtilisateur << ")= " << sinus << endl;
				cout << "cos(" << nbrUtilisateur << ")= " << cosinus << endl;
				cout << "tan(" << nbrUtilisateur << ")= " << tangente << endl;

			}
				break;
			case Option::quitter          : {
				quitter = repondOui('N', 'O', "Voulez-vous quitter?");
			}
				break;
		}

	} while(!quitter);

	return EXIT_SUCCESS;
}
