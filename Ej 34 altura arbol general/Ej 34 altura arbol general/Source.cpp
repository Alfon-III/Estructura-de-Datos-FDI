// Alfonso Tercero López
// A74

#include "bintree_eda.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int resolver() {
    int raiz;
    std::cin >> raiz;
    if (raiz == 0) { // es un arbol vacio
        return 1;
    }
    else { // leer recursivamente los hijos
        int numNodos = 0;
        for (int i = 0; i < raiz; ++i) {
            numNodos = max(resolver(), numNodos);           
        }
        return numNodos + 1;
    }
}


void resuelveCaso() {
    cout << resolver() << endl;
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