// Alfonso Tercero López
// A74

#include "bintree_eda.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int const NAV = 3;

struct info {
    int caudal;
    int nav;
};


info numNavegables(bintree<int> const &arbol){
    

    if (arbol.empty()) {//Arbol vacío
        return {0,0};
    }
    if (arbol.left().empty() && arbol.right().empty()) {//Es hoja
        return { 1, 0 };
    }

    info L, R;
    int caudalTotal, navegables;

    L = numNavegables(arbol.left());
    R = numNavegables(arbol.right());
    
    caudalTotal = L.caudal + R.caudal - arbol.root();
    
    if (caudalTotal < 0) {
        caudalTotal = 0;
    }
    navegables = L.nav + R.nav;

    if (caudalTotal >= NAV) {
        navegables++;
    }

    return { caudalTotal, navegables };

    
}


//Hay que tener cuidado con que "la desembocadura" del río (la raíz del árbol) 
//no cuente como caudal navegable en caso que la suma de L y R pueda ser navegable
int resuelve(bintree<int> arbol) {

    info sol= numNavegables(arbol);
    if (sol.caudal >= NAV ) {
        return sol.nav - 1;
    }
    else {
        return sol.nav;
    }
}


void resuelveCaso() {
    bintree<int> arbol = leerArbol(-1);
    cout << resuelve(arbol) << endl;

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