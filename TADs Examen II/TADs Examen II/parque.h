#ifndef PARQUE_H
#define PARQUE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <list>
#include <string>
#include <map>
#include "unordered_map"

using namespace std;

using ecosistem = string;
using especie = string;


class Parque {

	//Alamcena los ecosistemas del parque  y las especies que hay ewn cada ecosistema
	unordered_map<ecosistem, unordered_map<especie, int>> parque;

	//Almacena cronológicamente las especies que se han agregado recientemente a un ecosistema
	unordered_map<ecosistem, list<especie>> lista_especies;

	//Almacena de manera ordenada las especies y el número de ellas que hay en el parque
	map<especie, int> parque_especie;

public:

	void crea() {

	}

	//O(1)
	void an_ecosistema(string ecosistema) {
		auto it = parque.find(ecosistema);
		
		//No se encuentra el ecosistema en el parque
		if (it == parque.end()) {
			parque[ecosistema];
		}
		//Si ya existe, se lanza excepción;
		else {
			throw domain_error("EEcosistemaDuplicado");
		}

	}

	//O(log n) n = Numero de animales distintos en el parque
	void an_ejemplares(string ecosistema, string especie, int n) {

		auto it = parque.find(ecosistema);

		
		//Si no existe, se lanza excepción;
		if (it == parque.end()) {
			throw domain_error("EEcosistemaNoExiste");
		}
		//Si existe
		else {
			auto it2 = parque[ecosistema].find(especie);
			
			//Si la especie no está en ese ecosistema, se añade
			//
			if (it2 == parque[ecosistema].end()) {
				parque[ecosistema][especie] = n;
				lista_especies[ecosistema].push_front(especie);

				//Almacena en este mapa ordenado el numero de especies que habitan el parque
				//Aquí añadimos las nuevas especies
				parque_especie[especie] += n;
			}
			//Si ya existía, se incrementa el numero de especies
			//No 
			else {
				parque[ecosistema][especie] += n;
				parque_especie[especie] += n;

			}


		}
	}

	//max(O(1), O(n) )  n = numero introducido por el usuario 
	list<especie> lista_especies_ecosistema(string ecosistema, int n) {
		auto it = lista_especies.find(ecosistema);


		//Si no existe, se lanza excepción;
		if (it == lista_especies.end()) {
			throw domain_error("EEcosistemaNoExiste");
		}
		//Si existe
		else {
			list<especie> aux;

			//Si n es mayor que el numero de especies de ese ecosistema
			//Retorno todos
			if (n >= lista_especies[ecosistema].size()) {
				return lista_especies[ecosistema];
			}
			//Retorno los n primeros
			else {
				int i = 0;

				//Introduzco los n primeros en el vector. Es un aimplementación incorrecta 
				//Pero no me acordaba de cómo hacerlo correctamente
				for (especie x : lista_especies[ecosistema]) {
					if (i == n)
						return aux;
					aux.push_back(x);
					i++;
				}
			}
		}
	}
	//O(1)
	int numero_ejemplares_en_ecosistema(string ecosistema, string especies) {
		auto it = parque.find(ecosistema);


		//Si no existe, se lanza excepción;
		if (it == parque.end()) {
			throw domain_error("EEcosistemaNoExiste");
		}
		else {
			auto it2 = parque[ecosistema].find(especies);

			//Si la especie no está en ese ecosistema retornamos 0
			if (it2 == parque[ecosistema].end())
				return 0;
			else
				//Retorno el nunm de especies en ese ecosistema
				return parque[ecosistema][especies];
		}
	}

	//O(n log n) n = numero de animales distintos en parque_especie
	list<especie> lista_especies_parque() {
		list<especie> aux;


		//En parque especie hemos guardado todos los animales distintos en el parque
		//Junto al numero de ellos que hay
		for (auto esp : parque_especie) {
			aux.push_back(esp.first);
		}

		return aux;

	}

	//Mapa ordenado
	//O(log n) bn = numero de especies distintas en el parque
	int numero_ejemplares_en_parque(string especie) {
		auto it = parque_especie.find(especie);
		if (it == parque_especie.end())
			return 0;

		else
			return parque_especie[especie];

	}

};


#endif