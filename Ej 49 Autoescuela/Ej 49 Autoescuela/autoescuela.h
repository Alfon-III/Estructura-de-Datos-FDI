#ifndef AUTOESCUELA_H
#define AUTOESCUELA_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <map>

#include "hashmap_eda.h";

using namespace std;

struct infoAlumno {
	string profe;
	int nota;
};

class autoescuela {

	unordered_map < string, map<string, int>> profesor;
	unordered_map <string, infoAlumno> alumno;

public:

	void alta(string a, string p) {
		auto it = alumno.find(a);

		//No existe
		if (it == alumno.end()) {
			alumno[a].nota = 0;
			alumno[a].profe = p;

			profesor[p][a] = 0;

		}
		//existe
		else {
			//Ha cambiado de profesor
			if (alumno[a].profe != p) {
				int nota = alumno[a].nota;

				//Borramos al alumno de su antiguo profesor
				profesor[alumno[a].profe].erase(a);

				//Lo insertamos en el nuevo prtofesor con su nota
				profesor[p][a] = nota;

				alumno[a].profe = p;
			}

		}
	}

	bool es_alumno(string a, string p) {
		auto it = alumno.find(a);

		//Existe el alumno
		if(it != alumno.end()){
			//Si de dicho alumno, su profesor coincide con p, es alumno.
			if (it->valor.profe == p)
				return true;
		}

		return false;

	}

	int puntuacion(string a) {

		auto it = alumno.find(a);

		if (it != alumno.end()) {
			return it->valor.nota;
		}
		else {
			throw domain_error("ERROR");
		}
	}

	void actualizar(string a, int n) {
		auto it = alumno.find(a);

		//Existe el alumno
		if (it != alumno.end()) {
			//Subimos la nota
			it->valor.nota += n;

			profesor[alumno[a].profe][a] += n;

		}
		else {
			throw domain_error("ERROR");
		}
	}

	vector<string> examen(string p, int n) {
		
		vector<string> aux;

		//Asumo que el profesor existe
		profesor[p];

		for (auto al : profesor[p]) {
			if (al.second >= n)
				aux.push_back(al.first);
		}
		return aux;

	}

	void aprobar(string a) {
		auto it = alumno.find(a);

		//Existe el alumno
		if (it != alumno.end()) {

			profesor[alumno[a].profe].erase(a);
			alumno.erase(a);
		}
		else {
			throw domain_error("ERROR");
		}
	}


};

#endif // !CONSULTORIO_H
