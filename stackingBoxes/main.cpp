#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <ctime>
#include <time.h>
#include <sys/time.h>
#include <iomanip>
#include <cmath>
#include <stdio.h>
using namespace std;

typedef pair< int,int> caja;


int main()
{
     int n;
    while (cin >> n && n!=0){
    int peso,cap;
     caja cajitas[n];
    for(int i=0; i<n; i++){
      int peso, cap;
      cin >> peso >> cap;
      caja aux(peso,cap);
      cajitas[i]=aux;
    }
    int resistencias[n];
    for(int y=0;y<n;y++){
        resistencias[y]=-1;
    }
    for(int box=0;box<n;box++){

       for(int k=box;k>=0;k--){
            if(k==0){
                if(resistencias[k]<cajitas[box].second){
                    resistencias[k]=cajitas[box].second;
                }
            }else{
                if(resistencias[k-1]>=cajitas[box].first){
                  int aux=min(resistencias[k-1]-cajitas[box].first,cajitas[box].second);

                  if(aux>resistencias[k]){
                        resistencias[k]=aux;
                  }
                }
            }
        }
    }
        bool termine=false;
        int cuenta=0;
        int j=0;
        while((j<n)&&(!termine)){
            if(resistencias[j]!=-1){
                cuenta++;
            }else{
                termine=true;
            }
            j++;
        }
        cout<< cuenta<<endl;
    }
  
 }
  






