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

albero creaAlberoDiRicercaBinario(albero albero_input);
albero creaAlberoDiRicercaBinario_rico(albero albero, int numero);
void cerca_value (albero albero_input, albero &albero_output);
void StampaAlberoInOrdine(albero albero);
void deallocaAlbero(albero albero);


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
albero creaAlberoDiRicercaBinario(albero albero_input) {
    albero albero_output = NULL;

    cerca_value(albero_input, albero_output);

    return albero_output;
}

void cerca_value (albero albero_input, albero &albero_output) {
    if (albero_input != NULL) {
        cerca_value(albero_input->left, albero_output);
        if (albero_input->value % 2 == 0) {
            albero_output = creaAlberoDiRicercaBinario_rico(albero_output, albero_input->value);
        }
        cerca_value(albero_input->right, albero_output);
    }
}

albero creaAlberoDiRicercaBinario_rico(albero albero, int numero) {
    if (albero == NULL) {
        nodo* tmp = new nodo;
        tmp->value = numero;
        tmp->left = NULL;
        tmp->right = NULL;
        albero = tmp;
    } else {
        if (numero <= albero->value) {
            albero->left = creaAlberoDiRicercaBinario_rico(albero->left, numero);
        } else {
            albero->right = creaAlberoDiRicercaBinario_rico(albero->right, numero);
        }
    }
    return albero;
}


// SB: ok
void StampaAlberoInOrdine(albero albero) {
    if (albero != NULL) {
        StampaAlberoInOrdine(albero->left);
        cout << albero->value << " ";
        StampaAlberoInOrdine(albero->right);
    }
}


// SB: ok
void deallocaAlbero(albero albero) {
    if (albero != NULL) {
        deallocaAlbero(albero->left);
        deallocaAlbero(albero->right);
        delete albero;
    }
}