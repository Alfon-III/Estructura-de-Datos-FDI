//A74
//Alfonso Tercero López

#include <iostream>
#include <fstream>
#include <string>
#include"parque.h"

using namespace std;


bool resuelveCaso() {

    int n;
    string op, eco, especie;

    std::cin >> op;
    if (!std::cin)
        return false;

    Parque parque;

    while (op != "FIN") {
        try {
            if (op == "an_ecosistema") {
                cin >> eco;
                parque.an_ecosistema(eco);
            }
            else if ("an_ejemplares") {
                cin >> eco >> especie >> n;
                parque.an_ejemplares(eco, especie, n);
            }
            else if ("lista_especies_ecosistema") {
                cin >> eco >> n;
                list<string> aux = parque.lista_especies_ecosistema(eco, n);
            }
            else if ("numero_ejemplares_en_ecosistema") {
                cin >> eco >> especie;
                cout << parque.numero_ejemplares_en_ecosistema(eco, especie) << endl;
            }
            else if ("lista_especies_parque") {
                list<string> aux = parque.lista_especies_parque();
            }
            else if ("numero_ejemplares_en_parque") {
                cin >> especie;
                cout << parque.numero_ejemplares_en_parque(especie);
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