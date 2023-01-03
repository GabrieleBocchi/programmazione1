// GDT: esercizio corretto. Il ciclo per contare i caratteri della stringa
// è un po' macchinoso. Non bastava semplicemente contare i caratteri fino a '\0'
// e poi verificare se cont >= 5?

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv [])
{
  if(argc!=3) {
    cout<<"Inserire <file_input> e <file_output>"<<endl;
    exit(1);
  }

  fstream input, output;
  input.open(argv[1], ios::in);
  if(input.fail()) {
    cout<<"File di input non trovato"<<endl;
    exit(1);
  }
  output.open(argv[2], ios::out);
  if(output.fail()) {
    cout<<"File di output non trovato"<<endl;
    exit(1);
  }

  char lista[10000][100];
  int i=0;

  while(input>>lista[i]) {
    i++;
  }

  int cont = 0;
  bool verifica;
  
  for(int j=i-1; j>=0; j--) {
    cont = 0;
    verifica = false;
    while(cont<5 and !verifica) {
      if(lista[j][cont] != '\0'){
        cont++;
        if(lista[j][cont] == '\0' and cont<5) {
          verifica = true;
        }
      }
    }
    if(cont >=5 ) {
      if(j==0) {                    //con questo if evito di stampare uno spazio in più se siamo all'ultima parola
        output<<lista[j];
      }
      else{
        output<<lista[j]<<" ";
      }
    }
  }
  

  input.close();
  output.close();
  return 0;
}
