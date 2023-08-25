#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

struct nodo{
    nodo *siguiente;
    int dato;
};

void insertarFila(nodo *&, nodo *&, int);
bool quitarLista(nodo *&, nodo *&);
void eliminarNodo(nodo *&, nodo *&);
void mostratFila(nodo *&, nodo*&);
void confirmarSalida(int *);

#endif // PROTOTIPOS_H_INCLUDED
