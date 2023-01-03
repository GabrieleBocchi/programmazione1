#include <iostream>
#include <cstdlib>

using namespace std;

struct nodo {
    int value;
    nodo* left;
    nodo* right;
};
typedef nodo* albero;


albero generaAlbero(int numeroDiNodi = 10);
void stampaAlbero(albero radice, int spazio=0);
void deallocaAlbero(albero t);
void StampaAlberoInOrdine(albero t);
albero creaAlberoDiRicercaBinario (albero alberoiniziale);


int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale


    albero alberoIniziale = generaAlbero();
    //stampaAlbero(alberoIniziale); // nel caso in cui possa essere utile, la funzione "stampaAlbero" stampa graficamente l'albero a video

    albero alberoBinario = creaAlberoDiRicercaBinario(alberoIniziale);
    cout << "L'albero di ricerca binario è: ";
    StampaAlberoInOrdine(alberoBinario);
    cout << endl;

    deallocaAlbero(alberoIniziale);
    deallocaAlbero(alberoBinario);

    return 0;
}


albero generaAlbero(int numeroDiNodi) {
    
    // Se modificate la funzione "generaAlbero", ricordarsi poi di ripristinare il codice originale

    srand(time(NULL));
    nodo* nodi[numeroDiNodi];

    cout << "L'albero iniziale è:";

    for (int i = 0; i<numeroDiNodi; i++) {
        nodi[i] = new nodo;
        nodi[i]->value = rand() % 10;
        nodi[i]->left = NULL;
        nodi[i]->right = NULL;
        cout << " " << nodi[i]->value;
    }
    cout << endl;

    for (int i = 0; (2*i + 1)<numeroDiNodi; i++) {
        nodi[i]->left = nodi[2*i + 1];
        if ((2*i + 2) < numeroDiNodi) {
            nodi[i]->right = nodi[(2*i + 2)];
        }
    }

    return nodi[0];
}

void stampaAlbero(albero radice, int spazio) {

    // Se modificate la funzione "stampaAlbero", ricordarsi poi di ripristinare il codice originale

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


/* 
 * Inserire qui la definizione di "creaAlberoDiRicercaBinario", "StampaAlberoInOrdine", 
 * "deallocaAlbero" e di eventuali altre funzioni ausiliarie.
 */

// SB: funzione non invocata nel programma
int numpariAlbero(albero alberoiniziale){
    int counter = 0;
    if (alberoiniziale!=NULL){
        if (alberoiniziale->left==NULL && alberoiniziale->right == NULL){
            if(alberoiniziale->value%2==0) {
                counter++;
            }
        }
        creaAlberoDiRicercaBinario(alberoiniziale->left);
        creaAlberoDiRicercaBinario(alberoiniziale->right);
    }
    return counter;
}

// SB: alla prima invocazione, assumendo un albero con una radice con entrambi
//     i nodi figli, la funzione ritorna semplicemente "t", una variabile non inizializzata
albero creaAlberoDiRicercaBinario (albero alberoiniziale){

    
    nodo* t;

    if (alberoiniziale!=NULL){
        if (alberoiniziale->left==NULL && alberoiniziale->right == NULL){
            if(alberoiniziale->value%2==0) {
                t = new nodo;
                t->value = alberoiniziale->value;
                t->left = creaAlberoDiRicercaBinario(alberoiniziale->left);
                t->right = creaAlberoDiRicercaBinario(alberoiniziale->right);
            }
        }
        creaAlberoDiRicercaBinario(alberoiniziale->left);
        creaAlberoDiRicercaBinario(alberoiniziale->right);
    }

    return t;
}

// SB: vengono stampate solo le foglie
void StampaAlberoInOrdine(albero t) {
    if (t!=NULL){
        if (t->left==NULL && t->right == NULL){
            cout<<t->value<<endl;
        }
        StampaAlberoInOrdine(t->left);
        StampaAlberoInOrdine(t->right);
    }
}

// SB: vengono deallocate solo le foglie
void deallocaAlbero(albero t) {
    if (t!=NULL){
        if (t->left==NULL && t->right == NULL){
            delete t;
        }
        deallocaAlbero(t->left);
        deallocaAlbero(t->right);
    }
}