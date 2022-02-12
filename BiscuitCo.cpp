#include "BiscuitCo.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

BiscuitCo::BiscuitCo() {
	cout << "Construction BiscuitCo sans paramètre" << endl;
	// Initialisation de la liste des cookies
	this->teteCookie = this->queueCookie = this->courantCookie = new Cookie();
}

BiscuitCo::~BiscuitCo() {
	cout << "Destruction BiscuitCo" << endl;
}

/** 
* Ajouter une commande au client indiqué, 
* Modifier les informations sur les cookies achetés
* @param _client : le client 
* @param _commande : la commande à ajouter
*/
void BiscuitCo::ajouterCommande(string _nomClient, Commande& _commande) {

	// Mettre le pointeur sur le bon client
	/*if(this->trouver(_nomClient)) {*/

		// Inserer la commande dans la liste des commandes du client
		/*this->clientCourant().insererCommande(_commande);*/


		// Ajouter les informations des achats de cette commande à la liste des cookies
	for (_commande.fixerTete(); _commande.estDansListe(); _commande.suivant()) {
		Achat* cookie = _commande.achatCourant();
		string nomCookie = cookie->nomCookie;
		short int quantiteCookie = cookie->quantiteCookie;
		delete cookie;

		/*// Insertion des données côté liste des Cookies*/

	}

	/* } else { // endif */
		cout << "Le client "+ _nomClient + "ne fait pas partie des membres enregistrés." << endl; 
		cout << "La commande n’a pas été sauvegardée." << endl;
	/* } // endelse */
}

//void supprimerCommande(string _nomClient, Commande* _commande) {
//	// Mettre le pointeur sur le bon client
//	/*if(this->trouver(_nomClient)) {*/
//
//		
//		/*// Suppression des données côté liste de Cookies*/
//
//	/* } else { // endif */
//	cout << "Le client " + _nomClient + "ne fait pas partie des membres enregistrés." << endl;
//	cout << "Aucune action n’a été effectuée." << endl;
//	/* } // endelse */
//}


bool BiscuitCo::trouverClient(string _nomClient) {

	
	for (fixerTeteClient(); estDansListeClient(); clientSuivant()) {
		Client* temp = clientCourant();
		if (temp->nom == _nomClient) {
			return true;
		}
	}
	return false;

	
}

// Transporte le pointeur courant à la tête de la liste
// Code provenant du cours
void BiscuitCo::fixerTeteClient() {
	courantClient = teteClient;

}

// Return true si le pointeur courant est à l’intérieur de la liste
// Code provenant du cours
bool BiscuitCo::estDansListeClient() const {
	return (courantClient != nullptr) && this->courantClient-> clientSuivant != nullptr;
}

// Transporte le pointeur courant au cookie suivant dans la liste
// Code provenant du cours
void BiscuitCo::clientSuivant() {
	if (courantClient != nullptr)
		courantClient = courantClient->clientSuivant;
}

bool BiscuitCo::trouverCookie(string _nomCookie) {

	for (fixerTeteCookie(); estDansListeCookie(); cookieSuivant()) {
		Cookie* tmp = cookieCourant();
		if (tmp->nomCookie == _nomCookie) {
			return true;
		}
	}
	return false;
}

Client* BiscuitCo::clientCourant() {

	return courantClient->clientSuivant;

}

void BiscuitCo::insererClient(string _nomClient, short int _numero, string _rue) {

	queueClient = queueClient->clientSuivant = new Client(_nomClient, _numero, _rue);

}

void BiscuitCo::supprimerClient(string _nomClient) {

	if (trouverClient(_nomClient) == true) {
		Client* courant = clientCourant();
		courantClient->clientSuivant = courant->clientSuivant;
		if (queueClient == courant) {
			queueClient = courantClient;
		}
		delete courant;

		supprimerCommande(_nomClient);
	}

}



// Return true si le pointeur courant est à l’intérieur de la liste
// Code provenant du cours
bool BiscuitCo::estDansListeCookie() const {
	return (courantCookie != nullptr) && this->courantCookie->cookieSuivant != nullptr;
}

// Transporte le pointeur courant à la tête de la liste
// Code provenant du cours
void BiscuitCo::fixerTeteCookie() {
	courantCookie = teteCookie;
}

// Transporte le pointeur courant au cookie suivant dans la liste
// Code provenant du cours
void BiscuitCo::cookieSuivant() {
	if (courantCookie != nullptr)
		courantCookie = courantCookie->cookieSuivant;
}


Cookie* BiscuitCo::cookieCourant() const {
	return this->courantCookie->cookieSuivant;
}

Cookie* BiscuitCo::meilleurCookie() {
	Cookie* meilleur = nullptr;

	for (fixerTeteCookie(); estDansListeCookie(); cookieSuivant())

	return nullptr;
}



void BiscuitCo::liste_clients() {

	ifstream fin("Files/PRESIDENTS_CLIENTS.txt"); //Lecture
	cout << "Contenu du fichier : \n";

	string nom;
	string rue;
	short int num;

	while (fin >> nom) {
		fin >> num >> rue;
		cout << nom + "\n";

		//Créer un client
	//	Client client = client(nom, numero, rue);
	//	ajouterClient(client);

	}

	cout << "\n **** Fin du fichier. **** \n";

	fin.close();
}

void BiscuitCo::liste_commandes() {

	string achat[2];
	string temp;
	string source;
	string destinataire;
	ifstream fin("Files/PRESIDENTS_COMMANDES.txt");

	string nomCookie;
	short int quantiteCookie;

	while (fin >> source){
		fin >> destinataire;
		//if (trouverClient(source) && trouverClient(destinataire)) {
			Commande* commande = new Commande(source, destinataire);

			string courant = "";

			// Si ce n'est pas & c'est que nous avons un achat
		
			fin >> courant;
			while (courant != "&") {
				// Si ce n'étais pas "&" c'était alors le nom d'un cookie.
				nomCookie = courant;
				fin >> quantiteCookie;

				commande->insererAchat(nomCookie,quantiteCookie);

				// Changer de ligne
				fin >> courant;
			}
			cout << commande->toString();

			//}
	}

}

string* BiscuitCo::split_str_to_achat(string s) {
	int i = 0;
	string res[2];
	while (s[i] != ' ') {
 		i++;
	}
	res[0] = s.substr(0, i);
	res[1] = s.substr(i + 1, s.length());

	return res;
}

//void BiscuitCo::liste_transactions() {
//
//	ifstream fin("Files/PRESIDENTS_TRANSACTIONS.txt"); //Lecture
//	cout << "Contenu du fichier : \n";
//	char co;
//	while (fin.get(co))
//		cout << co;
//	
//		cout << nom + "\n";
//
//	cout << "\n **** Fin du fichier. **** \n";
//
//	fin.close();
//}
