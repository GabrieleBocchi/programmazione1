// Giovanni: il testo dell'esercizio specificava chiaramente che il programma
// dovesse prendere come argomenti il nome del file in input e il nome del file
// in output. A parte questo errore, però il codice è corretto.

#include <iostream>
#include <fstream>
using namespace std;

int parola_lenght(char parola[])
{
  int i;
  for (i = 0; parola[i] != '\0'; i++)
  {
  }
  return i;
}

bool checkparola(char parola[])
{
  bool check = true;
  int parola_dim;
  int I_counter = 0;
  bool after_I = false;
  parola_dim = parola_lenght(parola);

  if (parola[0] == 'M' && parola[parola_dim - 1] != 'U')
  {
    check = false;
  }

  for (int i = 0; i < parola_dim; i++)
  {
    if (parola[i] == 'I')
    {
      I_counter++;
      if (parola[i + 1] == 'M')
      {
        check = false;
      }
    }
  }

  if (I_counter % 2 == 0 && I_counter != 0)
  {
    check = false;
  }

  return check;
}

int main(int argc, char *argv[])
{
  fstream fin, fout;
  int maxdim = 100;
  char parola[maxdim];

  if (argc != 2)
  {
    cerr << "Usa ./a.out <input>" << endl;
    exit(1);
  }

  fin.open(argv[1], ios::in);

  if (fin.fail())
  {
    cerr << "Non esiste nessun file " << argv[1] << ", crealo prima di eseguire il programma" << endl;
    exit(1);
  }

  fout.open("risultato.txt", ios::out);

  fin >> parola;
  while (!fin.eof())
  {
    if (checkparola(parola))
    {
      fout << parola << endl;
    }
    fin >> parola;
  }

  if (checkparola(parola))
  {
    fout << parola << endl;
  }

  fin.close();
  fout.close();

  return 0;
}
