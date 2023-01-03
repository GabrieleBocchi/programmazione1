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
void inserisciRicorsivo(albero nuovaRadice, nodo* nodo);
void inserisciNodoInAlberoDiRicercaBinaria(albero radice, int valore);
void StampaAlberoInOrdine(albero radice);
nodo* creaNodo(int valore);
void deallocaAlbero(albero radice);


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


albero creaAlberoDiRicercaBinario(albero radice) {
    albero nuovaRadice = creaNodo(radice->value);
    inserisciRicorsivo(nuovaRadice, radice->left);
    inserisciRicorsivo(nuovaRadice, radice->right);
    return nuovaRadice;
}

void inserisciRicorsivo(albero nuovaRadice, nodo* nodo) {
    if (nodo != NULL) {
        inserisciNodoInAlberoDiRicercaBinaria(nuovaRadice, nodo->value);
        inserisciRicorsivo(nuovaRadice, nodo->right);
        inserisciRicorsivo(nuovaRadice, nodo->left);
    }
}

void inserisciNodoInAlberoDiRicercaBinaria(albero radice, int valore) {
    if (valore % 2 != 0) {
        if (valore > radice->value) {
            if (radice->right == NULL) {
                radice->right = creaNodo(valore);
            }
            else {
                inserisciNodoInAlberoDiRicercaBinaria(radice->right, valore);
            }
        }
        else {
            if (radice->left == NULL) {
                radice->left = creaNodo(valore);
            }
            else {
                inserisciNodoInAlberoDiRicercaBinaria(radice->left, valore);
            }
        }
    }
}

void StampaAlberoInOrdine(albero radice) {
    if (radice != NULL) {
        StampaAlberoInOrdine(radice->right);
        cout << radice->value << " ";
        StampaAlberoInOrdine (radice->left);
    }
}

nodo* creaNodo(int valore) {
    nodo* nuovoNodo = new nodo;
    nuovoNodo->left = NULL;
    nuovoNodo->right = NULL;
    nuovoNodo->value = valore;
    return nuovoNodo;
}

void deallocaAlbero(albero radice) {
    if (radice != NULL) {
        deallocaAlbero(radice->left);
        deallocaAlbero(radice->right);
        delete radice;
    }
}