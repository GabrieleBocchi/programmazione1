#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool check_cod_fiscale(char *parola)
{
  bool check = true;

  if (strlen(parola) != 16)
  {
    check = false;
  }

  for (int i = 0; i < 4; i++)
  {
    if (parola[i] < 'A' || parola[i] > 'Z')
    {
      check = false;
    }
  }

  for (int i = 4; i < 16; i++)
  {
    if (parola[i] < '0' || parola[i] > '9')
    {
      check = false;
    }
  }
  return check;
}

int main(int argc, char *argv[])
{
  fstream fin, fout;
  char parola[100];
  int counter = 0;

  if (argc != 3)
  {
    cerr << "Usa ./a.out <input> <output>" << endl;
    exit(1);
  }

  fin.open(argv[1], ios::in);
  if (fin.fail())
  {
    cerr << "Non esiste nessun file " << argv[1] << ", crearlo prima di eseguire il programma" << endl;
    exit(1);
  }

  fin >> parola;
  while (!fin.eof())
  {
    if (check_cod_fiscale(parola))
    {
      counter++;
    }
    fin >> parola;
  }
  fin.close();

  // GDT: questo pezzo di codice non serve. Se l'ultima parola è un codice
  // corretto, il conto risulterà aumentato di 1, perchè l'ultima parola viene
  // contata due volte.
  if (check_cod_fiscale(parola))
    {
      counter++;
    }

  fout.open(argv[2], ios::out);
  fout << counter;
  fout.close();
  return 0;
}
