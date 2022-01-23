#include <iostream>
#include "Cookie.h"
#include "ListeCookies.h"
#include "Commande.h"
#include "Client.h"
using namespace std;

int main_commande() {
    ListeCookies list;
    Cookie c1 = Cookie("Chocolat");
    c1.AugmenterTotal(20);
    Cookie c2 = Cookie("Vanille");
    c2.AugmenterTotal(10);

    list.Inserer(c1);
    list.Inserer(c2);

    Client bob;
    Client alice;

    Client* p_bob = &bob;
    Client* p_alice = &alice;
    ListeCookies* p_list = &list;
    Commande CommandeBtoA = Commande(p_bob, p_alice, p_list);
    //La Commande est constitué de 4 Cookies Vanille
    CommandeBtoA.AjouterCookie("Vanille", 4);

    // On reduit le nombre de Cookie Chocolat, faisant du Cookie Vanille le "meilleurCookie"
    CommandeBtoA.RetirerCookie("Chocolat", 20);

    Cookie best = list.getMeilleurCookie();
    cout << best.getNom() << " avec " << best.getTotal() << endl;
    system("pause");
    return 0;
}