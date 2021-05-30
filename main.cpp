#include <cstdlib>
#include <iostream>
#include <string>
#include "Contact.h"

using namespace std;
      
int main(int argc, char *argv[])
{
                   //Création variables
    int choix = 0, choice = 0, numeroRue = 0, codePostal = 0;
    string  prenom = "", nom = "", ville = "", rue ="", vidage = "", numTel = "", numPortable = "", adresseMail ="";
     bool continuer = true;
               
                  //Création objet
    Contact john;
    
    while (continuer == true)
    {
                               // Action possible
    cout << "Que desirez-vous faire ? " << endl;
    cout << "********************************************************************************" << endl;
    cout << "******************************  1) Ajouter un contact  *************************" << endl;
    cout << "******************************  2) Modifier un contact  ************************" << endl;
    cout << "******************************  3) Supprimer un contact  ***********************" << endl;
    cout << "******************************  4) afficher un contact  ************************" << endl;
    cout << "******************************  5) afficher tous les contacts  *****************" << endl;
    cout << "********************************************************************************" << endl;
    cin >> choix;
    
     switch (choix)
        {
           case 1 :
                system ("CLS");
                getline (cin, vidage);
                cout << "Rue : ";
                getline(cin, rue);
                cout << "numero de rue : ";
                cin >> numeroRue;
                cout << "Code Postal : ";
                cin >> codePostal;
                cout << "Ville : (avec des tiret pour des villes composes)";
                cin >> ville;
                cout << "Telephone Fixe : ";
                cin >> numTel;
                cout << "Telephone Portable : ";
                cin >> numPortable;
                cout << "Adresse Mail : ";
                cin >> adresseMail;
                cout << "Nom : ";
                cin >> nom;
                cout << "Prenom : ";
                cin >> prenom;
                john.ajouterContact(prenom, nom, ville, rue, numeroRue, codePostal, numTel, numPortable, adresseMail);
                break;
            
           case 2 :
                system ("CLS");
                cout << "Nom du contact a modifier : ";
                cin >> nom;
                cout << "Prenom du contact a modifier : ";
                cin >> prenom;
                john.ModifierContact(prenom, nom);
                break;
                
           case 3 :
                system ("CLS");
                cout << "Nom du contact a supprimer : ";
                cin >> nom;
                cout << "Prenom du contact a supprimer : ";
                cin >> prenom;
                john.supprimerContact(prenom, nom);
                break;
                
                case 4 :
                     system ("CLS");
                cout << "Nom du contact a afficher : ";
                cin >> nom;
                cout << "Prenom du contact a afficher : ";
                cin >> prenom;
              john.afficherContact(nom, prenom);
                break;
                
           case 5 :
                system ("CLS");
                john.listerContact();
                break;
                
          default :
                   
                   break;
        }
        cout << "Tapez 1 pour continuer et 2 pour arreter ?" << endl;
        cin >> choice;
        if (choice == 1)
        {
         continuer = true;          
        }
        else
        {
         continuer = false;
        }
        system ("CLS");
}
    system("PAUSE");
    return EXIT_SUCCESS;
}
