#include <iostream>
#include <cstdlib>
#include <ctime> // Il mio codice non compila senza questa libreria (colpa del srand(time(NULL)))

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
void deallocaAlbero (albero & t);



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
void insertIfOdd (albero & res, int n)
{
    if (n%2)
    {
        if (res == NULL)
        {
            res = new nodo {n, NULL, NULL};
        }
        else if (n < res->value)
        {
            insertIfOdd (res->left, n);
        }
        else
        {
            insertIfOdd (res->right, n);
        }
    }
}

void insertTree(albero source, albero & res)
{
    if (source != NULL)
    {
        insertIfOdd(res, source->value);
        insertTree(source->left, res);
        insertTree(source->right, res);
    }
}

// SB: ok
albero creaAlberoDiRicercaBinario(albero t)
{
    albero res = NULL;
    insertTree(t, res);
    return res;
}

// SB: ok
void StampaAlberoInOrdine(albero t)
{
    if (t != NULL)
    {
        StampaAlberoInOrdine(t->right);
        cout << t->value << " ";
        StampaAlberoInOrdine(t->left);
    }
}

// SB: ok
void deallocaAlbero (albero & t)
{
    if (t != NULL)
    {
        deallocaAlbero(t->left);
        deallocaAlbero(t->right);
        delete t;
        t = NULL;
    }
}