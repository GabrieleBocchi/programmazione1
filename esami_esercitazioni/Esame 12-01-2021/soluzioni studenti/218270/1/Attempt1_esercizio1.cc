// GDT: l'esercizio non da risultati corretti. Fare riferimento alla soluzione
// ufficiale per un possibile svolgimento.

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv [])
{
  const int maxdim = 10000;
  char buffer[maxdim];
  char buffer2[maxdim];
  int i=0;

  if (argc != 3) {
    cerr << "Usage: ./a.out <inputfile.txt> <outputfile.txt>" << endl;
    exit (1);
  }

  fstream in,out;

  in.open(argv[1], ios::in);
  if (in.fail()) {
    cerr << "Errore, impossibile aprire il file di Input" << endl;
    exit (1);
  }

  out.open(argv[2], ios::out);
  if (out.fail()) {
    cerr << "Errore, impossibile scrivere in questa posizione" << endl;
    exit (1);
  }

  in>>noskipws;
  in>>buffer[i];
  while (!in.eof()) {
    ++i;
    in>>buffer[i];
  }
  
  for (int p=0;p<i;p++) {
    int contalettere=0;
    if (buffer[p]!= ' ') {
      contalettere++;
    }
    else {
      if ((contalettere%2) == 0) {
        for (int g=p;g<contalettere+p;g++) {
          buffer2[g]=buffer[g];
        }
      }
      contalettere = 0;
    }
  }

  out << buffer2[i];
  while (i>0) {
    --i;
    out << buffer2[i];
  }

  in.close();
  out.close();
  
  



  return 0;
}
