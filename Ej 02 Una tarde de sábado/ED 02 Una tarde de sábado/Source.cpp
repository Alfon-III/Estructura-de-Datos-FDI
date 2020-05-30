#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <fstream>

#include "Horas.h"
#include "Peli.h"
using namespace std;

/*

3
17:40:20 02:20:10 El hombre tranquilo
15:30:00 01:35:40 12 hombres sin piedad
20:40:10 01:55:10 Horizontes lejanos

*/

bool resuelveCaso() {

	int casos;
	cin >> casos;
	if (casos == 0) {
		return false;
	}

	vector<Pelicula> peliculas(casos);

	//Introducir datos
	for (Pelicula& p : peliculas) {
		try {
			cin >> p;
		}
		catch (invalid_argument& ia) {
			cout << "ERROR" << endl;
		}
	}
	//Ordenamos...

	sort(peliculas.begin(), peliculas.end());
	for (Pelicula& p : peliculas) {
		cout << p << endl;
	}
	cout << "---" << endl;
	return true;
}


int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
