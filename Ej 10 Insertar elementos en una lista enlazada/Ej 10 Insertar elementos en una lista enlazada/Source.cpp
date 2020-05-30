// Alfonso Tercero López
// A74


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
#include "Inserta_cola.h"

using namespace std;


bool resuelveCaso() {

	int N, x, n_elem, pos;
	cin >> N;
	if (!std::cin)
		return false;

	InsertaCola<int> cola;
	InsertaCola<int> cola_aux;

	//Introducimos los datos en la cola principal
	
	for (int i = 0; i < N; i++) {
		cin >> x;
		cola.push(x);
	}

	cin >> n_elem >> pos;

	for (int i = 0; i < n_elem; i++) {
		cin >> x;
		cola_aux.push(x);
	}

	cola.inserta();

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