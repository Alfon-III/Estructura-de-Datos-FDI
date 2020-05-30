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



bool resuelveCaso() {

    int N;
    cin >> N;
    if (N == 0) { return false; }

    //unordered_map<string, int>



    for (int i = 0; i < N; i++) {
        string titulo;
        cin >> titulo;
        auto& reparto = pelis[titulo].second;

        int NA;
        cin >> NA;

        string nombre;
        int tiempo;

        for (int j = 0; j < NA; j++) {
            cin >> nombre >> tiempo;
            reparto[nombre] = tiempo;

        }

        map<string, int> actores;



        //Recorremso emisiones
        int E;
        cin >> E;
        string titulo;

        for(int i = 0; i < E; i++) {
            cin >> titulo;


            

        }


    }



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