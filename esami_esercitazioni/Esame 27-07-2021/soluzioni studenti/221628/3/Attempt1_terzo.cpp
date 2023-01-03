#include <iostream>

using namespace std;

bool *create(int n);
void add(bool* bloom_filter, int dim, char* array);
bool control(bool* bloom_filter, int dim, char* array);
void destroy(bool* &a);

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
    bool *array = new bool[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = false;
    }

    return array;
}

// SB: ok
void add(bool* bloom_filter, int dim, char* array) {
    for (int i=0; array[i] != '\0'; i++) {
        int ascii = (int)array[i];

        if (ascii >= dim) {
            ascii = ascii%dim;
        }

        bloom_filter[ascii] = true;
    }
}

// SB: ok
bool control(bool* bloom_filter, int dim, char* array) {
    bool controllo = true;

    for (int i=0; array[i] != '\0' && controllo == true; i++) {
        int ascii = (int)array[i];

        if (bloom_filter[ascii] != true) {
            controllo = false;
        }
    }

    /*//Scorre il bloom_filter per controllare se ci sono lettere in eccesso
    for (int i=0; bloom_filter[i] != '\0' && controllo == true; i++) {

        if (bloom_filter[i] == true) {
            controllo = false;
            for (int j = 0; array[j] != '\0' && controllo == false; j++) {
                if ((int)array[j] == i) {
                    controllo = true;
                }
            }
        }
    }
    */

    return controllo;
}

// SB: ok
void destroy(bool* &a) {
    delete[] a;
}