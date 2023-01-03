// GDT: il numero massimo di stringhe è errato. Dovrebbe essere 10000 come
// da consegna.

#include <iostream>
#include <fstream>
using namespace std;

#define MAX_LEN 101     // la lunghezza massima di una stringa
#define MAX_STR 100     // il numero massimo di stringhe
#define MIN_LEN 4       // lunghezza minima delle stringhe da considerare

int strlen(char* s){    // funzione che ritorna la lunghezza di una stringa
  int len = 0;

  while(*s != '\0'){
    len++;
    s++;
  }

  return len;
}

int main(int argc, char * argv [])
{
  fstream in, out;
  char parole[MAX_STR][MAX_LEN];

  if(argc!=3){            // se non ci sono abbastanza argomenti termina con errore
    cerr << "Uso del programma: ./a.out <file_input> <file_output>";
    exit(1);
  }

  in.open(argv[1],ios::in);

  if(in.fail()){          // se non riesce ad aprire il file di input termina con errore
    cerr << "Impossibile aprire il file di input";
    exit(2);
  }

  out.open(argv[2],ios::out);
  
  if(out.fail()){        // se non riesce ad aprire il file di output termina con errore
    cerr << "Impossibile aprire il file di output";
    exit(3);
  }

  int i=0;
  in >> parole[i];
  while (!in.eof() && i < MAX_STR)
  {
    i++;
    if(i < MAX_STR)
      in >> parole[i];
  }

  in.close();

  i--;
  for (; i >= 0; i--)
  {
    if(strlen(parole[i]) > MIN_LEN )
      out << parole[i] << " ";
  }
  
  out.close();

  return 0;
}
