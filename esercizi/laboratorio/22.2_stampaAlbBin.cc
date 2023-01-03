#include <iostream>
#include <fstream>
 
using namespace std;
 
struct nodo {
    int value;
    nodo* left;
    nodo* right;
};
typedef nodo* albero;
 
 
albero creaAlberoDiRicercaBinaria(char * file);
void inserisciNodo(albero radice, nodo* nuovoNodo);
void stampaAlbero(albero radice, int spazio=0);
void stampaAlberoCrescente(albero radice);
 
 
int main (int argc, char * argv[]) {
 
    if (argc != 2) {
        cout << "Usage: ./a.out <file>" << endl;
        exit(1);
    }
 
    albero radice = creaAlberoDiRicercaBinaria(argv[1]);
 
    if (radice == NULL) {
        cout << "Errore nella creazione dell'albero" << endl;
    } else {
        cout << "Albero di ricerca binaria: " << endl << endl;
        stampaAlbero(radice);
        cout << endl;
        cout << "Elementi dell'albero in ordine crescente: " << endl << endl;
        stampaAlberoCrescente(radice);
        cout << endl;
    }
    return 0;
}
 
albero creaAlberoDiRicercaBinaria(char * file) {
 
    albero radice = NULL;
    fstream input;
 
    input.open(file, ios::in);
    if (input.fail()) {
        cout << "Errore in lettura" << endl;
    } else {
 
        int numero;
        input >> numero;
        radice = new nodo{numero, NULL , NULL};    
 
        while(input >> numero) {
            nodo* nuovoNodo = new nodo{numero, NULL, NULL};
            inserisciNodo(radice, nuovoNodo);
        }
 
        input.close();
    }
 
    return radice;
}
 
 
void inserisciNodo(albero radice, nodo* nuovoNodo) {
 
    if (nuovoNodo->value > radice->value) {
        if (radice->right == NULL) {
            radice->right = nuovoNodo;
        } else {
            inserisciNodo(radice->right, nuovoNodo);
        }
    } else {
        if (radice->left == NULL) {
            radice->left = nuovoNodo;
        } else {
            inserisciNodo(radice->left, nuovoNodo);
        }
    }
}
 
void stampaAlbero(albero radice, int spazio) {
   if (radice != NULL) {
    spazio ++;
 
    stampaAlbero(radice->right, spazio);
 
    for (int i = 1; i < spazio; i++) {
        cout<<"\t";
    }
    cout<<radice->value<<"\n";
 
    stampaAlbero(radice->left, spazio);
   }
}

void stampaAlberoCrescente(albero radice)
{
    if (radice->left != NULL)
    {
        stampaAlberoCrescente(radice->left);
        cout << radice->value << "  ";
    }
    else
        cout << radice->value << "  ";
    if (radice->right != NULL)
        stampaAlberoCrescente(radice->right);
    return;
}