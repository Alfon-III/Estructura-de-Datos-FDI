#include <iostream>
#include <fstream>
#include "Hora.h"
using namespace std;

/*
4 2
06:40:30 12:50:00 19:20:00 21:25:00
10:20:00
22:00:00
6 3
00:00:00 09:30:00 16:40:30 17:00:00 20:10:40 22:35:00
20:10:40
08:61:30
08:40:30
0 0
*/

bool resuelveCaso() {
	int n, casos;
	Horas trenes[1000];
	Horas consultas[1000];
	cin >> n >> casos;

	while (n != 0 && casos != 0) {
		//Obtenemos los datos de los trenes

		try {

			for (int i = 0; i < n; i++) {
				cin >> trenes[i];
			}

			//Guardamos las consultas
			for (int i = 0; i < casos; i++) {
				cin >> consultas[i];
			}

			//Comprobamos para cada caso...
			int aux = 0;
			for (int i = 0; i < casos; i++) {
				if (!consultas[i].esErroneo()) {
					while (aux < n && trenes[aux] < consultas[i]) {
						aux++;
					}
					if (aux == n) {
						cout << "NO" << endl;
					}
					else {
						cout << trenes[aux] << endl;
					}
				}
				else {
					cout << "ERROR" << endl;
				}
				aux = 0;
			}
			cout << "---" << endl;
			

		}
		catch (std::invalid_argument& ia) {
			std::cout << ia.what() << '\n';
		}
		catch (...) {
			cout << "Excepcion no tratada" << endl;
		}
		cin >> n >> casos;
	}
	return false;

}

int main() {

	while (resuelveCaso()) {
	
	} // Resolvemos todos los casos
	return 0;

}
