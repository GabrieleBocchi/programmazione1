#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const char codice[]="NNNN-NNNN-NNNN-NNNN";

bool controllo(char buffer[]);

int main(int argc, char * argv [])
{
  if(argc!=3){
    cout<<"Errore, scrivere: <./a.out> <input.txt> <output.txt>"<<endl;
    exit(1);
  }
  else{
    fstream input, output;
    input.open(argv[1], ios::in);
    if(input.fail()){
      cout<<"Errore apertura file input"<<endl;
    }
    else{
      output.open(argv[2], ios::out);
      if(output.fail()){
        cout<<"Errore apertura file output"<<endl;
      }
      else{
        char buffer[101];
        int i=0;
        while (input>>buffer) {
          if(controllo(buffer)){
            i++;
          }
        }
        output<<i;
      }
      output.close();
    }
    input.close();
  }

  return 0;
}

bool controllo(char buffer[]){
  bool ris=false;
  if(strlen(buffer)==strlen(codice)){
    int j=0;
    for(int i=0; codice[i]!='\0'; i++){
      if(codice[i]=='N' && buffer[i]>='0' && buffer[i]<='9'){
        j++;
      }
      else if(codice[i]=='-' && buffer[i]=='-'){
        j++;
      }
    }
    if(j==strlen(codice)){
      ris=true;
    }
  }
  return ris;
}
