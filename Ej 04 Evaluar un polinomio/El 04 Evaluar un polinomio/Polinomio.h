//Juan Antonio Escobar de los Angeles 2ºA

#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <vector>
#include "Monomio.h"
class polinomio {

private:

	vector<monomio> polinom;

public:

	polinomio() {}

	int evaluar(int x) const {
		int tot = 0;

		for (monomio i: polinom) {
			tot += i.evaluar(x);
		}

		return tot;
	}

	void add(int coef, int expo) {
		monomio aux(coef, expo);
		polinom.push_back(aux);
	}

};


#endif