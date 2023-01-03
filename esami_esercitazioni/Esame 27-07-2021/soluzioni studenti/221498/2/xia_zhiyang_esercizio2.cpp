#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"

// MR: La funzione doveva avere un solo argomento! Veda testo esame!
int funzione(int n, int i);
// Scrivere qui sopra la dichiarazione e definizione della funzione "funzione"

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cout << "Usage: " << argv[0] << " <positivenum> " << std::endl;
    exit(1);
  }
  int n = atoi(argv[1]);
  std::cout << "The read string is: " << argv[1] << std::endl;
  std::cout << "The converted value is: " << n << std::endl;
  // MR: Non era prescritto di cambiare il main! La funzione doveva
  // avere un solo argomento!
  std::cout << "function(" << n << ") = " << funzione(n, 0) << std::endl;
}

int funzione(int n, int i)
{
  if (n <= 0)
  {
    return 0;
  }
  else
  {

    if ((n % 10) % 2 == 1 && ((n / 10) % 10) % 2 == 1)
    {
      i++;
    }
    // Forse qui manca un return e/o salvare risultato chiamata
    // ricorsiva?
    funzione(n / 10, i);
  }
  return i;
}
