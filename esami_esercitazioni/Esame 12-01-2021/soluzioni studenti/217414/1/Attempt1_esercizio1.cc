// GDT: il codice risponde alle specifiche. Come unica cosa, ti
// suggerirei per il futuro di evitare di utilizzare troppi if innestati.
// Diventa infatti difficile analizzare il comportamento del programma nei diversi casi di errore.
// Fai riferimento alla soluzione ufficiale per un possibile svolgimento.

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_DIM = 100 + 1;

int lunghezza(const char stringa[])
{
  int cont = 0;
  for (int i = 0; i < MAX_DIM && stringa[i] != '\0'; i++)
  {
    cont++;
  }
  return cont;
}

int main(int argc, char *argv[])
{
  if (argc == 3)
  {
    fstream input;
    input.open(argv[1], ios::in);
    if (!input.fail())
    {
      char **matrix = new char *[1000];
      int lung, i = 0;
      fstream output;
      output.open(argv[2], ios::out);
      if (!output.fail())
      {
        while (!input.eof() && i < 1000)
        {
          matrix[i] = new char[MAX_DIM];
          input >> matrix[i];
          i++;
        }
        for (int j = i-1; j >= 0; j--)
        {
          lung = lunghezza(matrix[j]);
          if (lung > 4)
          {
            output << matrix[j] << " ";
          }
        }
      }
      else
      {
        cout << "Errore riguardante il file di output" << endl;
      }
      for (int j = 0; j < i; j++)
      {
        delete[] matrix[j];
      }
      delete matrix;
      output.close();
    }
    else
    {
      cout << "Errore: File di input inesistente o impossibile da aprire" << endl;
    }
    input.close();
  }
  else
  {
    cout << "Errore provare con: ./a.out input_A output" << endl;
  }
  return 0;
}
