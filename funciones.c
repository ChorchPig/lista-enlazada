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
    if (*head == NULL) {
        *head = new_node;
    } else {
        sll_node* aux = *head;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = new_node;
    }
    return 1;
}

int sll_add_node2(sll_node** head, sll_node* new_node) {
    if (new_node == NULL) return 0;
    sll_node** aux = head;
    while (*aux != NULL) {
        aux = &(*aux)->next;
    }
    *aux = new_node;
    return 1;
}

void sll_add(sll_node** head, LIST_ELEMENT element) {
    sll_node** aux = head;
    while (*aux != NULL) {
        aux = &(*aux)->next;
    }
    *aux = sll_node_create(element);
}

void sll_add2(sll_node** head, LIST_ELEMENT element) {
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
    sll_node* aux = *head;
    sll_node* prev = NULL;
    while (aux != NULL && aux->value != element) {
        prev = aux;
        aux = aux->next;
    }
    if (aux != NULL) {
        node_to_remove = aux;
        if (prev == NULL) {
            *head = aux->next;
        } else {
            prev->next = aux->next;
        }
        node_to_remove->next = NULL;
    }
    return node_to_remove;
}

sll_node* sll_remove_element2(sll_node** head, LIST_ELEMENT element) {
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
    while (sll_remove(head, element) == 1) {
        result = 1;
    }
    return result;
}

