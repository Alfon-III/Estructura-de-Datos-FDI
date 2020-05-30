// Nombre del alumno : Alfonso Tercero López
// Usuario del Juez:   A74

#include <iostream>
#include <iomanip>
#include <fstream>
#include "complejo.h"
using namespace std;


void resuelveCaso() {
	// leer los datos de la entrada
	float a, b, n;
	cin >> a >> b >> n;

	complejo<float> c(a, b);
	complejo<float> z(0, 0);

	float i = 0;
	while (i < n && z.modulo() <= 2.0) {

		//cout << z.modulo() << endl;
		z = (z * z) + c;
		i++;
	}
	//cout << i << endl;
	if (i == n) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}


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
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}