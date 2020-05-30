#ifndef DUPLICA_COLA_H
#define DUPLICA_COLA_H

#include "queue_eda.h"
#include <iostream>
using namespace std;


template <class T>
class DuplicaCola : public queue<T> {

	//Importo Nodo
	using Nodo = typename queue<T>::Nodo;

public: 
	void duplica() {
		if (this->empty()) {
			return;
		}
		else {
			Nodo* act = this->prim;//Pos actual, que voy a copiar
			Nodo* aux = this->prim;//Guarda la sig posicion 

			Nodo* copia;//La copia

			//Ejemplo: 5 3 1 (0)
			//Resultado 5 5 3 3 1 1

			while (act->sig != nullptr) {
				aux = act->sig;//Apuntamos al siguiente (3)
				copia = new Nodo(act->elem);//Creo copia de 5, falta "enlazarla"
				act->sig = copia; //El 5 original apunta ahora al nuevo 5
				copia->sig = aux;//el nuevo 5 apunt a a 3

				act = aux;//Nos situamos en la pos 3
				this->nelems++;
			}
			//CHAPUZA!!! Duplico el último elemento, la condición del while
			//está mal entonces
			aux = act->sig;
			copia = new Nodo(act->elem);
			act->sig = copia; 
			copia->sig = aux;

			act = aux;
			this->nelems++;
			//Poner el fin
			this->ult = nullptr;


		}
	}

	void print(ostream &out = cout) const {
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
inline ostream& operator << (ostream& out, DuplicaCola<T> const& cola) {
	cola.print(out);
	return out;
}


#endif