#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <cstddef>    // size_t
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <iostream>
#include <math.h>       /* sqrt */

template <class T>
class complejo {
private:
	T a;
	T b;
public:
	//Constructor
	complejo(T a_in, T b_in) {
		a = a_in;
		b = b_in;
	}

	complejo operator+(complejo otro) {
		return complejo(otro.a + a, otro.b + b);
	}

	complejo operator*(complejo otro) {
		return complejo(((a * otro.a) - (b * otro.b)), ((a * otro.b) + (otro.a * b)));
	}


	T modulo() {
		return sqrt((a*a) + (b*b));
	}

};

#endif