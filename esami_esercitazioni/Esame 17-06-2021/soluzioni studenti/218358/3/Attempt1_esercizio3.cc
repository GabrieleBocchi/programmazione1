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
albero creaAlberoDiRicercaBinario(albero alberoI);
void creaAlberoDiRicercaBinario_aux(albero alberoI, albero &alberoO);
void addNodo(albero &alberoI, int n);
void  StampaAlberoInOrdine(albero alberoI);
void deallocaAlbero(albero alberoI);

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
albero creaAlberoDiRicercaBinario(albero alberoI){
    albero returnValue = NULL;
    creaAlberoDiRicercaBinario_aux(alberoI, returnValue);
    return returnValue;
}
void creaAlberoDiRicercaBinario_aux(albero alberoI, albero &alberoO){
    if(alberoI != NULL){
        if(alberoI->value % 2 == 1) addNodo(alberoO, alberoI->value);
        creaAlberoDiRicercaBinario_aux(alberoI->left, alberoO);
        creaAlberoDiRicercaBinario_aux(alberoI->right, alberoO);
    }
}

void addNodo(albero &alberoI, int n){
    //non specificato -> decido uguale sulla sx
    if(alberoI == NULL){
        //albero vuoto
        alberoI = new nodo;
        alberoI->value = n;
        alberoI->left = NULL;
        alberoI->right = NULL;
    }else{
        if(n>alberoI->value){
            //dx
            if(alberoI->right == NULL){
                alberoI->right = new nodo;
                alberoI->right->value = n;
                alberoI->right->left = NULL;
                alberoI->right->right = NULL;
            }else{
                addNodo(alberoI->right,n);
            }
        }else{
            //sx
            if(alberoI->left == NULL){
                alberoI->left = new nodo;
                alberoI->left->value = n;
                alberoI->left->left = NULL;
                alberoI->left->right = NULL;
            }else{
                addNodo(alberoI->left,n);
            }
        }
    }
}

// SB: ok
void  StampaAlberoInOrdine(albero alberoI){
    if(alberoI != NULL){
        StampaAlberoInOrdine(alberoI->left);
        cout<<alberoI->value<<" ";
        StampaAlberoInOrdine(alberoI->right);
    }
}

// SB: ok
void deallocaAlbero(albero alberoI){
    if(alberoI != NULL){
        deallocaAlbero(alberoI->left);
        deallocaAlbero(alberoI->right);
        delete alberoI;
    }
}