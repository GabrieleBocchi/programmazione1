#include <iostream>

using namespace std;

//implementazione ricorsiva di strlen
int strlen(const char *str)
{
    return *str ? (strlen(str + 1) + 1) : 0;
}

// SB: ok
//Allocazione nella heap di un array di bool di dim n
bool *init(int n)
{
    return new bool[n];
}

// SB: l'istruzione corretta è "delete [] del".
//Dealocazione del array nell heap, utilizzando come parm una referens a array
void deinit(bool *&del)
{
    delete del;
}

// SB: ok
//Implementazione della funzione insert
void insert(bool *bloom_filter, int n, const char *str)
{
    //Itera sulla parola
    for (int i = 0; i < strlen(str); i++)
    {
        //Accede alla "cella" n-essima prendendo il valore tabulato del carattere per il modulo e lo setta a true
        bloom_filter[str[i] % n] = true;
    }
}

// SB: ok
bool check(bool *bloom_filter, int n, const char *str)
{
    //Dichiarazione e init del risultato
    bool res = true;
    //Itera sulla parola
    for (int i = 0; i < strlen(str); i++)
    {
        // SB: evitare di mettere istruzione condizionale e corpo nella stesa riga
        //Testa se la "cella" n-essima e' true in caso contrario imposta il res a false
        if(bloom_filter[str[i] % n] != true) res = false;
    }
    return res;
}

int main(int argc, char *argv[])
{

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool *bloom_filter = init(n);

    char ciao[] = {'c', 'i', 'a', 'o', '\0'};
    insert(bloom_filter, n, ciao);
    
    cout << "Ho inserito la parola 'ciao' nel bloom filter" << endl;

    if (check(bloom_filter, n, ciao))
    {
        cout << "La parola 'ciao' è presente nel bloom filter " << endl;
    }
    else
    {
        cout << "La parola 'ciao' NON è presente nel bloom filter " << endl;
    }

    char volo[] = {'v', 'o', 'l', 'o', '\0'};
    if (check(bloom_filter, n, volo))
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