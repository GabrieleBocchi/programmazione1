#include <iostream>

using namespace std;

typedef bool* bloomF; 

bloomF init (int dim);
void insert (bloomF & bf, const int dim, char word []);
bool check (bloomF & bf, const int dim, char word []);
void deinit (bloomF & bf);

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
bloomF init (int dim){
    bool* bf = new bool [dim];

    for (int i = 0; i < dim; i++){
        bf[i] = false;
    }

    return bf;
}

// SB: ok
void insert (bloomF & bf, const int dim, char word []){
    int i = 0;

    while(word[i] != '\0'){
        // SB: il ciclo for si può semplificare in "bf[(int) word[i] % dim] = true"
        for(int k = 0; k < dim; k++){
            if(bf[k] == false && (word[i]%dim) == k){
                bf[k] = true;
            }
        }
        i++;
    }
}

// SB: ok
bool check (bloomF & bf, const int dim, char word []){
    int i = 0;
    bool flag = true;

    while(word[i] != '\0' && flag){
        // SB: stessa semplificazione della funzione "insert"
        for(int k = 0; k < dim; k++){
            if((word[i]%dim) == k){
                if(bf[k] == false){
                    flag = false;
                }
            }
        }
        i++;
    }

    return flag;
}

// SB: ok
void deinit (bloomF & bf){
    delete [] bf;
}