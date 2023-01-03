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
void risolviLabirinto(int l[5][5], int x, int y);
bool controlloRiga(int l[5][5],int riga);
bool controlloColonna(int l[5][5],int colonna);


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


void risolviLabirinto(int l[5][5], int x, int y)
{
  bool trovato=false;
  if(l[0][0]!=1)
    {
      cout<<"Errore nella matrice"<<endl;
      exit(0);
    }
    if(l[x][y]!=1)
    {
      cout<<"Questo punto non contiene il numero 1, quindi è irrangiungibile!"<<endl;
      exit(0);
    }
    cella  partenza;
    partenza.indiceRiga=0;
    partenza.indiceColonna=0;
    nodo * p=new nodo();
    p->value= partenza;
    p->next=NULL;

    //...

    delete p;
  
}

//funzioni di supporto 
bool controlloRiga(int l[5][5],int riga)
{
  bool retv=false;
  for(int colonna=0;colonna<5;colonna++)
    {
      if(l[riga][colonna]==1)
	{
	  retv=true;
	  break;
	}
    }
  return retv;
}

bool controlloColonna(int l[5][5],int colonna)
{
  bool retv=false;
  for(int riga=0;riga<5;riga++)
    {
      if(l[riga][colonna]==1)
	{
	  retv=true;
	  break;
	}
    }
  return retv;
}
