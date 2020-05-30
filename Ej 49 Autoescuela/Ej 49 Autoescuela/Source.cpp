//A74
//Alfonso Tercero López

#include <iostream>
#include <fstream>
#include <string>
#include "autoescuela.h"

using namespace std;

bool resuelveCaso() {

    string op, alumno, profe;
    int nota;

    cin >> op;

    if (!std::cin)
        return false;

    autoescuela cole;

    while (op!="FIN") {

        try {
            if (op == "alta") {
                cin >> alumno >> profe;
                cole.alta(alumno, profe);
            }
            else if (op == "es_alumno") {
                cin >> alumno >> profe;
                if (cole.es_alumno(alumno, profe)) {
                    cout << alumno << " es alumno de " << profe << endl;
                }
                else {
                    cout << alumno << " no es alumno de " << profe << endl;
                }

            }
            else if (op == "puntuacion") {
                cin >> alumno;
                int punt = cole.puntuacion(alumno);

                cout << "Puntuacion de " << alumno << ": " << punt << endl;

            }
            else if (op == "actualizar") {
                cin >> alumno >> nota;

                cole.actualizar(alumno, nota);

            }
            else if (op == "examen") {
                cin >> profe >> nota;
                vector<string> aux = cole.examen(profe, nota);
                cout << "Alumnos de " << profe << " a examen:" << endl;
                for (int i = 0; i < aux.size(); i++) {
                    cout << aux[i] << endl;
                }

            }
            else if (op == "aprobar") {
                cin >> alumno;
                cole.aprobar(alumno);
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