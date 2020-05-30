#ifndef IPOD_H
#define IPOD_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <map>
#include <list>

#include "hashmap_eda.h";

using namespace std;

struct infoSong {
	string artist;
	int time;
	bool onPL = false;//On playlist
	bool played = false;
};

struct infoPL {
	list<string> songs;
	int totTime = 0;
};

class ipod {

	infoPL playList;
	list<string> reciente;
	unordered_map<string, infoSong> mp3;

public:


	
	void addSong(string S, string A, int D) {
		auto it = mp3.find(S);
		if (it != mp3.end()) {
			throw domain_error("ERROR addSong");
		}
		else {
			mp3[S].artist = A;
			mp3[S].time = D;
		}
		
	}

	void addToPlaylist(string S) {
		auto it = mp3.find(S);
		if (it == mp3.end()) {
			throw domain_error("ERROR addToPlaylist");
		}
		else {
			//Si no está en la Playlist, se añade y se marca como añadidad
			if (!mp3[S].onPL) {
				playList.songs.push_back(S);
				playList.totTime += mp3[S].time;

				mp3[S].onPL = true;
			}
		}
	}

	//Playlist
	string current() {
		if (playList.songs.empty())
			throw domain_error("ERROR current");
		else
			return playList.songs.front();
		

	}

	//Pop, reproducida
	string play() {
		if (!playList.songs.empty()) {

			mp3[playList.songs.front()].onPL = false;

			//Si no ha sido reproducida antes, se añade a la lista de recientes
			if (!mp3[playList.songs.front()].played) 
				//Las más reciente sprimero
				reciente.push_front(playList.songs.front());
			
			mp3[playList.songs.front()].played = true;

			string song_aux;
			song_aux = playList.songs.front();

			playList.totTime -= mp3[playList.songs.front()].time;
			playList.songs.pop_front();
			return song_aux;
		}
		else {
			throw domain_error("No hay canciones en la lista");
		}
			
	}

	int totalTime() {
		return playList.totTime;
	}

	vector<string> recent(int N) {
		vector<string> aux;
		if (N > reciente.size()) {
			for (string x : reciente) {
				aux.push_back(x);
			}
		}
		else {
			int i = 0;
			for (string x : reciente) {
				if (i != N)
					aux.push_back(x);
				else
					return aux;
				i++;

			}
		}
		return aux;
	}

	void deleteSong(string S) {
		//Elimino de playlist
		auto it = mp3.find(S)
			;
		//La cancion existe y ha de ser eliminada
		if (it != mp3.end()) {
			//Si ha sido reproducida hay que eliminarla de recientes
			if (it->valor.played) {
				reciente.remove(S);

			}
			//Si está en la playlist ha de ser eliminada
			else if (it->valor.onPL) {
				playList.totTime -= mp3[S].time;
				playList.songs.remove(S);
			}
			//Eliminamos del mp3

			mp3.erase(S);

		}



	}


};

#endif // 
