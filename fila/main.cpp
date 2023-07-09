#include <iostream>
#include "prototipos.h"

//Es necesario modificar quitarLista
int main(){
    nodo *inicioFila=NULL;
    nodo *finalFila=NULL;
    int option=1, num=0;
    while(option){
        std::cout<<"Select an option \n\t";
        std::cout<<"1. Add data to the queue \n\t2. Remove data from the queue ";
        std::cout<<"\n\t3. Show queue \n\t0. Exit program \n";
        std::cin>>option;
        switch(option){
            case 0: confirmarSalida(&option); break;
            case 1: {
                std::cout<<"Give me a number: ";
                std::cin>>num;
                insertarFila(inicioFila, finalFila, num);
                std::cout<<num<<" succesfuly stored.\n";
            } break;
            case 2: {
                if(inicioFila)quitarLista(inicioFila, finalFila);
                else std::cout<<"The queue is empty.\n";
            } break;
            case 3: {
                if(inicioFila){
                    mostratFila(inicioFila, finalFila);
                }
                else{
                    std::cout<<"The queue is empty.\n";
                }
            } break;
            default : std::cout<<"No option selected\n";
        }
    }
    while(inicioFila){
        quitarFila(inicioFila, finalFila);
    }
    return 0;
}
