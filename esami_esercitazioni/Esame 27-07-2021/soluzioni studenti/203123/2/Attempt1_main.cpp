#include <iostream>
#include <cstdlib>

using namespace std;

int countParity (int *n, int counter){
  // MR: Su input 122122 da risultato sbagliato. Penso per le
  // operazioni fatte con side effect su *n! Non capisco perche'
  // passarlo come puntatore invece che per riferimento! Anche su
  // esempi del testo i risultati sono errati!
	if(*n <= 10){
	  // MR: Se = 10 forse andrebbe gestito in modo diverso (ci sono
	  // due cifre, che ok sono diverse e non sono pari, ma...
		return counter;
	}
	// MR: Qui mi sto perdendo nella logica che non e' chiara!
	int c = *n%10;
	*n = (*n-c)/10;
	if(*n%2 == 0 && c%2 == 0){
		counter++;
	}
	*n = *n/10;
	return countParity(n, counter);
}

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzione(int n){
	if(n <= 0){
		return 0;
	}
	int contatore = 0;
	int parity = countParity(&n, contatore);
	return parity;
}
// Scrivere qui sopra la dichiarazione e definizione della funzione "funzione"

int main(int argc, char ** argv) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <positivenum> " << std::endl;
    exit(1);
  }
  int n = atoi(argv[1]);
  std::cout << "The read string is: " << argv[1] << std::endl;
  std::cout << "The converted value is: " << n << std::endl;
  std::cout << "function("<< n << ") = " << funzione(n) << std::endl;
  return 0;
}
