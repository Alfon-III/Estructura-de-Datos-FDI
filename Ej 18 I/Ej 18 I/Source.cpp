// Alfonso Tercero López
// A74

#include "bintree_eda.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta


struct info {
    int nodos;
    int hojas;
    int altura;
};

info resuelve(bintree<char>const& arbol) {

    info auxR, auxL;

    if (arbol.empty()) {
        return {0, 0, 0};
    }

    auxR = resuelve(arbol.right());
    auxL = resuelve(arbol.left());
    
    //Estoy en una hoja
    if (auxL.hojas + auxR.hojas == 0) {
        return { auxR.nodos + auxL.nodos + 1, 1, max(auxR.altura, auxL.altura) + 1 };
    }
    else {
        return { auxR.nodos + auxL.nodos + 1, //Nodos
                 auxL.hojas + auxR.hojas, //Hojas
                 max(auxR.altura, auxL.altura) + 1 };//Altura
    }

}

info infoArbol(bintree<char> arbol) {
    info sol; sol.altura = 0; sol.hojas = 0; sol.nodos = 0;
    
    if (!arbol.empty()) {
        sol = resuelve(arbol);
    }
    return sol;
}

void resuelveCaso() {


    bintree<char> arbol = leerArbol('.');

    info sol = infoArbol(arbol);

    cout << sol.nodos << " " << sol.hojas << " " << sol.altura << endl;

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