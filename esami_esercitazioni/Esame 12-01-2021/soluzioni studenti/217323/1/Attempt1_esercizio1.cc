#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
  int retval;
  if (argc != 3)
  {
    cout << "Errore nell'utilizzo: a.out input output" << endl;
    retval = 1;
  }
  else
  {
    fstream input, output;
    input.open(argv[1], ios::in);
    if (input.fail())
    {
      cout << "File di input non esistente" << endl;
      retval = 2;
    }
    else
    {
      output.open(argv[2], ios::in);
      if (output.fail())
      {
        cout << "Errore nel file di output" << endl;
        retval = 3;
      }
      else
      {
        char buffer[101];
        char lettera;
        int cont = 0, lunghezza = 0, riga = 0;
        input >> lettera;
        char **matrix;

        //calcolo quante parole sono più lunghe di 4 lettere
        while (!input.eof())
        {
          //se la parola è più lunga di 4 caratteri e ciò che leggo è uno spazio o un fine riga incremento il numero di parole
          //più lunghe di 4 caratteri
          if (lunghezza >= 4&&(lettera==' '||lettera=='\n'))
          {
            riga++;
            cont = 0;
          }
          //controllo se ciò che leggo è una lettera e lo inserisco nell'array, aumento il contatore e la lunghezza dell'array
          if (lettera != ' ' || lettera != '\n')
          {
            buffer[cont] = lettera;
            lunghezza++;
            cont++;
          }
          input>>lettera;
        }

        //inserisco il singolo array dentro la riga della matrice che ho generato, anche se non è efficace come soluzione
        matrix = new char *[riga];
        cont = 0;
        input >> lettera;
        while (!input.eof())
        {
          for (int i = 0; i < riga; i++)
          {
            if (lettera != ' ' || lettera != '\n')
            {
              buffer[cont] = lettera;
              cont++;
            }
            else
            {
              matrix[i] = buffer;
              cont = 0;
            }
          }
          input>>lettera;
        }

        //stampo la matrice al contrario nel file di output
        for (int i = riga; i > 0; i--)
        {
          output << matrix[i] << " ";
        }

        //dealloco la matrice
        for (int i = 0; i < riga; i++)
        {
          delete[] matrix[i];
        }
        delete matrix;
      }
    }

    return retval;
  }
}