#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzione(int n)
{
    int retvalue = 0;
    
	if(n>=10)
	{
		int ultima_cifra = n%10;
	    int penultima_cifra = ((n-ultima_cifra)/10)%10;
	    
	    if(ultima_cifra!=penultima_cifra)
	       retvalue = 1;
	       
		retvalue = retvalue + funzione(n/10);
	}

    return retvalue;
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
}
