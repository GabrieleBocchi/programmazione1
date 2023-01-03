#include <iostream>
#include <cstdlib>

using namespace std;

int f_aux(int n, int current)
{
    if (n == 0)
    {
        return 0;
    }
    int next = n % 10;

    if (next != current)
    {
        return 1 + f_aux(n / 10, next);
    }
    else
    {
        return f_aux(n / 10, next);
    }
}

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzione(int n)
{
    if (n < 0)
    {
        return 0;
    }

    return f_aux(n / 10, n % 10);
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