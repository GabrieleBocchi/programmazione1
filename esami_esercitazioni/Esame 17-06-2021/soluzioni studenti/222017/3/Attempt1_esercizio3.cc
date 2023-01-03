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
albero creaAlberoDiRicercaBinario(albero radice);
void wrapperCreaAlbero(albero & even_tree, albero radice);
void StampaAlberoInOrdine(albero radice);
void deallocaAlbero(albero radice);
void insertElement(albero & even_tree, int value);



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

// SB: la funzione ritorna 
albero creaAlberoDiRicercaBinario(albero radice){
    albero even_tree = NULL;
    wrapperCreaAlbero(even_tree,radice);
    return even_tree;
}

void wrapperCreaAlbero(albero & even_tree, albero radice){
    if(radice != NULL){
        // SB: forse l'invocazione doveva esser alla funzione wrapper, non all'originale "creaAlberoDiRicercaBinario"
        creaAlberoDiRicercaBinario(radice->left);
        if ((radice->value % 2) == 0){
            insertElement(even_tree,radice->value);
        }
        creaAlberoDiRicercaBinario(radice->right);
    }
}

// SB: ok
void insertElement(albero & even_tree, int value){
    if (even_tree == NULL){
        even_tree = new (nothrow) nodo;
        if (even_tree != NULL){
            even_tree->value = value;
            even_tree->left = NULL;
            even_tree->right = NULL;
        }
    }else if(even_tree->value >= value){
        insertElement(even_tree->left,value);
    }else{
        insertElement(even_tree->left,value);
    }
}

// SB: ok
void StampaAlberoInOrdine(albero radice){
    if (radice != NULL){
        StampaAlberoInOrdine(radice->right);
        cout << radice->value << " ";
        StampaAlberoInOrdine(radice->left);
    }
}

// SB: si devono deallocare prima i nodi a destra/sinistra e solo infine la radice
void deallocaAlbero(albero radice){
    if (radice != NULL){
        deallocaAlbero(radice->left);
        delete radice;
        deallocaAlbero(radice->right);
    }
}
