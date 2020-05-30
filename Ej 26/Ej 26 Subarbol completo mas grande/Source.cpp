// Alfonso Tercero López
// A74

#include "bintree_eda.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct info {
    int max;//Mayor subarbol completo encontrado
    int corta;//Nivel del subarbol completo actual
};

info resuelve(bintree<char> const& arbol) {
    if (arbol.empty()) {
        return { 0 , 0 };
    }

    info L, R;
    if (arbol.left().empty() && arbol.right().empty()) {
        return { 1, 1 };
    }

    //Si HAy un arama vacía, el nivel de ese árbol pasa a ser 1 (pues ya no es completo) 
    else if (!arbol.left().empty() && arbol.right().empty()) {
        L = resuelve(arbol.left());
        return { L.max, 1};

    }
    else if (arbol.left().empty() && !arbol.right().empty()) {
        R = resuelve(arbol.right());
        return { R.max, 1};
    }

    else {
        L = resuelve(arbol.left());
        R = resuelve(arbol.right());

        if (min(L.corta, R.corta)  > max(L.max, R.max)) {
            return { min(L.corta ,R.corta) + 1, min(L.corta, R.corta) + 1 };
        }
        else {
            return { max(L.max, R.max), min(L.corta, R.corta) + 1 };
        }

    }
}

void resuelveCaso() {
    bintree<char> arbol = leerArbol('.');
    
    cout << resuelve(arbol).max << endl;

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