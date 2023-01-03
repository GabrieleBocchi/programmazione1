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
void risolviLabirinto(int [][6], int , int );


int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale  

    // E' possibile modificare la matrice per effettuare dei test   
    int labirinto[6][6] = {
        { 1, 0, 1, 1, 0, 0 },
        { 1, 1, 1, 0, 1, 0 },
        { 0, 1, 0, 1, 1, 0 },
        { 1, 1, 1, 1, 1, 0 },
        { 1, 1, 1, 1, 1, 0 },
        { 0, 0, 0, 0, 0, 0 },
    };

    // E' possibile modificare la cella di arrivo per effettuare dei test (la cella di partenza invece è sempre [0,0])   
    cout<<"Percorso: ";
    risolviLabirinto(labirinto, 4, 2);
   
    return 0;
}
void risolviLabirinto(int m[][6], int x_arrivo, int y_arrivo )
{
  init();

  int x = 0;
  int y = 0;
  int x_prec = 0;
  int y_prec = 0;
  
  cella start;
  start.indiceRiga = x;
  start.indiceColonna = y;
  
  push ( start );

  while ( x != x_arrivo && y != y_arrivo )
    {
      if ( m[x+1][y] == 1 && x+1 < 6 )
	{
	  if ( x+1 != x_prec )
	    {
	      x_prec = x;
	  x += 1;
	  cella nuovacella;
	  nuovacella.indiceRiga = x;
	  nuovacella.indiceColonna = y;
	  push ( nuovacella );
	    }
	  else
	    {
	      pop();
	      x += 1;
	    }
	}
      else if ( m[x][y+1] == 1 && y+1 < 6 )
	{
	   if ( y+1 != y_prec )
	     {
	       y_prec = y;
	  y += 1;
	  cella nuovacella;
	  nuovacella.indiceRiga = x;
	  nuovacella.indiceColonna = y;
	  push ( nuovacella );
	     }
	   else
	     {
	       pop();
	      y += 1;
	     }
	}
      else if ( m[x-1][y] == 1 && x-1 >= 0 )
	{
	   if ( x-1 != x_prec )
	     {
	       x_prec = x;
	  x -= 1;
	  cella nuovacella;
	  nuovacella.indiceRiga = x;
	  nuovacella.indiceColonna = y;
	  push ( nuovacella );
	     }
	   else
	     {
	       pop();
	      x += 1;
	     }
	}
      else if ( m[x][y-1] == 1 && y-1 >= 0 )
	{
	   if ( y-1 != y_prec )
	     {
	       y_prec = y;
	  y -= 1;
	  cella nuovacella;
	  nuovacella.indiceRiga = x;
	  nuovacella.indiceColonna = y;
	  push ( nuovacella );
	     }
	   else
	     {
	       pop();
	      y += 1;
	     }
	}
    }
  cella tmp;
  while ( top(tmp) )
    {
      cout << tmp ;
      pop();
    }
}
	  
  
