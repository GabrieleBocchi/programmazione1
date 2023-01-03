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

//funzioni dichiarate da me
void inserisciBinario(albero radice, nodo *inserire);
albero creaAlberoDiRicercaBinario(albero radice);
void StampaAlberoInOrdine(albero radice);
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

void inserisciBinario(albero radice, nodo *inserire)
{
    if (radice == NULL)
    { //se sono arrivato alla fine dell'albero allora punterò al nodo
        radice = inserire;
    }
    if (inserire->value > radice->value)
    { //siccome è binario se il valore è maggiore scendo a dx
        inserisciBinario(radice->right, inserire);
    }
    else if (inserire->value < radice->value)
    { //altrimenti a sx
        inserisciBinario(radice->left, inserire);
    }
}

// SB: la variabile "result" non viene passata come parametro tra le invocazioni fra le 
//     chiamate ricorsive delle funzione "creaAlberoDiRicercaBinario". Come risultato,
//     vengono creati dei nodi che non sono però collegati fra loro.
albero creaAlberoDiRicercaBinario(albero radice)
{
    albero result = NULL;
    if (radice != NULL)
    { //controllo che l'albero non sia vuoto
        if ((radice->value % 2) == 0)
        { //mi interessano solo i valori pari
            nodo *inserire = new nodo{radice->value, NULL, NULL};
            if (result == NULL)
            { //se l'albero da creare è vuoto allora avrò solo un elemento
                result = inserire;
            }
            else //altrimento inserisco il valore dentro l'albero
            {
                inserisciBinario(result, inserire); //altrimenti lo inserisco nell'albero di ritorno
            }
        }
        creaAlberoDiRicercaBinario(radice->left);
        creaAlberoDiRicercaBinario(radice->right);
    }
    return result;
}

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

// SB: bisogna prima deallocare i nodi a destra e sinistra, e solo infine la radice
void deallocaAlbero(albero radice)
{
    nodo *tmp;
    if (radice != NULL)
    {                                 //se l'albero è vuoto non devo deallocare nulla
        deallocaAlbero(radice->left); //scendo in ricorsione a sinistra
        tmp = radice;                 //punto alla foglia dell'albero
        delete tmp;                   //cancello la foglia   SB: questa è la radice, non la foglia
        deallocaAlbero(radice->right);
    }
}
