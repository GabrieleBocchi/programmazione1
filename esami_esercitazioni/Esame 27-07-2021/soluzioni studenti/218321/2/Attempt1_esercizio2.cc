#include <iostream>
#include <cstdlib>

using namespace std;

int check (int x)
{
  bool result = true;
  
  if( x <= 0 )
    result = false;

  return result;
}

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzione (int n, int counter = 0)
{
  if( check(n) )
    {
      int temp = (n - (n%10)) / 10;
      
      if(n%10 == temp%10)
	counter = funzione(temp, ++counter);
      else
	counter = funzione(temp, counter);
    }
  
  return counter;
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
