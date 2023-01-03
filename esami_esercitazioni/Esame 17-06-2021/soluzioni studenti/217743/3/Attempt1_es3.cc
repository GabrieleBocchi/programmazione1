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
void StampaAlberoInOrdine(const albero a);
nodo* creaAlberoDiRicercaBinario(const albero a);

// SB: ok
void deallocaAlbero(albero &a){
    if(a!= NULL){
        deallocaAlbero(a->left);
        deallocaAlbero(a->right);
        delete a;
    }
}

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

// SB: ok
void StampaAlberoInOrdine(const albero a){
    if (a!= NULL){
        StampaAlberoInOrdine(a->right);
        cout << a->value << " ";
        StampaAlberoInOrdine(a->left);
    }
}

void insert(albero &t, int elem)
{
    if (t == NULL)
    {
        t = new nodo;
        t->left = NULL;
        t->right = NULL;
        t->value = elem;
    }
    else if (elem < t->value)
    {
        insert(t->left, elem);
    }
    else if (elem > t->value)
    {
        insert(t->right, elem);
    }
}
void crea(albero s, albero &d){
    if (s!= NULL){
        if (s->value %2 == 0){
            insert(d, s->value);
        }
        crea(s->left,d);
        crea(s->right,d);
    }
}
// SB: ok
nodo* creaAlberoDiRicercaBinario(const albero a){
    nodo * n;
    crea(a,n);
    return n;
}