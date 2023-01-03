#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_DIM = 100;

bool compatibile(char buffer[]);

int main(int argc, char *argv[])
{

  if (argc != 3)
  {
    cout << "Usage: esercizio1 <input.txt> <output.txt>" << endl;
    exit(1);
  }

  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  if (input.fail() || output.fail())
  {
    cout << "Problema nell'apertura del file" << endl;
    exit(1);
  }

  char buffer[MAX_DIM];
  int numero_compatibili = 0;

  while (input >> buffer)
  {

    if (compatibile(buffer))
    {
      numero_compatibili++;
    }
  }

  input.close();

  output << numero_compatibili << endl;
  output.close();

  return 0;
}

bool compatibile(char buffer[])
{
  bool valida = true;
  int lunghezza = strlen(buffer);
  if (lunghezza != 19)
  {
    valida = false;
  }
  else
  {
    for (int i = 0; i < lunghezza && valida; i++)
    {
      if (buffer[i] >= 'A' && buffer[i] <= 'Z')
      {
        valida = true;
      }
      else if (i == 4 || i == 9 || i == 14)
      {
        if (buffer[i] == '-')
        {
          valida = true;
        }
      }
      else
      {
        valida = false;
      }
    }
  }
  return valida;
}