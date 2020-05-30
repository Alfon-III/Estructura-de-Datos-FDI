// Alfonso Tercero López
// A74

//#include "frontera.h"
#include "bintree_eda.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

//Funcion Extra
void frontera(bintree<int> const& arbol, vector<int>& v) {
    if (arbol.empty()) {
        return;
    }
    else if (arbol.left().empty() && arbol.right().empty()) {
        v.push_back(arbol.root());
    }
    else {
        frontera(arbol.left(), v);
        frontera(arbol.right(), v);
    }
}


void resuelveCaso() {

    //FronteraArbol<int> arbol = leer(-1);
    //arbol.frontera();

    bintree<int> arbol = leerArbol(-1);
    vector<int> aux;

    frontera(arbol, aux);

    for (int i = 0; i < aux.size(); i++) {
        cout << aux[i] << " ";
    }

    cout << endl;

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