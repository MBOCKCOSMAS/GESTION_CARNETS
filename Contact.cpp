#include <cstdlib>
#include <iostream>
#include <string>
#include "Contact.h"
#include <fstream>
#include <stdio.h>
#include <windows.h>

using namespace std;

//Debut constructeur
Contact::Contact() : m_nom("Wayne"), m_prenom("John"), m_ville("paris"), m_rue("champs elysee"), m_codePostal(69000), m_numeroRue(3), m_telephoneFixe("00-00-00-00-00"), m_telephonePortable("00-00-00-00-00"), m_adresseMail("exemple@exemple.net")
{
                   
}

//Debut méthodes

void Contact::ajouterContact  (std::string prenom, std::string nom, std::string ville, std::string rue, int numeroRue, int codePostal, std::string numTel, std::string numPortable, std::string adresseMail)
{
                              //crée un fichier par contact dans le repertoire Contact
     string chemin = "C:\\ProgramData\\Contact\\";
     CreateDirectory(chemin.c_str(), NULL);
     chemin = chemin + nom + " " + prenom + ".txt";
     ofstream monFlux(chemin.c_str());
     if(monFlux)    
    {
        monFlux << "Prenom : " << prenom  << endl;
        monFlux << "Nom : " << nom << endl;
        monFlux << "Numero de la rue : " << numeroRue << endl;
        monFlux << "Nom de la rue : " << rue << endl;
        monFlux << "Code Postal : " << codePostal <<endl;
        monFlux << "Ville : " << ville << endl;
        monFlux << "Fixe : " << numTel << endl;
        monFlux << "Portable : " << numPortable  << endl;
        monFlux << "Adresse mail : " << adresseMail << endl;
        
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
    
}



void Contact::ModifierContact (string prenom, string nom)
{                             
                              //Modifie une information sur un contact
     int choix = 0;
     string  ville = "", rue ="",vidage = "", numTel = "", numPortable = "", adresseMail ="", numeroRue = "", codePostal = "";
     string chemin = "C:\\ProgramData\\Contact\\", chemin1 = "C:\\ProgramData\\Contact\\";
   string ligne = "";
    WIN32_FIND_DATA infoRecherche; 
     chemin = chemin + nom + " " + prenom + ".txt";
     if (INVALID_HANDLE_VALUE==FindFirstFile(chemin.c_str(), &infoRecherche)) 
    { 
      cout << "Ce contact n'existe pas !" << endl;
    } 
    else
    {
     ifstream monflux(chemin.c_str());
     {
       if(monflux)
{
       getline(monflux, ligne);
       cout << prenom << endl;
       
       getline(monflux, ligne);
       cout << nom << endl;
       
       getline(monflux, ligne);
       numeroRue = ligne;
       cout << numeroRue.substr(18) << " ";
       
       getline(monflux, ligne);
       rue = ligne;
       cout << rue.substr(16) << " ";
       
       getline(monflux, ligne);
       codePostal = ligne;
       cout << codePostal.substr(14) << " ";
       
       getline(monflux, ligne);
       ville = ligne;
       cout << ville.substr(8) << endl;
               
       getline(monflux, ligne);
       numTel = ligne;
       cout << numTel.substr(7) << endl;
       
       getline(monflux, ligne);
       numPortable = ligne;
       cout << numPortable.substr(11) << endl;
       
       getline(monflux, ligne);
       adresseMail = ligne;
       cout << adresseMail.substr(15) << endl;
       monflux.close();
}       
     }
   ofstream monFlux(chemin.c_str()); 


    cout << "Quelles informations desirez-vous modifier ? " << endl;
    cout << "********************************************************************************" << endl;
    cout << "******************************  1) Le nom  *************************************" << endl;
    cout << "******************************  2) Le numero de rue  ***************************" << endl;
    cout << "******************************  3) Le nom de Rue  ******************************" << endl;
    cout << "******************************  4) La ville  ***********************************" << endl;
    cout << "******************************  5) Le code postal  *****************************" << endl;
    cout << "******************************  6) Le numero de telephone fixe  ****************" << endl;
    cout << "******************************  7) Le numero de portable  **********************" << endl;
    cout << "******************************  8) L'adresse mail  *****************************" << endl;
    cout << "********************************************************************************" << endl;
    cin >> choix;
    if(monFlux)
{
    switch (choix)
        {
           case 1 :
                cout << "Nouveau nom : ";
                cin >> nom;
        monFlux << "Prenom : " << prenom  << endl;
        monFlux << "nom : " << nom << endl;
        monFlux << numeroRue << endl;
        monFlux << rue << endl;
        monFlux << codePostal << endl;
        monFlux << ville << endl;
        monFlux << numTel << endl;
        monFlux << numPortable  << endl;
        monFlux << adresseMail << endl;
                chemin1 = chemin1 + nom + " " + prenom + ".txt";
                monFlux.close();
                rename(chemin.c_str(),chemin1.c_str());
                break;
            
           case 2 :
                cout << "Nouveau numero de rue : ";
                cin >> numeroRue;
        monFlux << "Prenom : " << prenom  << endl;
        monFlux << "nom : " << nom << endl;
        monFlux << "Numero de la rue : " << numeroRue << endl;
        monFlux << rue << endl;
        monFlux << codePostal << endl;
        monFlux << ville << endl;
        monFlux << numTel << endl;
        monFlux << numPortable  << endl;
        monFlux << adresseMail << endl;
        monFlux.close();
                break;
                
           case 3 :
                getline (cin, vidage);
                cout << "Nouveau nom de rue : ";
                getline(cin, rue);
        monFlux << "Prenom : " << prenom  << endl;
        monFlux << "nom : " << nom << endl;
        monFlux << numeroRue << endl;
        monFlux << "Nom de la rue : " << rue << endl;
        monFlux << codePostal << endl;
        monFlux << ville << endl;
        monFlux << numTel << endl;
        monFlux << numPortable  << endl;
        monFlux << adresseMail << endl;
        monFlux.close();
                break;
                
           case 4 :
                cout << "Nouvelle ville : ";
                cin >> ville;
        monFlux << "Prenom : " << prenom  << endl;
        monFlux << "nom : " << nom << endl;
        monFlux << numeroRue << endl;
        monFlux << rue << endl;
        monFlux << codePostal << endl;
        monFlux << "Ville : " << ville << endl;
        monFlux << numTel << endl;
        monFlux << numPortable  << endl;
        monFlux << adresseMail << endl;
        monFlux.close();
                break;
                
           case 5 :
                cout << "Nouveau code postal : ";
                cin >> codePostal;
        monFlux << "Prenom : " << prenom  << endl;
        monFlux << "nom : " << nom << endl;
        monFlux << numeroRue << endl;
        monFlux << rue << endl;
        monFlux << "Code Postal : " << codePostal << endl;
        monFlux << ville << endl;
        monFlux << numTel << endl;
        monFlux << numPortable  << endl;
        monFlux << adresseMail << endl;
        monFlux.close();
                break;
                
            case 6 :
                cout << "Nouveau numero de telephone fixe : ";
                cin >> numTel;
        monFlux << "Prenom : " << prenom  << endl;
        monFlux << "Nom : " << nom << endl;
        monFlux << numeroRue << endl;
        monFlux << rue << endl;
        monFlux << codePostal << endl;
        monFlux << ville << endl;
        monFlux <<"Fixe : " << numTel << endl;
        monFlux << numPortable  << endl;
        monFlux << adresseMail << endl;
        monFlux.close();
                break;
                
           case 7 :
                cout << "Nouveau numero de telephone portable : ";
                cin >> numPortable;
        monFlux << "Prenom : " << prenom  << endl;
        monFlux << "Nom : " << nom << endl;
       monFlux << numeroRue << endl;
        monFlux << rue << endl;
        monFlux << codePostal << endl;
        monFlux << ville << endl;
        monFlux << numTel << endl;
        monFlux <<"Portable : " << numPortable  << endl;
        monFlux << adresseMail << endl;
        monFlux.close();
                break;
                
           case 8 :
                cout << "Nouvelle adresse mail : ";
                cin >> adresseMail;
        monFlux << "Prenom : " << prenom  << endl;
        monFlux << "Nom : " << nom << endl;
       monFlux << numeroRue << endl;
        monFlux << rue << endl;
        monFlux << codePostal << endl;
        monFlux << ville << endl;
        monFlux << numTel << endl;
        monFlux << numPortable  << endl;
        monFlux <<"Adresse mail : "<< adresseMail << endl;
        monFlux.close();
                break;
                
          default :
                   
                   break;
        }
        }
else
{
    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
}
}
}



void Contact::supprimerContact (string prenom, string nom)
{
                               //supprime un contact specifique
     string chemin = "C:\\ProgramData\\Contact\\";
     chemin = chemin + nom + " " + prenom + ".txt";
  remove(chemin.c_str());
}



void Contact::afficherContact(string nom, string prenom) const
{
                                     //affiche information sur un contact specifique
   string chemin = "C:\\ProgramData\\Contact\\";
    string  ville = "", rue ="",vidage = "", numTel = "", numPortable = "", adresseMail ="", numeroRue = "", codePostal = "", ligne = "";
     chemin = chemin + nom + " " + prenom + ".txt";
   ifstream monFlux(chemin.c_str());  

if(monFlux)
{
    getline(monFlux, ligne);
       cout << prenom << endl;
       
       getline(monFlux, ligne);
       cout << nom << endl;
       
       getline(monFlux, ligne);
       numeroRue = ligne;
       cout << numeroRue.substr(18) << " ";
       
       getline(monFlux, ligne);
       rue = ligne;
       cout << rue.substr(16) << " ";
       
       getline(monFlux, ligne);
       codePostal = ligne;
       cout << codePostal.substr(14) << " ";
       
       getline(monFlux, ligne);
       ville = ligne;
       cout << ville.substr(8) << endl;
               
       getline(monFlux, ligne);
       numTel = ligne;
       cout << numTel.substr(7) << endl;
       
       getline(monFlux, ligne);
       numPortable = ligne;
       cout << numPortable.substr(11) << endl;
       
       getline(monFlux, ligne);
       adresseMail = ligne;
       cout << adresseMail.substr(15) << endl;
}
else
{
    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
}
}


void Contact::listerContact() const
{
     //liste fichier donc contact et enleve l'extension
 string name = "";
    size_t number = 0;
   WIN32_FIND_DATA FindData;
  HANDLE hFind = FindFirstFile("C:\\ProgramData\\Contact\\*.txt", &FindData);
  if(hFind != INVALID_HANDLE_VALUE) 
  {
    do {
      name = FindData.cFileName;
      number = name.size();
      name.resize(number-4);
      cout << name << endl << endl;
    } while(FindNextFile(hFind, &FindData));
    
    FindClose(hFind);
}
}
