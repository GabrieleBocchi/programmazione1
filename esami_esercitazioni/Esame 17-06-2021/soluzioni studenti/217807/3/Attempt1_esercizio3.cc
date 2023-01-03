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

albero creaAlberoDiRicercaBinario(albero);

void inserisciOrdinato(albero, int);
void StampaAlberoInOrdine(albero);
void deallocaAlbero(albero);


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

// SB: l'albero risultante contiene nodi con valore indefinito (quando "tree->value" è dispari)
//     e soprattutto non è un albero di ricerca binario
albero creaAlberoDiRicercaBinario(albero tree) {
  albero res = new nodo;

  if (tree != NULL) {

    res->left = creaAlberoDiRicercaBinario(tree->left);
  
    if (tree->value % 2 == 0) {
      res->value = tree->value;
    }
    
    res->right = creaAlberoDiRicercaBinario(tree->right);
  }
  else {
    res = NULL;
  }

  return res;
}

// SB: ok
void StampaAlberoInOrdine(albero tree) {
  if (tree != NULL) {
    StampaAlberoInOrdine(tree->left);
    
    cout << tree->value << " ";
    
    StampaAlberoInOrdine(tree->right);
  }
}

// SB: funzione non usata nel programma
void inserisciOrdinato(albero tree, int valore) {
  albero iter = tree;

  if (iter == NULL) {
    iter = new nodo;
    iter->left = NULL;
    iter->right = NULL;
  }
  else if (iter->value >= valore) {
    inserisciOrdinato(iter->left, valore);
  }
  else {
    inserisciOrdinato(iter->right, valore);
  }
}

// SB: ok
void deallocaAlbero(albero tree) {
  if (tree != NULL) {
    deallocaAlbero(tree->left);
    deallocaAlbero(tree->right);
    delete tree;
  }
}
