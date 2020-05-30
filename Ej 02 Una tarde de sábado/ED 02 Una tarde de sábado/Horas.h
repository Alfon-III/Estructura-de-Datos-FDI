#ifndef HORA
#define HORA

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <locale>
#include <iomanip>
#include <ctime>
#include <inttypes.h> 
#include <stdio.h>
using namespace std;

class Horas {

private:
	int hora, minuto, segundo;
	bool revisa(int h, int m, int s) {
		return ((0 <= h && h < 24) && (0 <= m && m < 60) && (0 <= s && s < 60));
	}

public:

	//Constructor
	Horas(int h = 0, int m = 0, int s = 0) : hora(h), minuto(m), segundo(s) {
		if (revisa(h, m, s)) {
			hora = h; 
			minuto = m;
			segundo = s;
		}
		else {
			throw std::invalid_argument("ERROR");
		}
	};
	//Getters

	int get_hora()const { return hora; }
	int get_min() const { return minuto; }
	int get_sec() const { return segundo; }

	//Operator "<" certifica que esta hora es menor que horas que recibe
	bool operator < (Horas const& horas) const {
		if ((3600 * hora + 60 * minuto + segundo) < (horas.get_TimeInSec())) {
			return true;
		}
		else {
			return false;
		}
	}

	//Sumamos a esta hora, lo que le pasemos por parametro
	//Tener cvuidado a que la suuma no exceda el 23:59:59! = 82800 + 3540 + 59 = 86.399

	Horas operator+ (Horas const& hora_extra) const{
		Horas aux;
		int total = ((hora * 3600) + (minuto * 60) + (segundo)) + hora_extra.get_TimeInSec();
		if ( (	((hora * 3600) + (60 * minuto) + (segundo)) + hora_extra.get_TimeInSec()) <  86400) {
			aux.segundo = total % 60;
			total = total / 60;
			aux.minuto = total % 60;
			total = total / 60;
			aux.hora = total;
			return aux;
		}
		else {
			throw std::invalid_argument("ERROR");
		}

	}

	int get_TimeInSec() const {
		return ((hora * 3600) + (minuto * 60) + (segundo));
	}

	//Manera optima para leer...
	void read(istream& in = cin) {
		int h, m, s;
		char basura;

		in >> h >> basura >> m >> basura >> s;
		
		//Guardo dichos valores en "este" objeto IMPORTANTE EL PUNTERO!
		*this = Horas(h, m, s);
	}



};

//Funcion mostrar la hora
inline std::ostream& operator << (std::ostream& out, Horas const& horas) {
	cout << setw(2) << setfill('0') << horas.get_hora() << ":"
		<< setw(2) << setfill('0') << horas.get_min() << ":"
		<< setw(2) << setfill('0') << horas.get_sec();
	return out;
}

inline std::istream& operator >> (std::istream& in, Horas& horas) {
	horas.read(in);
	return in;
}

#endif