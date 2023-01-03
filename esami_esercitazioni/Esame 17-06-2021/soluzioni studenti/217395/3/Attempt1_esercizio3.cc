//Pivetta Leonardo mat. 217395
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
albero creaAlberoDiRicercaBinario(albero a);
void deallocaAlbero(albero a);
void StampaAlberoInOrdine(albero a);


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

// SB: un albero di ricerca binario convenzionalmente ha i nodi con valore maggiore a destra, e i nodi con valore minore a sinistra
void inserisciSuAlbero(albero a, int val){
    if(a == NULL) return;
    if(a -> value > val){
        if(a->right == NULL){
            a->right = new nodo;
            a->right->value = val;
            a->right->right = NULL;
            a->right->left = NULL;
        }else{
            inserisciSuAlbero(a->right,val);
        }
    }else{
        if(a->left == NULL){
            a->left = new nodo;
            a->left->value = val;
            a->left->right = NULL;
            a->left->left = NULL;
        }else{
            inserisciSuAlbero(a->left, val);
        }
    }
}

void cercaValoriPari(albero a, albero out){
    if(a == NULL) return;
    if(a->value %2 == 0){
        inserisciSuAlbero(out, a->value);
    }
    cercaValoriPari(a->left, out);
    cercaValoriPari(a->right, out);
}


albero creaAlberoDiRicercaBinario(albero a){
    if(a == NULL) return NULL;
    albero out = new nodo;

    cercaValoriPari(a, out);
    return out;
}

// SB: ok
void StampaAlberoInOrdine(albero a){
    if(a != NULL){
        StampaAlberoInOrdine(a->left);
        cout << a->value << " ";
        StampaAlberoInOrdine(a->right);
    }
}


// SB: ok
void deallocaAlbero(albero a){
    if(a != NULL){
        deallocaAlbero(a->left);
        deallocaAlbero(a->right);
        delete a;
    }
}

