// GDT: il programma va in segmentation fault. A riga 28, il buffer *buffer viene
// inizializzato, ma non viene allocata nessuna area di memoria. Perciò il programma
// fallisce. Il comando corretto è char * buffer = new char[101];

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool controlla_codice(char *, int);

int main(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "ERRORE: troppi o troppi pochi parametri passati!" << endl;
    exit(argc-3);
  }

  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  if (input.fail()) {
    cout << "ERRORE: il file di input non esiste" << endl;
    exit(4);
  } else if (output.fail()) {
    cout << "ERRORE: il file di output non esiste!" << endl;
    exit(5);
  }

  char *buffer;
  int len = -1, n_codici = 0;
  while (!input.eof()) {
    input >> buffer;
    len = strlen(buffer);
    if (len == 19) {
      if (controlla_codice(buffer, len)) n_codici+=1;
    }
  }

  output << n_codici-1;

  input.close();
  output.close();

  return 0;
}

bool controlla_codice(char *buffer, int len) {
  bool aggiungi = true;
  for (int i = 0; i < len; i++) {
    if (buffer[i] != '-' && (buffer[i] < 'A' || buffer[i] > 'Z')) {
      aggiungi = false;
    }
  }
  return aggiungi;
}
