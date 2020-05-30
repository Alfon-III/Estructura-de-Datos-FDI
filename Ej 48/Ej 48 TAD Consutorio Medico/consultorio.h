#ifndef CONSULTORIO_H
#define CONSULTORIO_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <map>

#include "fecha.h"
#include "hashmap_eda.h";

using namespace std;

using medico = string;
using paciente = string;

//Creamos la clase map

struct info {
	Fecha fecha;
	string paciente;
};


class consultorio {
	
	unordered_map<medico, map<Fecha, paciente>> consu;

public:

	//Constante
	void nuevoMedico(medico m) {
		consu[m];
	}

	void pideconsua(paciente p, medico m, const Fecha& f) {
		auto it = consu.find(m);
		//No debo usar "at" pues muestra otra excepción
		if (it == consu.end()) {
			throw domain_error("Medico no existente");
		}
		else {
			auto itFecha = consu[m].find(f);
			//Si no está ocupada la fecha, se introduce

			if (itFecha != consu[m].end()) {
				throw domain_error("Fecha ocupada");
			}
			else{
				consu[m][f] = p;
			}
		}

	}

	paciente siguientePaciente(medico m) {
		auto it = consu.find(m);
		if (it == consu.end()) {
			throw domain_error("Medico no existente");
		}
		else {
			auto itFecha = consu[m].begin();
			if (itFecha == consu[m].cend()) {
				throw domain_error("No hay pacientes");
			}
			else {
				//Borra de un médico, la primera consulta
				return itFecha->second;
			}
		}
	}

	void atiendeConsulta(medico m) {
		auto it = consu.find(m);
		if (it == consu.end()) {
			throw domain_error("Medico no existente");
		}
		else {
			auto itFecha = consu[m].begin();
			if (itFecha == consu[m].cend()) {
				throw domain_error("No hay pacientes");
			}
			else {
				//Borra de un médico, la primera consulta
				consu[m].erase(itFecha->first);
			}
		}
	}

	vector<info> listaPacientes(medico m, int dia) {
		auto it = consu.find(m);
		if (it == consu.end()) {
			throw domain_error("Medico no existente");
		}
		else {
			vector<info> lista;
			//Si hay citas puede quye haya para ese día
			if (!consu[m].empty()) {

				//Recorremos las consultas de ese doctor y las que coincidan con el día se incluyen
				for (auto& aux : consu[m]) {
					if (aux.first.getDia() == dia) {
						lista.push_back({ aux.first, aux.second });
					}
				}
			}
			return lista;

		}
	}

};

#endif // !CONSULTORIO_H
