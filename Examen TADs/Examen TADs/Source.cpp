//A74
//Alfonso Tercero López

#include <iostream>
#include <fstream>
#include <string>
#include "farming.h"
using namespace std;


bool resuelveCaso() {

    int n;
    string op, id, plaga;

    std::cin >> op;
    if (!std::cin)
        return false;

    Farming terreno;

    while(op != "FIN") {
        try {
            if (op == "alta") {
                cin >> id >> n;
                terreno.alta(id, n);
            }
            else if (op == "datos") {
                cin >> id >> plaga >> n;
                terreno.datos(id, plaga, n);
            }
            else if (op == "fumigar") {
                vector<infoPlaga> v = terreno.fumigar();
                for (int i = 0; i < v.size(); i++) {
                    cout << "Fumigar la plaga " << v[i].plaga << " en el sector : " << v[i].id << endl;
                }

            }
            else if (op == "plagas") {
                cin >> id;

                vector<vPlaga> v = terreno.plaga(id);

                cout << "Plagas del sector " << id << ":";
                for (vPlaga aux : v) {
                    cout << " " <<aux.plaga << " " << aux.afectada;
                }
                cout << endl;
            }
            
        }
        catch (domain_error exception) {
            std::cout << exception.what() << endl;
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