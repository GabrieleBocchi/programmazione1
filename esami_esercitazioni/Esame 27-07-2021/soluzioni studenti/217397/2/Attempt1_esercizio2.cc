#include <iostream>
#include <cstdlib>

using namespace std;

void funzioneRic(int n, int & i)
{
    if(n > 9)
    {
      int tmp, tml, nn;
      tmp = n%10;
      nn = n/10;
      tml = nn%10;
      
      if(tmp != tml)
      {
        i++;
      }
    funzioneRic(n/10,i);
    }
    
}
// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzione(int n);
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

int funzione(int n)
{
    int ris;
    if(n <=0)
    {
        ris = 0;
    }
    else{
        int i = 0;
        funzioneRic(n,i);
        ris = i;
    }
    return ris;
}