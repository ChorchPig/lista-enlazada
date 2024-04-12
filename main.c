#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"


void dividirLista(sll_node*,sll_node*);
void eliminarLista(sll_node*);
void fusionarListas(sll_node*,sll_node*);
void eliminarDuplicados(sll_node*);
int existeEnLista(sll_node*,LIST_ELEMENT);

int main(){
    sll_node *lista=NULL;
    sll_add(&lista, 1);
    sll_add(&lista, 2);
    sll_add(&lista, 1);
    sll_add(&lista, 3);
    sll_add(&lista, 1);
    sll_add(&lista, 2);
    sll_add(&lista, 3);
    sll_print(lista);
    eliminarDuplicados(lista);
    sll_print(lista);
    //eliminarLista(lista);
    return 0;
}

void eliminarDuplicados(sll_node *lista){
    sll_node *aux=lista;
    while(aux){
        if(existeEnLista(aux->next, aux->value))
            {
            sll_remove_all(&aux->next, aux->value);
        }
        aux=aux->next;
    }
}

int existeEnLista(sll_node *lista, LIST_ELEMENT elemento){
    int existe=0;
    if(lista){
        sll_node *aux=lista;
        while(aux->next&&!existe){
            if(aux->value==elemento)existe=1;
            aux=aux->next;
        }
    }
    return existe;
}

int sll_remove_all(sll_node** head, LIST_ELEMENT element) {
    int result = 0;
    while (sll_remove(head, element) == 1) {
        result = 1;
    }
    return result;
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
