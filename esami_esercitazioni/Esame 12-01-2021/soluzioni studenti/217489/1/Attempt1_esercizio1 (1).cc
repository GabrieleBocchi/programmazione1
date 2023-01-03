#include <iostream>
#include <fstream>
using namespace std;

// GDT: L'indentazione è un po' traballante qua e la
// GDT: fare riferimento alla soluzione ufficiale per lo svolgimento
// GDT: il codice se eseguito va in segmentation fault

int main(int argc, char * argv [])
{
  if(argc != 3)
    {
      // GDT: il messaggio d'errore dovrebbe dare informazioni su
      // come utilizzare il programma (minore)
      cout << "errore!" << endl;
    }
  else
    {
      fstream input, output;
      input.open(argv[1], ios::in);
      output.open("output.txt", ios::out);

      if(input.fail())
	{
	  cout << "errore" << endl;
	}
      else if(output.fail())
	{
	  cout << "errore" << endl;
	}
      else
	{
	  char buffer[100];
	  char **array = new char *[10000];
	  int i = 0;
	  int conta = 0;
	  while(!input.eof())
	    {
	      i=0;
	      input >> buffer;
	      while(buffer[i] != ' ' || buffer[i] != '\n')
		{
		  i++;
		}
	      cout << i << endl;;
	      if(i % 2 == 0)
		{
		  //array[i] = new char [i];
		  array[conta] = new char[i+1];
      //GDT: non stai copiando la stringa in questo modo
      //stai solo assegnando il puntatore all'array
		  array[conta] = buffer;
		  cout << array[conta] << " ";
		}
	      conta++;
	    }

	  for(int j = conta-1; j >= 0; j--)
	    {
	      output << array[j];
	    }

	}
    }

  //GDT: manca deallocazione e chiusura stream

  return 0;
}
