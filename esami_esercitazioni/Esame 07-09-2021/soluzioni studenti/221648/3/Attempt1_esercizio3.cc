#include <iostream>
#include "pila.h"


using namespace std;


/**
 * Ricordare che il file "pila.h" contiene la definizione della struct "cella" (qui sotto riportata)
 * 
 * struct cella {
 *   int indiceRiga;
 *   int indiceColonna;
 * };
 */

//funzioni ausiliarie
void printPercorso();
cella nextVisit(int [][5], int** , int, int);

void risolviLabirinto(int [][5], int, int);


int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale  

    // E' possibile modificare la matrice per effettuare dei test   
    int labirinto[5][5] = {
        { 1, 0, 1, 1, 0 },
        { 1, 1, 1, 0, 1 },
        { 0, 1, 0, 1, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 }
    };

    // E' possibile modificare la cella di arrivo per effettuare dei test (la cella di partenza invece è sempre [0,0])   
    cout<<"Percorso: ";
    risolviLabirinto(labirinto, 4, 2);

    return 0;
}

void risolviLabirinto(int labirinto[][5], int dR, int dC){
  int** visitate = new int*[5];
  for(int i=0; i<5; i++)
    visitate[i] = new int[5];

  cella c = {0,0};
  cella next;
  bool esci = false;

  init();

  push(c);

  while(!esci){
    //cerco la prossima cella da visitare
    next = nextVisit(labirinto, visitate, c.indiceRiga, c.indiceColonna);

    //verifico se l'ho trovata
    if(next.indiceRiga == -1 || next.indiceColonna == -1)
      esci = true;
    else{
      // SB: se il primo percorso che l'algoritmo trova è quello giusto, allora 
      //     il programma funziona. Purtroppo, manca la logica per tornare a 
      //     celle precedenti in caso il percorso scelto non sia quello corretto 
      //     Per esempio, se la cella di destinazione è [4,0].
      labirinto[c.indiceRiga][c.indiceColonna] = 2;
      c = next;
      push(c);
    }

    //verifico se sono arrivato a destinazione
    if(c.indiceRiga == dR && c.indiceColonna == dC){
      printPercorso();
      esci = true;
    }
  }

  deinit();
}

cella nextVisit(int labirinto[][5], int** visitate, int r, int c){
  cella c1;

  c1.indiceRiga = -1;
  c1.indiceColonna = -1;
  
  if(r+1 < 5 && labirinto[r+1][c]==1 && visitate[r+1][c]==0){
    c1.indiceRiga = r+1;
    c1.indiceColonna = c;
  }else if(r-1 >= 0 && labirinto[r-1][c]==1 && visitate[r-1][c]==0){
    c1.indiceRiga = r-1;
    c1.indiceColonna = c;
  }else if(c+1 < 5 && labirinto[r][c+1]==1 && visitate[r][c+1]==0){
    c1.indiceRiga = r;
    c1.indiceColonna = c+1;
  }else if(c-1 >= 0 && labirinto[r][c-1]==1 && visitate[r][c-1]==0){
    c1.indiceRiga = r;
    c1.indiceColonna = c-1;
  }

  //cout << "NEXT: [" << c1.indiceRiga << "," << c1.indiceColonna << "]" << endl;

  return c1;
}

void printPercorso(){
  cella c;

  while(!vuota()){
    top(c);

    cout << "[" << c.indiceRiga << "," << c.indiceColonna << "] ";
    pop();
  }

  cout << endl;
}
