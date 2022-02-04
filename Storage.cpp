#include "Storage.h"
#include <iostream>
#include <fstream>
using namespace std;


std::ifstream entree; //fichier d'entrée

//Lecture de la liste Presidents_Clients
void Storage::liste_clients(){
	
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

void Storage::liste_commandes() {

	ifstream fin("Files/PRESIDENTS_COMMANDES.txt"); //Lecture
	cout << "Contenu du fichier : \n";
	char co;
	while (fin.get(co))
		cout << co;

	cout << "\n **** Fin du fichier. **** \n";

	fin.close();
}

void Storage::liste_transactions() {

	ifstream fin("Files/PRESIDENTS_TRANSACTIONS.txt"); //Lecture
	cout << "Contenu du fichier : \n";
	
	string source;
	string destination;
	string achat;

	while (fin >> source) {
		fin >> destination;
		while (fin >> achat && achat != "&") { 
			//Il faut séparer achat pour avoir le nom du cookie et la quantité
			achat
		}
		cout << nom + "\n";

	cout << "\n **** Fin du fichier. **** \n";

	fin.close();
}
