#include <iostream>
#include <cstdlib>

using namespace std;

int funzione(int n);

int funzione(int n){
  // MR: Questo non capisco a cosa serva, se non per creare errore!
  // Infatti accede ad area di memria non allocata, fa conversione in
  // intero e quindi da qui in avanti n e' un valore random rispetto a
  // quello passato come argomento!
  char **argv;
  n = atoi(argv[1]);
  int coppie=0;
  int a, b;

  if(n<0)
    n=coppie;
  else    {
    a=n%10;
    b=n%100;
    if (((a%2)==0)&& ((b%2)==0)){
	coppie++;
	n/=10;
      }
  }
  // E se il numero e'composto da piu' di due cifre?
  return n;
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
