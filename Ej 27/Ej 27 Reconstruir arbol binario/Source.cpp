// Alfonso Tercero López
// A74

#include "bintree_eda.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

int busca(const vector<int>& inorden, int ini, int fin, int busca) {
    for (int i = ini; i <= fin; i++) {
        if (inorden[i] == busca)
            return i;
    }
}

bintree<int> reconstruye(const vector<int>& preorden, const vector<int>& inorden, int ini, int fin, int posPreor) {


    if (ini > fin) {
        return {};
    }

    int elem = preorden[posPreor++];
   

    if (ini == fin) {
        return { bintree<int>(), elem, bintree<int>() };
    }

    int posInorden = busca(inorden, ini, fin, elem);

    bintree<int> L = reconstruye(preorden, inorden, ini, posInorden - 1, posPreor);
    bintree<int> R = reconstruye(preorden, inorden, posInorden + 1, fin, posPreor);

    return{ L, elem, R };



}

bintree<int> resuelve(const vector<int>& preorden, const vector<int>& inorden, int tam) {
    return reconstruye(preorden, inorden, 0, tam - 1, 0);
}

bool resuelveCaso() {
    vector<int> preorden, inorden;
    string pre, in;

    //Cargamso vector preorden
    getline(cin, pre);
    
    if (!cin) 
        return false;


    std::stringstream aux(pre);
    int num;
    while (aux >> num)
        preorden.push_back(num);

    //Cargamos vector inorden 
    getline(cin, in);
    std::stringstream aux2 (in);
    while (aux2 >> num)
        inorden.push_back(num);

    //Resolver

    bintree<int> arbol = resuelve(preorden, inorden, inorden.size());

    auto sol = arbol.postorder();

    for (int i = 0; i < sol.size(); ++i) {
        cout << sol[i] << " ";
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
    system("PAUSE");
#endif

    return 0;
}