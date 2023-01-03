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
void StampaAlberoInOrdine(albero a);
albero creaAlberoDiRicercaBinario(albero root);
void deallocaAlbero(albero root);


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


void alberoInsert(albero a, int value){
    cout<<"Inserting "<<value<<"... Current value: "<<a->value<<endl;
    if(value <= a->value){
        if(a->left == NULL){
            a->left = new nodo{value, NULL, NULL};
        }else{
            alberoInsert(a->left, value);
        }
    }else{
        if(a->right == NULL){
            a->right = new nodo{value, NULL, NULL};
        }else{
            alberoInsert(a->right, value);
        }
    }
}

void creaAlberoDiRicercaBinarioSupporto(albero master, albero root){
    alberoInsert(master, root->value);
    if(root->left != NULL){
        creaAlberoDiRicercaBinarioSupporto(master, root->left);
    }
    if(root->right != NULL){
        creaAlberoDiRicercaBinarioSupporto(master, root->right);
    }
}

// SB: ok, ma la funzione inserisce nell'albero di ricerca binario anche i numeri pari
albero creaAlberoDiRicercaBinario(albero root){
    albero ret = new nodo{root->value, NULL, NULL};
    creaAlberoDiRicercaBinarioSupporto(ret, root->left);
    creaAlberoDiRicercaBinarioSupporto(ret, root->right);
    return ret;
}

// SB: ok
void StampaAlberoInOrdine(albero a){
    if(a->left != NULL){
        StampaAlberoInOrdine(a->left);
    }
    cout<<a->value<<" ";
    if(a->right != NULL){
        StampaAlberoInOrdine(a->right);
    }
}

// SB: ok
void deallocaAlbero(albero root){
    if(root->left){
        deallocaAlbero(root->left);
    }
    if(root->right){
        deallocaAlbero(root->right);
    }
    delete root;
}