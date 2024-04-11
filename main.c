#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(){
    return 0;
}

int listaOrdenada(sll_node *lista){
    if(lista==NULL)return 0;
    sll_node *aux=lista;
    int ordenada=1;
    while((aux->next!=NULL)&&ordenada==1){
        if(aux->value>aux->next->value)ordenada=0; //mandar el criterio de comparación como función aparte
        aux=aux->next;
    }
    return ordenada;
}

LIST_ELEMENT obtenerValorMinimo(sll_node *lista){
    LIST_ELEMENT minimun=9999;
    if(lista==NULL)return minimun;
    sll_node *aux=lista;
    while(aux->next!=NULL){
        if(minimun>aux->value)minimun=aux->value;
        aux=aux->next;
    }
    return minimun;
}
