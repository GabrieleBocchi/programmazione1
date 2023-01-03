// GDT: la procedura per scrivere su file è errata. Il file di output contiene
// tutte le parole senza spazi. Inoltre, il ciclo dovrebbe iniziare da i-1, poichè 
// la parola in posizione i non dovrebbe essere salvata.

#include <iostream>
#include <fstream>
using namespace std;

bool is_dispari(const char word[]);

int main(int argc, char * argv [])
{
  if (argc != 3) {
    cerr << "Usage " << argv[0] << " <inputfile> <outputfile>\n";
    exit(1);
  }

  fstream input, output;
  input.open(argv[1], ios::in);
  if (!input.is_open()) {
    cerr << "Can't open input file.\n";
    exit(2);
  }
  output.open(argv[2], ios::out | ios::trunc);
  if (!output.is_open()) {
    input.close();
    cerr << "Can't open output file.\n";
    exit(3);
  }

  char **testo = new char*[10000];

  testo[0] = new char[101];
  int i = 0;
  for (i = 0; i < 10000 && !input.eof();) {  
    input >> testo[i];

    if (is_dispari(testo[i])) {
      i++;
      testo[i] = new char[101];
    }
  }
  input.close();

  for (int k = i; k >= 0; k--) {
    output << testo[k];
    cout << testo[k] << " ";
    delete [] testo[k];
  }
  output.close();

  delete [] testo;

  return 0;
}

bool is_dispari(const char word[])
{
  int i = 0;
  while (word[i] != 0) {
    i++;
  }

  return (i%2);
}
