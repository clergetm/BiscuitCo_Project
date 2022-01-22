#pragma once
#include <string>
using namespace std;
class Cookie
{
	string nom;						// Nom/Type du Cookie
	short int total;				// Compte du nombre de cookie de ce type acheté 

public:
	Cookie();						// Constructeur de Cookie sans paramètre
	Cookie(string);					// Constructeur avec nom de Cookie
	~Cookie();						// Destructeur de Cookie
	string getNom();				// Getter de nom
	short int getTotal();			// Getter de total
	void setNom(string);			// Setter de nom
	void AjouterTotal(short int);	// Ajout au compte total
	void RetirerTotal(short int);	// Retrait au compte total
	bool EstEquivalent(Cookie);		// Vérifier l’équivalence entre 2 Cookie
};

