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


bool resuelveCaso() {

    int casos;
    cin >> casos;
    std::cin.ignore();

    if(casos == 0){
        return false;
    }
    using alumno = std::string;
    map<alumno, int> tabla;
    string nombre, calif;
    char basura;

    for (int i = 0; i < casos; i++) {
       
        getline(cin, nombre);
        cin >> calif; 
        std::cin.ignore();

        if (calif == "CORRECTO") {
            tabla[nombre]++;
        }
        else {
            tabla[nombre]--;
        }
    }

    //Imprimo, por orden alfabético (por defecto)
    for (auto al : tabla) {
        if (al.second == 0) {
            //no evaluado
        }
        else {
            cout << al.first << ", " << al.second << endl;
        }
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