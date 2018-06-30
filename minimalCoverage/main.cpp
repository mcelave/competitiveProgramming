#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <utility>
#include <time.h>
#include <sys/time.h>
using namespace std;

bool menor(pair<int, int> d1, pair<int, int> d2){
       if(d1.first==d2.first){
          return (d1.second<d2.second);
       }else{
           return (d1.first<d2.first);
       }
}

bool NoEsValido(pair<int,int> p){
        return (((p.first<0) && (p.second<0)));
}

void imprimirSolucion(vector < pair<int, int> > solution){
    cout<<solution.size()<<endl;
    int i=0;
    while(i<solution.size()){
        cout<<solution[i].first<<" "<<solution[i].second<<endl;
        i++;
    }
}

bool esta(int m,pair<int, int> d1){
    return((d1.first<=m) && (d1.second>=m));
}

bool sePasa(int m, pair<int, int> d1){
    return ((m>d1.first) &&(d1.second<m));
}

bool HayEspacios(pair<int,int> d1, pair<int,int> d2){
    return ((d1.second)<(d2.first));
}

bool HaySolucion(vector< pair<int, int> > vec, int m){
    int j= 0;
    bool termine=false;
    bool haySol=true;
		if(vec[0].first<=0 &&vec[vec.size()-1].second>=m){
			while((j<vec.size() -1) &&!termine){
				if(HayEspacios(vec[j],vec[j+1])){
                    termine = true;
                    haySol=false;
                }
                j++;
			}	
		}else{
		return false;
	}
	return haySol;

}


void minCover( vector<pair<int,int> > intervalos, int m, vector<pair<int,int> > solParcial){
unsigned int j=0;
int cubierto=0;
pair<int,int> ultimoVisto=intervalos[0];
while((j<intervalos.size()) && (cubierto<m)){
		if(esta(cubierto,intervalos[j])){
				if((intervalos[j].second) > (ultimoVisto.second)){
					ultimoVisto=intervalos[j];
				}
			}else{
				if(!sePasa(cubierto,intervalos[j])){
						cubierto=ultimoVisto.second;
						solParcial.push_back(ultimoVisto);
						ultimoVisto=intervalos[j];
						j--;
					}
				}
					
	
		if((j==intervalos.size()-1)&& esta(cubierto,ultimoVisto)){
			solParcial.push_back(ultimoVisto);
			}
	j++;	
}

if(HaySolucion(solParcial,m)){
			imprimirSolucion(solParcial);
		}else{
			cout<<"0"<<endl;
		}
}

int main()
{

  int cuenta;
   cin>>cuenta;
   cout<<endl;
   int cont=cuenta;
    while(cont>0){
        vector< pair<int,int> > v;
        int a,b,M;
        cin>>M;   
        bool Entrada=true;
        while(Entrada){
            cin>>a>>b;
             pair<int, int> d(a,b);
            if(a==0 && b==0){
                Entrada=false;
                cout<<endl;
            }else{
                if(!NoEsValido(d)){
                    v.push_back(d);
                }
            }
        }
     if(v.size()!=0){
		sort(v.begin(),v.end(),menor);
		vector<pair<int,int> > sp;
		minCover(v,M,sp);
	}else{
		cout<<"0"<<endl;
	}
cont--;
    }  
    
}
