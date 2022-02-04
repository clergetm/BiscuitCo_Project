#include "BiscuitCo.h"
#include <string>
#include <iostream>
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
		else {
			return false;
		}

	}

	
}

bool BiscuitCo::trouverCookie(string _nomCookie) {

	for (fixerTeteCookie(); estDansListeCookie(); cookieSuivant()) {
		Cookie* tmp = CookieCourant();
		if (tmp->nomCookie == _nomCookie) {
			return true;
		}
	}
	return false;
}
