// Alfonso Tercero López
// A74

#include "bintree_eda.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct info {
    int arbol;
    int rama;
    int max;
};


struct info diametro(bintree<char> arbol) {

    struct info LeftRama = { 0,0,0 };
    struct info RightRama = { 0,0,0 };

    if (arbol.empty()) {
        return { 0, 0, 0 };
    }

    else if (!arbol.left().empty() && arbol.right().empty()) {
        LeftRama = diametro(arbol.left());
        
    }
    else if (arbol.left().empty() && !arbol.right().empty()) {
        RightRama = diametro(arbol.right());
    }
    else {
        LeftRama = diametro(arbol.left());
        RightRama = diametro(arbol.right());
    }

    //cout << LeftRama.rama + RightRama.rama + 1 << " " << max(LeftRama.rama, RightRama.rama) + 1 << " " << (max(LeftRama.rama + RightRama.rama + 1, max(LeftRama.rama, RightRama.rama) + 1)) << endl;

    return{
        LeftRama.rama + RightRama.rama + 1,
        max(LeftRama.rama, RightRama.rama) + 1,
        max({LeftRama.rama + RightRama.rama + 1, (max(LeftRama.rama, RightRama.rama) + 1), LeftRama.max, RightRama.max})
    };
}

/*Para obtener el máximo, selecciono el nodo en el cual tiene la mayor rama o la suma de dos ramas en cualquier nodo, por ello he de hacer 4 comparaciones
    -Mayor rama
    -Mayor suma de ramas (Esto es, la suma de la rama más larga izquierda y derecha)
    -Mayor suma de ramas en el nodo derecho
    -Mayor suma de ramas en el nodo izquierdo
*/

void resuelveCaso() {

    bintree<char> arbol = leerArbol('.');
    cout << diametro(arbol).max << endl;

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