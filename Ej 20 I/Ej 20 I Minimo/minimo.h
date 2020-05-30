#ifndef PROPIEDAD_ARBOL_H
#define PROPIEDAD_ARBOL_H

#include "bintree_eda.h"
#include <iostream>
#include <algorithm>

using namespace std;


template <class T>
class arbolMinimo : public bintree<T> {

    //Importo Link
    using Link = typename bintree<T>::Link;

public:

    arbolMinimo() : bintree<T>() {}

    arbolMinimo(arbolMinimo<T> const& l, T const& e, arbolMinimo<T> const& r) : bintree<T>(l, e, r) {}

public:

    
    T calculaMin() const {
        return minimo(this->raiz);
    }

private:
    
    T minimo(Link arbol) const{
        if (arbol->left == nullptr && arbol->right == nullptr) {
            return arbol->elem;
        }

        //Derecha vacía
        else if (arbol->left != nullptr && arbol->right == nullptr) {
            return min(arbol->elem, minimo(arbol->left));
        }

        //Izquierda vacía
        else if (arbol->left == nullptr && arbol->right != nullptr) {
            return min(arbol->elem, minimo(arbol->right));
        }
        else {
            return min(min(minimo(arbol->right), minimo(arbol->left)), arbol->elem);
        }
    }


};

template <class T>
inline arbolMinimo<T> leer(T vacio) {
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