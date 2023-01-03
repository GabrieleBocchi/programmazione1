#include <iostream>

using namespace std;

// SB: ok
bool * create(int size)
{
    bool * bloom_filter = new bool[size]; 
    for(int i = 0; i < size; ++i)
        bloom_filter[i] = false; 
    
    return bloom_filter; 
}

// SB: ok
void insert(bool *bloom_filter, int size, char const* word)
{
    while(*word != '\0')
    {
        int i = static_cast<int>(*word) % size; 
        bloom_filter[i] = true; 
        ++word; 
    }
}

// SB: ok
bool control(bool const* bloom_filter, int size, char const* word)
{
    bool is_present = true; 
    while(*word != '\0' && is_present)
    {
        int i = static_cast<int>(*word) % size; 
        is_present = bloom_filter[i] && is_present; 
        ++word; 
    }
    return is_present; 
}

// SB: ok
void deinit(bool * bloom_filter)
{
    delete[] bloom_filter; 
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