#include <iostream>

using namespace std;

// SB: ok
bool *create(int n)
{
    bool *bloom_filter = new bool[n];
    for (int i = 0; i < n; i++)
    {
        bloom_filter[i] = 0;
    }
    return bloom_filter;
}

// SB: ok, forse meglio usare la notazione "[]"
void add(bool *bloom_filter, int n, char *char_array)
{
    while (*char_array != '\0')
    {
        char c = *char_array;
        int ascii = c;

        if (bloom_filter[ascii % n] == false)
        {
            bloom_filter[ascii % n] = true;
        }
        char_array++;
    }
}

// SB: ok come sopra
bool control(bool *bloom_filter, int n, char *char_array)
{
    bool check = true;
    while (*char_array != '\0' && check)
    {
        char c = *char_array;
        int ascii = c;

        if (bloom_filter[ascii % n] == false)
        {
            check = false;
        }
        char_array++;
    }
    return check;
}

// SB: ok
void destroy(bool *bloom_filter)
{
    delete[] bloom_filter;
}

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