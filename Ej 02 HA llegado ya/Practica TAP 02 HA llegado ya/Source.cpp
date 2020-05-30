#include <iostream>
#include <fstream>
#include "set.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int numGrupos;
	cin >> numGrupos;
	if (numGrupos == 0)
		return false;
	string anfitrion;
	cin >> anfitrion;
	set <string> s;
	s.insert(anfitrion);

	for (int i = 0; i < numGrupos; i++) {
		string conocido;
		int numMiembros;
		cin >> conocido;
		cin >> numMiembros;

		//No lo encontramos
		if (s.find(conocido)) {
			for (int j = 0; j < numMiembros; j++) {
				string aux;
				cin >> aux;
			}
			cout << "NO" << endl;
		}

		//Lo encontré!
		else {
			cout << "SI" << endl;
			//Los guardo
			for (int j = 0; j < numMiembros; j++) {
				string aux;
				cin >> aux;
				s.insert(aux);
			}
		}
	}

	for (int i = 0; i < s.size(); i++) {
		cout << i <<" "<<s.<<endl;
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


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}