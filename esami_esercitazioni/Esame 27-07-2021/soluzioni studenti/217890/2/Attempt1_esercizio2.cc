#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
void estrai(int n, int cifra, int &res);
int funzione(int n)
{
    int res = 0;
    estrai(n, 0, res);
    return res;
}

void estrai(int n, int cifra, int &res)
{
  // MR: Il codice controlla se le coppie sono uguali e pari, ma non
  // era quello richiesto, dovevano essere solo pari: ad esempio
  // 54211228 deve riportare 3 e non 1! Le coppie sono: 54 42 21 11 12
  // 22 28 e quelle pari sono 42 22 e 28!
    if (n <= 0)
    {
    }
    else
    {
        int tmp = cifra;
        cifra = n % 10;
        if (tmp == cifra && cifra % 2 == 0)
        {
            res++;
        }
        n = n / 10;
        estrai(n, cifra, res);
    }
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
