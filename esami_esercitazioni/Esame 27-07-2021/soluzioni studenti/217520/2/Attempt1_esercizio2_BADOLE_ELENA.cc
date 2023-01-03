#include <iostream>
#include <cstdlib>

using namespace std;

//Dichiaro e definisco le funzioni ricorsive

int funzione(int n);
int funzione_ric(int n, int conta);

int funzione(int n){
  //dichiaro la variabile che conta le coppie e chiamo la funzione ricorsiva
  int conta = 0;

  conta = funzione_ric(n, conta);

  return conta;
}

int funzione_ric(int n, int conta){
  //se il numero ha solo una cifra o è negativo si esce 
  if(n < 10){
    return conta;
  }
  else{
    //parto dal fondo e controll0
    if(n % 10 != ((n % 100)/10)){
    
      //Se le ultime due lettere sono diverse tra loro incremento il contatore e diminuisco il numero
      return funzione_ric(n/10, conta+1);
    }
    else{
      return funzione_ric(n/10, conta);
    }
  }
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <positivenum> " << std::endl;
    exit(1);
  }
  int n = atoi(argv[1]);
  std::cout << "The read string is: " << argv[1] << std::endl;
  std::cout << "The converted value is: " << n << std::endl;
  std::cout << "function("<< n << ") = " << funzione(n) << std::endl;
}