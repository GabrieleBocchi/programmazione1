#include <iostream>
#include <cstdlib>

using namespace std;

int funzione_aux(int n, int prec, int &res)
{
  // MR: Qui il valore di ritorno non é mai utilizzato, infatti il
  // risultato e' memorizzato in res. Per essere precisi, avrebbe
  // dovuto definirla come procedura (tipo void).


  //caso base se n e' 0 o inferiore allora il risulato e' zero
    if (n <= 0)
    {
        return 0;
    }
    else
    {
        /*** testa nel primo ciclo un caso impossibile -1 == [0,9]
        *    alla iterazione succ. il valore prec diventa il valore precedentemente testato
        *    finche non si arriva al ultimo valore il quale ritorna zero
        *    ma questo zero non sara mai usato in quanto l'unico valore a fare a essere ritornato e' res
        ***/
        if (prec == n % 10)
        {
            res++;
        }
        return funzione_aux((int)((n - (n % 10)) / 10), n % 10, res);
    }
}

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzione(int n)
{
    /*Non credo sia la soluzione piu' elgenate*/

    int res = 0;
    funzione_aux(n, -1, res);
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
