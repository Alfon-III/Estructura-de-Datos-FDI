#ifndef CARNET_H
#define CARNET_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include <list>
#include <string>
//#include "hashmap_eda.h"

using namespace std;

const int MAX = 15;

using dni = string;
using pts = int;

class Carnet {


	unordered_map<dni, std::pair<pts, std::list<dni>::iterator>> tabla;
	vector<list<dni>> usuarioPuntos;


public:

	~Carnet() {};

	void nuevo(string dni) {
		auto it = tabla.find(dni);
		if (it == tabla.end()) {
			usuarioPuntos[15].push_front(dni);
			tabla[dni] = { 15, usuarioPuntos.begin() };
		}
		else {
			throw domain_error("Conductor duplicado");
		}
	}

	void quitar(string dni, int puntos) {
		auto it = tabla.find(dni);
		if (it == tabla.end()) {
			throw domain_error("Conductor inexistente");
		}
		else {

			//Tienes más puntos de los que te quitan
			if (tabla[dni] >= puntos) {
				usuarioPuntos[tabla[dni]]--;
				tabla[dni] -= puntos;
				usuarioPuntos[tabla[dni]]++;
			}
			//Me deja en menos de 0 puntos
			else if (tabla[dni] < puntos) {
				usuarioPuntos[tabla[dni]]--;
				tabla[dni] = 0;
				usuarioPuntos[0]++;
			}

		}
	}

	int consultar(string dni) {
		auto it = tabla.find(dni);
		if (it == tabla.end()) {
			throw domain_error("Conductor inexistente");
		}
		else {
			return tabla[dni];
		}
	}

	int cuantos_con_puntos(int puntos) {
		if (puntos > 15 || puntos < 0) {
			throw domain_error("Puntos no validos");
		}
		else {
			return usuarioPuntos[puntos];
		}
	}

	void recuperar(string dni, int puntos) {
		auto it = tabla.find(dni);
		if (it == tabla.end()) {
			throw domain_error("Conductor inexistente");
		}
		else {

			if (tabla[dni] + puntos <= 15) {
				usuarioPuntos[tabla[dni]]--;
				tabla[dni] += puntos;
				usuarioPuntos[tabla[dni]]++;
			}
			else if (tabla[dni] + puntos > 15) {
				usuarioPuntos[tabla[dni]]--;
				tabla[dni] = 15;
				usuarioPuntos[15]++;
			}

		}
	}

	vector<string> lista_por_puntos(int puntos) {
		vector<string> aux;

		if (puntos > 15 || puntos < 0) {
			throw domain_error("Puntos no validos");
		}
		else {

		}

	}

};




#endif