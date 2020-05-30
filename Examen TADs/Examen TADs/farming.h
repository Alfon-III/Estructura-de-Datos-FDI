#ifndef FARMING_H
#define FARMING_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <stdexcept>
//#include <unordered_map>
#include <list>
#include <string>
#include <map>
#include "hashmap_eda.h"
using namespace std;


using id = string;
using plaga = string;

struct info {
	int plantas;
	int afectadas;
};

struct infoPlaga {
	string id;
	string plaga;
};

//Struct para devolver info en un vector para la funcion plagas
struct vPlaga {
	string plaga;
	int afectada;
};

class Farming {

	unordered_map<id, info> sectores;
	list<infoPlaga> listaFumigar;
	unordered_map<id, map<plaga, int>> plagas;

public:



	~Farming() {};

	void alta(string id, int n) {
		auto it = sectores.find(id);
		//No existe el sector, Se introduce
		if (it == sectores.end())
			sectores[id] = { n, 0 };

		else
			sectores[id].plantas += n;

	}

	void datos(string id, string p, int n) {
		auto it = sectores.find(id);
		//No existe el sector
		if (it == sectores.end())
			throw domain_error("Sector no existente");
		else {
			if(n > sectores[id].plantas)
				throw domain_error("Numero de plantas incorrecto");

			sectores[id].afectadas += n;
			listaFumigar.push_back({ id, p });
			plagas[id][p] = n;
		}
	}

	vector<infoPlaga> fumigar() {
		vector<infoPlaga> v;
		auto it = listaFumigar.begin();
		while (it != listaFumigar.end()) {

			//Si un cuarto de las planats de este sector está afectada, 
			//se añade al vector y se elimina de la lista

			if (sectores[it->id].afectadas != 0 && sectores[it->id].plantas / sectores[it->id].afectadas <= 4) {
				v.push_back({it->id, it->plaga});

				plagas[it->id][it->plaga] = 0;
				sectores[it->id].afectadas = 0;

				listaFumigar.erase(it++);

			}
			else {
				++it;
			}
				

		}

		return v;
	}

	vector<vPlaga> plaga(string id) {
		vector<vPlaga> v;
		auto it = plagas.find(id);
		if (it == plagas.end()) {
			throw domain_error("Numero de plantas incorrecto");
		}
		auto it2 = plagas[id].begin();
		while (it2 != plagas[id].end()) {

			v.push_back({ it2->first, it2->second });

			it2++;
		}
		return v;
	}


};


#endif