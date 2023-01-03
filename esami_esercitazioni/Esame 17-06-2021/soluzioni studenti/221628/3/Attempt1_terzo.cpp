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

albero creaAlberoDiRicercaBinario(albero q);
void inserisci(albero q, albero t);
void StampaAlberoInOrdine(albero q);
void deallocaAlbero(albero q);

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

albero creaAlberoDiRicercaBinario(albero q)
{
    albero z = new nodo{q->value, NULL, NULL};

    while (q != NULL)
    {
        if ((q->value % 2) == 1)
        {
            albero t = new nodo{q->value, NULL, NULL};
            inserisci(z, t);
        }
    }

    return z;
}

void inserisci(albero q, albero t)
{
    if (t->value < q->value)
    {
        if (q->left == NULL)
        {
            q->left = t;
        }
        else
        {
            inserisci(q->left, t);
        }
    }
    else
    {
        if (q->right == NULL)
        {
            q->right = t;
        }
        else
        {
            inserisci(q->right, t);
        }
    }
}

void stampaAlberoInOrdine(albero q)
{
    if (q != NULL)
    {
        stampaAlberoInOrdine(q->left);
        stampaAlberoInOrdine(q->right);

        cout << q->value << " ";
    }
}

void deallocaAlbero(albero q)
{
    if (q != NULL)
    {
        deallocaAlbero(q->left);
        deallocaAlbero(q->right);

        delete q;
    }
}