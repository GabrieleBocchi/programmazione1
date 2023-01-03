#include <iostream>

using namespace std;

bool *create(int n);
void add(bool *bloom_filter, int n, char *parola);
bool control(bool *bloom_filter, int n, char *parola);
void destroy(bool *bloom_filter);
int strlen(char *parola);

int main(int argc, char *argv[])
{

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool *bloom_filter = create(n);

    char ciao[] = {'c', 'i', 'a', 'o', '\0'};
    add(bloom_filter, n, ciao);
    cout << "Ho inserito la parola 'ciao' nel bloom filter" << endl;

    if (control(bloom_filter, n, ciao))
    {
        cout << "La parola 'ciao' è presente nel bloom filter " << endl;
    }
    else
    {
        cout << "La parola 'ciao' NON è presente nel bloom filter " << endl;
    }

    char volo[] = {'v', 'o', 'l', 'o', '\0'};
    if (control(bloom_filter, n, volo))
    {
        cout << "La parola 'volo' è presente nel bloom filter " << endl;
    }
    else
    {
        cout << "La parola 'volo' NON è presente nel bloom filter " << endl;
    }

    destroy(bloom_filter);

    return 0;
}

// SB: ok
bool *create(int n)
{
    bool *bloom_filter = new bool[n];

    for (int i = 0; i < n; i++)
    {
        bloom_filter[i] = false;
    }
    return bloom_filter;
}

// SB: ok
void add(bool *bloom_filter, int n, char *parola)
{
    for (int i = 0; i < strlen(parola); i++)
    {
        int posizione = (int)parola[i];

        if (posizione >= n)
        {
            posizione = (posizione) % n;
        }

        if (bloom_filter[posizione] != true)
        {
            bloom_filter[posizione] = true;
        }
    }
}

// SB: ok
bool control(bool *bloom_filter, int n, char *parola)
{
    bool presente = true;

    for (int i = 0; i < strlen(parola) && presente; i++)
    {
        int posizione = (int)parola[i];

        if (posizione >= n)
        {
            posizione = (posizione) % n;
        }

        if (bloom_filter[posizione] != true)
        {
            presente = false;
        }
    }

    return presente;
}

// SB: ok
void destroy(bool *bloom_filter)
{
    delete[] bloom_filter;
}

int strlen(char *parola)
{
    int contatore = 0;
    while (parola[contatore] != '\0')
    {
        contatore++;
    }
    return contatore;
}