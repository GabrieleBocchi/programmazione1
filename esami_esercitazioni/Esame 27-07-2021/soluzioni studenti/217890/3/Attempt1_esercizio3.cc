#include <iostream>

using namespace std;

// SB: i nomi delle funzioni non corrispondono alla consegna
// SB: controllare la soluzione fornita per la corretta inizializzazione dell'array
bool *init(int n)
{
    bool *tmp[n];
    for (int i = 0; i < n; i++)
    {
        tmp[i] = new bool;
    }
    return *tmp;
}

// SB: ok
void insert(bool *bloom, int n, char *txt)
{
    for (int i = 0; txt[i] != '\0'; i++)
    {
        bloom[txt[i] % n] = true;
    }
}

// SB: ok
bool control(bool *bloom, int n, char *txt)
{
    bool check = true;
    for (int i = 0; txt[i] != '\0'; i++)
    {

        if (bloom[txt[i] % n] != true)
        {
            check = false;
        }
    }
    return check;
}

// SB: ok
void deinit(bool *bloom)
{
    delete[] bloom;
}

int main(int argc, char *argv[])
{

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool *bloom_filter = init(n);

    char ciao[] = {'c', 'i', 'a', 'o', '\0'};
    insert(bloom_filter, n, ciao);
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

    deinit(bloom_filter);

    return 0;
}