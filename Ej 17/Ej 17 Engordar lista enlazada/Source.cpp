

#include <iostream>
#include <fstream>
using namespace std;
#include "deque_eda.h"
class EngordarLista : public deque<int> {
	using Nodo = deque<int>::Nodo;
public:

	void print(std::ostream& o = std::cout) const {
		Nodo* act = this->fantasma->sig;
		while (act != this->fantasma) {
			cout << act->elem << " ";
			act = act->sig;
		}
	}

	void engordar(EngordarLista& other) {
		int pos = other.nelems;
		Nodo* actOther = other.fantasma->sig;
		Nodo* sigOther = actOther->sig;
		int aux = 1;
		while (actOther != other.fantasma) {
			if (aux % 2 == 0) { // itroducimos por el final
				Nodo* ultimo = this->fantasma->ant;
				// insertar elemento por el final
				ultimo->sig = actOther;
				this->fantasma->ant = actOther;
				actOther->sig = this->fantasma;
				actOther->ant = ultimo;
			}
			else { // introducimos por el principio
				if (this->nelems == 0) { // si no existe ningun elemento en la lista principal, el que insertamos será el primero y el último a la vez
					this->fantasma->ant = actOther;
				}
				Nodo* primeroThis = this->fantasma->sig;

				this->fantasma->sig = actOther; // conectamos (->) el fantasma de this con el primero de other
				actOther->ant = this->fantasma;
				actOther->sig = primeroThis;
				primeroThis->ant = actOther;//El anterior al primero(this) es el último de other 
			}
			// avanzamos en la lista Other;
			actOther = sigOther;
			sigOther = sigOther->sig;
			aux++;
		}
		// vaciamos la lista
		this->nelems += other.nelems;
		other.nelems = 0;
		other.fantasma->sig = other.fantasma->ant = other.fantasma;
	}
};
inline std::ostream& operator<<(std::ostream& o, EngordarLista const& lista) {
	lista.print(o);
	return o;
}
EngordarLista leerListaPlus() {
	EngordarLista lista;
	int n, val;
	std::cin >> n; // tamaño
	while (n--) {
		std::cin >> val;
		lista.push_back(val);
	}
	return lista;
}

void resuelveCaso() {
	auto lista1 = leerListaPlus();
	auto lista2 = leerListaPlus();
	lista1.engordar(lista2);
	std::cout << lista1 << '\n';
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif
	int casos;
	cin >> casos;
	while (casos--) {
		resuelveCaso();
	}
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}