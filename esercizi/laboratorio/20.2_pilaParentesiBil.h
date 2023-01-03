#ifndef pilaParentesiBil_h
#define pilaParentesiBil_h
 
struct nodo {
    int value;
    nodo* next;
};
typedef nodo* lista;
 
void init();
bool push(int);
bool top(int &);
bool pop();
void deinit();
 
#endif