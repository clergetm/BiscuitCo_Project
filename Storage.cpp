#include "Storage.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Storage::Storage(BiscuitCo* _entreprise) {
	entreprise = _entreprise;
}

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

		string achat[2];
		string temp;
		string source;
		string destinataire;
		ifstream fin("Files/PRESIDENTS_COMMANDES.txt");

		while (fin >> source){
			fin >> destinataire;
			if (entreprise->trouverClient(source) && entreprise->trouverClient(destinataire)) {
				Commande* commande = new Commande(source, destinataire);

				string courant = "";
				while ( courant != "&") {
					//Achat
					//Lire nom
					short count = 0;
					while (getline(fin, courant, ' ')) {
						achat[count] = courant;
						count++;
					}
					commande->insererAchat(achat[0],stoi(achat[1]));
					}
				cout << "toto" << endl;
				cout << commande->toString();

				}
		}
				
}


//void Storage::liste_transactions() {
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
