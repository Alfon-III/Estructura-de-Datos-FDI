// Alfonso Tercero López
// A74


#include <iostream>
#include <iomanip>
#include <fstream>
#include"mezclaListas.h"

using namespace std;

void resuelveCaso() {

	int x;
	mezclaListas<int> q1;
	mezclaListas<int> q2;
	mezclaListas<int> sol;

	
	cin >> x;
	while (x != 0) {
		q1.push(x);
		cin >> x;
	}

	cin >> x;
	while (x != 0) {
		q2.push(x);
		cin >> x;
	}

	sol = q1.inserta(q2);
	cout << sol << endl;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		resuelveCaso();
	}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}