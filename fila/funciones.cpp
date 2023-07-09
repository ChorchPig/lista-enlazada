#include <iostream>
#include "prototipos.h"

void insertarFila(nodo *&inicioFila, nodo *&finalFila, int num){
    nodo *nuevoNodo=new nodo();
    nuevoNodo->dato=num;
    nuevoNodo->siguiente=NULL;
    (inicioFila==NULL)?inicioFila=nuevoNodo:finalFila->siguiente=nuevoNodo;
    finalFila=nuevoNodo;
}

void quitarFila(nodo *&inicioFila, nodo *&finalFila){
    nodo *aux=inicioFila;
    if(inicioFila==finalFila){
        inicioFila=NULL;
        finalFila=NULL;
    }
    else{
        inicioFila=inicioFila->siguiente;
    }
    delete aux;
}

void mostratFila(nodo *&inicioFila, nodo*&finalFila){
    nodo *aux=inicioFila;
    while(aux){
        std::cout<<aux->dato<<"\n";
        aux=aux->siguiente;
    }
}

void quitarLista(nodo *&inicioFila, nodo *&finalFila){
    //resulta imposible eliminar el último elemento de la lista enlazada
    int num=0;
    nodo *aux=inicioFila;
    std::cout<<"Element to remove: ";
    std::cin>>num;
    if(inicioFila->dato==num)quitarFila(inicioFila, finalFila);
    else{
            while(aux->siguiente!=finalFila){
                if(aux->siguiente->dato==num)quitarFila(aux->siguiente, finalFila);
                else aux=aux->siguiente;
            }
        }
}

void confirmarSalida(int *option){
    std::cout<<"You are about to exit the program, to confirm this action press 0.\n";
    std::cin>>*option;
}
