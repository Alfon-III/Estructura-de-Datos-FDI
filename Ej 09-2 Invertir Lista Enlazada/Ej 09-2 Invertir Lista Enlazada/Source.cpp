// Alfonso Tercero L�pez
// A74


#include <iostream>
#include <iomanip>
#include <fstream>
#include "deque_eda.h"
#include "invierteDeque.h"

using namespace std;


bool resuelveCaso() {

	int x;
	cin >> x;
	if (!std::cin)
		return false;

	invierteListaDoble<int> lista;

	while (x != 0) {
		lista.push_back(x);
		cin >> x;
	}

	lista.invierte();

	cout << lista << endl;

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