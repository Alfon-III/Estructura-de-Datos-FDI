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
public:
	Horas() {
		hora = 0;
		minuto = 0;
		segundo = 0;

	};

	Horas(int h, int m, int s) : hora(h), minuto(m), segundo(s) {
		if (h >= 24 || h < 0) {
			erronea = true;
		}
		else if (m >= 60 || m < 0) {
			
			erronea = true;
		}
		else if (s >= 60 || s < 0) {
			erronea = true;
		}
	};
	//Getters

	int get_hora() const {
		return hora;
	}
	int get_min() const {
		return minuto;
	}
	int get_sec() const {
		return segundo;
	}
	bool esErroneo() const {
		return erronea;
	}

	//Operator "<" certifica que esta hora es menor que horas que recibe
	bool operator < (Horas const& horas) const {
		if ((3600 * hora + 60 * minuto + segundo) < ((3600 * horas.hora) + (60 * horas.minuto) + (horas.segundo))) {
			return true;
		}
		else {
			return false;
		}
	}


private:
	int hora, minuto, segundo;
	bool erronea = false;
};

//Funcion mostrar la hora
inline std::ostream& operator << (std::ostream& out, Horas const& horas) {
	cout << setw(2) << setfill('0') << horas.get_hora() << ":"
		<< setw(2) << setfill('0') << horas.get_min() << ":"
		<< setw(2) << setfill('0') << horas.get_sec();
	return out;
}

inline std::istream& operator >> (std::istream& in, Horas& horas) {
	int h, m, s;
	char c; //Aux :
	in >> h >> c >> m >> c >> s;
	horas = Horas(h, m, s);
	return in;
}

#endif