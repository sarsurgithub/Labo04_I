#include "fonctions.h"
#include <iostream>
#include <cstdlib>
#include <cmath>


using namespace std;

bool estPair (int nombreUtilisateur)
{
   return nombreUtilisateur % 2 == 0;
}

int sommeChiffres (int nombreUtilisateur)
{
   int somme = 0;
   int chiffre;

   while (nombreUtilisateur > 0)
   {
      chiffre = nombreUtilisateur % 10;
      somme = somme + chiffre;
      nombreUtilisateur = nombreUtilisateur / 10;
   }
   return somme;
}

bool nbre1er (int nombreUtilisateur)
{
   bool testNbrPremier = true;

   if (nombreUtilisateur <= 1)
   {
      return false;
   }
   else
   {
      for(int i = 2; pow(i,2) <= nombreUtilisateur; i++) {
         if(nombreUtilisateur % i == 0) {
            testNbrPremier = false;
            break;
         }
      }
      return testNbrPremier;
   }

}

bool nbreArmstrong (int nombreUtilisateur)
{
   int somme = 0;
   int chiffre;
   int nombreUtilisateurInitial = nombreUtilisateur;

   while (nombreUtilisateur > 0)
   {
      chiffre = nombreUtilisateur % 10;
      somme = somme + pow(chiffre, 3);
      nombreUtilisateur = nombreUtilisateur / 10;
   }
   return (somme == nombreUtilisateurInitial);
}

bool   repondOui(char valeurNon, char valeurOui, string question) {
   char reponse;
   bool saisieIncorrecte = false;

   do {
      cout << question << " [" << valeurOui << '/' << valeurNon << ']' << " : ";
      cin >> reponse;



      cout << endl << reponse << valeurNon << valeurOui << endl;


      saisieIncorrecte = !(reponse == valeurOui || reponse == valeurNon) || cin.fail();

      if (saisieIncorrecte) {
         cout << "/!\\ recommencer saisie" << endl;

      }
   } while (saisieIncorrecte);

   if (reponse == valeurOui) {
      return true;
   }
   else {
      return false;
   }
}