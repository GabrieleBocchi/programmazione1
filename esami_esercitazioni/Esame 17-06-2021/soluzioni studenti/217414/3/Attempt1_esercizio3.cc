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
albero creaAlberoDiRicercaBinario(const albero alb);
void StampaAlberoInOrdine(albero alb);
void deallocaAlbero(albero alb);
void insertOrdinato(albero & alb, int num);


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
albero creaAlberoDiRicercaBinario_aux(const albero alb, albero &radice);

// SB: ok
albero creaAlberoDiRicercaBinario(const albero alb){
    albero radice = NULL;
    creaAlberoDiRicercaBinario_aux(alb, radice);
    return radice;
}

albero creaAlberoDiRicercaBinario_aux(const albero alb, albero &radice){
    if(alb != NULL){
        creaAlberoDiRicercaBinario_aux(alb->left, radice);
        creaAlberoDiRicercaBinario_aux(alb->right, radice);
        if(alb->value % 2 == 1){
            insertOrdinato(radice, alb->value);
        }
    }
    return radice;
}

// SB: ok
void StampaAlberoInOrdine(albero alb){
    if(alb != NULL){
        StampaAlberoInOrdine(alb->right);
        cout << alb->value << " ";
        StampaAlberoInOrdine(alb->left);
    }
}
// SB: ok
void deallocaAlbero(albero alb){
    if(alb != NULL){
        deallocaAlbero(alb->left);
        deallocaAlbero(alb->right);
        delete alb;
    }
}
void insertOrdinato(albero & alb, int num){
    if(alb == NULL){
        nodo* tmp = new nodo{num, NULL, NULL};
        alb = tmp;
    }
    else{
        if(alb->value < num){
            insertOrdinato(alb->right, num);
        }
        else{
            insertOrdinato(alb->left, num);
        }
    }
}