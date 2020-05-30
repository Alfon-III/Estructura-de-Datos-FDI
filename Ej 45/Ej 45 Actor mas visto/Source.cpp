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
#include "hashmap_eda.h"
using namespace std;

struct infoActor {
    string nombre;
    int tiempo;

};

struct infoPeli {
    vector<infoActor> actores;
    int numEmisiones;
    int pos;
};

bool resuelveCaso() {



    int nPeli, nActores, tiempoActor;
    string nombrePeli, nombreActor;

    cin >> nPeli;

    //Nombre, tiempo
    map<string, int>actores;

    //Titulo Peli
    unordered_map<string, infoPeli> pelis;

    
    if (nPeli == 0)
        return false;


    //Registro la información de las películas y sus actores
    for (int i = 0; i < nPeli; ++i) {
        cin >> nombrePeli >> nActores;

        pelis[nombrePeli].numEmisiones = 0;
        pelis[nombrePeli].pos = 0;
        //Guardo para cada peli los actores que aparecen en ella y el tiempo que aparece
        //Inicializo el tiempo en emisión de cada actor a 0
        for (int j = 0; j < nActores; ++j) {
            cin >> nombreActor >> tiempoActor;
            pelis[nombrePeli].actores.push_back({nombreActor, tiempoActor});
            actores[nombreActor] = 0;
        }
    }

    int emisiones;
    cin >> emisiones;

    //Actualizo para las películas registradas, el numero de veces que han aparecido por pantalla

    for (int i = 0; i < emisiones; ++i) {
        cin >> nombrePeli;
        if(pelis[nombrePeli].pos == 0)
            pelis[nombrePeli].pos = i + 1;

        pelis[nombrePeli].numEmisiones++;

    }

    //Calculamos el tiempo en emisón de cada actor cuya película ha aparecido en pantalla

    auto itPeli = pelis.begin();

    //Inicializados a 0, menos la posición para que quede fuera de rango
    string nombrePeliMax = itPeli->clave;
    infoPeli peliMax = itPeli->valor;
    int  tiempoMax = 0;


    //O(nPelis * nActores)10.000 * 50 en el peor de los casos (Todos los actores aparecen en todas las películas y todas se emiten al menos una vez)
    while (itPeli != pelis.end()) {
        string titulo = itPeli->clave;
        infoPeli auxPeli = itPeli->valor;
        //en caso que no se emitiese una peli, no se itera para ahorrar iteraciones
        if (auxPeli.numEmisiones != 0) {
            if (auxPeli.numEmisiones > peliMax.numEmisiones ||
                (auxPeli.numEmisiones == peliMax.numEmisiones && auxPeli.pos > peliMax.pos)) {
                peliMax = auxPeli;
                nombrePeliMax = titulo;
            }

            //Para cada actor de esa peli, le sumamos el tiempo qeu aparece * las veces que se reproduce la película
            for (int i = 0; i < itPeli->valor.actores.size(); ++i) {
                actores[itPeli->valor.actores[i].nombre] += itPeli->valor.actores[i].tiempo * itPeli->valor.numEmisiones;

                //Calculo el tiempo maximo en pantalla de un actor
                if (tiempoMax < actores[itPeli->valor.actores[i].nombre]) {
                    tiempoMax = actores[itPeli->valor.actores[i].nombre];
                }
                    

            }
        }

        ++itPeli;
    }

    cout << peliMax.numEmisiones << " " << nombrePeliMax << endl;
    cout << tiempoMax;/*Actores que han aparecido el tiempo maximo*/
    for (auto act : actores) {
        if (act.second == tiempoMax) {
            cout << " " << act.first;
        }
    }
    cout << endl;

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}