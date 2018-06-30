#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <sys/time.h>
#include <time.h>


using namespace std;

bool mayor(int a, int b){
    return a>b;
}

bool menor(int a, int b){
    return a<=b;
}



int main()
{


vector<int> medianas;
priority_queue< int,vector<int>, greater<int> > MasGrandesQueMediana;
priority_queue< int,vector<int>, less<int> > MasChicosQueMediana;

int a;
int cuenta=1;
int cantmedianas =0;
int tamChicos;
int tamGrandes;
int  med;
int auxtope;
    while(cin>>a){
        if(cuenta==1){
            MasChicosQueMediana.push(a);
            medianas.push_back(a);
            cantmedianas++;
            }else{
                if(cuenta % 2 == 0){
                    if(a>medianas[cantmedianas-1]){
                            MasGrandesQueMediana.push(a);
                            tamGrandes=MasGrandesQueMediana.size();
                            tamChicos=MasChicosQueMediana.size();
                               if((tamGrandes-tamChicos > 1)){
                                    auxtope=MasGrandesQueMediana.top();
                                MasChicosQueMediana.push(auxtope);
                                MasGrandesQueMediana.pop();
                                med=((MasChicosQueMediana.top()+MasGrandesQueMediana.top())/2);
                                medianas.push_back(med);
                                cantmedianas++;
                                }else{
                                    med=((MasChicosQueMediana.top()+MasGrandesQueMediana.top())/2);
                                     medianas.push_back(med);
                                    cantmedianas++;
                                }

                            }else{ 
                                MasChicosQueMediana.push(a);
                                tamGrandes=MasGrandesQueMediana.size();
                               tamChicos=MasChicosQueMediana.size();
                               if((tamChicos-tamGrandes > 1)){
                                    auxtope=MasChicosQueMediana.top();
                                    MasGrandesQueMediana.push(auxtope);
                                    MasChicosQueMediana.pop();
                                    med=((MasChicosQueMediana.top()+MasGrandesQueMediana.top())/2);
                                    medianas.push_back(med);
                                    cantmedianas++;
                               }else{
                                med=((MasChicosQueMediana.top()+MasGrandesQueMediana.top())/2);
                                medianas.push_back(med);
                                cantmedianas++;
                               }
                            }

                }else{
                    if(a>medianas[cantmedianas-1]){
                            MasGrandesQueMediana.push(a);
                            med=MasGrandesQueMediana.top();
                            medianas.push_back(med);
                            cantmedianas++;
                    }else{
                        MasChicosQueMediana.push(a);
                            med=MasChicosQueMediana.top();
                            medianas.push_back(med);
                            cantmedianas++;
                    }

                }

            }

            cuenta++;
    }
    int contador=0;
    while(contador<medianas.size()){
        cout<<medianas[contador]<<endl;
        contador++;
    }

}
