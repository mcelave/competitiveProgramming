#include <map>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#define forall(it, X) for(typeof((X).begin()) it = (X).begin();it != (X).end(); ++it)
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

void agregarNodoYRelaciones(map<char,set<char> >& parejas,char& nodo, string& relaciones) {
	//Agrego las aristas salientes de este nodo
	if(parejas.find(nodo)==parejas.end())
		parejas[nodo] = set<char>(relaciones.begin(),relaciones.end());
	else
		parejas[nodo].insert(relaciones.begin(),relaciones.end());

	//Agrego a los nodos relacionados, las aristas desde nodo
	forn(i,relaciones.size()) {
		if(parejas.find(relaciones[i])==parejas.end()) {
			set<char> aux;
			parejas[relaciones[i]] = aux;
		}
	}
}

void procesarEntrada(map<char,set<char> >& parejas,string& linea) {
	int posInicial = 0;
	int posDelimitador = linea.find(';');
	while(posDelimitador>0) {
		char nodo = linea.at(posInicial);
		string relaciones = linea.substr(posInicial+2,posDelimitador-(posInicial+2));
		agregarNodoYRelaciones(parejas,nodo,relaciones);
		posInicial = posDelimitador + 1;
		posDelimitador = linea.find(';',posInicial);
	}
	char nodo = linea.at(posInicial);
	string relaciones = linea.substr(posInicial+2);
	agregarNodoYRelaciones(parejas,nodo,relaciones);
}

bool compararNodosConGrado(pair<char,int> nodoi, pair<char,int> nodoj) {
	return ((nodoi.second<nodoj.second)||((nodoi.second==nodoj.second) && (nodoi.first<nodoj.first)));
}

int calcularAnchoDeBanda(map<char,set<char> >& parejas, string& ordenamiento) {
	unsigned int anchoDeBanda = 0;
	map<char,int> ubicaciones;
	forn(i,ordenamiento.size()) {
		ubicaciones[ordenamiento[i]] = i;
	}
	forn(i,ordenamiento.size()) {
		set<char> relaciones = parejas[ordenamiento[i]];
		int posNodo = ubicaciones[ordenamiento[i]];
		forall(it2,relaciones) {
			if(ubicaciones.find(*it2)!=ubicaciones.end()) {
				unsigned int distancia = abs(posNodo-ubicaciones[*it2]);
				if(distancia>anchoDeBanda)
					anchoDeBanda = distancia;
			}
		}
	}
	return anchoDeBanda;
}

void convertirEnGrafoNoDirigido(map<char,set<char> > & parejas)
{
    forall(it,parejas) {
		forall(it2,it->second) {
			parejas[*it2].insert(it->first);
		}
	}
}

void extraerNodosConSusAdyacenciasOrdenadasPorGrado(map<char,set<char> > & parejas, map<char,vector<char> > & nodosConAdyacenciasOrdenadasPorGrado)
{
    forall(it,parejas) {
		vector<pair<char,int> > nodosConGrado;
		forall(it2,it->second) {
			nodosConGrado.push_back(pair<char,int>(*it2,parejas[*it2].size()));
		}
		sort(nodosConGrado.begin(),nodosConGrado.end(),compararNodosConGrado);
		vector<char> adyacencias;
		forn(i,nodosConGrado.size()) {adyacencias.push_back(nodosConGrado[i].first);}
		nodosConAdyacenciasOrdenadasPorGrado[it->first] = adyacencias;
	}
}

int calcularCotaSuperior(map<char,set<char> > parejas) {
	map<char,vector<char> > nodosConAdyacenciasOrdenadasPorGrado;
    convertirEnGrafoNoDirigido(parejas);
    extraerNodosConSusAdyacenciasOrdenadasPorGrado(parejas,
    		nodosConAdyacenciasOrdenadasPorGrado);
    map<char,bool> nodosVisitados;
	char nodoInicial = nodosConAdyacenciasOrdenadasPorGrado.begin()->first;
	unsigned int grado = nodosConAdyacenciasOrdenadasPorGrado.begin()->second.size();
	forall(it,nodosConAdyacenciasOrdenadasPorGrado) {
		nodosVisitados[it->first] = false;
		if((it->second.size()<grado)||((it->second.size()==grado)&&(it->first<nodoInicial))){
			nodoInicial = it->first;
			grado = it->second.size();
		}
	}
	queue<char> colaDeRecorrido;
	nodosVisitados[nodoInicial] = true;

	string ordenamiento;
	ordenamiento.push_back(nodoInicial);
	forall(it,nodosConAdyacenciasOrdenadasPorGrado[nodoInicial]) {colaDeRecorrido.push(*it);}
	while(!colaDeRecorrido.empty()) {
		char nodo = colaDeRecorrido.front();
		colaDeRecorrido.pop();
		if(!nodosVisitados[nodo]) {
			nodosVisitados[nodo] = true;
			ordenamiento.push_back(nodo);
			forall(it,nodosConAdyacenciasOrdenadasPorGrado[nodo]) {colaDeRecorrido.push(*it);}
		}
		if(colaDeRecorrido.empty()) {
			grado = 0;
			nodoInicial = ' ';
			forall(it,nodosVisitados) {
				if(!it->second) {
					if((grado==0)||
						(nodosConAdyacenciasOrdenadasPorGrado[it->first].size()<grado)||
						((nodosConAdyacenciasOrdenadasPorGrado[it->first].size()==grado)&&(it->first<nodoInicial))){
						grado = nodosConAdyacenciasOrdenadasPorGrado[it->first].size();
						nodoInicial = it->first;
					}
				}
			}
			if(nodoInicial!=' ')colaDeRecorrido.push(nodoInicial);
		}
	}
	return calcularAnchoDeBanda(parejas,ordenamiento);
}

int calcularCotaInferior(map<char,set<char> >& parejas) {
	float nodos = parejas.size();
	float aristas = 0;
	forall(it,parejas) { aristas += it->second.size(); }
	aristas /= 2;
	unsigned int cota = ceil((2*nodos-1-sqrt(pow(2*nodos-1,2)-8*aristas))/2);
	return cota;
}

bool generarPermutaciones(map<char,set<char> >& parejas,vector<char>& nodos, string& permutacion,string& ordenamiento,
		int cantNodos, int cotaInferior, int* cotaSuperior) {
	if(permutacion.size()==cantNodos-1) {
		permutacion.push_back(nodos[0]);
		int anchoDeBandaPermutacion = calcularAnchoDeBanda(parejas,permutacion);
		if(anchoDeBandaPermutacion==cotaInferior) {
			ordenamiento = permutacion;
			return true;
		}
		if(anchoDeBandaPermutacion<=*cotaSuperior) {
			*cotaSuperior = anchoDeBandaPermutacion-1;
			ordenamiento = permutacion;
		}
		return false;
	}
	vector<char>::iterator it = nodos.begin();
	forn(i,nodos.size()) {
		string nuevaPerm = permutacion;
		nuevaPerm.push_back(*it);
		if(calcularAnchoDeBanda(parejas,nuevaPerm)>*cotaSuperior) return false;
		vector<char> nodosRestantes;
		if(it!=nodos.begin()) {nodosRestantes.insert(nodosRestantes.end(),nodos.begin(),it);}
		it++;
		nodosRestantes.insert(nodosRestantes.end(),it,nodos.end());
		if(generarPermutaciones(parejas,nodosRestantes,nuevaPerm,ordenamiento,cantNodos,cotaInferior,cotaSuperior))
			return true;
	}
	return false;
}

int encontrarOrdenamientoOptimo(map<char,set<char> >& parejas,string& ordenamiento, int cotaInferior, int cotaSuperior) {
	vector<char> nodos;
	forall(it,parejas) { nodos.push_back(it->first); }
	sort(nodos.begin(),nodos.end());
	string permutacion;
	generarPermutaciones(parejas,nodos,permutacion,ordenamiento,nodos.size(),cotaInferior,&cotaSuperior);
	return calcularAnchoDeBanda(parejas,ordenamiento);
}

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
