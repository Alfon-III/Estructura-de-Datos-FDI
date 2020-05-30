// Alfonso Tercero López
// A74

#include "minimo.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

template <class T>
T minimo(bintree<T> arbol) {

    T Left, Right;
    //Si es una hoja, la retorna
    if (arbol.left().empty() && arbol.right().empty()) {
        return arbol.root();
    }
    else if (!arbol.left().empty() && arbol.right().empty()) {
        Left = minimo(arbol.left());
        return min(arbol.root(), Left);
    }
    else if (arbol.left().empty() && !arbol.right().empty()) {
        Right = minimo(arbol.right());
        return min(arbol.root(), Right);
    }
    else {
        Left = minimo(arbol.left());
        Right = minimo(arbol.right());
        if (min(Left, Right) < arbol.root()) {
            return min(Left, Right);
        }
        return arbol.root();

    }
}

bool resuelveCaso() {
    char tipo;
    string marca = "#";
    cin >> tipo;
    if (!cin)
        return false;

    if (tipo == 'N') {
        arbolMinimo<int> arbolNum = leer(-1);
        cout << arbolNum.calculaMin() << endl;

    }
    if (tipo == 'P') {
        arbolMinimo<string> arbolLetra = leer(marca);
        cout << arbolLetra.calculaMin() << endl;
    }

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}