// Alfonso Tercero L�pez
// A74


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <string>
using namespace std;

//Al solo necesitar almacenar dos datos, NO he creado una clase
struct accidente{
	string fecha;
	int vict;
};

//Dada la pila, imprime si hay alg�n accidente con m�s v�ctimas que "vic"
//Siendo "vic" el num de v�ctimas de un accidente nuevo


	/*Mientras que la pila no est� vac�a, eliminar� las primeras posiciones con
	menos v�ctimas que el nuevo accidente
	La idea es adem�s borrar todos los elementos intermedios hasta lleghar al
	elemento mayor.
	EJ:

	[80, 30, 20, 10, 5] (siendo "5" top())
	Si llega un accidente con 40 v�ctimas, [30, 20, 10, 5]
	dejar�n de ser relevantes para futuras consultas, por lo cual son eliminadas

	Dej�ndolo en...
	[80, 40]
	Lo que viene a ser una """lista""" decreciente

	*/

void mayorAccidente(stack<accidente>& pila, accidente accident) {

	while (!pila.empty() && pila.top().vict <= accident.vict) {
		pila.pop();
	}

	if (pila.empty()) {
		cout << "NO HAY" << endl;
	}
	else {
		cout << pila.top().fecha << endl;
	}

}

bool resuelveCaso() {

	stack<accidente> pila;
	accidente aux;

	int numCasos;
	cin >> numCasos;

	if (!std::cin)
		return false;

	for (int i = 0; i < numCasos; i++) {
		cin >> aux.fecha >> aux.vict;

		//Consultamos
		mayorAccidente(pila, aux);

		//Lo ponemos en la cima de la pila
		pila.push(aux);
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