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
void ricerca(albero radice, int n);
 
 
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
        int n;
        cout << "Inserire il numero che si vuole ricercare: ";
        cin >> n;
        cout << endl;
        cout << "L'elemento si trova al seguente percorso: " << endl << endl;
        ricerca(radice, n);
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

void ricerca(albero radice, int n)
{
    if (radice->value == n)
    {
        cout << radice->value << endl;
        return;
    }
    if ((n < radice->value && radice->left == NULL) || (n > radice->value && radice->right == NULL))
    {
        cout << radice->value << " -> Il numero non e' presente nell'albero" << endl;
        return;
    }
    else if (n < radice->value)
    {
        cout << radice->value << " -> sinistra -> ";
        ricerca(radice->left, n);
    }
    else if (n > radice->value)
    {
        cout << radice->value << " -> destra -> ";
        ricerca(radice->right, n);
    }
    return;
}