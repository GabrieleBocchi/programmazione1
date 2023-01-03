#include <iostream>

using namespace std;

// SB: i nomi delle funzioni non corrispondono alla consegna
bool *init(int n);
void insert(bool bloom_filter[], int n, char parola[]);
bool check(bool bloom_filter[], int n, char parola[]);
void deinit(bool bloom_filter[]);

// SB: ok
//creo un array dinamico di tipo booleano e lo setto a false
bool *init(int n){
    bool *bloom_filter = new bool[n];

    for(int i=0; i<n; i++){
        bloom_filter[i] = false;
    }

    return bloom_filter;
}

//setto a 1 le celle corrispondenti all'ASCII di ogni carattere della parola data
void insert(bool bloom_filter[], int n, char parola[]){
    int pos = 0;
    int ascii = 0;

    //controllo ogni carattere
    while(parola[pos] != '\0'){
        //trovo l'ASCII
        ascii =(int) parola[pos];

        // SB: questo "if" andrebbe sostituito con "bloom_filter[ascii % n] == true"
        //controllo se l'ASCII esce dal bloom filter
        if(ascii >= n){
            // SB: questo accesso all'array è sicuramente out of bound (visto che ascii >= n), e
            // risulta in un comportamento imprevedibile
            //controllo che la posizione nel bloom filter sia vuota
            while(bloom_filter[ascii] == true){
                ascii = ascii % n;
            }
        }

        bloom_filter[ascii] = true;
        pos++;
    }
}

// SB: non implementata
bool check(bool bloom_filter[], int n, char parola[]){
    bool controllo = true;
    return controllo;
}

// SB: ok
//dealloco l'array dinamico 
void deinit(bool bloom_filter[]){
    delete[] bloom_filter;
}

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