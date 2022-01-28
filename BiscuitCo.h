#pragma once
#include <string>
#include <iostream>
using namespace std;

/**
* Structure du Commande et Noeud-Commande
*/
struct Commande {
	// Structure Commande
	string source;
	string destinataire;

	//Liste achats
	/**
	* Structure de achat
	* Une commande est composée de plusieurs achats
	* Chaque achat modifie le total des cookies commandés
	*/
	struct achat
	{
		string nomCookies;
		short int quantiteCookies;
		achat* achatSuivant;
	};

	achat* listeAchat;
	// Structure Noeud-Commande
	Commande* commandeSuivante;
};

/**
* Structure du Client et Noeud-Client
*/
struct Client {
	// Structure Client
	string nom;
	short int numero;
	string rue;

	// Structure Noeud-Client
	Client* clientSuivant;

	// Liste Commande 
	Commande* commandeSuivante;
};


/**
* Structure du Commande et Noeud-Commande
*/
struct Cookie {
	// Structure Cookie
	string nom;
	short int total;

	// Structure Noeud-Cookie
	Cookie* cookieSuivant;
};

class BiscuitCo
{
	Client* listeClients;
	Cookie* listeCookies;
	//Storage storage;

	// Tete Queue et Courant pour Client
	// Tete Queue et Courant pour Commande
	// Tete Queue et Courant pour Cookies
	// Tete Queue et Courant pour Achat



};

