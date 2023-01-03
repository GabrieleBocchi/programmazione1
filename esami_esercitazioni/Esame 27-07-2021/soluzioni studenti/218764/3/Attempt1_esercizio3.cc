#include <iostream>

using namespace std;

// SB: i nomi delle funzioni non corrispondono alla consegna
// SB: ok
bool* init(int n){
    bool* bloom_filter=new bool[n];
    for(int i=0;i<n;i++){
        bloom_filter[i]=false;
    }
    return bloom_filter;
}

// SB: ok
void insert(bool* bloom_filter,int n,char* parola){
    int i=0;
    int posizione=0;
    while(parola[i]!='\0'){
        posizione=parola[i]%n;
        bloom_filter[posizione]=true;
        i++;
    }
}

// SB: ok
bool check(bool* bloom_filter,int n, char* parola){
    int i=0;
    int posizione;
    bool res=true;
    while(parola[i]!='\0' && res){
        posizione=parola[i]%n;
        if(bloom_filter[posizione]!=true){
            res=false;
        }
        i++;
    }
    return res;
    
}

// SB: ok
void deinit(bool* bloom_filter){
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

