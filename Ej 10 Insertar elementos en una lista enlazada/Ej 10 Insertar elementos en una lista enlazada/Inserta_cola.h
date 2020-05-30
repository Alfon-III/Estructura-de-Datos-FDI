#ifndef DUPLICA_COLA_H
#define DUPLICA_COLA_H

#include "queue_eda.h"
#include <iostream>
using namespace std;


template <class T>
class InsertaCola : public queue<T> {

	//Importo Nodo
	using Nodo = typename queue<T>::Nodo;

public:

	void inserta(InsertaCola& cola, int pos) {

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
inline ostream& operator << (ostream& out, InsertaCola<T> const& cola) {
	cola.print(out);
	return out;
}


#endif