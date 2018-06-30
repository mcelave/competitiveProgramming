#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stdio.h>

using namespace std;

struct jugador {
  int coordx;
  int coordy;
  int id;
  jugador(int x, int y,int no):coordx(x),coordy(y),id(no){}
};


double Dist(jugador primero, jugador segundo){
    double x1=primero.coordx;
    double x2=segundo.coordx;
    double y1=primero.coordy;
    double y2=segundo.coordy;


    return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}

struct arista {
    jugador primero;
	jugador segundo;
	double costo;

	arista(jugador x, jugador y):primero(x),segundo(y),costo(Dist(primero,segundo)){}

};

bool menor(arista a,arista b){
    return (a.costo<b.costo);
}

bool mayor(arista a,arista b){
    return (a.costo>b.costo);
}

void merge(int a, int b, int componentes[],int tam){
    int i= min(a,b);
    int j= max(a,b);
    int k=0;
    while(k<tam){
        if(componentes[k]==j){
            componentes[k]=i;
        }
    k++;
    }
}


int main()
{
  	
    int casos;
    cin>>casos;

    while(casos>0){
    int conexiones,jugadores;
     int cont=0;
    cin>>conexiones>>jugadores;
    vector<arista> todasLasAristas;
    vector<jugador> todosLosJugadores;
    int ejex,ejey;
    while(cont<jugadores){
        cin>>ejex>>ejey;
        jugador nuevo(ejex,ejey,cont);
        int limite=todosLosJugadores.size();
        for(int i=0;i<limite;i++){
            arista nuevaArista(todosLosJugadores[i],nuevo);
            todasLasAristas.push_back(nuevaArista);
        }
        todosLosJugadores.push_back(nuevo);
        cont++;
    }

        
        sort(todasLasAristas.begin(),todasLasAristas.end(),menor);

        int componentes[todosLosJugadores.size()];
        for(int k=0;k<todosLosJugadores.size();k++){
            componentes[k]=todosLosJugadores[k].id;
 
        }
        int cantNodos=todosLosJugadores.size();
        int aristaActual=0;

        vector<arista> T;
        while(T.size()<cantNodos-1){
            arista aux=todasLasAristas[aristaActual];
            int primComp = (aux.primero).id;
            int segComp = (aux.segundo).id;
            int uComp = componentes[primComp];
            int vComp = componentes[segComp];
            if(uComp!=vComp){
                merge(uComp,vComp,componentes,cantNodos);
                    T.push_back(aux);
            }
            aristaActual++;
        }

        double res;
        if((conexiones==0)){
            res = (T[T.size()-1]).costo;
        }else{
            if(conexiones>=jugadores){
                res =0.00;
            }else{
                res = (T[T.size()-conexiones].costo);
            }
        }

        cout<<fixed<<setprecision(2)<<res<<endl;


    casos--;
    }
    
}

