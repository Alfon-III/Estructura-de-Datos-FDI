#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;


class Fecha{
	int dia;
	int hora;
	int min;

public:


	Fecha(int d, string h) {
		dia = d;
		hora = 0;
		min = 0;

		bool x = true;
		//Chapuza GIGANTE
		for (char aux : h) {
			//Si no hemos pasado por este caracter, se poen las cifras en la hora
			if (aux == ':')
				x = false;

			if (x)
				hora = (aux - '0') + hora * 10;
			else if(aux != ':')
				min = (aux - '0') + min * 10;

		}

	}	


	//Destructor
	~Fecha() {};
	//is This < aux?

	bool operator<(Fecha aux) const {
		if (dia < aux.dia) return true;
		else if (dia > aux.dia) return false;
		else {
			if (hora < aux.hora) return true;
			else if (hora > aux.hora) return false;
			else {
				if (min < aux.min) return true;
				else return false;
			}
		}
	}

	int getDia() const {
		return dia;
	}

	int getHora() const {
		return hora;
	}

	int getMin() const {
		return min;
	}

	void printFecha() {
		cout << setw(2) << setfill('0') << hora << ":"
			<< setw(2) << setfill('0') << min;
	}

};

#endif