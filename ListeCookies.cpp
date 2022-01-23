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
	// Destruction des Noeuds un à un
	while (tete != nullptr) {
		courant = tete;
		tete = tete->suivant;
		delete courant;
	}
}

/**
* Méthode permettant d’augmenter le total du Cookie passé
* en paramètre s‘il existe déjà. Sinon créé et insert un nouveau Cookie
*
* Le cookie est définit en son ensemble
* @param _cookie : le Cookie
*/
void ListeCookies::Inserer(const Cookie& _cookie) {
	queue = queue->suivant = new NoeudCookie(_cookie);
}

/**
* Méthode permettant d’augmenter le total du Cookie passé 
* en paramètre s‘il existe déjà. Sinon créé et insert un nouveau Cookie
* 
* Le cookie est définit par son nom et sa quantité
* @param _nomCookie : le nom du Cookie
* @param _quantite : la quantite du Cookie
*/
void ListeCookies::Inserer(string _nomCookie, short int _quantite) {

	// Si le Cookie existe déjà
	if (Trouver(_nomCookie)) {
		// On modifie la valeur du Total de ce Cookie
		Cookie cookieCourant = this->ValeurCourante();
		cookieCourant.AugmenterTotal(_quantite);

		//Modifier la valeur dans le Noeud
		FixerValeur(cookieCourant);
	}
	// Sinon, il faut Ajouter ce nouveau Cookie
	else {
		Inserer(Cookie(_nomCookie, _quantite));
	}
}

/**
* Méthode permettant la suppression du Noeud
* @param _cookie : Un Cookie
*/
void ListeCookies::Supprimer(const Cookie& _cookie) {
	//Mettre le pointeur courant sur le Cookie a supprimer
	Trouver(_cookie); 
	// Sauvegarde du pointeur du noeud Courant
	NoeudCookie* ptemp = courant->suivant; 
	// suppression de l'élément
	courant->suivant = ptemp->suivant; 
	if (queue == ptemp)
		// C'est le dernier élément supprimé, mise à jour de Queue
		queue = courant; 
	delete ptemp;
}

/**
* Méthode permettant de réduire la quantite totale d’un cookie
* @param _nomCookie : le nom du Cookie
* @param _quantite : la quantité du cookie à réduire
*/
void ListeCookies::Reduire(string _nomCookie, short int _quantite) {
	//Mettre le pointeur courant sur le Cookie a supprimer
	if (Trouver(_nomCookie)) { 

		// Reduire la quantite de ce Cookie
		Cookie cookieCourant = this->ValeurCourante();
		cookieCourant.ReduireTotal(_quantite); 

		//Modifier la valeur dans le Noeud
		FixerValeur(cookieCourant);


		// Si cette quantite devient inférieur ou égale à 0, Supprimer le Cookie
		if (this->ValeurCourante().getTotal() <= 0) {
			Supprimer(this->ValeurCourante());
		}
	}
}

/**
* Modifier le Cookie du pointeur Courant pour le Cookie en paramètre.
* @param _cookie : le nouveau Cookie
*/
void ListeCookies::FixerValeur(const Cookie& _cookie) {
	courant->suivant->element = _cookie;
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
	// Vérifier que le courant et son suivant ne sont pas null
	return (courant != nullptr) && (courant->suivant != nullptr);
}

/**
* Méthode parcourant la liste afin de trouver le Cookie souhaité
* Si la liste possède ce Cookie, le pointeur courant sera sur le noeud correspondant et la méthode renverra true
* Sinon le pointeur courant sera sur au même emplacement que queue et la méthode renverra false
* 
* La vérification se fait sur l’ensemble du Cookie (nom et total)
* @param _cookie : un Cookie
*/
bool ListeCookies::Trouver(const Cookie& _cookie) {
	// On replace courant au début de la liste
	courant = tete; 

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
* Méthode parcourant la liste afin de trouver le Cookie souhaité
* Si la liste possède un Cookie de ce nom, le pointeur courant sera sur le noeud correspondant et la méthode renverra true
* Sinon le pointeur courant sera sur au même emplacement que queue et la méthode renverra false
* 
* La vérification se fait que de nom
* @param _nomCookie : le nom du Cookie
*/
bool ListeCookies::Trouver(const string _nomCookie) {
	// On replace courant au début de la liste
	courant = tete; 

	// Tant que nous sommes dans la liste
	while (this->EstDansListe()) {
		// Si le Cookie est trouvé dans le noeud courant, on retourne true
		if (this->ValeurCourante().getNom() == _nomCookie) {
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

	// On se place en début de liste
	courant = tete; 

	//On parcourt tous les noeuds afin de trouver le meilleur Cookie
	while (this->EstDansListe()) {
		// Si le Cookie du Noeud Courant est mieux que le meilleur Cookie : remplacer les Cookies
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
bool ListeCookies::EstVide() {
	return tete->suivant == nullptr;
}


void FixerTete();
void FixerQueue();
void Precedent();
void Suivant();