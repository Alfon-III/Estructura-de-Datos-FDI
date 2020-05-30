// Alfonso Tercero López
// A74


#include <iostream>
#include <iomanip>
#include <fstream>
#include "deque_eda.h"
#include "DuplicaColaDoble.h"

using namespace std;


bool resuelveCaso() {

	int x;
	cin >> x;
	if (!std::cin)
		return false;

	DuplicaColaDoble<int> cola;

	//Introducimos los datos en la cola

	while (x != 0) {
		cola.push_back(x);
		cin >> x;
	}

	cola.duplica();

	cout << cola << endl;


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