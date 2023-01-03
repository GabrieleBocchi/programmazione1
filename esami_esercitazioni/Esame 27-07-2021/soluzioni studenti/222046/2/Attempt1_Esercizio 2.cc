#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"

int funzione(int n);
int funzioneAusiliaria(int n, int nCoppie);

int funzione(int n)
{
    funzioneAusiliaria(n,0);
}

int funzioneAusiliaria(int n, int nCoppie)
{
    if(n<10)
        return nCoppie;

    int cifra1=n%10;
    n=n/10;
    int cifra2=n%10;

    if(cifra2%2!=0 && cifra1%2!=0)
    {
        nCoppie++;
    }
    funzioneAusiliaria(n,nCoppie);

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