#include<iostream>
#include<fstream>
using namespace std;

struct nodo
{
  char dato [101];
  nodo* next;
};

int lenght ( char p[101]);
void copia ( char c[101], char p[101]);

int main(int argc, char* argv[])
{
  if ( argc != 3 )
    {
      cout << "Usage: " << argv[0] << "<file_input.txt> <file_output.txt> " << endl;
      exit (0);
    }

  fstream input,output;

  input.open ( argv[1], ios::in );
  

  if ( input.fail() )
    {
      cout << "Errore lettura file! " << endl;
      exit (0);
    }

  output.open ( argv[2], ios::out );

  if ( output.fail() )
    {
      cout << "Errore scrittura file!" << endl;
    }
  else
    {
      char parola[101];
      nodo* pila = new nodo;
      int l;

      nodo* ap = pila;
      while ( input >> parola )
	{
	  l = lenght ( parola );
	  if ( l%2 == 0 )
	    {
	      nodo* nn = new nodo;
	      copia ( nn->dato, parola );
	      ap->next = nn;
	      ap = ap->next;
	    }
	}
      input.close();
      
      while ( pila != NULL )
	{
	  output << pila->dato << " ";
	  nodo* tmp = pila;
	  pila = pila->next;
	  delete tmp;
	}
      output.close();
    }
  return 0;
}
int lenght ( char p[101] )
{
  int i=0;
  while ( p[i] != '\0' )
    {
      i++;
    }
  return i;
}
void copia ( char c[101], char p[101] )
{
  
  for ( int i=0; i<101 && p[i] != '\0'; i++ )
    {
      c[i] = p[i];
    }
}

