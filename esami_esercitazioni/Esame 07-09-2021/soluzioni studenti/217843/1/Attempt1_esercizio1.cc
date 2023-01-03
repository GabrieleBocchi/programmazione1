// GDT: il codice non riporta il risultato corretto in alcuni casi di test.
// Vedi commenti nel codice

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_CHAR= 200+1;

int main(int argc, char * argv [])
{
  if ( argc != 3 )
    {
      cout << "Usage: " << argv[0] << " <file_input.txt> <file_output.txt> " << endl;
      exit(1);
    }

  fstream input,output;

  input.open ( argv[1], ios::in );

  if ( input.fail() )
    {
      cout << "ERRORE nella lettura del file: " << argv[1] << endl;
      exit(1);
    }

  output.open ( argv[2], ios::out );

  char parola[MAX_CHAR];

  input >> parola;
  bool uppercase = true;
  int lenght;

  while ( !input.eof() )
    {
      lenght = strlen ( parola );
      cout << parola << endl;

      // GDT: indentazione un po' difficile da leggere
      if ( uppercase )
    	{
        // GDT: qua deve essere maggiore o uguale >=, perchè devi includere
        // anche possibili parole che iniziano con la lettera a o z.
    	  if ( parola[0] > 'a' && parola[0] < 'z' )
    		{
    		  parola[0] = parola[0] + ('A' - 'a');
    		}
    	}
      else
    	{
        // GDT: in caso la parola segua uno dei caratteri di punteggiatura indicati
        // non era specificato che dovesse essere messo in minuscolo.
    	  if ( parola[0] > 'A' && parola[0] <'Z' )
    	    {
    	      parola[0] = parola[0] - ( 'A' - 'a' );
    	    }
    	}
        if ( parola[lenght-1] == ',' || parola[lenght-1] == ':' || parola[lenght-1] == ';' )
      	{
      	  cout << "false" << endl;
      	  uppercase = false;
      	}
            else
      	{
      	  uppercase = true;
      	}
          output << parola << " " ;
          input >> parola;
        }

  output << endl;
  input.close();
  output.close();


    return 0;
}
