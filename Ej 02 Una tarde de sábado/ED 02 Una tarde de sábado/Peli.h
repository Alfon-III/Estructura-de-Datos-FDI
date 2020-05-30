#ifndef peli_h
#define peli_h

#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>


#include "Horas.h"

class Pelicula {
private:
	Horas hora_inicio;
	Horas duracion;
	Horas hora_fin; //Hora_inicio + duracion + (posible error)
	string titulo;
public: 

	Pelicula(Horas hora_ini = Horas(), Horas dur = Horas(), string tit = "") {
		hora_inicio = hora_ini;
		hora_fin = hora_ini + dur;
		duracion = dur;
		titulo = tit;
	}
	bool operator < (Pelicula const& pelic) const {
		if (hora_fin.get_TimeInSec() < pelic.hora_fin.get_TimeInSec()) {
			return true;
		}
		else if (hora_fin.get_TimeInSec() == pelic.hora_fin.get_TimeInSec()) {
			if (titulo < pelic.titulo) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

	Horas get_hora_fin() const{
		return hora_fin;
	}

	string get_titulo() const {
		return titulo;
	}

	void read(istream& in = cin) {
		Horas ini, duracion;
		string titulo;
		in >> ini >> duracion;
		getline(in, titulo);
		*this = Pelicula(ini, duracion, titulo);	
	}

	void print(ostream& out = cout) const {
		out << hora_fin << " " << titulo;
	}

};

inline std::istream& operator>>(std::istream& in, Pelicula& peli) {
	peli.read(in);
	return in;
}

inline std::ostream& operator<<(std::ostream& out, Pelicula const& peli) {
	peli.print(out);
	return out;
}

#endif //Peli_h