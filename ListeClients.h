#pragma once
#include "Client.h"

class ListeClients{
 /*   Noeud<Client>* tete;
    Noeud<Client>* courant;
    Noeud<Client>* queue;*/
public:
    ListeClients();
    ~ListeClients();
    
    void Inserer(const Client& client);
    void Supprimer(const Client&);
    Client ValeurCourante();

    void Precedent();
    void Suivant();
    void AllerTete();
    void AllerQueue();

    bool EstVide();
    bool VerifierClient(const Client&);

};

