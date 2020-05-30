// Alfonso Tercero López
// A74

#include "bintree_eda.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

/*
    L = left tree
    R = Right tree
*/


bool simetrico(bintree<char> L, bintree<char> R){
    
    if (L.empty() && R.empty()) return true;
    else if (L.empty() && !R.empty()) return false;
    else if (!L.empty() && R.empty()) return false;
    //Si ambos arboles tienen información, repetimos recursión para ver si sus nodos hijos siguen cumpliendos
    else {
        return ( simetrico(L.left(), R.right()) &&  simetrico(L.right(), R.left())  );
    }
}


void resuelveCaso() {
    bintree<char> arbol = leerArbol('.');

    //Caso especial: arbol vacío
    if (arbol.empty()) {
        cout << "SI" << endl;
        return;
    }

    if (simetrico(arbol.left(), arbol.right())) {
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