#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzione(int n, bool was_even = false)
{
  if(n <= 0)
    return 0;
  else
  {
    int current = n % 10;

    if(current % 2 == 0)
      // MR: Static cast e' una feature avanzata, mi pare esagerato
      // usarlo per convertire un bool in intero 0/1, ma ok.
      return static_cast<int>(was_even) + funzione(n/10, true);
    else
      return funzione(n/10, false);
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
