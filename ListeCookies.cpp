#include "ListeCookies.h"

/**
* Constructeur de ListeCookies sans paramètre
*/
ListeCookies::ListeCookies() {
	queue = courant = tete = new NoeudCookie();
}

/**
* Destructeur de ListeCookie
*/
ListeCookies::~ListeCookies() {
	while (tete != nullptr) {
		courant = tete;
		tete = tete->suivant;
		delete courant;
	}
}

/**
* Méthode permettant d’insérer un nouveau noeud en fin de Liste Chaînée
* @param Un nouveau cookie
*/
void ListeCookies::Inserer(const Cookie& _cookie) {
	queue = queue->suivant = new NoeudCookie(_cookie);
}

/**
* Obtenir le Cookie au noeud courant
* @return un Cookie
*/
Cookie ListeCookies::ValeurCourante() const {
	return courant->suivant->element;
}

/**
* Méthode permettant de vérifier que courant cible toujours un noeud de la liste
* @return true si courant est sur un noeud de la liste, false sinon
*/
bool ListeCookies::EstDansListe() const {
	return (courant != nullptr) && (courant->suivant != nullptr);
}

/**
* Méthode parcourant la liste afin de trouver le Cookie souhaité
* Si la liste possède ce Cookie, le pointeur courant sera sur le noeud correspondant et la méthode renverra true
* Sinon le pointeur courant sera sur au même emplacement que queue et la méthode renverra false
*/
bool ListeCookies::Trouver(const Cookie& _cookie) {
	courant = tete; // On replace courant au début de la liste

	// Tant que nous sommes dans la liste
	while (this->EstDansListe()) {
		// Si le Cookie est trouvé dans le noeud courant, on retourne true
		if (this->ValeurCourante().EstEquivalent(_cookie)) {
			return true;
		}
		// Sinon on passe au noeud suivant
		else {
			courant = courant->suivant;
		}
	}
	//Si le Cookie ne fait pas partie de la liste, on retourne false
	return false;
}

/**
* Méthode permettant d’obtenir le Cookie avec le Total le plus Haut 
* @return le meilleur Cookie
*/
Cookie ListeCookies::getMeilleurCookie() {
	Cookie meilleur;
	courant = tete; // On se place en début de liste

	//On parcourt tous les noeuds afin de trouver le meilleur Cookie
	while (this->EstDansListe()) {
		// Si le Cookie du Noeud Courant est mieux que le "meilleur" Cookie, remplacer les Cookies
		if (this->ValeurCourante().getTotal() > meilleur.getTotal()) {
			meilleur = this->ValeurCourante();
		}
		// Sinon on passe au noeud suivant
		else {
			courant = courant->suivant;
		}
	}
	return meilleur;
}




// Possiblement à supprimer 

/**
* Méthode permettant de savoir si la liste est vide
* @return true si le suivant du premier noeud est videm false sinon
*/
bool ListeCookies::ListeVide() {
	return tete->suivant == nullptr;
}

/**
* Méthode permettant la suppression du Noeud
* @param Un Cookie
*/
void Supprimer(const Cookie& _cookie) {

}
void FixerTete();
void FixerQueue();
void Precedent();
void Suivant();