#pragma once
#include "Client.h"
#include "Cookie.h"
#include "ListeCookies.h"
#include <list>
#include <string>
using namespace std;

struct CommandeCookie {
	string nomCookie;											// Nom de ce Cookie
	short int quantite;											// Quantité commandée de ce Cookie
	CommandeCookie(string _nomCookie, short int _quantite) {	// Constructeur de CommandeCookie
		nomCookie = _nomCookie;
		quantite = _quantite;
	};
};
class Commande
{
	Client* source;									// Client source de la Commande
	Client* destinataire;							// Client destinataire de la Commande
	list<CommandeCookie> listeCommandeCookies;		// La liste des Cookies Commandés
	ListeCookies* listeCookies;						// La liste de TOUS les Cookies
public : 
	Commande();										// Constructeur de Commande sans paramètre
	Commande(Client*,Client*,ListeCookies*);		// Constructeur de Commande 
	~Commande();									// Destructeur de Commande

	Client* getSource();							// Getter du Client source
	Client* getDestinataire();						// Getter du Client destinataire
	list<CommandeCookie> getListeCommandeCookies();	// Getter de la Liste des Cookies Commandés
	
	void setSource(Client*);						// Setter du Client source
	void setDestinaire(Client*);					// setter du Client destinataire

	void AjouterCookie(string, short int);			// Ajouter une quantité d’un Cookie
	void RetirerCookie(string, short int);			// Retirer une quantié d’un Cookie
	void ViderCookies();							// Retirer tous les cookies de cette Commande

	void AfficherCommande();						// Afficher toutes les informations de cette Commande

};

