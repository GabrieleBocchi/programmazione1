#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char *source, int maxdim);
// Inserire qui sopra la dichiarazione della funzione convert

bool check_base(const char n, const int base)
{
    switch (base)
    {
    case 2:
        return ((n == '0') || (n == '1'));
    case 4:
        return ((n >= '0') && (n <= '3'));
    case 8:
        return ((n >= '0') && (n <= '8'));
    case 16:
        return (((n >= '0') && (n <= '9')) ||
                ((n >= 'A') && (n <= 'D')) ||
                ((n >= 'a') && (n <= 'd')));
    default:
        return false;
    }
}

bool controlla(char *num, const int maxdim, const unsigned int base = 4)
{
    for (int i = 0; ((i < maxdim) && (num[i] != '\0')); i++)
    {
        if (num[i] >= 'A' && num[i] <= 'Z')
        {
            num[i] = 'a' + (num[i] - 'A');
        }
        if (!check_base(num[i], base))
            return false;
    }
    return true;
}

int main()
{
    const unsigned int maxdim = 100;
    char number[maxdim];

    cout << "Inserire numero: ";
    cin >> number;
    if (!controlla(number, maxdim))
    {
        cout << "Il numero deve contenere solo caratteri rispetto alla base" << endl;
        exit(1);
    }

    long long int decimal = convert(number, maxdim);

    cout << "The converted number is: " << decimal << endl;
}

// Inserire qui sotto la definizione della funzione convert
long long int converti(char *a, int dim, int resto, long long int &res, int &cont);
int pow(int n, int dim);

long long int convert(char *source, int maxdim)
{
    int resto = 0;
    long long int res = 0;
    int cont = 0;
    long long int n = converti(source, maxdim, resto, res, cont);

    return n;
}

long long int converti(char *a, int dim, int resto, long long int &res, int &cont)
{
    int pos = cont;
    int n = a[cont - pos] - '0';
    // MR: cont - pos = cont - cont = 0 visto che pos = cont!
    // MR: Nessun controllo che cont sia < maxdim
    if (a[cont] != '\0')
    {
        resto = n % 8;
        n /= 8;

        converti(a, dim, resto, res, ++cont);
    }

    res += n * pow(8, cont);
    cout << pow(8, cont-pos) << endl;

    return res;
}

int pow(int n, int dim)
{
    int res = n;
    if (dim == 0)
    {
        res = 1;
    }
    else if (dim != 1)
    {
      // MR: COSA NON E' CHIARO IN QUESTA FRASE "La funzione converti
      // deve essere ricorsiva ed al suo interno NON ci possono essere
      // cicli o chiamate a funzioni contenenti cicli. Si può però
      // fare uso di funzioni ausiliarie da chiamare all'interno di
      // questa funzione che NON contengano cicli o che siano
      // ricorsive."?
        for (int i = 0; i < dim - 1; i++)
        {
            res *= n;
        }
    }
    return res;
}

// Inserire qui sopra la definizione della funzione convert
