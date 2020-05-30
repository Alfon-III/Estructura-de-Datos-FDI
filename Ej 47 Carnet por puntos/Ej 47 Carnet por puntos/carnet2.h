#ifndef CARNET_H
#define CARNET_H

#include <iostream>
#include <fstream>
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

struct info {
	
	int pts;
	//Para guardar la posición en la lista usuarioPuntos
	list<dni>::const_iterator pos;

};


class Carnet {



	std::unordered_map<dni, info> tabla;
	vector<list<dni>> usuarioPuntos;


public:

	Carnet() : usuarioPuntos(MAX + 1, list<string>()) {}
	

	~Carnet() {};

	void nuevo(string dni) {
		auto it = tabla.find(dni);
		if (it == tabla.end()) {
			usuarioPuntos[15].push_front(dni);
			
			tabla[dni] = { 15, usuarioPuntos[15].begin() };

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
			if (tabla[dni].pts >= puntos) {
				//Elimino al usuariuo de la lista con los puntos anteriores y se los descuento
				usuarioPuntos[tabla[dni].pts].erase(tabla[dni].pos);
				tabla[dni].pts -= puntos;

				//Le introduzco en la nueva lista correspondiente y guardo la nueva posición en el iterador del usuario
				usuarioPuntos[tabla[dni].pts].push_front(dni);
				tabla[dni].pos = usuarioPuntos[tabla[dni].pts].begin();
			}
			//Me deja en menos de 0 puntos
			else if (tabla[dni].pts < puntos) {
				usuarioPuntos[tabla[dni].pts].erase(tabla[dni].pos);
				tabla[dni].pts = 0;

				usuarioPuntos[0].push_front(dni);
				tabla[dni].pos = usuarioPuntos[0].begin();
			}

		}
	}

	int consultar(string dni) {
		auto it = tabla.find(dni);
		if (it == tabla.end()) {
			throw domain_error("Conductor inexistente");
		}
		else {
			return tabla[dni].pts;
		}
	}

	int cuantos_con_puntos(int puntos) {
		if (puntos > 15 || puntos < 0) {
			throw domain_error("Puntos no validos");
		}
		else {
			return usuarioPuntos[puntos].size();
		}
	}

	void recuperar(string dni, int puntos) {
		auto it = tabla.find(dni);
		if (it == tabla.end()) {
			throw domain_error("Conductor inexistente");
		}
		else {

			if (tabla[dni].pts + puntos <= 15) {
				
				usuarioPuntos[tabla[dni].pts].erase(tabla[dni].pos);
				tabla[dni].pts += puntos;

				
				usuarioPuntos[tabla[dni].pts].push_front(dni);
				tabla[dni].pos = usuarioPuntos[tabla[dni].pts].cbegin();
			}
			
			else if (tabla[dni].pts < puntos) {
				usuarioPuntos[tabla[dni].pts].erase(tabla[dni].pos);
				tabla[dni].pts = 15;

				usuarioPuntos[15].push_front(dni);
				tabla[dni].pos = usuarioPuntos[15].cbegin();
			}

		}
	}

	list<string> lista_por_puntos(int puntos) {
		vector<string> aux;

		if (puntos > 15 || puntos < 0) {
			throw domain_error("Puntos no validos");
		}
		else {
			return usuarioPuntos[puntos];
		}
		return {};
	}

};


#endif