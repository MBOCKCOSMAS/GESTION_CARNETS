#include <cstdlib>
#include <iostream>
#include <string>

class Contact
{
      private :
  //Debut attributs
  std::string m_nom;
  std::string m_prenom;
  std::string m_ville;
  std::string m_rue;
  int m_codePostal;
  int m_numeroRue;
  std::string m_telephoneFixe;
  std::string m_telephonePortable;
  std::string m_adresseMail;
  
  
  
      public :
      //Constructeur:
      Contact();
      
  //Debut méthodes
      void ajouterContact  (std::string prenom, std::string nom, std::string ville, std::string rue, int numeroRue, int codePostal, std::string numTel, std::string numPortable, std::string adresseMail);
      void ModifierContact (std::string prenom, std::string nom);
      void supprimerContact (std::string prenom, std::string nom);
      void afficherContact (std::string nom, std::string prenom) const;
      void listerContact() const;
};
