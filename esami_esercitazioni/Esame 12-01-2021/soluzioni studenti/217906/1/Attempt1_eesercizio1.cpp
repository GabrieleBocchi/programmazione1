// GDT: fare riferimento alla soluzione ufficiale per uno svolgimento. 

#include <iostream>
#include <fstream>
using namespace std;

int length(char str[]);
int main(int argc, char *argv[]){
  fstream input, output;
  char tmp[100];
  int g = 0;

  if(argc!=3){
    cout << "Errore nei parametri richiesti";
    exit(0);
  }

  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  if(input.fail()){
    cout << "Errore nel file di input, verificare sia esistente!";
    exit(0);
  }

  while(!input.eof()){
    input >> tmp;
    g = sizeof(tmp)/sizeof(char);

    if(g%2 != 0){
      output << tmp << " ";
    }

  }

  input.close();
  output.close();

  return 0;
}
