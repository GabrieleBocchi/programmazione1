#include <iostream>

using namespace std;

bool * create(int n);
void insert(bool * vettore, int n, char * caratteri);
bool control(bool * vettore, int n, char * caratteri);
void deinit(bool * vettore);

// SB: l'istruzione corretta è "delete [] filter"
void deinit(bool * vettore)
{
    delete vettore;
}

bool control(bool * vettore, int n, char * caratteri)
{
    int indiceC=0,valoreAsciiCarattere;
    while(caratteri[indiceC]!='\0')
    {
        valoreAsciiCarattere=caratteri[indiceC];
        if(valoreAsciiCarattere>n)
        {
            // SB: l'istruzione giusta è "ascii = ascii % n", il 100 era solo un esempio, non la consegna
            valoreAsciiCarattere=valoreAsciiCarattere%100;
        }
        if(vettore[valoreAsciiCarattere]==false)
        {
            return false;
        }
        indiceC++;
    }
    return true;
}


void insert(bool * vettore, int n, char * caratteri)
{
    int indiceC=0,valoreAsciiCarattere;

    while(caratteri[indiceC]!='\0')
    {
        valoreAsciiCarattere=caratteri[indiceC];
        if(valoreAsciiCarattere>n)
        {
            // SB: l'istruzione giusta è "ascii = ascii % n", il 100 era solo un esempio, non la consegna
            valoreAsciiCarattere=valoreAsciiCarattere%100;
        }
        vettore[valoreAsciiCarattere]=true;
        indiceC++;
    }
}

// SB: ok
bool * create(int n)
{
    bool * vettore = new bool [n];

    for(int i=0;i<n;i++)
    {
        vettore[i]=false;
    }
    return vettore;
}

int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool* bloom_filter = create(n);

    char ciao[] = { 'c', 'i', 'a', 'o', '\0' };

    insert(bloom_filter, n, ciao);

    cout << "Ho inserito la parola 'ciao' nel bloom filter" << endl;

    if (control(bloom_filter, n, ciao)) {
        cout << "La parola 'ciao' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'ciao' NON è presente nel bloom filter " << endl;
    }

    char volo[] = { 'v', 'o', 'l', 'o', '\0' };

    if (control(bloom_filter, n, volo)) {
        cout << "La parola 'volo' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'volo' NON è presente nel bloom filter " << endl;
    }

    deinit(bloom_filter);

    return 0;
}