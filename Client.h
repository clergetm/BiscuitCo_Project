#pragma once
#include "ListeCommandes.h"
#include <string>
using namespace std;
class Client {
	string nom = "";
	short int num;
	string rue = "";
	//ListeCommandes liste;

public:
	Client();
	~Client();
	void AfficherCommandes();
	string getNom();
	//void AjouterCommande(Commande &_commande);

};

