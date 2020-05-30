#ifndef PROPIEDAD_ARBOL_H
#define PROPIEDAD_ARBOL_H

#include "bintree_eda.h"
#include <iostream>
#include <algorithm>

using namespace std;


template <class T>
class FronteraArbol : public bintree<T> {

    //Importo Link
    using Link = typename bintree<T>::Link;

public:
    FronteraArbol() : bintree <T >() {}
    FronteraArbol(FronteraArbol <T > const& l, T const& e, FronteraArbol <T > const& r) : bintree <T >(l, e, r) {}
    
    void frontera() {
        front(this->raiz);
    }

protected:

    bool ultimoNodo(Link arbol) {
        if (arbol == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }

    void front(Link arbol) {
        if (arbol == nullptr) {
            return;
        }
        if (ultimoNodo(arbol->left) && ultimoNodo(arbol->right)) {
            cout << arbol->elem << " ";
        }
        else {
            if (ultimoNodo(arbol->left) && !ultimoNodo(arbol->right)) {
                front(arbol->right);
            }
            else if (!ultimoNodo(arbol->left) && ultimoNodo(arbol->right)) {
                front(arbol->left);
            }
            else{
                front(arbol->left);
                front(arbol->right);
            } 
        }
    }
};

template <class T>
inline FronteraArbol<T> leer(T vacio) {
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