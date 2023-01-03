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

albero creaAlberoDiRicercaBinario(albero alberoIniziale);
void StampaAlberoInOrdine(albero alberoBinario);
void deallocaAlbero(albero alberoIniziale);


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

bool insert(albero alberoIniziale){
    if(alberoIniziale==NULL){
        return false;
    }else if(alberoIniziale->value%2==0){
        return true;
    }else{
        return false;
    }
}

void inserisci(albero rad, int value){
    if(rad==NULL){
        rad=new nodo;
        rad->value=value;
        rad->left=NULL;
        rad->right=NULL;
    }else if(value<=rad->value){
        inserisci(rad->left, value);
    }else if(value>rad->value){
        inserisci(rad->right, value);
    }
}


// SB: la funzione non ha valore di ritorno
albero creaAlberoDiRicercaBinario(albero alberoIniziale){
    if(alberoIniziale!=NULL){

        // SB: la variabile "rad" deve essere inizializzata esplicitamente a NULL
        //     Inoltre, viene creata una nuova variabile "rad" ogni volte che la 
        //     funzione "creaAlberoDiRicercaBinario" viene invocata ricorsivamente
        albero rad;
        creaAlberoDiRicercaBinario(alberoIniziale->left);
        creaAlberoDiRicercaBinario(alberoIniziale->right);
        if(insert(alberoIniziale)){
            inserisci(rad, alberoIniziale->value);
        }
    }
}


// SB: ok
void StampaAlberoInOrdine(albero alberoBinario){
    if(alberoBinario!=NULL){
        StampaAlberoInOrdine(alberoBinario->left);
        cout<<alberoBinario->value<<" ";
        StampaAlberoInOrdine(alberoBinario->right);
    }
}

// SB: ok
void deallocaAlbero(albero alberoIniziale){
    if(alberoIniziale!=NULL){
        albero temp=alberoIniziale;
        deallocaAlbero(alberoIniziale->left);
        deallocaAlbero(alberoIniziale->right);
        delete temp;
    }
}