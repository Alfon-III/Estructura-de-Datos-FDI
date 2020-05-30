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

vector<string> frase2palabras(string frase) {
    vector<string> palabras;
    stringstream aux(frase);
    string palabra;
    while (aux >> palabra) {
        //Pasamos cada palabra a caso menor si son de más de 2 letras
        if (palabra.size() > 2) {
            for (int i = 0; i < palabra.size(); i++) {
                palabra[i] = tolower(palabra[i]);
            }
            palabras.push_back(palabra);
        }
    }
    return palabras;
}

bool resuelveCaso() {

    int lines, line;
    string frase, word;
    vector<string> palabras;
    cin >> lines;
    cin.ignore();
    if (lines == 0) return false;

    using palabra = string;
    map<palabra, vector<int>>map;

    for (int i = 1; i <= lines; i++) {
        getline(cin, frase);
        palabras = frase2palabras(frase);

        for (int j = 0; j < palabras.size(); j++) {
            word = palabras[j];
            if (map[word].size() > 0 && map[word].back() != i) {
                map[word].push_back(i);
            }
            else if (map[word].size() == 0) {
                map[word].push_back(i); 
            }
        }

    }

    for (auto p : map) {
        cout << p.first;
        for (int i = 0; i < p.second.size(); i++) {
            cout << " " << p.second[i];
        }
        cout << endl;
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
    system("PAUSE");
#endif

    return 0;
}