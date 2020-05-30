// Alfonso Tercero López
// A74

#include "bintree_eda.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct info {
    int rescate;
    int excursionista;
    int max;
};


struct info explora(bintree<int> arbol) {

    struct info L = { 0,0,0 };
    struct info R = { 0,0,0 };

    if (arbol.empty()) {
        return { 0, 0, 0 };
    }

    else if (!arbol.left().empty() && arbol.right().empty()) {
        L = explora(arbol.left());

    }
    else if (arbol.left().empty() && !arbol.right().empty()) {
        R = explora(arbol.right());
    }
    else {
        L = explora(arbol.left());
        R = explora(arbol.right());
    }

    if (L.rescate + R.rescate == 0 && arbol.root() != 0) {
        return{
            L.rescate + R.rescate + 1,
            L.excursionista + R.excursionista + arbol.root(),
            max({L.excursionista, R.excursionista}) + arbol.root()
        };
    }
    //Ya tenemos un rescatador en esta rama o no hay excursionistas, retornamos los resultados encontrados

    else{
        //cout << L.excursionista << " " << R.excursionista <<" "<<arbol.root()<< endl;
        return{
            L.rescate + R.rescate,
            max({L.excursionista, R.excursionista}) + arbol.root(),
            max({L.excursionista, R.excursionista}) + arbol.root()
        };
    }

}


void resuelveCaso() {

    bintree<int> arbol = leerArbol(-1);
    info sol = explora(arbol);
    cout << sol.rescate << " " << sol.max << endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}