/*
  ---------------------------------------------------------------------------
  Fichier     : main.cpp
  Nom du labo :
  Auteur(s)   : Sarah Jallon & Florian Conti
  Date        : 05.11.20 - 11.11.20
  But         :

  Remarque(s) :

  Compilateur : MinGW-W64 g++ 8.1.0
  ---------------------------------------------------------------------------
*/

#include "fonctions.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

#define CLEAR_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;


int main() {

   const int ALIGNEMENT_NOMBRE = 5;
   const int ALIGNEMENT_TEXTE = 12;

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

   int choixUtilisateur;
   int nombreUtilisateur;
   int intervalleMin, intervalleMax;

   do {
      if (cin.fail())
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
            cout << "Entrez une valeur [0 - 1000] :";
            cin >> nombreUtilisateur;
            CLEAR_BUFFER;
         } while (nombreUtilisateur < 0 or nombreUtilisateur > 1000 or cin.fail());

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
               cout << "\nle nombre " << intervalleMin << " est un nombre premier";
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

            cout << "   - debut  :" << setw(ALIGNEMENT_TEXTE) << "[ 0 - 1000] : ";
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


   return 0;
}
