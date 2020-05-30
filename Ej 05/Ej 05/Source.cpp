//Alfonso Tercero López
//A74

#include<iostream>
#include<string>
#include <fstream>
#include "conjunto.h"
using namespace std;

template<class T>
void resuelve(T centinela, int k) {
	set<T> cjto;
	T elem;
	cin >> elem;
	while (elem != centinela) {  //complejidad del bucle n*k
		cjto.insert(elem);
		if (cjto.size() > k) {
			cjto.erase_min(); //eliminar el minimo
		}
		cin >> elem;
	}

	cout << cjto.minimo();
	cjto.erase_min();
	while (!cjto.empty()) {
		cout << ' ' << cjto.minimo();
		cjto.erase_min();
	}

	for (int i = 0; i < cjto.size(); i++) {
		cout << cjto.minimo() << " ";
	}

	cout << '\n';
}

bool resuelveCaso() {
	char letra;
	int k;
	cin >> letra >> k;

	if (!cin) {
		return false;
	}
	if (letra == 'N') { //el caso de numeros
		resuelve(-1, k);
	}
	else { //letra = P
		resuelve(string("FIN"), k);
	}
	return true;
}

int main() {
# ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
# endif
	while (resuelveCaso()) {}
# ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system(" PAUSE ");
# endif
	return 0;
}

