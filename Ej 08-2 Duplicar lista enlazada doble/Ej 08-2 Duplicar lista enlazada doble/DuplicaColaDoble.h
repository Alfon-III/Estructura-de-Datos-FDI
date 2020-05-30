#ifndef DUPLICA_COLA_DOBLE_H
#define DUPLICA_COLA_DOBLE_H

#include "deque_eda.h"
#include <iostream>
using namespace std;

template <class T>
class DuplicaColaDoble : public deque<T> {
	//Importamos Nodo
	using Nodo = typename deque<T>::Nodo;

public:

	void duplica() {
		if (!this->empty()) {
			Nodo* act = this->fantasma->sig;
			Nodo* nextNode = act->sig;

			//Para recorrer la lista adecuadamente uso el esquema de la función copia
			while (act != this->fantasma) {
				this->inserta_elem(act->elem, act, nextNode);
				act = nextNode;
				nextNode = act->sig;
			}

		}
	}

	void print(ostream& out = cout) const {
		if (!this->empty()) {
			Nodo* aux = this->fantasma->sig;
			//aux = fantasma;//Nos colocamos en la posición 0
			while (aux != this->fantasma) {
				out << aux->elem << " ";
				aux = aux->sig;
			}
		}
	}
	
};

template <class T>
inline ostream& operator << (ostream& out, DuplicaColaDoble<T> const& colaDoble) {
	colaDoble.print(out);
	return out;
}


#endif