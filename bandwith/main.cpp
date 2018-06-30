#include <map>
#include <iostream>
#include <string>
#include <set>
#include "definicionesGlobales.h"
#include "calculoDeCotas.h"
#include "determinacionDeLaSolucion.h"
#include "procesamientoDeLaEntrada.h"
using namespace std;

int main(int argc,char** argv) {
	string linea;
	getline(cin,linea);
	while(linea.compare("#")!=0) {
		map<char,set<char> > parejasPorCaracter;
		procesarEntrada(parejasPorCaracter,linea);
		
		int cotaInferiorAnchoDeBanda = calcularCotaInferior(parejasPorCaracter);
		int	cotaSuperiorAnchoDeBanda = calcularCotaSuperior(parejasPorCaracter);

		string ordenamiento;
		int anchoDeBanda = encontrarOrdenamientoOptimo(parejasPorCaracter,
				ordenamiento,cotaInferiorAnchoDeBanda,cotaSuperiorAnchoDeBanda);

		forn(i,ordenamiento.size()) {
			cout<<ordenamiento[i]<<" ";
		}
		cout<<"-> "<<anchoDeBanda<<endl;
		getline(cin,linea);
	}
	return 0;
}
