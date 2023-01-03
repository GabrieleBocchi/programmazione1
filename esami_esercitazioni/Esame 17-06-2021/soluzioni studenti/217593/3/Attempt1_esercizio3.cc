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
void inserisci(albero root, nodo* value);
albero creaAlberoDiRicercaBinario(albero root);
void StampaAlberoInOrdine(albero root);
void deallocaAlbero(albero root);



void inserisciInOrdine(albero root, int value);

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

nodo* creaNodo(int value){
    nodo* n = new nodo;
    n->value = value;
    n->right = nullptr;
    n->left = nullptr;

    return n;
}

// SB: ok, ma la funzione inserisce nell'albero anche i numeri dispari
albero creaAlberoDiRicercaBinario(albero root){

    albero binary = creaNodo(root->value);
    inserisci(binary, root->left);
    inserisci(binary, root->right);

    return binary;
}
void inserisci(albero radice, nodo* n){
    if(n != nullptr){
        inserisciInOrdine(radice, n->value);
        inserisci(radice, n->right);
        inserisci(radice, n->left);
    }
}
// SB: un albero di ricerca binario convenzionalmente ha i nodi con valore maggiore a destra, e i nodi con valore minore a sinistra
void inserisciInOrdine(albero root, int value){
    if(value <= root->value){

        if(root->right == nullptr){
            root->right = creaNodo(value);
        }else{
            inserisciInOrdine(root->right, value);
        }
    }else{

        if(root->left == nullptr){
            root->left = creaNodo(value);
        }else{
            inserisciInOrdine(root->left, value);
        }
    }
}

// SB: ok
void StampaAlberoInOrdine(albero root){
    if (root != NULL) {
        StampaAlberoInOrdine(root->left);
        cout<<root->value << " ";

        StampaAlberoInOrdine(root->right);
    }
}

// SB: ok
void deallocaAlbero(albero root){
    if(root != nullptr){
        deallocaAlbero(root->left);
        deallocaAlbero(root->right);

        delete root;
    }
}






