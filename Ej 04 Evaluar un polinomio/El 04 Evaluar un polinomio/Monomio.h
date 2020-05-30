#ifndef MONOMIO_H
#define MONOMIO_H


#include <iostream>
#include <algorithm>
using namespace std;

class monomio {
private:
	int coef;
	int expo;
public:

	monomio(int c, int exp) {
		coef = c;
		expo = exp;
	}

	int evaluar(int x) {
		int aux = 1;

		//Pow daba error
		for (int i = 0; i < expo; i++) {
			aux *= x;
		}

		return coef * aux;
	}

};


#endif // !MONOMIO_H
