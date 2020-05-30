#ifndef PROPIEDAD_ARBOL_H
#define PROPIEDAD_ARBOL_H

#include "bintree_eda.h"
#include <iostream>
#include <algorithm>

using namespace std;


template <class T>
class propiedadArbol : public bintree<T> {

	//Importo Link
	using Link = typename bintree<T>::Link;

public:

    propiedadArbol() : bintree<T>() {}

    propiedadArbol(propiedadArbol<T> const& l, T const& e, propiedadArbol<T> const& r) : bintree<T>(l, e, r) {}

    int nodos() const{
        return numNodos(this->raiz);
    }

    int altura() const {
        return maxAltura(this->raiz);
    }

    int hojas() const{
        return numHojas(this->raiz);
    }


protected:


	int numNodos(Link arbol) const{
        //nodo vacío
		if (arbol == nullptr) {
			return 0;
		}
		return  numNodos(arbol->left) + numNodos(arbol->right) + 1;
	}

    int maxAltura(Link arbol) const {
        if (arbol == nullptr) {
            return 0;
        }
        return max(maxAltura(arbol->left) + 1, maxAltura(arbol->right) + 1);
    }

    int numHojas(Link arbol) const {
        //Nodo sin hijos, es decir una hoja
        if (arbol == nullptr) {
            return 0;
        }

        if ((numHojas(arbol->left) + numHojas(arbol->right)) == 0) {
            return 1;
        }
        else {
            return  numHojas(arbol->left) + numHojas(arbol->right);
        }
    }

};

template <class T>
inline propiedadArbol<T> leer(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) {
        return {};
    }
    else {
        auto iz = leer(vacio);
        auto dr = leer(vacio);
        return { iz, raiz, dr };
    }
}


#endif