// GDT: il codice va bene, solo che l'output non è corretto (inserisci una parola in più).
// Questo capita perchè, quando vai a ciclare su num_parola per inserire tutto nel file di output, dovresti far partire il ciclo da num_parola-1.
// Infatti, dal tuo codice, le parole valide vanno da 0 a num_parola-1, visto che la parola in posizione num_parola non è stata ancora controllata. 

#include <iostream>
#include <fstream>
using namespace std;

bool check(char parola[]);

int main(int argc, char *argv[])
{
  int MAXPAROLE = 1000;
  int maxchar = 100;
  int num_parola = 0;
  char parole[MAXPAROLE][maxchar];
  fstream in, out;
  
  if (argc != 3)
  {
    cout << "errore uso: ./a.out inputfile.txt outputfile.txt" << endl;
    exit(0);
  }

  in.open(argv[1], ios::in);

  if (in.fail())
  {
    cout << "errore lettura file" << endl;
    exit(1);
  }
  in >> parole[num_parola];
  while (!in.eof())
  {
    if (check(parole[num_parola]))
    {
      num_parola = num_parola + 1;
    }
    in >> parole[num_parola];
  }

  in.close();
  out.open(argv[2], ios::out);

  if (out.fail())
  {
    cout << "errore file output" << endl;
    exit(2);
  }

  for (int j = num_parola; j >= 0; j--)
  {
    out << parole[j] << " ";
  }

  out.close();

  return 0;
}

bool check(char parola[])
{
  bool check = false;
  int i = 0;
  while (parola[i] != '\0')
  {
    i = i + 1;
  }
  if (i <= 4)
  {
    check = true;
  }

  return check;
}
