#include <iostream>

using namespace std;

struct carro{
    int placa;
    carro *sig;
};
carro *cab, *aux, *aux2;

int registrar(){
    aux = (struct carro *) malloc (sizeof(struct carro));
    aux->sig = NULL;
    cout<<"Registrar Auto ultimo numero placa: "<<endl;
    cin>>aux->placa;
    if(!cab){
        cab = aux;
    } else {
        aux2 = cab;
        while(aux2->sig != NULL) {
            aux2 = aux2->sig;
        }
        aux2->sig = aux;
    }
    aux = aux2 = NULL;
    free(aux);
    free(aux2);

}
int mostrar(){
        aux2 = cab;
        while(aux2 != NULL) {
            cout<<"Auto: "<<aux2->placa<<endl;
        }
        aux2->sig = aux;
}

int main(){
    int opcion = 0;
    do {
        cout<<"Menu"<<endl;
        cout<<"1. Registrar Autos"<<endl;
        cout<<"2. Mostrar Autos"<<endl;
    } while(opcion!=5);
    return 0;
}