//A74
//Alfonso Tercero López

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;


bool resuelveCaso() {

    unordered_map <string, vector<string>> avisos;

    int N, M, sensor;
    string aviso, hora;


    //Avisos
    std::cin >> N;
    if (!std::cin)
        return false;

    //Consultas
    cin >> M;

    for (int i = 0; i < N; ++i) {
        cin >> aviso >> hora;

        avisos[aviso].push_back(hora);

    }
    
    for (int i = 0; i < M; i++) {
        cin >> aviso >> sensor;
        auto it = avisos.find(aviso);

        if (it == avisos.end()) {
            cout << "-- ";
        }
        else {
            if (it->second.size() <= sensor - 1) {
                cout << "-- ";
            }
            else {
                cout << it->second[sensor - 1] << " ";
            }
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
    //system("PAUSE");
#endif

}