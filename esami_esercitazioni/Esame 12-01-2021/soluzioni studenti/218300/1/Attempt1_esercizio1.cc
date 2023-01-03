// GDT: piccola imprecisione. La prima volta che leggi dal file di input utilizzi
// le parentesi angolari dal verso sbagliato (dovrebbe essere >> invece che <<). 

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv [])
{
  fstream input, output;
  int contatore = 0;
  char parole [10000][101]; // da testo il file ha al massimo 10000 parole lunghe al massimo 100 caratteri ai quali va aggiunto il \0 alla fine
  if (argc!=3){
    cerr << "Sintassi errata, usare: ./a.out <nomeInput> <nomeOutput>" << endl;
    exit (0);
  }
  input.open (argv[1], ios::in);

  if (input.fail()){
    cerr << "Non trovo il file " << argv[1] << endl;
    exit (0);
  }
  input << parole [contatore];
  contatore++;
  while (!input.eof()){
    input >> parole [contatore];
    contatore ++;
  }
  input.close();
  output.open (argv[2], ios::out);
  if (output.fail()){
    cerr << "Non riesco a scrivere nel file " << argv[2] << endl;
    exit (0);
  }
  for (int j = contatore-1; j>=0; j--){
    for (int m = 1; m<=4; m++){ // per verificare che una parola e' lunga 4 o meno controllo che ci sia il carattere \0 tra la posizione 1 e 4 
      if (parole[j][m]=='\0'){
	output << parole [j] << " ";
	m = 5;
	}
    }
  }
  
  output.close();
  return 0;
}
