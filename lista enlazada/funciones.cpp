#include <iostream>
#include <cstdlib>
#include<math.h>
#include "prototipos.h"

void insertarFila(nodo *&inicioFila, nodo *&finalFila, int frec, float valor){
    nodo *nuevoNodo=new nodo();
    verificarMemoria(nuevoNodo, 1);
    nuevoNodo->valorVariable=valor;
    nuevoNodo->frecuencia=frec;
    nuevoNodo->siguiente=NULL;
    (inicioFila==NULL)?inicioFila=nuevoNodo:finalFila->siguiente=nuevoNodo;
    finalFila=nuevoNodo;
}

bool quitarLista(nodo *&inicioFila, nodo *&finalFila){
    float num=0;
    nodo *aux=inicioFila;
    std::cout<<"Element to remove: ";
    std::cin>>num;
    if(inicioFila->valorVariable==num){
        eliminarNodo(inicioFila, finalFila);
        return true;
    }
    if(inicioFila==finalFila)return false;
    while(aux->siguiente!=finalFila){
        if(aux->siguiente->valorVariable==num){
            eliminarNodo(aux->siguiente, finalFila);
            return true;
        }
        else aux=aux->siguiente;
    }
    if(aux->siguiente->valorVariable==num){
        eliminarNodo(aux->siguiente, finalFila);
        finalFila=aux;
        return true;
    }
    return false;
}

void eliminarNodo(nodo *&inicioFila, nodo *&finalFila){
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

void mostratFila(nodo *&inicioFila){
    nodo *aux=inicioFila;
    while(aux){
        std::cout<<"X: "<<aux->valorVariable<<" fa: "<<aux->frecuencia<<"\n";
        aux=aux->siguiente;
    }
}

void confirmarSalida(int *option){
    std::cout<<"You are about to exit the program, to confirm this action press 0.\n";
    std::cin>>*option;
}

void verificarMemoria(void *ptr, int llamado){
    if(!ptr){
        std::cout<<"Error occurd in the "<<llamado<<" call.\n";
        exit(EXIT_FAILURE);
    }
}

float calcularPromedio(nodo *&inicioFila){
    float promedio=0.0;
    int cantidadDatos=0;
    nodo *aux=inicioFila;
    while(aux){
        promedio=promedio+aux->valorVariable*aux->frecuencia;
        cantidadDatos+=aux->frecuencia;
        aux=aux->siguiente;
    }
    promedio/=cantidadDatos;
    return promedio;
}

float obtenerModa(nodo *&inicioFila){
    nodo *aux=inicioFila;
    float moda=-999.999;
    int frecuenciaModa=-999;
    while(aux){
        if(aux->frecuencia>frecuenciaModa){
            moda=aux->valorVariable;
            frecuenciaModa=aux->frecuencia;
        }
        aux=aux->siguiente;
    }
    return moda;
}

float calcularMediana(nodo *&inicioFila){
    float mediana=0.0;
    int frecuenciaAcumulada=0;
    nodo *aux=inicioFila;
    while(aux){
        frecuenciaAcumulada+=aux->frecuencia;
        aux=aux->siguiente;
    }
    aux=inicioFila;
    mediana=(frecuenciaAcumulada+1)/2;//Posición de la mediana
    return mediana;
}

float calcularVariabilidad(nodo *&inicioFila){
    nodo *aux=inicioFila;
    float promedio=calcularPromedio(inicioFila), variabilidad=0.0, varianza=0.0;
    int frecuenciaAcumulada=0;
    while(aux){
        frecuenciaAcumulada+=aux->frecuencia;
        aux=aux->siguiente;
    }
    aux=inicioFila;
    while(aux){
        varianza+=(pow(aux->valorVariable-promedio, 2)*aux->frecuencia)/(frecuenciaAcumulada-1);
        aux=aux->siguiente;
    }
    variabilidad=sqrt(varianza)/promedio;
    return variabilidad;
}
