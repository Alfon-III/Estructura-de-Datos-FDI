// Alfonso Tercero López
// A74


#include <iostream>
#include <iomanip>
#include <fstream>
#include "alumnoAfortunado.h"

using namespace std;


bool resuelveCaso() {

	int n, saltos;

	alumnoAfort<int> lista;

	cin >> n >> saltos;
	if (n == 0 && saltos == 0) {
		return false;
	}
	
	for (int i = 0; i < n; i++) {
		lista.push(i + 1);
	}
	
	lista.afortunado(saltos);
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