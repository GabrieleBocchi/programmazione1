#ifndef codaFilaPoste_h
#define codaFilaPoste_h
 
struct nodo {
	char* nome;
	nodo* next;
};
typedef nodo* lista;
 
struct coda {
    lista tail;
    lista head;
};
 
void init ();
bool enqueue(char *);
bool first(char * &);
bool dequeue();
void deinit();
void print();
 
#endif