//A74
//Alfonso Tercero López

#include <iostream>
#include <fstream>
#include <string>
#include "consultorio.h"
#include "fecha.h"
using namespace std;


bool resuelveCaso()   {

    int n;

    std::cin >> n;
    if (!std::cin)
        return false;

    consultorio consulta;
   
    for (int i = 0; i < n; ++i) {
        try {
        string operacion, medico, paciente, hora;
        int dia;
        cin >> operacion;

        if (operacion == "nuevoMedico") {
            cin >> medico;
            consulta.nuevoMedico(medico);
        }
        else if (operacion == "pideConsulta") {
            cin >> paciente >> medico >> dia >> hora;

            Fecha f(dia, hora);
            consulta.pideconsua(paciente, medico, f);

        }
        //Muestra
        else if (operacion == "siguientePaciente") {
            cin >> medico;

            string paciente = consulta.siguientePaciente(medico);

            cout << "Siguiente paciente doctor " << medico << endl;
            cout << paciente <<endl;
        }
        else if (operacion == "atiendeConsulta") {
            cin >> medico;
            consulta.atiendeConsulta(medico);

        }
        //Muestra
        else if (operacion == "listaPacientes") {
            cin >> medico >> dia;
            vector<info> lista = consulta.listaPacientes(medico, dia);
            cout << "Doctor " << medico << " dia " << dia << endl;

            for (info aux : lista) {
                cout << aux.paciente << " "; 
                aux.fecha.printFecha();
                cout << endl;
            }

        }

        //Fin del try
        }
        catch (domain_error exception) {
            std::cout << exception.what() << endl;
        }
        

    }
    cout << "---" << endl;

    return true;
}

int main() {

    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

}