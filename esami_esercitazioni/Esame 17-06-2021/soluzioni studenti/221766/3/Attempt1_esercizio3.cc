#include <iostream>
#include <cstdlib>
#include <ctime> 
// ho incluso la libreria ctime per far funzionare srand(time(NULL));
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
void StampaAlberoInOrdine(albero radice);
albero creaAlberoDiRicercaBinario(albero radice);
void bubblesort(int array[], int dim);
void deallocaAlbero(albero radice);

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

// SB: ok
void StampaAlberoInOrdine(albero radice)
{
    if (radice != NULL)
    {
        StampaAlberoInOrdine(radice->right);
        cout << radice->value << " ";
        StampaAlberoInOrdine(radice->left);
    }
}

void assegna(albero nodo, int array_nodi[], int *i)
{
    if (nodo == NULL)
        return;

    assegna(nodo->left, array_nodi, i);

    // se dispari
    if (nodo->value % 2 != 0)
    {
        array_nodi[*i] = nodo->value;
        (*i)++;
    }

    assegna(nodo->right, array_nodi, i);
}

int contaNodi(albero radice)
{
    if (radice == NULL)
        return 0;
    // se dispari
    if (radice->value % 2 != 0)
    {
        return 1 + contaNodi(radice->left) + contaNodi(radice->right);
    }
    return contaNodi(radice->left) + contaNodi(radice->right);
}

void inserisciNodoInAlberoDiRicercaBinaria(albero radice, nodo *nuovoNodo)
{
    if (nuovoNodo->value > radice->value)
    {
        if (radice->right == NULL)
        {
            radice->right = nuovoNodo;
        }
        else
        {
            inserisciNodoInAlberoDiRicercaBinaria(radice->right, nuovoNodo);
        }
    }
    else
    {
        if (radice->left == NULL)
        {
            radice->left = nuovoNodo;
        }
        else
        {
            inserisciNodoInAlberoDiRicercaBinaria(radice->left, nuovoNodo);
        }
    }
}

// SB: complicato ma funziona
albero creaAlberoDiRicercaBinario(albero radice)
{
    if (radice == NULL)
        return NULL;

    int n = contaNodi(radice);
    int arr[n];
    int i = 0;

    assegna(radice, arr, &i);

    bubblesort(arr, n);

    i = 0;

    albero new_radice = new nodo{arr[n / 2], NULL, NULL};
    for (int i = 0; i < n; i++)
    {
        // non riaggiunge la radice
        if (i != n / 2)
        {
            albero new_nodo = new nodo{arr[i], NULL, NULL};
            inserisciNodoInAlberoDiRicercaBinaria(new_radice, new_nodo);
        }
    }

    return new_radice;
}

// SB: ok
void deallocaAlbero(albero radice)
{
    if (radice != NULL)
    {
        deallocaAlbero(radice->left);
        deallocaAlbero(radice->right);
        delete radice;
    }
}

void bubblesort(int array[], int dim)
{

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int tmp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = tmp;
            }
        }
    }
}