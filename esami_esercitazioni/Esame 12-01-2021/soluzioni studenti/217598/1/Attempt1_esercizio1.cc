// GDT: parole[i] = buffer non assegna il contenuto di buffer all'array parole. Quello che fa
// è assegnare il puntatore della variabile buffer all'array parole[i]. Per questo, alla fine nel
// file di output viene stampata sempre la stessa parola.
//
// Manca la deallocazione dell'area di memoria riservata con new.
//
// Fare riferimento alla soluzione ufficiale per un possibile svolgimento.

#include <iostream>
#include <fstream>
using namespace std;

int len(char * parola){ //funzione che calcola la lunghezza della parola
  int indice =0;
  while (parola[indice] != '\0'){
    indice++;
  }
  return indice;
}

int main(int argc, char * argv [])
{
  if (argc != 3){
    cerr << "Usage: ./a.out <file_input> <file_output>" << endl;
    exit(0);
  }

  fstream input, output;
  input.open(argv[1], ios::in);
  if (input.fail()){
    cerr << "Il file " << argv[1] << " non esiste" << endl;
    exit(0);
  }

  char **parole = new char*[1000]; //array che contiene le parole formate da un numero dispari di lettere
  int i =0;

  output.open(argv[2], ios::out);
  
  char buffer[100];
  input >> buffer;
  while (!input.eof()) {
    if (len(buffer)%2 != 0 ) {
      parole[i] = new char[100];
      parole[i] = buffer;
      i++;
    }
    input >> buffer;
  }
  input.close();
  for (int j=i-1; j>0; j--) {
    output << parole[j] << " ";
  }
  output << endl;
  output.close();

  return 0;
}
