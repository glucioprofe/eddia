#include <iostream>

using namespace std;

struct nodo{
    int id;
    nodo *sig;
};
nodo *cab, *aux, *aux2;

int registrar(){    
    if(!cab){
        cab = (struct nodo *) malloc (sizeof(struct nodo));
        cab->sig = NULL;   
        cab->id = 1;        
    } else {
        aux2 = cab;
        while(aux2->sig != NULL) {
            aux2 = aux2->sig;
        }
        aux = (struct nodo *) malloc (sizeof(struct nodo));
        aux->sig = NULL; 
        aux->id = aux2->id + 1; 
        aux2->sig = aux;
    }
    aux = aux2 = NULL;
    free(aux);
    free(aux2);
}
int mostrar(){
        aux2 = cab;
        while(aux2 != NULL) {
            cout<<"Nodo: "<<aux2->id<<endl;
            aux2 = aux2->sig;
        }
}
int eliminar(){
    int elemento=0;
    cout<<"Digite el identificador del nodo a eliminar: "<<endl;
    cin>>elemento;
    aux = cab;
    while(aux != NULL && aux->id!=elemento) {            
        aux = aux->sig;
    }
    if(aux!=NULL){
        aux2 = cab;
        while(aux2->sig!=aux){
            aux2 = aux2->sig;
        }
        aux2->sig = aux->sig;
        free(aux);
        aux2 = NULL;
        free(aux2);
    }
}

int main(){
    int opcion = 0;
    do {
        cout<<"Menu"<<endl;
        cout<<"1. Registrar Nodo"<<endl;
        cout<<"2. Mostrar Nodo"<<endl;        
        cout<<"3. Eliminar Nodo"<<endl;        
        cout<<"5. Salir"<<endl;        
        cin>>opcion;
        switch (opcion)
        {
            case 1: registrar();
            break;
            case 2: mostrar();
            break;               
            case 3: eliminar();
            break;               
        }
    } while(opcion!=5);
    return 0;
}