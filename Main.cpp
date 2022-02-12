#include <iostream>
#include <string>
#include "BiscuitCo.h"
using namespace std;

void test_Achat() {
    cout << "##########TEST ACHAT##########" << endl;
    Achat achat2 = Achat("vanille", 22);
    Achat achat1 = Achat("chocolat", 21,&achat2);

    cout << achat1.toString() << endl;
    // Censé afficher achat2
    cout << achat1.achatSuivant->toString() << endl;

}

void test_Commande() {
    cout << "##########TEST COMMANDE##########" << endl;
    Commande commande1 = Commande("alice", "bob");
    commande1.insererAchat("chocolat", 21);
    commande1.insererAchat("vanille", 22);
    commande1.insererAchat("caramel", 23);

    cout << "Commande 3 achats" << endl;
    cout << commande1.toString() << endl;

    /*cout << "Test for" << endl;
    for (commande1.fixerTete(); commande1.estDansListe();commande1.suivant()) {
        cout << commande1.achatCourant()->toString() << endl;
    }*/

    cout << "\n" << endl;

    ////Censé supprimer chocolat
    commande1.fixerTeteAchat();
    cout << "Suppression chocolat" << endl;
    commande1.supprimerAchat();
    //cout << "Suppression vanille" << endl;
    //commande1.supprimerAchat();
    //cout << commande1.toString() << endl;

    cout << "\n" << endl;

    ////Censé supprimer tous les achats
    cout << "Suppression complete" << endl;
    commande1.viderListeAchats();
    cout << commande1.toString() << endl;
}

void test_liste_clients() {
    BiscuitCo entreprise;
    entreprise.liste_clients();

    for (entreprise.fixerTeteClient(); entreprise.estDansListeClient(); entreprise.clientSuivant()) {
        cout << entreprise.clientCourant()->toString() << endl;
    }
}

void test_liste_commandes() {
    BiscuitCo entreprise;
    entreprise.liste_clients();
    entreprise.liste_commandes();

    for (entreprise.fixerTeteClient(); entreprise.estDansListeClient(); entreprise.clientSuivant()) {
        cout << entreprise.clientCourant()->toString() << endl;
    }
}

void test_get_meilleur_Cookie() {
    BiscuitCo entreprise;
    entreprise.liste_clients();
    entreprise.liste_commandes();

    entreprise.meilleurCookie();

    entreprise.supprimerCookie("chocolat", 10350);
    entreprise.trouverCookie("chocolat");
    cout << entreprise.cookieCourant()->toString() << endl;

    entreprise.meilleurCookie();


}

int main() {
     
   //test_Achat();
   // 
   //cout << "\n \n" << endl;
   //test_Commande();
   // 
   //cout << "\n \n" << endl;
   //test_liste_clients();
   // 
   //cout << "\n \n" << endl;
   //test_liste_commandes();
    test_get_meilleur_Cookie();
    //BiscuitCo entreprise;
    //entreprise.liste_clients();
    //entreprise.liste_commandes();
    //entreprise.liste_transactions();
       


    system("pause");
    return 0;
}