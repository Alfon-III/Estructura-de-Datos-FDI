// Alfonso Tercero López
// A74

#include "bintree_eda.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct info {
    bool cumple;
    //Mayor nivel encontrado a la derecha y la izquierda
    int I;
    int D;
};

struct info resuelve(bintree<char> const& arbol, int nivel) {
    if (arbol.empty()) {
        return { true, nivel, nivel };
    }


    if (arbol.left().empty() && arbol.right().empty()) {
        return { true, nivel, nivel };
    }
    else if (!arbol.left().empty() && arbol.right().empty()) {
        info L = resuelve(arbol.left(), nivel + 1);
        return{ L.cumple, max(L.I, L.D), nivel };
    }
    //Si solo tengo una rama derecha atumáticamente el arbol no puede ser completo o semi
    else if (arbol.left().empty() && !arbol.right().empty()) {
        return { false, nivel, nivel };
    }
    else {
        info L = resuelve(arbol.left(), nivel + 1);
        info R = resuelve(arbol.right(), nivel + 1);

        if (!L.cumple || !R.cumple) {
            return { false, nivel, nivel };
        }
        //Si el mayor nivel de la  izquierda es menor que el mayor de la derecha
        //O la difewrencia entre una hoja y otra se llevan más de 1 nivel
        //El arbol estará mal
        if (max(L.I, L.D) < max(R.I, R.D) || abs(max(L.I, L.D) - max(R.I, R.D)) > 1) {
            return { false, nivel, nivel };
        }
        else{
            return{ true, max(L.I, L.D) , max(R.I, R.D) };
        }
    }
}

void resuelveCaso() {
    bintree<char> arbol = leerArbol('.');

    info sol = resuelve(arbol, 1);

    if (sol.cumple) {
        if (sol.I == sol.D) {
            cout << "COMPLETO" << endl;
        }
        else {
            cout << "SEMICOMPLETO" << endl;
        }
    }
    else {
        cout << "NADA" << endl;
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