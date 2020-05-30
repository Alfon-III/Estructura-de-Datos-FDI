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

void resuelve(map<string, int> vieja, map<string, int> nueva) {
    vector<string> insert, elim, mod;//Nueva, eliminada, modificada

    //Recorremos el nuevo diccionario para ver que claves se han modificado o insertado
    for (auto x : nueva) {
        //Si el elemento x de la tabla nueva existe en la antigua pero no tiene el mismo valor
        if (vieja.count(x.first) == 1 && vieja[x.first] != x.second) {
            mod.push_back(x.first);//Insertamos la clave del elemento en el vector de modificados
        }
        //Si no se encuentra la antigua clave, se ha insertado una nueva clave y quizá se haya eliminado una vieja
        else if (!vieja.count(x.first)) {
            insert.push_back(x.first);
        }
    }
    //Recorro el diccionario viejo para ver que claves se han eliminado
    for (auto x : vieja) {
        //Si no se encuentra la clave vieja en el dicc nuevo, entonces se ha eliminado
        if (nueva.count(x.first) == 0) {
            elim.push_back(x.first);
        }
    }

    //Imprimimos resultados
    if (insert.empty() && elim.empty() && mod.empty()) {
        cout << "Sin cambios" << endl;
    }
    else {//Se hay algún vector con datos
        if (!insert.empty()) {
            cout << "+";
            for (int i = 0; i < insert.size(); i++) {
                cout << " " << insert[i];
            }
            cout << endl;
        }
        if (!elim.empty()) {
            cout << "-";
            for (int i = 0; i < elim.size(); i++) {
                cout << " " << elim[i];
            }
            cout << endl;
        }
        if (!mod.empty()) {
            cout << "*";
            for (int i = 0; i < mod.size(); i++) {
                cout << " " << mod[i];
            }
            cout << endl;
        }
    }
    cout << "---" << endl;



}

void resuelveCaso() {

    map<string, int> tabla1, tabla2;
    string clave, linea;
    int valor;

    //Leemos diccionario 1
    
    getline(cin, linea);
    stringstream aux(linea);
    while (aux >> clave >> valor) {
        tabla1[clave] = valor;
    }

    //Leemos diccionario 2
    getline(cin, linea);
    stringstream aux2(linea);
    while (aux2 >> clave >> valor) {
        tabla2[clave] = valor;
    }

    resuelve(tabla1, tabla2);

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
    cin.ignore();
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}