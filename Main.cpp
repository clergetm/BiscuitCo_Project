#include <iostream>
#include "Cookie.h"
#include "ListeCookies.h"
using namespace std;

int main() {
    ListeCookies list;
    Cookie c1 = Cookie("Chocolat");
    c1.AjouterTotal(20);
    Cookie c2 = Cookie("Vanille");
    c2.AjouterTotal(10);
    Cookie c3 = Cookie("Macadam");
    c3.AjouterTotal(30);
    Cookie c4 = Cookie("DoubleChocolat");
    c4.AjouterTotal(25);

    list.Inserer(c1);
    list.Inserer(c2);
    list.Inserer(c3);
    list.Inserer(c4);

    Cookie best = list.getMeilleurCookie();
    cout << best.getNom() << " avec " << best.getTotal() << endl;
    system("pause");
    return 0;
}