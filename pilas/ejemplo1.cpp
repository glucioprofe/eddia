#include <iostream>

using namespace std;

struct nodo{
    int id;
    nodo *sig;
};

nodo *cab, *aux, *aux2;

int registrar(){
    aux = (struct nodo *) malloc (sizeof(struct nodo));
    if(!cab){
        cab = aux;
        cab->sig = NULL;
        cab->id = 1;
    } else {
        aux->id = cab->id + 1;
        aux->sig = cab;
        cab = aux;
    }
    aux = NULL;
    free(aux);
    return 0;
}
int mostrar(){
    aux = cab;
    while(aux != NULL) {
        cout<<"Nodo: "<<aux->id<<endl;
        aux = aux->sig;
    }
    return 0;
}
int main(){
    int opcion = 0;
    do {
        cout<<"Menu Pila"<<endl;
        cout<<"1. Registrar Nodo"<<endl;
        cout<<"2. Mostrar Nodo"<<endl;        
        //cout<<"3. Eliminar Nodo"<<endl;        
        cout<<"5. Salir"<<endl;        
        cin>>opcion;
        switch (opcion)
        {
            case 1: registrar();
            break;
            case 2: mostrar();
            break;
        }
    } while(opcion!=5);    
    return 0;
}