#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"

int funzione(int num);
int funzioneAus(int num,int cont);


int funzione(int num)
{
  // Se chiamato su 57132219 ritorna erroneamente 5 invece che 4! Le
  // coppie sono: 57 71 13 32 22 21 19, e quelle dispari sono: 57 71
  // 13 e 19! Il problema penso sia dovuto all'assenza di return nella
  // funzione ausiliaria!
  int cont = 0;
  int returnValue = 0;

  if(num < 0)
    return 0;

  else if(num == 0)
    return 0;

  else
    {
      returnValue = funzioneAus(num,cont);
      return --returnValue;
    }

}

int funzioneAus(int num,int cont)
{
  int cifra,tmp,restoCifra,restoTmp;

  if(num > 0)
  {
    // MR: Che cosa ritorna quando e' in questo ramo dell'esecuzione?
      cifra = num % 10;
      tmp = funzioneAus(cifra/10,cont);

      restoCifra = cifra % 2;
      restoTmp = tmp % 2;

      if(restoCifra == 0 && restoTmp == 0)
	funzioneAus(num/10,cont);
      else
	{
	  cont++;
	  funzioneAus(num/10,cont);
	}
  }

  else
    return cont;

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
