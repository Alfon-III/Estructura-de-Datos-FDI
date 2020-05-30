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

struct infoDeporte {
    string deporte;
    int apuntados;
};

bool compara (infoDeporte x, infoDeporte y) {
    if (x.apuntados > y.apuntados ||(
        //Si tienen el mismo numero de miembros y x.nombre < y.nombre, a tiene prioridad sobre b
        x.apuntados == y.apuntados && x.deporte < y.deporte)) return true;

    else return false;
}

bool esMayus(string aux) {
    return (aux[0] >= 'A' && aux[0] <= 'Z');
}


bool resuelveCaso() {

    unordered_map<string, string> alumnosMap;
    unordered_map<string, int> deportesMap;

    string aux;//pues de ser un deporte o un alumno

    cin >> aux;

    if (!cin) {
        return false;
    }

    string deporte, alumno;

    //Coste lineal
    while (aux != "_FIN_") {
        if (esMayus(aux)) {
            deporte = aux;
            deportesMap[aux] = 0;
        }
        //Es un alumno que se apunta al deporte previamente indicado
        else {
            alumno = aux;

            //Si no existe el alumno, indicamos el deporte al que se apuntó
            //e incrementamos en 1 el número de alumnos apuntados a dicho deporte
            if (!alumnosMap.count(alumno)) {
                alumnosMap[alumno] = deporte ;
                deportesMap[deporte]++;
            }
            //Si el alumno ya existía pero se ha apuntado otra vez al mismo deporte
            //Es despistado
            else if (alumnosMap.count(alumno) && alumnosMap[alumno] == deporte) {
                
            }
            //Alumno inválido, se le etiqueta como basura
            else if (alumnosMap[alumno] == "BASURA") {

            }
            //Un alumno que ya estaba apunatdo a un deporte, se apunta aotro distinto
            else if (alumnosMap.count(alumno) && alumnosMap[alumno] != deporte) {
                //Se resta  del deporte que ya estuviera...
                deportesMap[alumnosMap[alumno]]--;
                //Y queda inválido
                alumnosMap[alumno] = "BASURA";
            }

        }

        cin >> aux;
        
    }

    vector<infoDeporte> sol;

    for (auto& i : deportesMap) {
        sol.push_back({i.clave, i.valor});
    }

    //Ordenamos el vector de deportes gracias a la función compara
    //Coste n log n
    sort(sol.begin(), sol.end(), compara);


    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i].deporte << " " << sol[i].apuntados << endl;
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


while(resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}