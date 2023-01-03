#include <iostream>
#include <fstream>
using namespace std;

int conta_caratteri(char parola[]);
void copia(char a[], char b[], int len);

int main(int argc, char * argv [])
{
  if(argc!=3){
    cerr << "Errore nei parametri" <<endl;
    exit(-1);
  }
  fstream input,output;
  input.open(argv[1],ios::in);
  if(input.fail()){
    cerr << "Errore nell'apertura del file di input"<<endl;
    exit(-2);
  }
  
  int cont_parole=0;
  char** list = new char*[10000];
  char parola[100];
  input >> parola;

  while(!input.eof()){
    int numero_caratteri=conta_caratteri(parola);
    if(numero_caratteri>4){
      list[cont_parole] = new char[100];
      copia(list[cont_parole],parola,numero_caratteri);
      cont_parole++;
    }
    input >> parola;
  }
  input.close();
  


  output.open(argv[2],ios::out);
  if(output.fail()){
    cerr << "Errore nell'apertura del file di output"<<endl;
    exit(-2);
  }

  for(int i=cont_parole-1; i>=0; i--){
    output << list[i] << " ";
    delete[] list[i];
  }
  delete[] list;

  return 0;
}


int conta_caratteri(char parola[]){
  int rtn=0;
  while(parola[rtn]!='\0'){
    rtn++;
  }
  return rtn;
}

void copia(char a[], char b[], int len){
  for(int i=0; i<len; i++){
    a[i] = b[i];
  }
}
