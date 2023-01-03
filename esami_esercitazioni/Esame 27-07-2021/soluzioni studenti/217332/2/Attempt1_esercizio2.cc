#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzione(int n);
// Scrivere qui sopra la dichiarazione e definizione della funzione "funzione"
int funzione_aux(int n, int prev);

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

int funzione(int n){
    int prev = -1;
    return funzione_aux(n,prev);
}
int funzione_aux(int n, int prev){
    if(n!=0){
        if((n%10)%2 == 1){
            if(prev%2 == 1){
                return 1+funzione_aux(n/10,n%10);
            } else{
                return funzione_aux(n/10,n%10);
            }
        } else {
            return funzione_aux(n/10,n%10);
        }
    }
    // MR: Cosa ritorna se n == 0?
}
