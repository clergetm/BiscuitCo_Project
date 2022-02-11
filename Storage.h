#pragma once
#include "BiscuitCo.h"
#include <fstream>

class Storage
{
	private :
		BiscuitCo* entreprise;
		ifstream entree; //fichier d'entrée

	public :
		Storage(BiscuitCo*);
		~Storage();
		void liste_clients();
		void liste_commandes();
		void liste_transactions();

};

