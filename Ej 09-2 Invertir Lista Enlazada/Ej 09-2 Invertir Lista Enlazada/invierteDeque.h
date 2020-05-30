#ifndef invierte_deque_h
#define invierte_deque_h

#include "deque_eda.h"
#include <iostream>
using namespace std;

template <class T>
class invierteListaDoble : public deque<T> {
	//Nodo = Nodo que hay de la clase que heredamos, deque
	using Nodo = typename deque<T>::Nodo;

public:

	void invierte() {
		if ( this->size() > 1) {

			Nodo* act = this->fantasma->sig;//Primer elemento
			Nodo* primero = this->fantasma;
			Nodo* ultimo = this->fantasma->ant;
			Nodo* nextNode = act->sig;
			Nodo* pastNode = this->fantasma;

			this->fantasma->ant = act;
			this->fantasma->sig = ultimo;

			while (act != this->fantasma) {
				nextNode = act->sig;
				act->sig = pastNode;
				act->ant = nextNode;

				pastNode = act;
				act = nextNode;
			}

		}		
	}


	void print(ostream& out = cout) const {
		if (!this->empty()) {
			Nodo* aux = this->fantasma->sig;
			//aux = fantasma;//Nos colocamos en la posición 0
			while (aux->sig != this->fantasma) {
				out << aux->elem << " ";
				aux = aux->sig;
			}
			//no recorro la lista doble correctamente
			out << aux->elem << " ";
			aux = aux->sig;
		}
	}

};

template <class T>
inline ostream& operator << (ostream& out, invierteListaDoble<T> const& colaDoble) {
	colaDoble.print(out);
	return out;
}


#endif