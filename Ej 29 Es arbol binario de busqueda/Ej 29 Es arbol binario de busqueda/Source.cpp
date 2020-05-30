// Alfonso Tercero López
// A74

#include "bintree_eda.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct info {
    int min;
    int max;
    bool cumple;
};

info resuelve(bintree<int> arbol) {
    if (arbol.empty()) {
        return{ -1, -1, true };
    }

    info L, R;
    if (arbol.left().empty() && arbol.right().empty()) {
        return { arbol.root(), arbol.root(), true };
    }
    else if (!arbol.left().empty() && arbol.right().empty()) {
        L = resuelve(arbol.left());

        if (!L.cumple) {
            return{  min(arbol.root(), L.min),  max(arbol.root(), L.max),  false};
        }
        //Si el máximo de la izquierda es menor que la raíz, cumple
        if (L.max < arbol.root()) {
            return {
                min(arbol.root(), L.min),
                max(arbol.root(), L.max),
                true
            };
        }
        else {
            return{
                min(arbol.root(), L.min),
                max(arbol.root(), L.max),
                false
            };
        }
    }
    else if (arbol.left().empty() && !arbol.right().empty()) {
        R = resuelve(arbol.right());
        if (!R.cumple) {
            return{ min(arbol.root(), R.min),  max(arbol.root(), R.max),  false };
        }
        //Si el mímimo de la izquierda es mayor que la raíz, cumple
        if (R.min > arbol.root()) {         
            return {
                min(arbol.root(), R.min),
                max(arbol.root(), R.max),
                true
            };
        }
        else {
            return{
                min(arbol.root(), R.min),
                max(arbol.root(), R.max),
                false
            };
        }
    }
   
    else {
        L = resuelve(arbol.left());
        R = resuelve(arbol.right());

        if (L.cumple && R.cumple) {
            if (L.max < arbol.root() && arbol.root() < R.min) {              
                return{
                    min(L.min, arbol.root()),
                    max(R.max, arbol.root()),
                    true
                };
            }
            else {
                return{ L.max, R.min, false };
            }
        }
        else {
            return{ L.max, R.min, false };//Los valores son basura
        }

    }
}

void resuelveCaso() {
    bintree<int> arbol = leerArbol(-1);
    if (resuelve(arbol).cumple) {
        cout << "SI" << endl;
    }
    else {
        cout << "NO" << endl;
    }

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