#pragma once
#include <string>
#include <iostream>
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
	void supprimerAchat() {
		
		// Sauvegarde du pointeur suivant
		Achat* courant = courantAchat;
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

	void supprimerTousAchats() {
		courantAchat = teteAchat->achatSuivant;
		while (this->estDansListe()) {
			supprimerAchat();
			courantAchat = courantAchat->achatSuivant;
		}
	}


	bool estDansListe() const {
		return (courantAchat != nullptr);
	}

	void fixerTete() {
		courantAchat = teteAchat;
	}

	void suivant() {
		if (courantAchat != nullptr)
			courantAchat = courantAchat->achatSuivant;
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
		courantAchat = teteAchat->achatSuivant;
		while (this->estDansListe()) {
			resultat += courantAchat->toString() + '\n';

			courantAchat = courantAchat->achatSuivant;
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
	Commande* teteCommande, queueCommande, courantCommande;
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
private:
	Client* listeClients;
	Cookie* listeCookies;
	//Storage storage;
public:
	BiscuitCo();
	~BiscuitCo();

	// Tete Queue et Courant pour Client
	// Tete Queue et Courant pour Cookies
	// Tete Queue et Courant pour Achat

};

