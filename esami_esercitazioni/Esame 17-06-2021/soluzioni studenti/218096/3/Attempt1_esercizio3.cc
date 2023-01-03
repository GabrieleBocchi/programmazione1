#include <iostream>
#include <cstdlib>

using namespace std;

struct nodo {
    int value;
    nodo* left;
    nodo* right;
};
typedef nodo* albero;

typedef nodo* alberoBinario;


albero generaAlbero(int numeroDiNodi = 10);
void stampaAlbero(albero radice, int spazio=0);

bool insert(albero& t, int value);
alberoBinario creaAlberoDiRicercaBinario(albero a);
void creaAlberoAux(albero ,alberoBinario& t);
void StampaAlberoInOrdine(alberoBinario t);
void deallocaAlbero(alberoBinario& t);


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

// SB: (solo un'osservazione) il valore di ritorno è sempre "false" e non è mai usato
bool insert(albero& t, int value){
    if(t==NULL){
        t = new (nothrow) nodo;
        if(t!=NULL){
            t->value = value;
        }else{
            return false;
        }
    }else if(value <= t->value){
        return insert(t->left, value);
    }else{
        return insert(t->right, value);
    }
    return false;
}

// SB: ok, ma la funzione inserisce nell'albero di ricerca binario anche i numeri pari
alberoBinario creaAlberoDiRicercaBinario(albero a){
    alberoBinario t;
    creaAlberoAux(a,t);
    return t;
}


void creaAlberoAux(albero a,alberoBinario& t){
    if(a!=NULL){
        insert(t,a->value);
        creaAlberoAux(a->left,t);
        creaAlberoAux(a->right,t);
    }
}

// SB: ok
void StampaAlberoInOrdine(alberoBinario t){
    if(t!=NULL){
        StampaAlberoInOrdine(t->left);
        cout << t->value << " ";
        StampaAlberoInOrdine(t->right);
    }
}

// SB: ok
void deallocaAlbero(alberoBinario& t){
    if(t!=NULL){
        deallocaAlbero(t->left);
        deallocaAlbero(t->right);
        delete t;
        t = NULL;
    }
}