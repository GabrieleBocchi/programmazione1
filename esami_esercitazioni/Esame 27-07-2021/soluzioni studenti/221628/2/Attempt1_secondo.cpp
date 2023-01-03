#include <iostream>
#include <cstdlib>

using namespace std;

void funzione_aux(int n, int &res)
{  // MR: n / 10 avrebbe potuto calcolarlo una sola volta, ma ok.
    if (n/10 != 0)
    {
        if (n%10 != (n/10) % 10)
        {
            res++;
        }

        funzione_aux(n / 10, res);
    }
}
// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzione(int n)
{
    int res = 0;

    if (n >= 0)
    {
        funzione_aux(n, res);
    }

    return res;
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
