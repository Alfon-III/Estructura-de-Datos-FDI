//A74
//Alfonso Tercero López

#include <iostream>
#include <fstream>
#include <string>
#include "ipod.h"
using namespace std;


bool resuelveCaso() {

    string op, song, autor;
    int time, n;

    cin >> op;
    if (!std::cin)
        return false;

    ipod ipod;

    while(op != "FIN") {
        try {
            if (op == "addSong") {
                cin >> song >> autor >> time;
                ipod.addSong(song, autor, time);
            }
            else if (op == "addToPlaylist") {
                cin >> song;
                ipod.addToPlaylist(song);
            }
            else if (op == "current") {
                string aux = ipod.current();
                cout << "Sonando " << aux << endl;
            }
            else if (op == "play") {

                string aux = ipod.play();

                cout << "Sonando " << aux << endl;

            }
            else if (op == "totalTime") {
                cout << "Tiempo total " << ipod.totalTime() << endl;
            }
            else if (op == "recent") {
                cin >> n;
                vector<string> aux = ipod.recent(n);
                cout << "Las 2 mas recientes" << endl;
                for (string x : aux) {
                    cout <<"    "<< x << endl;
                }
            }
            else if (op == "deleteSong") {
                cin >> song;
                ipod.deleteSong(song);
            }

        //Fin del try
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