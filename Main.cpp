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

    ////Censé supprimer chocolat
    //cout << "Suppression chocolat" << endl;
    //commande1.fixerTete();
    //commande1.supprimerAchat();
    //cout << commande1.toString() << endl;

    //cout << "\n" << endl;

    //cout << "Suppression complete" << endl;
    //commande1.supprimerTousAchats();
    //cout << commande1.toString() << endl;
}

int main() {
     
    test_Achat();
    cout << "\n \n" << endl;
    test_Commande();
    system("pause");
    return 0;
}