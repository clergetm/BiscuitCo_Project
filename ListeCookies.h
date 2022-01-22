#pragma once
#include "Cookie.h"
#include "NoeudCookie.h"

class ListeCookies {
public:
	ListeCookies();						// Constructeur de ListeCookies
	~ListeCookies();					// Destructeur de ListeCookies
	void ViderListe();					// Retirer tous les Cookies de la liste
	
	void Inserer(const Cookie&);		// Insérer un nouveau Cookie à la liste
	void Supprimer(const Cookie&);
	
	void FixerTete();
	void FixerQueue();
	void Precedent();
	void Suivant();

	Cookie ValeurCourante() const;		// Obtenir la valeur au noeud courant
	
	bool ListeVide();					
	bool EstDansListe() const;			// Vérifier que le pointeur Courant est dans la liste
	bool Trouver(const Cookie&);		// Trouver si le Cookie fait partie de la liste
	
	Cookie getMeilleurCookie();			// Obtenir le Cookie avec le total le plus haut

private:
	NoeudCookie *tete;
	NoeudCookie *queue;
	NoeudCookie *courant;
};
