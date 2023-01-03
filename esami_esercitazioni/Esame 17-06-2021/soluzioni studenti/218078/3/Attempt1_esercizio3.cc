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
albero creaAlberoDiRicercaBinario(albero &sourceTree);
void StampaAlberoInOrdine(const albero &t);
void deallocaAlbero(albero &t);



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


void insertNode(albero &t, const int value){
    if (t == NULL){
        albero q = new (nothrow) nodo;
        if (q == NULL){
            cerr << "Impossible to insert node" << endl;
            exit(1);
        }
        q->value = value;
        cout << "Inserito " << q->value << endl;
        t = q;
    } else if (value < t->value){
        insertNode(t->left, value);
    } else
        insertNode(t->right, value);
}




void creaAlberoDiRicercaBinarioAux(const albero &sourceTree, albero &destTree) {
    if (sourceTree != NULL){
        if (sourceTree->value%2 == 0)
            insertNode(destTree, sourceTree->value);
        
        creaAlberoDiRicercaBinarioAux(sourceTree->left, destTree);
        creaAlberoDiRicercaBinarioAux(sourceTree->right, destTree);
    }
    
}

// SB: ok
albero creaAlberoDiRicercaBinario(albero &sourceTree) {
    albero tree = NULL;
    creaAlberoDiRicercaBinarioAux(sourceTree, tree);
    return tree;
}

// SB: ok
void StampaAlberoInOrdine(const albero &t){
    if (t != NULL){
        StampaAlberoInOrdine(t->left);
        cout << t->value << " ";
        StampaAlberoInOrdine(t->right);
    }
}

// SB: ok
void deallocaAlbero(albero &t){
    if (t!=NULL){
        deallocaAlbero(t->left);
        deallocaAlbero(t->right);
        delete t;
    }
}

