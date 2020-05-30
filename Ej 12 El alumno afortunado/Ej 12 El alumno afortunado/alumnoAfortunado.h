#ifndef alumono_afortunado_h
#define alumono_afortunado_h


#include <iostream>
#include"queue_eda.h"
using namespace std;

template <class T>
class alumnoAfort : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:

	void afortunado(int salto) {
		Nodo* past=this->prim;
		Nodo* act = this->prim;

		while (this->nelems != 1) {

			for (int i = 0; i < salto; i++) {
				past = act;
				act = act->sig;

				//si es el último, nos ponemos al inicio
				if (act == nullptr) {
					act = this->prim;
				}
			}

			//eliminamos el primer elemento

			if (act == this->prim) {
				//cout << "->"<<act->elem << endl;
				this->prim = act->sig;
				act = this->prim;
			}
			else {
				//cout << "->" << act->elem << endl;
				past->sig = act->sig;
				act = past->sig;
				//act = act->sig;
			}

			if (act == nullptr) {
				act = this->prim;
			}

			this->nelems--;
		}

		cout << this->prim->elem << endl;
	}

};

#endif
