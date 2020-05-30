// Alfonso Tercero López
// A74

#include "bintree_eda.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct info {
    bool correcto = true;
    int gen;
};


info resuelve(bintree<int> arbol) {

    if (arbol.empty()) {
        return { true, 0 };
    }
    //Hay un arbol que tiene hijo derecho pero no izquierdo
    if (arbol.left().empty() && !arbol.right().empty()) {
        return { false, 0 };
    }

    info L = resuelve(arbol.left());
    info R = resuelve(arbol.right());

    //cout << arbol.left().root() << " " << arbol.right().root() << endl;

    if (L.gen == 0) {
        return {
            true,
            max(L.gen, R.gen) + 1,
        };
    }

    if (R.gen == 0) {
        return{
            ((arbol.root() >= arbol.left().root() + 18) &&
             (R.correcto && L.correcto)),
            max(L.gen, R.gen) + 1,
        };
    }

    //Dos hijos
    return{
        ((arbol.root() >= arbol.left().root() + 18) && //La edad de los hijos es menor a la del padre por 18 años
        (arbol.root() >= arbol.right().root() + 18) &&
        (arbol.left().root() - 2 >= arbol.right().root()) && //Los hijos se han de llevar como minimo 2 años
        (R.correcto && L.correcto)),
        max(L.gen, R.gen) + 1
    };

}

void resuelveCaso() {

    bintree<int> arbol = leerArbol(-1);
    
    info sol = resuelve(arbol);

    if (sol.correcto) {
        cout << "SI " << sol.gen << endl;
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