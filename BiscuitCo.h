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
	short int quantiteCookie=0;
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
	Commande* commandeSuivante = nullptr;

	//Constructeur par défaut de Commande
	Commande(Commande * _suivante = nullptr) {
		teteAchat = queueAchat = courantAchat = new Achat;
		commandeSuivante = _suivante;
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
		// Destruction Achat
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
	bool estDansListeAchat() const {
		return (courantAchat != nullptr) && (courantAchat->achatSuivant != nullptr);
	}

	// Transporte le pointeur courant à la tête de la liste
	// Code provenant du cours
	void fixerTeteAchat() {
		courantAchat = teteAchat;
	}

	// Transporte le pointeur courant à l’Achat suivant dans la liste
	// Code provenant du cours
	void achatSuivant() {
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
		for (fixerTeteAchat(); estDansListeAchat();achatSuivant()) {
			resultat += achatCourant()->toString() + '\n';
		}

		// Ajout du caractère de fin de Commande
		resultat += "&";
		return resultat;
	}

};

/**
* Structure du Client et Noeud-Client
*/
struct Client {
	// Structure Client
	string nom;
	short int numero = 0;
	string rue;


	// Structure Noeud-Client
	Client* clientSuivant;

	// Liste Commande 
	Commande* teteCommande;
	Commande* queueCommande;
	Commande* courantCommande;


	// Constructeur par defaut de Client
	Client(Client * _suivant = nullptr) {
		teteCommande = queueCommande = courantCommande = new Commande;
		clientSuivant = _suivant;

	}

	/**
	* Constructeur de Client
	* @param _nom : le nom du client
	* @param _numero : le numero de rue du client
	* @param _rue : la rue du client
	* @param _suivant: pointeur vers le client suivant
	*/

	Client(string _nom, int _numero, string _rue, Client* _suivant = nullptr) {
		nom = _nom;
		numero = _numero;
		rue = _rue;
		clientSuivant = _suivant;
		teteCommande = queueCommande = courantCommande = new Commande();
	}

	//Destructeur de Client 
	~Client() {
		// Destruction Commandes
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
		// Placer le pointeur courant avant cette commande nouvellement ajoutée
		courantCommande = queueCommande;

		queueCommande = queueCommande->commandeSuivante = new Commande(_source, _destinataire);
	}

	// Supprimer une commande à la position courante
	// Code provenant du cours
	void supprimerCommande() {
		// Sauvegarde du pointeur suivant
		Commande* courant = commandeCourante();
		// Suppression de l’élément
		courantCommande->commandeSuivante = courant->commandeSuivante;

		if (queueCommande == courant) {
			// C’est le dernier élément supprimé, mise à jour de queueCommande
			queueCommande = courantCommande;
		}
		// Suppression du pointeur créé
		delete courant;		
	}

	// Methode permmante la suppression de toute les commandes d’un client
	void viderListeCommandes() {
		// On parcourt la liste et on supprime la commande courant à chaque itération
		while (teteCommande->commandeSuivante != nullptr) {
			courantCommande = teteCommande->commandeSuivante;
			courantCommande->viderListeAchats();
			teteCommande->commandeSuivante = courantCommande->commandeSuivante;
			delete courantCommande;
		}
		courantCommande = queueCommande = teteCommande;
	}

	// Transporte le pointeur courant à la tête de la liste
	// Code provenant du cours
	void fixerTeteCommande() {
		courantCommande = teteCommande;
	}

	// Return true si le pointeur courant est à l’intérieur de la liste
	// Code provenant du cours
	bool estDansListeCommande() const {
		return (courantCommande != nullptr) && courantCommande->commandeSuivante != nullptr;
	}

	// Transporte le pointeur courant à la commande suivant dans la liste
	// Code provenant du cours
	void commandeSuivante() {
		if (courantCommande != nullptr)
			courantCommande = courantCommande->commandeSuivante;
	}

	// Retourne la commande actuellement pointée
	// Code provenant du cours
	Commande* commandeCourante() const {
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
	string toStringCommandes() {
		string resultat;

		// Ajout des commandes de ce client
		for (fixerTeteCommande(); estDansListeCommande(); commandeSuivante()) {
			resultat += commandeCourante()->toString() + '\n';
		}
		return resultat;
	}

	string toString() {

		// Ajout du nom du Client source
		string resultat = nom + '\n';
		// Ajout du numero du Client destinataire
		resultat += to_string(numero) + '\n';
		// Ajout de la rue du Client destinataire
		resultat += rue + '\n';
		
		return resultat;
	}
};

/**
* Structure de Cookie et de Noeud-Cookie
*/
struct Cookie {
	// Structure Cookie
	string nomCookie;
	short int total;

	// Structure Noeud-Cookie
	Cookie* cookieSuivant;

	// Constructeur par défaut de Cookie
	Cookie() {
		this->nomCookie = "";
		this->total = 0;
		this->cookieSuivant = nullptr;
	}

	/**
	* Constructeur de Cookie
	* @param _nom : le nom du cookie
	* @param _total : le total du cookie
	* @_suivant : le cookie Suivant dans la liste chaînée
	*/
	Cookie(string _nom, short int _total=0, Cookie* _suivant = nullptr) {
		this->nomCookie = _nom;
		this->total = _total;
		this->cookieSuivant = _suivant;
	}

	// Destructeur de Cookie
	~Cookie() {}

	// Methode toString renvoyant le nom et le total
	string toString() {
		return nomCookie + " " + to_string(total);
	}
	/**
	* Méthode permettant d’augmenter le Total
	* @param _ajout : short int
	*/
	void AugmenterTotal(short int _ajout) { this->total += _ajout; }

	/**
	* Methode permettant de réduire le Total
	* @param _retrait : short int
	*/
	void ReduireTotal(short int _retrait) { this->total -= _retrait; }

};

/**
* Class BiscuitCo: objet principal du project 
* Permettant l’intégration et l’utilisation des clients, commandes, achats et cookies
*/
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

	// Clients
	bool trouverClient(string); // Trouver un client dans la liste client et retourne un false ou true
	void fixerTeteClient(); 
	bool estDansListeClient() const;
	void clientSuivant(); 
	Client* clientCourant() const; 

	void insererClient(string, short int, string); // Ajouter un nouveau client à la liste avec nom, numéro et rue
	void supprimerClient(string); // Supprime le client et ses commandes sources 
	void supprimerClientDest(string); // Supprime le client et ses commandes destinataire
	

	// Commandes
	void ajouterCommandeCookies(Commande*); // Ajouter la Commande passée en paramètre à la liste des commandes du client
	void supprimerCommandeCookies(Commande*); // Réduire le nombre de cookie de chaque type de cookie
	Commande* verifierClientsEtCreerCommande(string,string);


	// Cookies
	bool trouverCookie(string); // Trouver si le cookie existe, le pointeur cookiecourant pointera sur cookie
	void fixerTeteCookie(); 
	bool estDansListeCookie() const;
	void cookieSuivant();
	Cookie* cookieCourant() const;

	void insererCookie(string, short int); // Permet d'augmenter le nombre de cookie déjà commandé si le type de cookie existe, sinon on créer un nouveau type
	void supprimerCookie(string, short int); // Permet de supprimer le nombre de cookie dans un type

	void meilleurCookie(); // Permet d'afficher le type de cookie avec le total le plus élevé dans une commande

	// Storage
	void ouverture_clients(string); // Permet la lecture des clients
	void ouverture_commandes(string); // Permet la lecture des commandes
	void ouverture_transactions(string); // Permet la lecture des transactions

	void sauvegarde_clients(string); // Permet la sauvegarde des clients
	void sauvegarde_commandes(string); // Permet la sauvegarde des commandes
};
