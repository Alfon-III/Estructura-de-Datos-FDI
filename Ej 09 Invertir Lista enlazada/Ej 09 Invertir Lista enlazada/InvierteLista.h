#ifndef INVIERTE_LISTA_H
#define INVIERTE_LISTA_H

#include "queue_eda.h"
#include <iostream>
using namespace std;


template <class T>
class InvierteLista : public queue<T> {
	using Nodo = typename queue<T>::Nodo;

public: 
	//Funciones que van a heredar de Nodo

	void invierte() {

		//Si la lista está vacía u ocupa 1 elemento, no se hace nada
		if (this->empty() || this->size() == 1) {
			return;
		}
		else {


			Nodo* act = this->prim;
			Nodo* primero = act;
			Nodo* pastNode = nullptr;
			Nodo* nextNode = act->sig;

			this->prim = this->ult;
			this->ult = primero;

			while (nextNode != nullptr) {
				nextNode = act->sig;
				act->sig = pastNode;
				pastNode = act;
				act = nextNode;
			}



		}


	}

	void print(ostream &out = cout) const{
		//Recuerda, al tratar con la clase superior, uso -> !!!
		if (this->empty()) {
			return;
		}
		else {

			Nodo* aux = this->prim;
			while (aux != nullptr) {
				out << aux->elem << " ";
				aux = aux->sig;
			}
		}
		
	}

};


template<class T>
inline ostream& operator << (ostream& out, InvierteLista<T> const& lista) {
	lista.print(out);
	return out;
}


#endif 