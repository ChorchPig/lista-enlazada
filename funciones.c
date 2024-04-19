#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

sll_node* sll_node_create (LIST_ELEMENT element) {
    sll_node* new_node = (sll_node*)malloc(sizeof(sll_node));
    if (new_node != NULL) {
        new_node->value = element;
        new_node->next = NULL;
    }
    return new_node;
}

void sll_print(sll_node* head) {
    if(!head)return;
    sll_node* aux = head;
    while (aux != NULL) {
        printf("%d ", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

int sll_add_node(sll_node** head, sll_node* new_node) {
    if (new_node == NULL) return 0;
    sll_node** aux = head;
    while (*aux != NULL) {
        aux = &(*aux)->next;
    }
    *aux = new_node;
    return 1;
}

void sll_add(sll_node** head, LIST_ELEMENT element) {
    sll_node* new_node = sll_node_create(element);
    sll_add_node(head, new_node);
}

void sll_add_first(sll_node** head, LIST_ELEMENT element) {
    sll_node* aux = sll_node_create(element);
    aux->next = *head;
    *head = aux;
}

sll_node* sll_remove_element(sll_node** head, LIST_ELEMENT element) {
    sll_node* node_to_remove = NULL;
    sll_node** aux = head;
    while (*aux != NULL && (*aux)->value != element) {
        aux = &(*aux)->next;
    }
    if (*aux != NULL) {
        node_to_remove = *aux;
        *aux = (*aux)->next;
        node_to_remove->next = NULL;
    }
    return node_to_remove;
}

int sll_remove(sll_node** head, LIST_ELEMENT element) {
    int result = 0;
    sll_node** aux = head;
    while (*aux != NULL && (*aux)->value != element) {
        aux = &(*aux)->next;
    }
    if (*aux != NULL) {
        sll_node* node_to_remove = *aux;
        *aux = (*aux)->next;
        node_to_remove->next = NULL;
        free(node_to_remove);
        result = 1;
    }
    return result;
}

int sll_remove_all(sll_node** head, LIST_ELEMENT element) {
    int result = 0;
    sll_node** aux = head;
    while (*aux != NULL) {
        if ((*aux)->value==element) {
            sll_node* node_to_remove = *aux;
            *aux = (*aux)->next;
            node_to_remove->next = NULL;
            free(node_to_remove);
            result = 1;
        }
        else aux = &(*aux)->next;
    }

    return result;
}

void eliminarDuplicados(sll_node *lista){
    sll_node *aux=lista;
    while(aux){
        if(existeEnLista(aux->next, aux->value))sll_remove_all(&aux->next, aux->value);
        aux=aux->next;
    }
}

int existeEnLista(sll_node *lista, LIST_ELEMENT elemento){
    int existe=0;
    if(lista){
        sll_node *aux=lista;
        if(aux->value==elemento)existe=1;
        while(aux->next&&!existe){
            if(aux->value==elemento)existe=1;
            aux=aux->next;
        }
    }
    return existe;
}

void fusionarListas(sll_node *lista1, sll_node *lista2){
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
        sll_remove(&lista, lista->value);
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

sll_node* copiarListaInvertida(sll_node *lista){
    sll_node *nuevaLista=NULL, *aux=lista;
    while(aux){
        sll_add_first(&nuevaLista, aux->value);
        aux=aux->next;
    }
    return nuevaLista;
}
