/*
  ---------------------------------------------------------------------------
  Fichier     : main.cpp
  Nom du labo : Librairie
  Auteur.e(s) : Sarah Jallon & Florian Conti
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

// TODO appeler ce defin ignore_buffer et pas clear, clear c'est une autre commande dont on a besoin pour gérer les erreurs
#define CLEAR_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;


int main() {

   const int ALIGNEMENT_NOMBRE = 5;
   const int ALIGNEMENT_TEXTE  = 12;

   //TODO une enum classe se déclaire en dehors du main, de préférence en majuscules
   enum class option {estPair = 1, sommeChiffres, nombre1er, nombreArmstrong, nombreAleatoire, buffer, trigo, quitter = 0};

   cout << "Options" << endl;
   cout << setw(ALIGNEMENT_NOMBRE) << (int)option::estPair         << "    " << "est pair"             << endl;
   cout << setw(ALIGNEMENT_NOMBRE) << (int)option::sommeChiffres   << "    " << "somme chiffres"       << endl;
   cout << setw(ALIGNEMENT_NOMBRE) << (int)option::nombre1er       << "    " << "nombre 1er"           << endl;
   cout << setw(ALIGNEMENT_NOMBRE) << (int)option::nombreArmstrong << "    " << "nombre de Armstrong"  << endl;
   cout << setw(ALIGNEMENT_NOMBRE) << (int)option::nombreAleatoire << "    " << "nombre aleatoire"     << endl;
   cout << setw(ALIGNEMENT_NOMBRE) << (int)option::buffer          << "    " << "buffer"               << endl;
   cout << setw(ALIGNEMENT_NOMBRE) << (int)option::trigo           << "    " << "trigo"                << endl;
   cout << setw(ALIGNEMENT_NOMBRE) << (int)option::quitter         << "    " << "quitter"              << endl;

   //TODO choisir une façon de déclarer pas tout mélanger
   int choixUtilisateur;
   int nombreUtilisateur;
   int intervalleMin, intervalleMax;

   do {
      if (cin.fail()) //todo dans tous les if l'accolade se mets après la parenthèse
      {
         cin.clear();
         CLEAR_BUFFER;
      }
      cout << "Votre choix[0 - 7] :";
      cin >> choixUtilisateur;
      CLEAR_BUFFER;
   } while (choixUtilisateur < 0 or choixUtilisateur > 7 or cin.fail());

   switch (option(choixUtilisateur)) {

      case option::estPair:
         do {
            if (cin.fail())
            {
               cin.clear();
               CLEAR_BUFFER;
            }
            cout << "Entrez une valeur [0 - 1000] :"; //todo pas de nombres magiques
            cin >> nombreUtilisateur;
            CLEAR_BUFFER;
         } while (nombreUtilisateur < 0 or nombreUtilisateur > 1000 or cin.fail()); //todo pas de nombres magiques

         if (estPair(nombreUtilisateur))
         {
            cout << nombreUtilisateur << " est une valeur paire";
         }
         else
         {
            cout << nombreUtilisateur << " est une valeur impaire";
         }
         break;

      case option::sommeChiffres:
         do {
            if (cin.fail())
            {
               cin.clear();
               CLEAR_BUFFER;
            }

            cout << "Entrez une valeur [0 - 1000] :";
            cin >> nombreUtilisateur;
            CLEAR_BUFFER;

         } while (nombreUtilisateur < 0 or nombreUtilisateur > 1000 or cin.fail());

         cout << "\nla somme des chiffres de " << nombreUtilisateur << " = " << sommeChiffres(nombreUtilisateur);
         break;


      case option::nombre1er:

         do {
            if (cin.fail())
            {
               cin.clear();
               CLEAR_BUFFER;
            }

            cout << "Determiner les nombres premiers compris dans un intervalle" << endl;

            cout << "   - debut  :" << setw(ALIGNEMENT_TEXTE) << "[ 0 - 1000] : ";
            cin >> intervalleMin;
            CLEAR_BUFFER;

            cout << "   - fin    :" << setw(ALIGNEMENT_TEXTE) << "[20 - 1000] : ";
            cin >> intervalleMax;
            CLEAR_BUFFER;

         } while (intervalleMin < 0 or intervalleMin > 1000 or intervalleMax < 20 or intervalleMax > 1000 or cin.fail());

         for (; intervalleMin <= intervalleMax; ++intervalleMin)
         {
            if(nbre1er(intervalleMin))
            {
               cout << "\nle nombre " << intervalleMin << " est un nombre premier"; //todo se retour à la ligne est pas très parlant ? à voir
            }
         }
         break;


      case option::nombreArmstrong:

         do {
            if (cin.fail())
            {
               cin.clear();
               CLEAR_BUFFER;
            }

            cout << "Determiner les nombres premiers compris dans un intervalle" << endl;

            cout << "   - debut  :" << setw(ALIGNEMENT_TEXTE) << "[ 0 - 1000] : "; //todo aligner les << et >>
            cin >> intervalleMin;
            CLEAR_BUFFER;

            cout << "   - fin    :" << setw(ALIGNEMENT_TEXTE) << "[20 - 1000] : ";
            cin >> intervalleMax;
            CLEAR_BUFFER;

         } while (intervalleMin < 0 or intervalleMin > 1000 or intervalleMax < 20 or intervalleMax > 1000 or cin.fail());

         for (; intervalleMin <= intervalleMax; ++intervalleMin)
         {
            if(nbreArmstrong(intervalleMin))
            {
               cout << "\nle nombre " << intervalleMin << " est un nombre de Armstrong";
            }
         }

         break;



      case option::nombreAleatoire  : cout << "test"; break;
      case option::buffer           : cout << "test"; break;
      case option::trigo            : cout << "test"; break;
      case option::quitter          : cout << "test"; break;
   }


   return 0; // todo faire une fin de programme digne de ce nom (sauf si on désir mourir)
}
