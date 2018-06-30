#include <iostream>
#include <utility>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stdio.h>

using namespace std;
vector< vector<int> >  adyacencia; 
typedef  pair<int,int> nodoNivel;



bool conectados(string str1, string str2){
     int diferencia=0;
    if(str1.size()!=str2.size()){
        return false;
    }else{
    string::iterator it=str1.begin();
   string::iterator it2 =str2.begin();
  while( (it2<str2.end()) && (it < str1.end()) && (diferencia<=2) ){
    if(*it!=*it2){
        diferencia++;
    }
    it2++;
    it++;
    }
    }
    return (diferencia<=1);
}

int Buscar(string source,vector<string> palabras){
    int i=0;
    int pos=0;
    bool encontre=false;
    while((i<palabras.size())&&!encontre){
        if(palabras[i]==source){
            encontre=true;
            pos=i;
        }
        i++;
    }
    return pos;
}

void BFS(vector<string> palabras, string source, string destino){
		
		
        int posSource = Buscar(source,palabras);
        int posDestino= Buscar(destino,palabras);
        queue<nodoNivel> cola;
        bool palabrasAgregadas[palabras.size()];
        bool palabrasSacadas[palabras.size()];
        for(int i=0;i<palabras.size();i++){
            palabrasSacadas[i]=false;
        }
        for(int j=0;j<palabras.size();j++){
                palabrasAgregadas[j]=false;
        }
        int res;
        nodoNivel prim(posSource,0);
        cola.push(prim);
        palabrasAgregadas[posSource]=true;
        bool termine=false;
        while((cola.size()!=0)&& !termine) {
            int nodoActual=(cola.front()).first;
            int nivel=(cola.front()).second;
            if(nodoActual==posDestino){
                termine=true;
                res=(cola.front()).second;
            }
            cola.pop();
            palabrasSacadas[nodoActual]=true;
       
            for(int k=0;k<palabras.size();k++){
                if(((adyacencia[nodoActual][k])==0)&&!palabrasSacadas[k]&&!palabrasAgregadas[k]){///si es vecino agrego
                    palabrasAgregadas[k]=true;
                    nodoNivel aux(k,nivel+1);
                    cola.push(aux);
                }
            }
        }
            cout<<source<<" "<<destino<<" "<<res<<endl;
}


int main()
{
    int test_i;
    int cantCasos;
    bool condicion;
    vector<string> palabras;
    string str;
    bool entrada;
    string source, destino, line;
    
    cin>>cantCasos;
    while(cantCasos>0){
   
		palabras.clear();
		entrada=true;
		while(entrada){
			cin>>str;
			if(str=="*"){
				entrada=false;
			}else{
			palabras.push_back(str);
			}
		}
		
		
	adyacencia.resize(palabras.size());
		for(int k=0;k<palabras.size();k++){
			adyacencia[k].resize(palabras.size());
		}
		
		
	
		for(int i=0;i<palabras.size();i++){
			for(int j=0;j<palabras.size();j++){
			   if(i!=j){
				   if((conectados(palabras[i],palabras[j]))){
					  (adyacencia[i])[j]=0; 
				   }else{
					   (adyacencia[i])[j]=1;				  
				   }
				}else{
					 (adyacencia[i])[j]=0;
				}
			}
		}
		
		
		
		condicion = true;
		getline( cin, line);
		test_i =0; 
		while(condicion){
			getline( cin, line);
			test_i++;
			if(!line.empty()){
				source = line.substr(0,line.find_first_of(' '));
				destino = line.substr(line.find_first_of(' ')+1);
				BFS(palabras,source,destino);
			}else{
				condicion = false;
			}
		}
		
		
		cantCasos--;
		if (cantCasos != 0) cout<<endl;
	}
}




