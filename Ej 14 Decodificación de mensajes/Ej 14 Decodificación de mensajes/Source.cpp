// Alfonso Tercero López
// A74


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <deque>
#include <stack>


using namespace std;

bool esVocal(char x) {
	if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ||
		x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U') {
		return true;
	}
	else {
		return false;
	}
}

bool resuelveCaso() {

	deque<char> cola;
	stack<char> pila;
	

	string code;


	if (!std::cin)
		return false;
	getline(cin, code);

	for (int i = 0; i < (int)code.size(); i++) {
		if (i % 2 == 0) {
			cola.push_back(code[i]);
			
		}
		else {
			pila.push(code[i]);
		}
	}
	while (!pila.empty()) {
		cola.push_back(pila.top());
		pila.pop();
	}

	//Aontaelccreet os e,natge
	//Analceto_,ag
	//otecre sente

	stack<char> consonantes;//Pila para invertir consonsntes
	string res;

	while (!cola.empty()) {
		if (esVocal(cola.front())) {
			while(!consonantes.empty()){
				res.push_back(consonantes.top());
				consonantes.pop();
			}
			res.push_back(cola.front());//Introduzco la vocal
		}
		else {//Es una consonante, la añado a la pila
			consonantes.push(cola.front());
		}
		//Paso al siguiente caracter boorando el primero
		cola.pop_front();

	}


	cout << res << endl;
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