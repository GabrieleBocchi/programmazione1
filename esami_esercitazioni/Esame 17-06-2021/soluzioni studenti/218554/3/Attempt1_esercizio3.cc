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

albero creaAlberoDiRicercaBinario (albero radice);
void StampaAlberoInOrdine (albero radice);
void deallocaAlbero (albero radice);
void Numeri (int array[], albero radice, int i);


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


// SB: il testo dell'esercizio non permetteva di fare nessuna assunzione sul numero di nodi dell'albero
//     La funzione ritorna esattamente lo stesso albero fornito in input
albero creaAlberoDiRicercaBinario (albero radice) {

  int array[10];
  Numeri(array, radice, 0);

  nodo* nodi[10];
  nodi[0] = new nodo;
  nodi[0]->value = array[0];
  nodi[0]->right = NULL;
  nodi[0]->left = NULL;
  
  for(int i = 1; i<10; i++){
    if(array[i-1] <= array[i]){
      nodi[i] = new nodo;
      nodi[i-1]->left = nodi[i];
      nodi[i]->value = array[i];
      nodi[i]->right = NULL;
      nodi[i]->left = NULL;
    }
    else if (array[i-1] > array[i]){
      nodi[i] = new nodo;
      nodi[i-1]->left = nodi[i];
      nodi[i]->value = array[i];
      nodi[i]->right = NULL;
      nodi[i]->left = NULL;
    }
  }

  return radice;
}

// SB: (solo un'osservazione) le funzioni hanno sempre un nome che inizia con una lettera minuscola
void Numeri (int array[], albero radice, int i){
  if ((radice != NULL) && (i < 10)){
    Numeri(array, radice->left,i+1);
    array[i] = radice->value;
    Numeri(array, radice->right,i+1);
  }
}

// SB: ok
void StampaAlberoInOrdine (albero radice){
  if(radice!=NULL){
    StampaAlberoInOrdine(radice->left);
    cout << radice->value << " ";
    StampaAlberoInOrdine(radice->right);
  }
}

// SB: ok
void deallocaAlbero (albero radice){
  if(radice!=NULL){
    deallocaAlbero(radice->left);
    deallocaAlbero(radice->right);
  }
  delete radice;
}
