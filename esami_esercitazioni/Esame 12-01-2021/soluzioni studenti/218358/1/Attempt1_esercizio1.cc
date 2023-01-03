#include <iostream>
#include <fstream>
using namespace std;

void caricaTesto (char path[], char *dataOutput[], int maxDim, int &realDim);
void copiaTesto (char from[], char to[], int dim);
void scriviTesto (char path[], char *data[], int dim);
int contaLunghezza (char parola[], int maxDim);
void pulisci(char ** parole, int realDim);
int main (int argc, char *argv[])
{
  if (argc < 3)
    {
      cerr << "Usage: ./a.out <input_A> <output>\n";
      exit (0);
    }
  char **parole = new char *[10000];
  char *input = argv[1];
  char *output = argv[2];
  int realDim = 0;
  caricaTesto (input, parole, 10000, realDim);
  scriviTesto (output, parole, realDim);
  pulisci(parole, realDim);  
  delete[] parole;
  return 0;
}

void pulisci(char ** parole, int realDim){
  for(int i = 0; i < realDim; i++){
    delete parole[i];
  }
}
void caricaTesto (char path[], char *dataOutput[], int maxDim, int &realDim)
{
  char buffer[100];		
  fstream input;		
  input.open (path, ios::in);
  if (!input.fail ())
    {
      while (!input.eof ())
	{
	  if (input >> buffer)
	    {
	      if (contaLunghezza (buffer, 100) <= 4)
		{
		  dataOutput[realDim] = new char[100];
		  copiaTesto (buffer, dataOutput[realDim], 100);
		  realDim++;
		}
	    }
	}
    }
  else
    {
      cerr << "Il file " << path << " non esiste\n";
      exit (0);
    }
  input.close ();
}

void copiaTesto (char from[], char to[], int dim)
{
  for (int i = 0; i < dim; i++)
    {
      to[i] = from[i];
    }
}

void scriviTesto (char path[], char **data, int dim)
{
  fstream myout;
  myout.open (path, ios::out);	
  if (!myout.fail ())
    {
      for (int i = dim - 1; i >= 0; i--)
	{
	  myout << data[i] << " ";
	}

    }
  else
    {
      cerr << "Il file " << path << " non esiste\n";
      exit (0);
    }
  myout.close ();
}

int contaLunghezza (char parola[], int maxDim)
{
  int ris = 0;
  char *c = parola;
  while (*c != '\0')
    {
      ris++;
      c++;
    }
  return ris;
}
