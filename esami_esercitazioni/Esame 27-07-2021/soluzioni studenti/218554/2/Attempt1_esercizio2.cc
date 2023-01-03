#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
void funzione_aux(int n, int &contatore, int &temp)
{
    if (n > 0)
    {
        int cifra = n % 10;
        funzione_aux(n / 10, contatore, temp);

        if (temp == -1)
        {
            temp = cifra;
        }

        if (cifra != temp)
        {
            contatore++;
        }

        temp = cifra;
    }
    else
    {
        temp = -1;
    }
}

int funzione(int n)
{

    if (n < 0)
    {
        return 0;
    }
    else
    {
        int contatore = 0;
        int temp = 0;
        funzione_aux(n, contatore, temp);

        return contatore;
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