#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzione(int n);
int appoggio(int n,int cifraPrec);

int funzione(int n)
{
	return appoggio(n/10,n % 10);
}

int appoggio(int n,int cifraPrec)
{
  // MR: il modulo avrebbe avuto senso metterlo dopo controllo per non
  // farlo quando non necessario!
	int primaCifra = n % 10;
	if(n > 0)
	{
		if(primaCifra != cifraPrec)
		{
			return 1 + appoggio(n/10,n % 10);
		}else{
			return 0 + appoggio(n/10,n % 10);
		}
	}else{
		return 0;
	}
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
