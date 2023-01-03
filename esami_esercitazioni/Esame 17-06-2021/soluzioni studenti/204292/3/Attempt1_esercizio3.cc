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

static bool empty (const albero& t);
void init (albero& t);
bool insert (albero& t, int val);
void scorri (const albero& t, albero& n);
albero creaAlberoDiRicercaBinario (const albero& t);
void StampaAlberoInOrdine (const albero& t);
void deallocaAlbero (albero& t);


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

static bool empty (const albero& t){
  return (t == NULL);
}

void init (albero& t){

  t = NULL;
  
  return;
}


void scorri (const albero& t, albero& n){

  if (!empty (t)){
    scorri (t->left, n);

    if ((t->value % 2) != 0){
      if (!insert (n, t->value)){
	cout << "Albero pieno" << endl;
      }
    }
    
    scorri(t->right, n);
  }
  
  return;
}

bool insert (albero& t, int val){
  
  bool res;

  if (empty (t)){
    t = new (nothrow) nodo;
    if (t == NULL){
      res = false;
    }

    else{
      t->value = val;
      t->left = NULL;
      t->right = NULL;
      res = true;
    }
  }

  else if (val <= t->value){
    res = insert (t->left, val);
  }

  else if (val > t->value){
    res = insert (t->right, val);
  }

  return res;
}

// SB: ok
albero creaAlberoDiRicercaBinario (const albero& t){

  albero nuovo;
  init (nuovo);
  
 
  if (!empty (t)){

    scorri (t, nuovo);
  }
  
  return nuovo;
}


// SB: ok
void StampaAlberoInOrdine (const albero& t){

  if (!empty (t)){

    StampaAlberoInOrdine (t->right);

    cout << t->value << " ";
    
    StampaAlberoInOrdine (t->left);
    
  }
  
  return;
}

// SB: ok
void deallocaAlbero (albero& t){


  if (!empty(t)){
    deallocaAlbero (t->left);
    deallocaAlbero (t->right);
    delete t;
  }
  
  return;
}
