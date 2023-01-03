#include <iostream>

using namespace std;

// SB: ok
bool * create(int n){
    bool * bloom_filter = new bool[n];

    for(int i = 0; i < n; i++){
        bloom_filter[i] = false;
    }

    return bloom_filter;
}

// SB: ok
void insert(bool * bloom_filter , int n, char array_caratteri[]){
    int i = 0;

    while(array_caratteri[i] != '\0'){
        int ascii = array_caratteri[i];

        if(ascii > n){
            // SB: l'istruzione giusta è "ascii = ascii % n", il 100 era solo un esempio, non la consegna
            ascii = ascii % 100;
        }

        bloom_filter[ascii] = true;

        i++;
    }
}

bool control(bool * bloom_filter , int n, char array_caratteri[]){
    int i = 0;
    bool finora_ok = false;

    do{
        int ascii = array_caratteri[i];

        if(ascii > n){
            // SB: l'istruzione giusta è "ascii = ascii % n", il 100 era solo un esempio, non la consegna
            ascii = ascii % 100;
        }

        if(bloom_filter[ascii]){
            finora_ok = true;
        }

        i++;
    }while(array_caratteri[i] != '\0' && finora_ok);

    return finora_ok;
}

// SB: ok
void deinit(bool * bloom_filter){
    delete[] bloom_filter;
}

int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool * bloom_filter = create(n);

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