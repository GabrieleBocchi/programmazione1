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

void scambia(int &x, int &y);
void ordina_crescente(int array[], int n);
void stampa_array(const int *array, int dim);
void Riempi_Array(const albero &alb, int *array, int &dim);
void StampaAlberoInOrdine(const albero &alb);

bool vuoto(const albero &alb);
albero creaAlberoDiRicercaBinario(albero &alberoIniziale);
void deallocaAlbero(albero &alb);

int main(int argc, char *argv[])
{

  // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale

  albero alberoIniziale = generaAlbero();
  //stampaAlbero(alberoIniziale); // nel caso in cui possa essere utile, la funzione "stampaAlbero" stampa graficamente l'albero a video

  //albero alberoBinario = creaAlberoDiRicercaBinario(alberoIniziale);
  cout << "L'albero di ricerca binario è: ";
  stampaAlbero(alberoIniziale);
  StampaAlberoInOrdine(alberoIniziale);
  //StampaAlberoInOrdine(alberoBinario);
  cout << endl;

  deallocaAlbero(alberoIniziale);
  //deallocaAlbero(alberoBinario);

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

bool vuoto(const albero &alb)
{
  return (alb == NULL);
}

albero creaAlberoDiRicercaBinario(albero &alberoIniziale)
{
  albero res = NULL;

  int array[10];
  int dim = 0;

  Riempi_Array(alberoIniziale, array, dim);

  // Per ragioni di tempo non sono riuscito a completare
  // Avrei Riempito un array e 
  // avrei inserito solo quelli dispari nel nuovo albero

  return res;
}

void scambia(int &x, int &y)
{
  int tmp = x;
  x = y;
  y = tmp;
}

void ordina_crescente(int array[], int n)
{
  int i, x;
  for (x = n - 1; x > 0; x--)
  {
    for (i = 0; i < x; i++)
    {
      if (array[i] > array[i + 1])
      {
        scambia(array[i], array[i + 1]);
      }
    }
  }
}

void stampa_array(const int *array, int dim)
{
  for (int i = 0; i < dim; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

void Riempi_Array(const albero &alb, int *array, int &dim)
{
  if (!vuoto(alb))
  {
    Riempi_Array(alb->left, array, dim);
    Riempi_Array(alb->right, array, dim);
    array[dim] = alb->value;
    dim++;
  }
}

// SB: l'albero di ricerca binario è già ordinato; era sufficiente  
//     stamparlo usando la ricorsione in modo del tutto simile alla 
//     funzione "deallocaAlbero". La conversione in array, il conseguente
//     ordinamento e infine la stampa raggiungono comunque (in modo
//     meno efficiente) lo stesso risultato. Non essendo esplicitamente
//     vietato nel testo dell'esercizio, accetto la soluzione. Tuttavia, 
//     l'array qui è dichiarato con una dimensione fissa (i.e., 10). Di
//     conseguenza, la funzione non riesce a gestire casi diversi da quello
//     proposto in esempio.
void StampaAlberoInOrdine(const albero &alb)
{
  int array[10];
  int dim = 0;
  // Metto tutti gli elementi in un array
  Riempi_Array(alb, array, dim);
  // Ordino l'array
  ordina_crescente(array, dim);
  // Stampo l'array
  stampa_array(array, dim);
}

// SB: ok
void deallocaAlbero(albero &alb)
{
  if (!vuoto(alb))
  {
    deallocaAlbero(alb->left);
    deallocaAlbero(alb->right);
    delete alb;
  }
}