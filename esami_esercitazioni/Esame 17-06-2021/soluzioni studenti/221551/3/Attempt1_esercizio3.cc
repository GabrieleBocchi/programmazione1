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
albero creaAlberoDiRicercaBinario(albero radice);
void StampaAlberoInOrdine(albero);
void StampaAlberoInOrdine(albero);
void deallocaAlbero(albero);
void creaAlberoDiRicercaBinario_ric(albero radice, albero binarioDispari);


int main(int argc, char* argv[]) {

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

// SB: la funzione "creaAlberoDiRicercaBinario_ric" non ha parametri passati per riferimento 
//     e nemmeno un valore di ritorno. In questo modo, anche se l'albero viene creato, il 
//     programma non ha un puntatore all'albero e torrerà sempre "NULL".
albero creaAlberoDiRicercaBinario(albero radice)
{
  albero binarioDispari = NULL;
  creaAlberoDiRicercaBinario_ric(radice, binarioDispari);
  return binarioDispari;
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

// SB: ok
void StampaAlberoInOrdine(albero radice)
{
  if (radice != NULL) //tecnicamente un albero di ricerca binario è gia ordinato quindi
                      // basta stampare sx, corrente, dx
  {
    StampaAlberoInOrdine(radice->left);
    cout << radice->value << " ";
    StampaAlberoInOrdine(radice->right);
  }
}

void creaAlberoDiRicercaBinario_ric(albero radice, albero binarioDispari)
{
  albero bin = binarioDispari;
  if (radice != NULL) // se la radice è NULL allora non faccio nulla
  {
    if ((radice->value)%2 == 1) // se il numero è dispari allora vado ad inserirlo nell'albero
    {
      if (binarioDispari == NULL) //creo il nodo base
      {
        bin = new nodo{radice->value, NULL, NULL};
      }
      else
      {
        if (binarioDispari->value >= radice->value)
        {
          creaAlberoDiRicercaBinario_ric(radice, binarioDispari->right);
        }

        if (binarioDispari->value < radice->value)
        {
          creaAlberoDiRicercaBinario_ric(radice, binarioDispari->left);
        }
      }
    }
    creaAlberoDiRicercaBinario_ric(radice->left, binarioDispari);
    creaAlberoDiRicercaBinario_ric(radice->right, binarioDispari);
  }
}