// GDT: vedere commenti nel codice.

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int lunghezza(char c[]);
bool lettere_maiuscole(char c[]);

bool numeri(char c[]);

int main(int argc, char * argv [])
{
  if(argc!=3){
    cerr<<"Hai inserito un numero di argomenti errato"<<endl;
    exit(0);
  }
  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);
  char buffer[100];
  int conta=0;
  // GDT: attenzione che l'ultima parola viene letta 2 volte.
  // L'istruzione giusta sarebbe
  //  input >> buffer;
  //   while(!input.eof()){
  //    ...
  //    input >> buffer;
  //   }
  while(!input.eof()){
    input>>buffer;
    int dim=lunghezza(buffer);
    if(dim==16){
      if(lettere_maiuscole(buffer)&&numeri(buffer)){
        conta++;
      }
    }
  }

  output<<conta;
  input.close();
  output.close();
  return 0;
}


int lunghezza(char c[]){
  int i=0;
  for(; c[i]!='\0'; i++){}
  return i;
}

bool lettere_maiuscole(char c[]){
  bool x=true;
  for(int i=0; (i<4) && (x==true); i++){

    if(c[i]>='A'&&c[i]<='Z'){
      x=true;
    }
    else{
      x=false;
    }

  }
  return x;
}

bool numeri(char c[]){
  bool x=true;
  for(int i=4; (i<16) && (x==true); i++){
    if(c[i]>='0' &&c[i]<='9'){
      x=true;
    }
    else{
      x=false;
    }
  }
  return x;

}
