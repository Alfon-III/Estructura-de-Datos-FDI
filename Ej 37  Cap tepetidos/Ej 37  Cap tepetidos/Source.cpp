// Alfonso Tercero López
// A74

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <map>
using namespace std;


void resuelveCaso() {

    long long int nCap, cap;
    int primer_dia, dia_seguidos, max;
    dia_seguidos = max = 0;
    primer_dia = 1;//Primer dia de la "racha" de capítulos distintos

    cin >> nCap;


    map<int, int> tabla;//capitulo, dia

  
    for (int i = 1; i <= nCap; i++) {
        cin >> cap;

        if (tabla[cap] >= primer_dia) {
            primer_dia = tabla[cap] + 1;
            //Dias seguidos = el dia actual - el día desde la última vez que se repitió el capítulo
            dia_seguidos = i - tabla[cap];

            tabla[cap] = i;

        }
        else {
            dia_seguidos++;
            if (dia_seguidos > max) {
                max = dia_seguidos;
            }
            tabla[cap] = i;
        }
    }
    cout << max << endl;
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