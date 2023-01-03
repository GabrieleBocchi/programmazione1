#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

struct nodo {
    int value;
    nodo* left;
    nodo* right;
};
typedef nodo* albero;


albero generaAlbero(int numeroDiNodi = 10);
void stampaAlbero(albero radice, int spazio=0);
albero creaAlberoDiRicercaBinario(albero radice,int numeroDiNodi = 10);
albero StampaAlberoInOrdine(albero alberoBinario,int numeroDiNodi = 10);
albero deallocaAlbero(albero alberoUsato);
int minore(albero al,int numeroDiNodi);
albero deallocaAlbero(albero alberoInizial);

int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale


    albero alberoIniziale = generaAlbero();
    //stampaAlbero(alberoIniziale); // nel caso in cui possa essere utile, la funzione "stampaAlbero" stampa graficamente l'albero a video

    albero alberoBinario = creaAlberoDiRicercaBinario(alberoIniziale);
    cout << "L'albero di ricerca binario �: ";
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

    cout << "L'albero iniziale �:";

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




// SB: in questo esercizio, l'albero viene trattato come un array.
//     Tuttavia, un albero è una struttura dati concettualmente differente. 
//     Per questo motivo, i metodi per interagire con un albero sono diversi.
//     Consiglio di ripassare le lezioni di teoria e laboratorio pertinenti.




albero creaAlberoDiRicercaBinario(albero radice,int numeroDiNodi)
{
    nodo* nodi[numeroDiNodi];
    int i=0,contatorenodi=0;
    for (int i = 0; i<numeroDiNodi; i++)
     {
        if(radice[i].value %2==0)
        {
            nodi[i] = new nodo;
            nodi[i]->value = rand() % 10;
            nodi[i]->left = NULL;
            nodi[i]->right = NULL;
            contatorenodi++;
        }
        i++;
    }

    for (int i = 0; (2*i + 1)<contatorenodi; i++) {
        nodi[i]->left = nodi[2*i + 1];
        if ((2*i + 2) < contatorenodi) {
            nodi[i]->right = nodi[(2*i + 2)];
        }
    }
    return nodi[0];

}

albero StampaAlberoInOrdine(albero alberoBinario,int numeroDiNodi)
{
    int supp[numeroDiNodi];
    for (int i = 0; i<numeroDiNodi; i++)
    {
        supp[i]=minore(alberoBinario,numeroDiNodi);
        cout<<supp[i]<<" ";
    }

}

int minore(albero al,int numeroDiNodi)
{
    int minore=100;

    for (int i = 0; i<numeroDiNodi; i++)
    {
        if(minore>al[i].value)
        {
            minore=al[i].value;
            al[i].value=100;

        }
    }
    return minore;

}

//Se dichiaro la funzione deallocaalbero void da errore
albero deallocaAlbero(albero alberoIniziale)
{
    delete [] alberoIniziale;
}
/*
 * Inserire qui la definizione di "creaAlberoDiRicercaBinario", "StampaAlberoInOrdine",
 * "deallocaAlbero" e di eventuali altre funzioni ausiliarie.
 */
