#include "Cookie.h"

/**
* Constructeur de Cookie sans paramètre
*/
Cookie::Cookie() : nom(""), total(0) {}

/**
* Constructeur de Cookie
* @param _nomCookie : le nom du Cookie
*/
Cookie::Cookie(string _nomCookie) : nom(_nomCookie), total(0) {}
/**
* Constructeur de Cookie
* @param _nomCookie :  le nom du Cookie
* @param _quantite :  la quantite de ce cookie
*/
Cookie::Cookie(string _nomCookie,short int _quantite) : nom(_nomCookie), total(_quantite) {}

/**
* Destructeur de Cookie
*/
Cookie::~Cookie() {}

/**
* Getter de Nom
* @return le nom de ce Cookie
*/
string Cookie::getNom() { return this->nom; }

/**
* Getter de Total
* @return le total de ce Cookie
*/
short int Cookie::getTotal() { return this->total; }

/**
* Setter de Nom
* @param  _nomCookie : le nom du Cookie
*/
void Cookie::setNom(string _nomCookie) { this->nom = _nomCookie; }

/**
* Méthode permettant d’augmenter le Total
* @param _ajout : short int
*/
void Cookie::AugmenterTotal(short int _ajout) { this->total += _ajout; }

/**
* Méthode permettant de réduire le Total
* @param _retrait : short int
*/
void Cookie::ReduireTotal(short int _retrait) { this->total -= _retrait; }

/**
* Méthode comparant deux Cookies
* @param _cookie : un second Cookie
* @return true si les deux Cookies ont un nom et un total identiques, false sinon
*/
bool Cookie::EstEquivalent(Cookie _cookie) {
	return (_cookie.getNom() == this->nom) && (_cookie.getTotal() == this->total);
}
