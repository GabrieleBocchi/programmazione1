#include <iostream>

using namespace std;

// SB: i nomi delle funzioni non corrispondono alla consegna
bool * init(int n);
void insert(bool * array,int dim, char caratteri[]);
bool check(bool *array,int dim, char caratteri[]);
void deinit(bool *array);

int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool* bloom_filter = init(n);

    char ciao[] = { 'c', 'i', 'a', 'o', '\0' };     
    insert(bloom_filter, n, ciao);
    cout << "Ho inserito la parola 'ciao' nel bloom filter" << endl;
    
    if (check(bloom_filter, n, ciao)) {
        cout << "La parola 'ciao' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'ciao' NON è presente nel bloom filter " << endl;
    }

    char volo[] = { 'v', 'o', 'l', 'o', '\0' }; 
    if (check(bloom_filter, n, volo)) {
        cout << "La parola 'volo' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'volo' NON è presente nel bloom filter " << endl;
    }

    deinit(bloom_filter);

    return 0;
}

// SB: ok
bool * init(int n)
{
    bool * array = new bool[n];
    for(int i = 0; i<n; i++)
    {
        array[i] = false;
    }
    return array;
}

// SB: ok
void insert(bool *array,int n, char caratteri[])
{
    int a = 0, b;
    while(caratteri[a]!= '\0')
    {
        b = caratteri[a];
        if(b > n)
        {
            b = b%n;
            array[b] = true;
        }else{
            array[b] = true;
        }
        a++;
    }

}

// SB: ok
bool check(bool * array,int n, char caratteri[])
{
    int a = 0, b, dimC = 0;
    bool ris = false;
    while(caratteri[dimC]!= '\0')
    {
        b = caratteri[dimC];
        if(b > n)
        {
            b = b%n;
            if(array[b] == true)
            {
                a++;
            }
        }else{
            if(array[b] == true)
            {
                a++;
            }
        }
        dimC++;
    }
    if(dimC == a)
    {
        ris = true;
    }
    return ris;
}

// SB: ok
void deinit(bool * array)
{
    delete[] array;
}