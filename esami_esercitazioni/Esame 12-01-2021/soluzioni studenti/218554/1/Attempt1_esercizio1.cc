// GDT: il codice va in segmentation fault (double free or corruption).
// Il problema è dato dall'istruzione parole[i] = parola. In quel caso, non stai
// assegnando la stringa, ma stai assegnando il puntatore parola. Quindi, tutte le
// entry dell'array parole in realtà saranno puntatori che puntano alla variable
// parola. Alla fine, quando vai a fare la deallocazione, il programma cerca di chiamare
// free multiple volte sulla stessa area di memoria. Cioò causa un errore.
//
// Fare riferimento alla soluzione ufficiale per un possibile svolgimento.

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_DIM1 = 100+1;
const int MAX_DIM2 = 10000+1;

bool pari(char parola[], int dim);

int main(int argc, char * argv [])
{

  if(argc != 3)
    {
      cout << "Usage: ./a.out <input> <output>" << endl;
      exit(0);
    }
  
  fstream input, output;

  input.open(argv[1], ios::in);
  if(input.fail())
    {
      cout << "errore apertura file di input" << endl;
      exit(0);
    }
    

  char ** parole = new char * [MAX_DIM2];
  int i;
  char parola[MAX_DIM1];
  int contatore = 0;
  
  input >> parola;
  for (i = 0; !input.eof(); i++)
    {
      if(pari(parola, 100))
	{ 
         parole[i] = new char[MAX_DIM1];
         parole[i] = parola;
	 contatore++;
	 input >> parola;
	}
      else
	{
	 input >> parola;
	}
    }

  output.open(argv[2], ios::out);
  if(output.fail())
    {
      cout << "errore di apertura file output" << endl;
      exit(0);
    }
  
  for (int j = contatore; j>0; j--)
    {
      output << parole[j] << " ";
      delete[] parole[j];
    }
  delete[] parole;
  
  input.close();
  output.close();
  
  return 0;
}

bool pari(char parola[], int dim)
{
  bool ok = false;
  int cont = 0;
  for (int k = 0; parola[k] != '\0'; k++)
    {
      cont++;
    }
  if ((cont%2) == 0)
    {
      ok = true;
    }
  return ok;
}
