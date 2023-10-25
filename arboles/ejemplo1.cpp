#include <iostream>

using namespace std; 

struct nodo {
    int valor;
    nodo *izq;
    nodo *der;
};

nodo *raiz, *aux, *aux2;

int posicionar(){
    if(aux->valor < aux2->valor){
        if(aux2->izq==NULL){
            aux2->izq = aux;
            aux2 = aux = NULL;
            free(aux);
            free(aux2);
        } else {
            aux2 = aux2->izq;
            posicionar();
        }
    } 
    else if(aux->valor > aux2->valor){
        if(aux2->der==NULL){
            aux2->der = aux;
            aux2 = aux = NULL;
            free(aux);
            free(aux2);
        } else {
            aux2 = aux2->der;
            posicionar();
        }
    }
};
int registrar(){
    aux = (struct nodo *)malloc(sizeof(struct nodo));
    cout<<"Ingrese el valor: ";
    cin>>aux->valor;
    aux->der = aux->izq = NULL;
    if(!raiz){
        raiz = aux;
        aux = NULL;
        free(aux);
    }
    else {
        aux2 = raiz;
        posicionar();
    }
};

int mostrar(nodo *item){
    if(item!=NULL){
        cout<<"Valor "<<item->valor<<endl;
        mostrar(item->izq);
        mostrar(item->der);
    }
    return 0;
    
};
//int eliminar();

int main(){
    int opc=0;
    do{
        cout<<"1. Registrar Nodo"<<endl;
        cout<<"2. Mostrar Nodo"<<endl;
        cout<<"3. Eliminar Nodo"<<endl;
        cout<<"5. Salir"<<endl;
        cin>>opc;
        switch (opc)
        {
            case 1: registrar(); break;
            case 2: mostrar(raiz); break;
            //case 3: eliminar(); break;
        }
    }while(opc!=5);

}


