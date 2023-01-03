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

albero creaAlberoDiRicercaBinario(albero radice);
void StampaAlberoInOrdine(albero radice);
void deallocaAlbero(albero radice);

int main(int argc, char *argv[])
{

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale

    albero alberoIniziale = generaAlbero();
    // stampaAlbero(alberoIniziale); // nel caso in cui possa essere utile, la funzione "stampaAlbero" stampa graficamente l'albero a video

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

void inserisciInAlbero(albero &radice, int valore)
{
    if (radice == NULL)
    {
        radice = new nodo;
        radice->value = valore;
        radice->left = NULL;
        radice->right = NULL;
        return;
    }
    if (valore > radice->value)
        inserisciInAlbero(radice->right, valore);
    else
        inserisciInAlbero(radice->left, valore);
}
void creaAlberoDiRicercaBinario_op(albero radice, albero &nuovo)
{
    if (radice == NULL)
        return;
    if (radice->value % 2 == 1)
        inserisciInAlbero(nuovo, radice->value);

    creaAlberoDiRicercaBinario_op(radice->left, nuovo);
    creaAlberoDiRicercaBinario_op(radice->right, nuovo);
}
albero trovaRadice(albero radice)
{
    albero nuovo = NULL;
    if (radice == NULL)
        return NULL;
    if (radice->value % 2 == 1)
    {
        nuovo = new nodo;
        nuovo->value = radice->value;
        nuovo->left = NULL;
        nuovo->right = NULL;
        return nuovo;
    }
    else
    {
        nuovo = trovaRadice(radice->left);
        if (nuovo == NULL)
            nuovo = trovaRadice(radice->right);
    }
    return nuovo;
}

// SB: ok, ma la funzione inserisce il nodo "nuovo" due volte nell'albero di ricerca binario
albero creaAlberoDiRicercaBinario(albero radice)
{
    albero nuovo = NULL;
    if (radice == NULL)
        return NULL;
    nuovo = trovaRadice(radice);
    creaAlberoDiRicercaBinario_op(radice, nuovo);
    stampaAlbero(nuovo);
    return nuovo;

    // if (radice->value % 2 == 1)
    // {
    //     creaAlberoDiRicercaBinario_op(radice->left, nuovo);
    //     creaAlberoDiRicercaBinario_op(radice->right, nuovo);
    // }
    // else
    // {
    //     nuovo = creaAlberoDiRicercaBinario(radice->left);
    //     if (nuovo == NULL)
    //         nuovo = creaAlberoDiRicercaBinario(radice->right);
    // }
    // return nuovo;
}

// SB: ok
void StampaAlberoInOrdine(albero radice)
{
    if (radice == NULL)
        return;

    StampaAlberoInOrdine(radice->left);

    cout << " ";
    cout << radice->value;
    cout << " ";

    StampaAlberoInOrdine(radice->right);
}

// SB: ok
void deallocaAlbero(albero radice)
{
    if (radice == NULL)
        return;
    deallocaAlbero(radice->left);
    deallocaAlbero(radice->right);
    delete radice;
}