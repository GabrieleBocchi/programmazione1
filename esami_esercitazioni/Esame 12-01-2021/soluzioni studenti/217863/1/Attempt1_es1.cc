// GDT: il codice è corretto. Non ho molto capito perchè vai ad includere
// l'header <new>. Comunque, siccome al suo interno non ci sono funzioni
// particolari, non sei stato penalizzato (non era consentito includere librerie
// diverse da quelle specificate nel testo d'esame). 

#include <iostream>
#include <new>
#include <fstream>

using namespace std;

int getSize(char mat[][101], int index)
{
  int i = 0;
  while (mat[index][i] != '\0')
  {
    i += 1;
  }
  return i;
}

int main(int argc, char *argv[])
{
  if (argc < 3)
  {
    cout << "Usage: ./" << argv[0] << " [input] [output]" << endl;
    exit(1);
  }
  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);
  if (input.fail() || output.fail())
  {
    cout << "Errore nell'apertura dei file specificati" << endl;
    exit(1);
  }

  char matrice[10000][101];
  int i = 0;
  while (!input.eof())
  {
    input >> matrice[i];
    i += 1;
  }

  // GDT: >= 0 andava bene uguale qui.
  for (int index = i - 1; index > -1; index--)
  {
    int size = getSize(matrice, index);
    if (size % 2 == 0)
    {
      output << matrice[index] << " ";
    }
  }

  input.close();
  output.close();
  return 0;
}
