#include <iostream>
#include <fstream>
using namespace std;

const int MAX_LEN = 100;
const int MAX_DIM = 10000;

int lunghezza(char* parola);
void copia_stringa(char* a, char* b);

int main(int argc, char * argv [])
{
  if(argc!=3){
    cerr << "Utilizzo: <./a.out> <input> <output>" << endl;
    exit(1);
  }

  fstream input, output;

  input.open(argv[1], ios::in);
  if(input.fail()){
    cerr << "Errore lettura file input." << endl;
    exit(2);
  }

  int numero_parole = 0;
  char parola[MAX_LEN];

  while(input>>parola && numero_parole<MAX_DIM){
    numero_parole++;
  }

  input.close();
  input.open(argv[1], ios::in);

  char** text = new char* [numero_parole];
  int index = 0;

  while(input >> parola && index<numero_parole){
    int len = lunghezza(parola) + 1;
    if(len%2 == 0){
      text[index] = new char[len];
      copia_stringa(text[index], parola);
      index++;
    }
  }

  input.close();

  output.open(argv[2], ios::out);

  for(int i=index-1; i>=0; i--){
    output << text[i] << " ";
  }

  output.close();

  for(int i=0; i<numero_parole; i++){
    delete[] text[i];
  }
  delete[] text;

  return 0;
}

int lunghezza(char* parola){
  int res = 1;
  for(int i=0; parola[i]!='\0'; i++){
    res++;
  }
  return res;
}

void copia_stringa(char* a, char* b){
  int i = 0;
  while(b[i]!='\0'){
    a[i] = b[i];
    i++;
  }
  a[i] = '\0';
}
