#include <iostream>

using namespace std;

bool* init(int n);
void deinit(bool* bloom_filter);
void insert(bool* bloom_filter, int n, char* charArr);
bool check(bool* bloom_filter, int n, char* charArr);


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
bool * init(int n){
    bool* ris = new bool[n];
    for(int i = 0; i < n; i++){
        ris[i] = false;
    }
    return ris;
}

// SB: ok
void deinit(bool* bloom_filter){
    delete[] bloom_filter;
}

// SB: ok ma meglio fare un cast esplicito di charArr[i] to int. 
// Poi, la condizione "if(charArr[i] > n){" non è necessaria
void insert(bool* bloom_filter, int n, char* charArr){
    for(int i = 0; charArr[i] != '\0'; i++){
        if(charArr[i] > n){
            if(bloom_filter[charArr[i] % n] != true){
                bloom_filter[charArr[i] % n] = true;
            }
        }else{
            if(bloom_filter[charArr[i]] != true){
                bloom_filter[charArr[i]] = true;
            }
        }
    }
}

// SB: ok anche se la condizione "if(charArr[i] > n){" non è necessaria. 
// Il codice può essere semplificato
bool check(bool* bloom_filter, int n, char* charArr){
    bool ris = true;
    for(int i = 0; charArr[i] != '\0' && ris; i++){
        if(charArr[i] > n){
            if(bloom_filter[charArr[i] % n] == false){
                ris = false;
            }
        }else{
            if(bloom_filter[charArr[i]] == false){
                ris = false;
            }
        }
    }
    return ris;
}