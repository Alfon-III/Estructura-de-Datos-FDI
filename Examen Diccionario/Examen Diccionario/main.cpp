
// Tercero L�pez Alfonso 
// A74

#include <iostream>               
#include <fstream>               
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

// COMENTARIO SOBRE LA SOLUCI�N Y SU COSTE JUSTIFICADO
/*
El problema se ha resuelto con un diccionario ordenado (map) en el cual se guardar�n el n�mero de
juegos distintos como clave y un array en la cual cada k-esima vez ser� l�a posic�n donde se guarde
qu� d�a jug� un jego esa k-�sima vez, como valor.

El coste de resuelveCaso es: O(max( N * log(n), M * log(n)), que se puede simplficar en
O(max(N, M)*log(n))
siendo N, el n�mero de d�as jugados, M el n�mero de preguntas y n, el n�mero
de juegos distintos jugados por el abuelo.
    
    1. El coste de crear la el diccionario es constante

    2. El coste de instertar en la tabla es N * log(n). Siendo N el numero de noches y n, el numero de
    juegos distintos. El coste de insertar en el vector es constante.
    El coste de acceder a la tabla es O(log (n)) y se hace N veces en el bucle.

    3. O(M * log(n))
    Muy similar al caso anterior, el coste de acceder al valor de una clave del 
    diccionario es O(log n), por que el coste de acceder a la posici�n del vector
    es constante, ya que no hay que recorrerlo. La M es por el n�mero de preguntas
    que ser� el numero de veces que se recorrer� el bucle.

*/


bool resuelveCaso() {
    int N, M, k;
    string nombreJuego;

    cin >> N;
    if (!cin)
        return false;

    //1. Crear Tabla
    map<string, vector<int>> juegos;

    //2. Insertar elementos
    for (int i = 1; i <= N; ++i) {
        cin >> nombreJuego;
        juegos[nombreJuego].push_back(i);
    }

    cin >> M;

    //3. Mostrar solucion
    for (int i = 0; i < M; ++i) {
        cin >> k >> nombreJuego;

        if (juegos[nombreJuego].size() >= k) {
            cout << juegos[nombreJuego][k - 1] << endl;
        }
        else {
            cout << "NO JUEGA" << endl;
        }

    }

    cout << "---" << endl;

    return true;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
