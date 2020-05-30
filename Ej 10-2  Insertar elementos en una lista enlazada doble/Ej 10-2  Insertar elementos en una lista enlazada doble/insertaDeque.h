#ifndef invierte_deque_h
#define invierte_deque_h

#include "deque_eda.h"
#include <iostream>
using namespace std;

template <class T>
class insertaListaDoble : public deque<T> {
	//Nodo = Nodo que hay de la clase que heredamos, deque
	using Nodo = typename deque<T>::Nodo;

public:

	//Precondición: lista.size() != 0 & this->size()!=0
	void inserta(insertaListaDoble& lista, int pos) {

		Nodo* ultimo_aux = lista.fantasma->ant;
		Nodo* primer_aux = lista.fantasma->sig;

		//lista al principio
		if (pos == 0) {

			Nodo* primer = this->fantasma->sig;

			//Fantasma a la nueva lista y la nueva lista a fantasma
			this->fantasma->sig = primer_aux;
			primer_aux->ant = this->fantasma;


			//Ultimo a primer y primer a ultimo
			ultimo_aux->sig = primer;
			primer->ant = ultimo_aux;


		}
		//lista al final
		else if (pos == this->size()) {
			Nodo* ultimo = this->fantasma->ant;
			
			ultimo->sig = primer_aux;
			primer_aux->ant = ultimo;

			ultimo_aux->sig = this->fantasma;
			this->fantasma->ant = ultimo_aux;

		}

		//Ahora que se ve el patrón claramente, 
		//podemos avanzar n posiciones
		else {

			Nodo* act = this->fantasma->sig;
			Nodo* next = act->sig; //Entre los nodos act y next insertaremos la lista

			for (int i = 0; i < pos - 1; i++) {
				act = next;
				next = act->sig;
			}

			act->sig = primer_aux;
			primer_aux->ant = act;

			next->ant = ultimo_aux;
			ultimo_aux->sig = next;

		}

		this->nelems += lista.nelems;

		lista.fantasma->sig = nullptr;
		//lista.fantasma->ant = nullptr;
		lista.nelems = 0;


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
inline ostream& operator << (ostream& out, insertaListaDoble<T> const& colaDoble) {
	colaDoble.print(out);
	return out;
}


#endif