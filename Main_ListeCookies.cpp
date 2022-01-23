#include <iostream>
#include "Cookie.h"
#include "ListeCookies.h"
using namespace std;

int main_ListeCookies() {
    // Creation d’une liste de Cookie
    ListeCookies list;

    // Ajout de 4 Cookies et 4 quantités différentes
    Cookie c1 = Cookie("Chocolat");
    c1.AugmenterTotal(20);
    Cookie c2 = Cookie("Vanille");
    c2.AugmenterTotal(10);
    Cookie c3 = Cookie("Macadam");
    c3.AugmenterTotal(30);
    Cookie c4 = Cookie("DoubleChocolat");
    c4.AugmenterTotal(25);

    list.Inserer(c1);
    list.Inserer(c2);
    list.Inserer(c3);
    list.Inserer(c4);

    // Le résultat devrait être Macadam
    Cookie best = list.getMeilleurCookie();
    cout << best.getNom() << " avec " << best.getTotal() << endl;

    system("pause");
    return 0;
}