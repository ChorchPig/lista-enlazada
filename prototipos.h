#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#define LIST_ELEMENT int

typedef struct _sll_node {
    LIST_ELEMENT value;
    struct _sll_node* next;
} sll_node;

sll_node* sll_node_create (LIST_ELEMENT element);
void sll_print(sll_node* head);
int sll_add_node(sll_node** head, sll_node* new_node);
void sll_add(sll_node** head, LIST_ELEMENT element);
void sll_add_first(sll_node** head, LIST_ELEMENT element);
sll_node* sll_remove_element(sll_node** head, LIST_ELEMENT element);
int sll_remove(sll_node** head, LIST_ELEMENT element);
int sll_remove_all(sll_node** head, LIST_ELEMENT element);

int listaOrdenada(sll_node*);
LIST_ELEMENT obtenerValorMinimo(sll_node *);

#endif // PROTOTIPOS_H_INCLUDED
