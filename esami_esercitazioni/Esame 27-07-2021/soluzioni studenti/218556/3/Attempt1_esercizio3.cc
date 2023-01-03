#include <iostream>

using namespace std;

bool *create(int n);
void insert(bool *filter, int dimFilter, char word[]);
bool control(bool *filter, int dimFilter, char word[]);
void deinit(bool *filter);

// SB: l'istruzione corretta è "delete [] filter"
void deinit(bool *filter)
{
    delete filter;
}

// SB: ok
bool *create(int n)
{
    bool *arr = new bool[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = false;
    }

    return arr;
}


void insert(bool *filter, int dimFilter, char word[])
{
    int i = 0;
    while (word[i] != '\0')
    {
        int index = (int)(word[i]);
        // SB: dovrebbe considerare anche il caso in cui "index == dimFilter"
        if (index > dimFilter)
        {
            index %= dimFilter;
        }

        filter[index] = true;
        i++;
    }
}

// SB: il codice non funziona se il bloom filter contiene più di un elemento
bool control(bool *filter, int dimFilter, char word[])
{
    bool *filterTmp = new bool[dimFilter];

    for (int i = 0; i < dimFilter; i++)
    {
        filterTmp[i] = filter[i];
    }

    int i = 0;
    while (word[i] != '\0')
    {
        int index = (int)(word[i]);
        // SB: dovrebbe considerare anche il caso in cui "index == dimFilter"
        if (index > dimFilter)
        {
            index %= dimFilter;
        }

        filterTmp[index] = !filterTmp[index];
        i++;
    }

    bool check = true;

    for (int i = 0; i < dimFilter; i++)
    {
        if (filterTmp[i])
        {
            check = false;
            i = dimFilter;
        }
    }

    deinit(filterTmp);

    return check;
}

int main(int argc, char *argv[])
{

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool *bloom_filter = create(n);

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