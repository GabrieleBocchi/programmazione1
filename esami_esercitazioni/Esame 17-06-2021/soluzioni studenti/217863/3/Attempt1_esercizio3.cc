#include <iostream>
#include <cstdlib>

using namespace std;

struct nodo
{
    int value;
    nodo *left;
    nodo *right;
};
typedef nodo *albero;

albero generaAlbero(int numeroDiNodi = 10);
void stampaAlbero(albero radice, int spazio = 0);
//dichiarazioni funzioni ausiliarie
bool inserisci(albero &radice, int val);
void creaAlberoDiRicercaBinarioRic(albero radice1, albero &radice2);
//dichiarazioni funzioni principali
albero creaAlberoDiRicercaBinario(albero radice);
void StampaAlberoInOrdine(const albero radice);
void deallocaAlbero(albero &radice);

int main(int argc, char *argv[])
{

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

albero generaAlbero(int numeroDiNodi)
{

    // Se modificate la funzione "generaAlbero", ricordarsi poi di ripristinare il codice originale

    srand(time(NULL));
    nodo *nodi[numeroDiNodi];

    cout << "L'albero iniziale è:";

    for (int i = 0; i < numeroDiNodi; i++)
    {
        nodi[i] = new nodo;
        nodi[i]->value = rand() % 10;
        nodi[i]->left = NULL;
        nodi[i]->right = NULL;
        cout << " " << nodi[i]->value;
    }
    cout << endl;

    for (int i = 0; (2 * i + 1) < numeroDiNodi; i++)
    {
        nodi[i]->left = nodi[2 * i + 1];
        if ((2 * i + 2) < numeroDiNodi)
        {
            nodi[i]->right = nodi[(2 * i + 2)];
        }
    }

    return nodi[0];
}

void stampaAlbero(albero radice, int spazio)
{

    // Se modificate la funzione "stampaAlbero", ricordarsi poi di ripristinare il codice originale

    if (radice != NULL)
    {
        spazio++;

        stampaAlbero(radice->right, spazio);

        for (int i = 1; i < spazio; i++)
        {
            cout << "\t";
        }
        cout << radice->value << "\n";

        stampaAlbero(radice->left, spazio);
    }
}

/* 
 * Inserire qui la definizione di "creaAlberoDiRicercaBinario", "StampaAlberoInOrdine", 
 * "deallocaAlbero" e di eventuali altre funzioni ausiliarie.
 */

bool inserisci(albero &radice, int val)
{
    //inserisce in ordine crescente
    bool res = false;
    if (radice == NULL)
    {
        radice = new (nothrow) nodo;
        if (radice != NULL)
        {
            radice->value = val;
            radice->right = radice->left = NULL;
            res = true;
        }
    }
    else if (val < radice->value)
    {
        res = inserisci(radice->left, val);
    }
    else
    {
        res = inserisci(radice->right, val);
    }
    return res;
}

void creaAlberoDiRicercaBinarioRic(albero radice1, albero &radice2)
{
    if (radice1 != NULL)
    {
        creaAlberoDiRicercaBinarioRic(radice1->left, radice2);
        if (radice1->value % 2 == 0)
        {
            //è pari
            bool res = inserisci(radice2, radice1->value);
            if (res)
                cout << radice1->value << endl;
            else
                cout << endl;
        }
        creaAlberoDiRicercaBinarioRic(radice1->right, radice2);
    }
}
// SB: ok
albero creaAlberoDiRicercaBinario(albero radice)
{
    // SB: memory leak
    albero risultato = new nodo;
    //inizializzo il nodo
    risultato = NULL;
    creaAlberoDiRicercaBinarioRic(radice, risultato);
    return risultato;
}


// SB: ok
void StampaAlberoInOrdine(const albero radice)
{
    //in ordine decrescente quindi da destra a sinistra
    if (radice != NULL)
    {
        StampaAlberoInOrdine(radice->right);
        cout << radice->value << " ";
        StampaAlberoInOrdine(radice->left);
    }
}


// SB: ok
void deallocaAlbero(albero &t)
{
    if (t != NULL)
    {
        deallocaAlbero(t->left);
        deallocaAlbero(t->right);
        delete t;
    }
}