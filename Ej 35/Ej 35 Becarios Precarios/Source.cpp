// Alfonso Tercero López
// A74

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


inline int resolver(int k, int nivel) {
    int raiz;
    std::cin >> raiz;
    if (raiz == 0) { // es un arbol vacio/hoja
        if (k <= nivel)
            return 1;
        else
            return 0;
    }
    else { // leer recursivamente los hijos
        int numNodos = 0;
        for (int i = 0; i < raiz; ++i)   
            numNodos += resolver(k, nivel + 1);
        return numNodos;
    }
}

bool resuelveCaso() {
    // leer los datos de la entrada

    int K;
    cin >> K;
    if (!std::cin)
        return false;

    cout << resolver(K, 0) << endl;

    // escribir sol


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