// Alfonso Tercero López
// A74

#include "bintree_eda.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


//En caso de encontrar un multiplo de 7, devolveremos
//Dicho numero y el nivel donde lo encontramos (empezando en 1)
struct info {
    int valor;
    int nivel;
};


bool esPrimo(int x) {
    for (int i = 2; i <= x / 2; ++i) {
        if (x % i == 0)
            return false;
    }
    return true;
}


struct info resuelve(bintree<int>const & arbol, int nivel) {
    //Lo primero que se comprueba es si se puede acceder a esta rama del arbol
    //Ya sea por no ser prima o no estar vacía
    if (arbol.empty() || esPrimo(arbol.root())) {
        return{ -1, -1 };
    }

    //Si encontramos un multiplo de 7 lo retornamos inmediatamente pues si seguimos 
    //avanzando en el arbol, el nivel será mayor
    if (arbol.root() % 7 == 0) {
        return { arbol.root(), nivel };
    }
    else if (arbol.left().empty() && arbol.right().empty()) {
        return { arbol.root(), nivel + 1 };
    }
    else if (!arbol.left().empty() && arbol.right().empty()) {
        return resuelve(arbol.left(), nivel + 1);
    }
    else if (arbol.left().empty() && !arbol.right().empty()) {
        return  resuelve(arbol.right(), nivel + 1);
    }
    else {
        info L, R;
        L = resuelve(arbol.left(), nivel + 1);
        R = resuelve(arbol.right(), nivel + 1); 

        //En caso que ambos valores sean válidos, retornamos el de menor nivel
        //Dando prioridad al de la izquierda
        if (L.valor != -1 && R.valor != -1) {
            if (L.nivel <= R.nivel) {
                return L;
            }
            else {
                return R;
            }
        }
        else if (L.valor != -1) {
            return L;
        }
        else {
            return R;
        }
    }
}

void resuelveCaso() {
    bintree<int> arbol = leerArbol(-1);

    info aux = resuelve(arbol, 1);
    if (aux.valor == -1) {
        cout << "NO HAY" << endl;
    }
    else {
        cout << aux.valor << " " << aux.nivel << endl;
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