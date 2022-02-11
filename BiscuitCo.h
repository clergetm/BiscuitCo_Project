#pragma once
#include <string>
#include <iostream>
#include "Storage.h"

using namespace std;
/**
* Structure de Achat
* Une commande est composée de plusieurs achats
* Chaque Achat modifie le total des cookies commandés
*/
struct Achat
{
	string nomCookie;
	short int quantiteCookie;
	Achat* achatSuivant;

	// Constructeur par defaut de Achat
	Achat() {
		achatSuivant = nullptr;
	};

	/**
	* Constructeur de Achat
	* @param _nomCookie : le nom du cookie
	* @param _quantiteCookie : la quantite achetée 
	* @param _suivant : pointeur vers l’achat suivant
	*/
	Achat(string _nomCookie, short int _quantiteCookie, Achat * _suivant = nullptr) {
		nomCookie = _nomCookie;
		quantiteCookie = _quantiteCookie;
		achatSuivant = _suivant;
	}
	
	// Destructeur de Achat
	~Achat() {}

	/**
	* Méthode renvoyant les informations de Achat sous forme de string
	* @return le nom du cookie suivit de sa quantité achetée
	*/
	string toString() {
		return nomCookie + " " + to_string(quantiteCookie);
	}

	/**
	* Setter de achatSuivant
	* @param un pointeur vers un autre Achat
	*/
	void setSuivant( Achat * _suivant) {
		achatSuivant = _suivant;
	}
};

/**
* Structure du Commande et Noeud-Commande
*/
struct Commande {
	// Structure Commande
	string source;
	string destinataire;

	//Liste achats
	Achat * teteAchat;
	Achat * queueAchat;
	Achat * courantAchat;
	
	// Structure Noeud-Commande
	Commande* commandeSuivante;

	//Constructeur par défaut de Commande
	Commande() {
		teteAchat = queueAchat = courantAchat = new Achat;
	}

	/**
	* Constructeur de Commande
	* @param _source : le nom du Client à la source de la Commande
	* @param _destinataire : le nom du destinataire de la Commande
	* @param _suivante : pointeur vers la Commande suivante
	*/
	Commande(string _source, string _destinataire, Commande * _suivante = nullptr) {
		source = _source;
		destinataire = _destinataire;
		commandeSuivante = _suivante;
		teteAchat = queueAchat = courantAchat = new Achat();
	}



	//Destructeur de Commande
	~Commande() {
		// Tant que la tete n’est pas vidée, on détruit l’élément suivant
		while (teteAchat != nullptr) {
			courantAchat = teteAchat;
			teteAchat = teteAchat->achatSuivant;
			delete courantAchat;
		}
	}

	/**
	* Inserer un Achat à la fin de la liste des Achats
	* @param _nomCookie : le nom du cookie
	* @param _quantiteCookie : la quantite achetée
	*/
	void insererAchat(string _nomCookie, short int _quantiteCookie) {
		queueAchat = queueAchat->achatSuivant = new Achat(_nomCookie, _quantiteCookie);
		
		// Partie avec la liste des cookies manquantes
	}

	// Supprimer un Achat à la position courante
	// Code provenant du cours
	void supprimerAchat() {
		
		// Sauvegarde du pointeur suivant
		Achat* courant = achatCourant();
		// Suppression de l’élément
		courantAchat->achatSuivant = courant->achatSuivant;

		if (queueAchat == courant) {
			// C’est le dernier élément supprimé, mise à jour de queueAchat
			queueAchat = courantAchat;
		}

		// Suppression du pointeur créé
		delete courant;

		// Partie avec la liste des cookies manquantes
	}
	
	// Supprimer tous les achats de la commande
	// Code provenant du cours
	void viderListeAchats() {

		// On parcourt la liste et on supprime l’achat courant à chaque itération
		while (teteAchat->achatSuivant != nullptr) {
			courantAchat = teteAchat->achatSuivant;
			teteAchat->achatSuivant = courantAchat->achatSuivant;
			delete courantAchat;
		}
		courantAchat = queueAchat = teteAchat;
	}


	// Return true si le pointeur courant est à l’intérieur de la liste
	// Code provenant du cours
	bool estDansListe() const {
		return (courantAchat != nullptr) && courantAchat->achatSuivant != nullptr;
	}

	// Transporte le pointeur courant à la tête de la liste
	// Code provenant du cours
	void fixerTete() {
		courantAchat = teteAchat;
	}

	// Transporte le pointeur courant à l’Achat suivant dans la liste
	// Code provenant du cours
	void suivant() {
		if (courantAchat != nullptr)
			courantAchat = courantAchat->achatSuivant;
	}

	// Retourne l’achat qui est actuellement pointé
	// Code provenant du cours
	Achat* achatCourant() const {
		return courantAchat->achatSuivant;
	}

	/**
	* Methode toString de Commande retournant toutes les informations d’une commande :
	*  - source
	*  - destinataire
	*  - toString() de chaque Achat
	*  - &
	* @return resultat : toute la commande dans un string
	*/
	string toString() {

		// Ajout du nom du Client source
		string resultat = source + '\n';
		// Ajout du nom du Client destinataire
		resultat += destinataire + '\n';


		// Ajout des achats de cette commande
		for (fixerTete(); estDansListe();suivant()) {
			resultat += achatCourant()->toString() + '\n';
		}

		// Ajout du caractère de fin de Commande
		resultat += "& \n";
		return resultat;
	}

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
	Commande* teteCommande;
	Commande* queueCommande;
	Commande* courantCommande;


	Client() {
		teteCommande = queueCommande = courantCommande = new Commande;
	}

	/**
	* Constructeur de client
	* @param _nom
	* @param _numero
	* @param _rue
	* @param _suivant: pointeur vers le client suivant
	*/

	Client(string _nom, int _numero, string _rue) {
		nom = _nom;
		numero = _numero;
		rue = _rue;
		teteCommande = queueCommande = courantCommande = new Commande();
	}

	//Destructeur de Client 
	~Client() {
		// Tant que la tete n’est pas vidée, on détruit l’élément suivant
		while (teteCommande != nullptr) {
			courantCommande = teteCommande;
			teteCommande = teteCommande->commandeSuivante;
			delete courantCommande;
		}
	}

	/**
	* Inserer une Commande à la fin de la liste des Commandes
	* @param _nomCookie : le nom du cookie
	* @param _quantiteCookie : la quantite achetée
	*/
	void insererCommande(string _source, string _destinataire) {
		queueCommande = queueCommande->commandeSuivante = new Commande(_source, _destinataire);

		
	}

	// Supprimer une commande à la position courante
	// Code provenant du cours
	void supprimerCommande() {

		// Sauvegarde du pointeur suivant
		Commande* courant = commandeCourant();
		// Suppression de l’élément
		courantCommande->commandeSuivante = courant->commandeSuivante;

		if (queueCommande == courant) {
			// C’est le dernier élément supprimé, mise à jour de queueCommande
			queueCommande = courantCommande;
		}

		// Suppression du pointeur créé
		delete courant;

		
	}

	void viderListeCommandes() {

		// On parcourt la liste et on supprime la commande courant à chaque itération
		while (teteCommande->commandeSuivante != nullptr) {
			courantCommande = teteCommande->commandeSuivante;
			teteCommande->commandeSuivante = courantCommande->commandeSuivante;
			delete courantCommande;
		}
		courantCommande = queueCommande = teteCommande;
	}


	// Return true si le pointeur courant est à l’intérieur de la liste
	// Code provenant du cours
	bool estDansListe() const {
		return (courantCommande != nullptr) && courantCommande->commandeSuivante != nullptr;
	}

	// Transporte le pointeur courant à la tête de la liste
	// Code provenant du cours
	void fixerTete() {
		courantCommande = teteCommande;
	}

	// Transporte le pointeur courant à la commande suivant dans la liste
	// Code provenant du cours
	void suivant() {
		if (courantCommande != nullptr)
			courantCommande = courantCommande->commandeSuivante;
	}

	// Retourne la commande qui est actuellement pointé
	// Code provenant du cours
	Commande* commandeCourant() const {
		return courantCommande->commandeSuivante;
	}

	/**
	* Methode toString de Client retournant toutes les informations d’un client :
	*  - nom
	*  - numero
	*  - rue
	*  - toString() de chaque Commande
	*  - &
	* @return resultat : du client dans un string
	*/
	string toString() {

		// Ajout du nom du Client source
		string resultat = nom + '\n';
		// Ajout du numero du Client destinataire
		resultat += numero + '\n';
		// Ajout de la rue du Client destinataire
		resultat += rue + '\n';

		// Ajout des commandes de ce client
		for (fixerTete(); estDansListe(); suivant()) {
			resultat += commandeCourant()->toString() + '\n';
		}

		// Ajout du caractère de fin de client
		resultat += "& \n";
		return resultat;
	}

};


/**
* Structure du Commande et Noeud-Commande
*/
struct Cookie {
	// Structure Cookie
	string nomCookie;
	short int total;

	// Structure Noeud-Cookie
	Cookie* cookieSuivant;

	Cookie() {
		this->nomCookie = "";
		this->total = 0;
		this->cookieSuivant = nullptr;
	}

	Cookie(string _nom, short int _total=0, Cookie* _suivant = nullptr) {
		this->nomCookie = _nom;
		this->total = _total;
		this->cookieSuivant = _suivant;
	}
};

class BiscuitCo
{
private:
	Client* teteClient;
	Client* queueClient;
	Client* courantClient;
	Cookie* teteCookie;
	Cookie* queueCookie;
	Cookie* courantCookie;

public:
	BiscuitCo();
	~BiscuitCo();
	bool trouverClient(string);
	void ajouterClient(string, Client&);
	void ajouterCommande(string, Commande&); // Ajouter la Commander passée en paramètre à la liste des commandes du client
	void supprimerCommande(string, Commande&);
	Client* clientCourant();
	bool trouverCookie(string);
	void fixerTeteCookie();
	bool estDansListeCookie();
	Cookie* cookieSuivant();

	void fixerTeteClient();
	bool estDansListeClient();
	Client* clientSuivant();
};
