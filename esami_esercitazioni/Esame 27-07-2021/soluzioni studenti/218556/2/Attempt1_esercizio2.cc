#include <iostream>
#include <cstdlib>

using namespace std;

int funzione_aux(int n, int lastDigit)
{
  if (n > 0)
  {
    if (lastDigit == n % 10)
    {
      return 1 + funzione_aux(n / 10, n % 10);
    }
    else
    {
      return funzione_aux(n / 10, n % 10);
    }
  }
  else
  {
    return 0;
  }
}
// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzione(int n)
{
  return funzione_aux(n / 10, n % 10);
}
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
  std::cout << "function(" << n << ") = " << funzione(n) << std::endl;
}