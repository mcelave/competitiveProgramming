#include <iostream>


using namespace std;

int resultadosParciales[1001][1001];
bool pasePorAqui[10001][10001];
int cortes[50]; //son como mucho 50 pero podria ir accediendo

int costo(int extremoInferior,int extremoSuperior){

    int res=1000000;// nadie es mayor a este numero

    if(extremoInferior+1 == extremoSuperior){
        return 0;
    }

    if(pasePorAqui[extremoInferior][extremoSuperior]){

        return resultadosParciales[extremoInferior][extremoSuperior];
    }


    for(int i=extremoInferior+1;i<extremoSuperior;i++){

        int minimoParteIzquierda= costo(extremoInferior,i);
        int minimoParteDerecha= costo(i,extremoSuperior);
        int longitudNueva = cortes[extremoSuperior]- cortes[extremoInferior];
        res=min(res,minimoParteIzquierda+minimoParteDerecha+longitudNueva );
    }

    resultadosParciales[extremoInferior][extremoSuperior] = res;
    pasePorAqui[extremoInferior][extremoSuperior]=true;

    return res;

}

 void inicializar(int longitud){

    for(int i=0;i<longitud;i++){
        for(int j=0;j<longitud;j++){
            pasePorAqui[i][j]=false;
        }
    }


}

int main()
{
    int longitud;
    int cantCortes;
    int num;
    bool termine=false;
    while(!termine){
        cin>>num;
    if(num!=0){

        longitud=num;
        //cout<<"la longitud es "<< longitud<<endl;
        cin>>num;
        cantCortes=num;
        // cout<<"la cantidad de cortes es "<< cantCortes<<endl;
        int k=0;
        cortes[0]=0;
        int i=1;
        while(k<cantCortes){
            cin>>num;
            cortes[i]=num;
           //  cout<<"corte en "<< num<<endl;
            i++;
            k++;
        }
        cortes[cantCortes+1]=longitud;
        inicializar(longitud);
        cout<<"The minimum cutting is "<< costo(0,cantCortes+1)<<"."<<endl;

        }else{
            termine=true;
        }
    }
}




