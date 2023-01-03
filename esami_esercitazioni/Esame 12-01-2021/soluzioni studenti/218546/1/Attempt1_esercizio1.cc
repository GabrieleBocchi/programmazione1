// GDT: questo codice non produce alcun file di output.
// Il problema nasce dal fatto che c'è un typo quando si va ad aprire
// lo stream di output
// -> errato: output.open(argv[2]), ios::out;
// -> corretto: output.open(argv[2], ios::out);
//
// Inoltre, il codice assume dei valori massimi sbagliati per la
// lunghezza delle parole e per il numero totale delle parole (50 invece
// che 100 caratteri e 10000 parole). Questo non fa funzionare correttamente
// in alcuni casi. 

#include <iostream>
#include <fstream>
using namespace std;

int str_len(char * c);
void copia(char * argv[]);

int main(int argc, char * argv [])
{
  if(argc == 3) {
    copia(argv);
  } else {
    cout << "Usage: ./a.out <file_input> <file_output>";
  }
  return 0;
}

int str_len(char * c) {
  int i=0;
    while(c[i] != '\0') {
      i++;
    }
  return i;
}

void copia(char * argv[]) {
  fstream input, output;
  input.open(argv[1], ios::in);;
  output.open(argv[2], ios::out);

  if(input.fail()) {
    cout << "file input non esistente\n";
  } else if(output.fail()) {
    cout << "file output non scrivibile\n";
  } else {

    int l_max = 50;
    char ** mat = new char * [l_max];
    
    int i=1;
    int dim;
    mat[0] = new char[l_max];
    input >> mat[0];
    while(!input.eof() && i < l_max) {
      mat[i] = new char[l_max];
      input >> mat[i];
      i++;
    }

    dim = i-1;
    for(i = dim; i >= 0; i--) {
    if(str_len(mat[i]) > 4)
      output << mat[i] << " ";
    }

    for(i=0; i<dim; i++) {
      delete[] mat[i];
    }
    delete [] mat;


    input.close();
    output.close();
  }

}
