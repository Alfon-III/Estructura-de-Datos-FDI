// Alfonso Tercero López
// A74


#include <iostream>
#include <iomanip>
#include <fstream>
#include "deque_eda.h"
#include "insertaDeque.h"

using namespace std;


bool resuelveCaso() {

	int n, m, pos, x;
	cin >> n;
	if (!std::cin)
		return false;

	insertaListaDoble<int> colaDoble;
	insertaListaDoble<int> colaAux;

	
	for (int i = 0; i < n; i++) {
		cin >> x;
		colaDoble.push_back(x);
	}

	cin >> m >> pos;

	for (int i = 0; i < m; i++) {
		cin >> x;
		colaAux.push_back(x);
	}

	colaDoble.inserta(colaAux, pos);

	cout << colaDoble << endl;

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}