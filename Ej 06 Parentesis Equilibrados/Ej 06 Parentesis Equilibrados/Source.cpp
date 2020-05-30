// Nombre del alumno Alfonso Tercero López
// Usuario del Juez A74


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <string>
using namespace std;

bool resuelveCaso() {
	// leer los datos de la entrada

	stack<char> pila;
	string frase;

	getline(cin, frase);
	if (!std::cin)
		return false;

	for (unsigned int i = 0; i < frase.length(); i++) {

		//En caso de abrirse, lo guardamos en la pila
		if (frase[i] == '(' || frase[i] == '[' || frase[i] == '{') {
			pila.push(frase[i]);
		}

		/*En caso que se cierre
			1.Comnprobamos que la pila no esté vacía si vamos a sustraer un elemento
			2. Si el elemento que vamso a sustraer coincide con su "pareja"
				hacemos pop
			*/

			//Vemos el caso que la pila esté vacía y se cierre 
		if (pila.empty() && (frase[i] == ')' || frase[i] == ']' || frase[i] == '}')) {
			cout << "NO" << "\n";
			return true;
		}

		else if (frase[i] == ')') {

			if (pila.top() == '(') {
				pila.pop(); // Quitamos el '('
			}

			else {
				//Avisamos que hay un error y salimso del bucle
				cout << "NO" << "\n";
				return true;
			}
		}


		else if (frase[i] == ']') {
			if (pila.top() == '[') {
				pila.pop();
			}
			else {
				cout << "NO" << "\n";
				return true;
			}
		}	

		else if (frase[i] == '}') {
				
			if (pila.top() == '{') {
				pila.pop();
			}
				
			else {
				cout << "NO" << "\n";
				return true;
			}
		}

	}


	if (pila.empty()) {
		cout << "SI";
	}
	else {
		cout << "NO";
	}
	cout << "\n";


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