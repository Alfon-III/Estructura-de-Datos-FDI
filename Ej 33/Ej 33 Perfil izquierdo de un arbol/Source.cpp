// Alfonso Tercero López
// A74

#include "bintree_eda.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct info {
    int nivel;
    bintree<int> arbol;
};

vector<int> levelorder(bintree<int>& arbol) {
    vector<int> level;
    int nivel = 1;
    int max = 0;
    if (!arbol.empty()) {
        queue<info> pendientes;
        pendientes.push({nivel, arbol});

        info aux;
        while (!pendientes.empty()) {
            aux = pendientes.front();
            pendientes.pop();
            if (aux.nivel > max) {
                max++;
                level.push_back(aux.arbol.root());
            }
            
            if (!aux.arbol.left().empty()) {
                pendientes.push({ aux.nivel + 1, aux.arbol.left() });
            }
            if (!aux.arbol.right().empty()) {
                pendientes.push({ aux.nivel + 1, aux.arbol.right() });
            }
        }
    }
    return level;

}

void resuelveCaso() {
    bintree<int> arbol = leerArbol(-1);
    vector<int> sol = levelorder(arbol);

    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
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