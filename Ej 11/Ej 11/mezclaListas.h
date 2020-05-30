#ifndef INSERTA_COLA_H
#define INSERTA_COLA_H

#include "queue_eda.h"
#include <iostream>
using namespace std;


template <class T>
class mezclaListas : public queue<T> {

	//Importo Nodo
	using Nodo = typename queue<T>::Nodo;

public:

	mezclaListas<int> inserta(mezclaListas& q2) {
		mezclaListas<int> sol;
		Nodo* act1 = this->prim;
		Nodo* act2 = q2.prim;

		/*Mientras que no hemos acabado con una lista,
		comparamos cual de los elementosd de las dos es el menor y 
		la inserto en la solucion */


		while (act1 != nullptr && act2 != nullptr) {
			if (act1->elem < act2->elem) {
				sol.push(act1->elem);
				act1 = act1->sig;
			}
			else {
				sol.push(act2->elem);
				act2 = act2->sig;
			}
		}
		//Nos hemos salido por que ya hemos recorrido toda la cola 2
		if (act1 != nullptr) {
			while (act1 != nullptr) {
				sol.push(act1->elem);
				act1 = act1->sig;
			}
		}
		if (act2 != nullptr) {
			while (act2 != nullptr) {
				sol.push(act2->elem);
				act2 = act2->sig;
			}
		}
		return sol;
	}

	void print(ostream& out = cout) const {
		if (!this->empty()) {
			Nodo* aux = this->prim;
			while (aux != nullptr) {
				out << aux->elem << " ";
				aux = aux->sig;
			}
		}
	}


};


template <class T>
inline ostream& operator << (ostream& out, mezclaListas<T> const& cola) {
	cola.print(out);
	return out;
}


#endif