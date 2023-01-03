// GDT: la variabile PAROLE ha un valore che non rispetta la consegna. Dovrebbe essere 10000.
// Perciò, il codice va in segmentation fault una volta eseguito su dei casi di test.

#include <iostream>
#include <fstream>
using namespace std;

const int CARATTERI = 100;
const int PAROLE = 100;

void stampa(char ** &testo,int n_parole,char file[]);
bool pari(char parole[]);

int main(int argc, char * argv [])
{
  int i,j = 0,n_parole = 0;
  char temp;
  fstream input;

  char ** testo = new char * [PAROLE];
  for(i = 0; i < PAROLE; i++){
    testo[i] = new char [CARATTERI+1];
    for(j = 0; j < (CARATTERI+1); j++){
      testo[i][j] = '\0';
    }
  }
  
  j = 0;
  if(argc == 3){
    input.open(argv[1],ios::in);
    if(input.fail()){
      cout << "Errore";
    }else{
      while(input >> testo[j]){
	n_parole++;
	j++;
      }
      stampa(testo,n_parole,argv[2]);
    }

    for(i = 0; i < PAROLE; i++){
      delete [] testo[i];
    }
    delete [] testo;
    
  }else{
    cout << "Errore";

  }
  
  return 0;
}

void stampa(char ** &testo,int n_parole,char file[]){
  fstream output;
  int i,j;
  output.open(file,ios::out);

  if(!output.fail()){
    for(i = (n_parole-1); i >= 0; i-- ){
      if(pari(testo[i])){
	output << testo[i] << " ";
      }
    }
   
  }else{
    cout << "Errore";
  }
  
}

bool pari(char parole[]){
  bool res = false;
  int i = 0,n = 1;
  while(parole[i] != '\0'){
    i++;
    n++;
  }
  n--;
  if((n % 2) == 0){
    res = true;
  }
  
  return res;
}
