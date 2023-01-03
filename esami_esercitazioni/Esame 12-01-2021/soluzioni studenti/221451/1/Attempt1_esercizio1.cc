#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    cout << "Usage: " << argv[0] << " input_A output.txt" << endl;
  }
  else
  {
    fstream input, output;

    input.open(argv[1], ios::in);
    if (input.fail())
    {
      cout << "Errore nella lettura del file input." << endl;
    }
    else
    {
      output.open(argv[2], ios::out);
      if (output.fail())
      {
        cout << "Errore nella lettura del file output." << endl;
      }
      else
      {
        char c;
        char parola[100];
        char risultato[50];
        int contatore = 0;
        int cursore = 0;

        while (input.get(c))
        {
          if (c != ' ')
          {
            parola[contatore] = c;
            contatore++;
          }
          else if (c == ' ')
          {
            if (contatore < 5)
            {
              for (int i = 0; i < contatore; i++)
              {
                risultato[cursore] = parola[i];
                cout << "Inserendo " << risultato[cursore] << endl;
                cursore++;
              }
              risultato[cursore] = ' ';
              cout << "Inserendo " << risultato[cursore] << endl;
              cursore++;

              contatore = 0;
            }
            else if (contatore >= 5)
            {
              contatore = 0;
            }
          }
        }
        for (int i = cursore; i > 0; i--)
        {
          if(risultato[i]!= ' ')
        }
      }
    }
  }
  return 0;
}
