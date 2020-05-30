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


//Struct para mostrar la solución en el vector para ordenarlo posteriormenete
struct sol {
    int num;
    int pos;
    int repeticiones;
};

//Struct donde guardo los datos en el unordered_map
struct info {
    int repeticiones;
    int pos;
};

bool compara(sol x, sol y) {
    if (x.pos < y.pos) return true;
    else return false;
}


bool resuelveCaso() {


    unordered_map<int, info> repetidos;

    int N, num;
    cin >> N;
    if (!std::cin)
        return false;

   //coste lineal 
    for (int i = 0; i < N; i++) {
        cin >> num;

        if (!repetidos.count(num)) {
            repetidos[num].pos = i;
            repetidos[num].repeticiones = 0;
        }

        repetidos[num].pos = repetidos[num].pos;
        repetidos[num].repeticiones = repetidos[num].repeticiones + 1;
        
    }

    vector<sol> sol;
    
    //Recorro el unordered_map para introduir los valores en el vector y ser ordenado posteriormente
    auto itRepe = repetidos.begin(); 

    
    while (itRepe != repetidos.end()) {
        sol.push_back({ itRepe->clave, itRepe->valor.pos, itRepe->valor.repeticiones });
        ++itRepe;
    }

    sort(sol.begin(), sol.end(), compara);


    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i].num <<  " " << sol[i].repeticiones << endl;
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