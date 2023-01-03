#include <iostream>
#include <cstdlib>

using namespace std;


// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzione (int n);
// Scrivere qui sopra la dichiarazione e definizione della funzione "funzione"

void funzione_aux (int n, int past, int & counter);

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

int funzione (int n){
    int ret = 0;
    if(n > 0){
        funzione_aux(n, -1, ret);
    }
    return ret;
}

void funzione_aux (int n, int past, int & counter){
  // MR: Non calcola correttamente il numero di coppie differenti
  // perche' ad esempio in 1211010 ci sono le coppie: 12 21 11 10 01
  // 10 e quindi quelle diverse sono 5 e non 3 come calcolato da lei!
  // Il problema penso che sia che non propaga correttamente il past!
  // Sugli esempi del testo funziona, ma su altri da risultati errati!
    if(n > 10){
        funzione_aux(n/10, n%10, counter);
        if(past > 0 && (n%10 != past)){
            counter++;
        }
    }else{
        if (past > 0 && n%10 != past){
            counter++;
        }
    }
}
