#include <iostream>

using namespace std;

// START AUX
int strlen(const char str[]){
    int i = 0;
    while(str[i] != '\0')i++;
    return i;
}

int mod(int x, int y){
    if(x<y)return x;
    return mod(x-y, y);
}
// END AUX

// SB: ok
bool * init(int n){
    bool * bloom =  new bool[n];
    for (int i=0; i<n;i++)
        bloom[i] = false;
    return bloom;
}

// SB: ok
void deinit(const bool* bloom){
    delete[] bloom;
}

// SB: ok
void insert(bool* bloom, int dim, char word[]){
    for (int i =0; i<strlen(word); i++)
        bloom[ mod( ((int)word[i]), dim) ] = true;
}

// SB: ok
bool check(const bool* bloom, int dim, char word[]){
    bool res = true;
    for (int i =0; i<strlen(word); i++){
        res = res && bloom[ mod (((int)word[i]),dim) ];
    }
    return res;
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