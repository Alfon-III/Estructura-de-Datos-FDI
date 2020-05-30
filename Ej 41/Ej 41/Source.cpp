// Alfonso Tercero López
// A74

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "hashmap_eda.h"
using namespace std;

struct resultado {
    int aciertos; //Nº de AC
    int tiempo;   //Tiempo total
};

struct solucion {
    string equipo;
    int aciertos;
    int tiempo;
};

struct infoProblema {
    int intentos;
    bool resuelto;
};

bool compara(solucion x, solucion y) {
    if (x.aciertos > y.aciertos) return true;
    else if (x.aciertos == y.aciertos && x.tiempo < y.tiempo) return true;
    else if (x.aciertos == y.aciertos && x.tiempo == y.tiempo && x.equipo < y.equipo) return true;
    else return false;
}


bool resuelveCaso() {

    //Equipo, resultado
    unordered_map<string, resultado> marcador;

    //[Nombre del problema<clave>] equipo<clave> -> nº de intentos
    unordered_map<string, unordered_map<string, infoProblema>> intentos;

    string equipo, problema, juez;
    int tiempo;

    cin >> equipo;

    //Coste lineal
    while (equipo != "FIN") {
        cin >> problema >> tiempo >> juez;
        //Si no exisate el equipo, se inicializa
        if (!marcador.count(equipo)) {
            marcador[equipo].aciertos = 0;
            marcador[equipo].tiempo = 0;
        }
        //Si no existe el problema o el equipo (en intentos), se registra que inicializa
        if (!intentos.count(problema) || !intentos[problema].count(equipo)) {
            intentos[problema][equipo].intentos = 0;
            intentos[problema][equipo].resuelto = false;
        }


        //Si no ha sido aceptado anteriormente este problema, se suman los datos indicados
        if (juez == "AC" && !intentos[problema][equipo].resuelto ) {

            int tiempo_aux = 0;
            //Si ya existía, puede que lo hibiese tenido mal
            //Ya había hecho alguien el problema y además lo ha hecho este equipo
            if (intentos.count(problema) && intentos[problema].count(equipo)) {
                tiempo_aux = intentos[problema][equipo].intentos * 20;
                intentos[problema][equipo].resuelto = true;
            }
            

            marcador[equipo].aciertos++;
            marcador[equipo].tiempo += tiempo + tiempo_aux;

        }
        else {
            //Ya había hecho alguien el problema y además lo ha hecho este equipo
               intentos[problema][equipo].intentos++;
        }

        cin >> equipo;

    }

    vector<solucion> sol;

    for (auto& i : marcador) {
        sol.push_back({ i.clave, i.valor.aciertos, i.valor.tiempo });
    }

    //Ordenamos el vector de deportes gracias a la función compara
    //Coste n log n
    sort(sol.begin(), sol.end(), compara);


    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i].equipo << " " << sol[i].aciertos << " " << sol[i].tiempo << endl;
    }
    cout << "---" << endl;
    return true;

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