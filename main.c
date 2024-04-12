#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"


void dividirLista(sll_node*,sll_node*);
void eliminarLista(sll_node*);
void fusionarListas(sll_node*,sll_node*);

int main(){
    sll_node *lista1=NULL, *lista2=NULL;
    sll_add(&lista1, 1);
    sll_add(&lista2, 2);
    sll_add(&lista1, 3);
    sll_add(&lista2, 4);
    sll_add(&lista1, 5);
    sll_print(lista1);
    sll_print(lista2);
    fusionarListas(lista1, lista2);
    sll_print(lista1);
    eliminarLista(lista1);
    return 0;
}

void fusionarListas(sll_node *lista1, sll_node *lista2){//asume que lista1->value<lista2->value
    sll_node *aux1=lista1, *aux2=lista2;
    while(aux1->next&&aux2){
        if(aux1->next->value>aux2->value){
            lista2=lista2->next;
            aux2->next=aux1->next;
            aux1->next=aux2;
            aux2=lista2;
        }
        aux1=aux1->next;
    }
    if(aux2)sll_add_node(&lista1, aux2);
}

void eliminarLista(sll_node *lista){
    while(lista->next){
        sll_remove(&lista, lista->value); //ocurre un error si la lista posee un único elemento
    }
    free(lista);
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
