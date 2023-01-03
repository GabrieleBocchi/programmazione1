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
albero creaAlberoDiRicercaBinario(albero t); 
void StampaAlberoInOrdine(albero t); 
void deallocaAlbero(albero t); 



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

void insert(albero& t, int n)
{
    if(t == nullptr)
        t = new nodo{n, nullptr, nullptr}; 
    else if(t->value < n)
        insert(t->right, n); 
    else 
        insert(t->left, n); 
}

void AlberoPari(albero& dest, albero src)
{
    if(src != nullptr)
    {
        if((src->value % 2) == 0)
            insert(dest, src->value); 
        
        AlberoPari(dest, src->left); 
        AlberoPari(dest, src->right); 
    }
}

// SB: ok
albero creaAlberoDiRicercaBinario(albero t)
{
    albero tp; 
    AlberoPari(tp, t); 
    return tp; 
}

// SB: la stampa è in ordine crescente, non decrescente
void StampaAlberoInOrdine(albero t)
{
    if(t != nullptr)
    {
        StampaAlberoInOrdine(t->left); 
        cout << t->value << ' '; 
        StampaAlberoInOrdine(t->right); 
    }
}

// SB: ok
void deallocaAlbero(albero t)
{
    if(t != nullptr)
    {
        deallocaAlbero(t->left); 
        deallocaAlbero(t->right); 
        delete t; 
    }
}