// Alfonso Tercero López
// A74


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Polinomio.h"
using namespace std;

bool resuelveCaso() {
	int coef, exp, casos, x;
	polinomio pol;
	cin >> coef;
	if (!cin)
		return false;
	cin >> exp;
	while (coef != 0 || exp != 0) {
		pol.add(coef, exp);
		cin >> coef >> exp;
	}

	cin >> casos;

	for (int i = 0; i < casos; i++) {
		cin >> x;
		cout << pol.evaluar(x) << " ";
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


	while (resuelveCaso())
		;



	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}