#ifndef CARNET_H
#define CARNET_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include <list>
//#include "hashmap_eda.h"

using namespace std;

const int MAX = 15;


class Carnet {

	unordered_map<string, int> tabla;
	vector<int> usuarioPuntos;


public:


	Carnet() : usuarioPuntos(16, 0){}


	~Carnet() {};

	void nuevo(string dni) {
		auto it = tabla.find(dni);
		if (it == tabla.end()) {
			tabla[dni] = 15;
			usuarioPuntos[15]++;
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
			else if(tabla[dni] < puntos){
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
		else{
			return usuarioPuntos[puntos];
		}
	}



};




#endif