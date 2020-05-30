//A74
//Alfonso Tercero López

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "carnet2.h"

using namespace std;


bool resuelveCaso() {

    string op, dni;
    int puntos;

    std::cin >> op;
    if (!std::cin)
        return false;

    Carnet carnet;

    while(op != "FIN") {
        try {
            if (op == "nuevo") {
                cin >> dni;
                carnet.nuevo(dni);
            }
            else if (op == "quitar") {
                cin >> dni >> puntos;
                carnet.quitar(dni, puntos);
            }
            else if (op == "consultar") {
                cin >> dni;
                int aux = carnet.consultar(dni);
                cout << "Puntos de " << dni << ": " << aux << endl;
            }
            else if (op == "cuantos_con_puntos") {
                cin >> puntos;
                int aux = carnet.cuantos_con_puntos(puntos);
                cout << "Con " << puntos << " puntos hay " << aux << endl;
            }
            else if (op == "recuperar") {
                cin >> dni >> puntos;
                carnet.recuperar(dni, puntos);
            }
            else if(op == "lista_por_puntos"){
                cin >> puntos;
                list<string> aux = carnet.lista_por_puntos(puntos);

                cout << "Tienen " << puntos << " puntos:";

                for (string dni : aux)
                    cout << " " << dni;

                cout << endl;
            }
        }
        catch (domain_error fallo) {
            cout << "ERROR: "<< fallo.what() << endl;
        }

        cin >> op;

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

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

}