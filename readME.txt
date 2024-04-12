sll_node_create(LIST_ELEMENT element)
crea un nodo de una lista enlazada que almacena element y devuelve un puntero a la dirección de memoria de ese nodo

list_print_r (sll_node* a_node, void pnt(LIST_ELEMENT))
imprime de manera recursiva la lista enlazada que empieza por a_node, mediante la función pnt

sll_print(sll_node* head)
imprime de forma iterativa la lista que empieza por head

sll_add_node(sll_node** head, sll_node* new_node)
agrega new_node al final de la lista que empieza en head, si new_node es nulo devuelve 0 y devuelve 1 en caso contrario

sll_add_node2(sll_node** head, sll_node* new_node)
funciona igual a sll_add_node, la implementación interna varía ligeramente

sll_add(sll_node** head, LIST_ELEMENT element)
crea al final de la lista un nodo nuevo que contiene element como dato

sll_add2(sll_node** head, LIST_ELEMENT element)
crea un nuevo nodo que contiene element e invoca a sll_add_node para añadirlo a la lista

sll_add_first(sll_node** head, LIST_ELEMENT element)
crea un nuevo nodo que contiene a element y lo añade al principio de la lista

sll_remove_element(sll_node** head, LIST_ELEMENT element)
elimina el nodo que contiene a element de la lista y devuelve su posición de memoria

sll_remove_element2(sll_node** head, LIST_ELEMENT element)
funciona igual a sll_remove_element pero cambia implementación interna

sll_remove(sll_node** head, LIST_ELEMENT element)
elimina el nodo que contiene a element de la lista y libera el espacio de memoria, devuelve 1 si no hubo problema alguno y 0 en caso contrario

sll_remove_all(sll_node** head, LIST_ELEMENT element)
libera el espacio de memoria de todos los nodos que contengan element, devuelve 1 si no hubo ningún problema y 0 en caso contrario

sll_remove_element4(sll_node** head, LIST_ELEMENT element)
funciona igual a sll_remove pero cambia su implementación interna

sll_remove_duplicates(sll_node** head)

