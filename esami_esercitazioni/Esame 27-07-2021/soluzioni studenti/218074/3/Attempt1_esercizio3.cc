#include <iostream>

using namespace std;

bool* init(int n);
void insert(bool* bloom, int n, char c[]);
bool check(bool* bloom, int n, char c[]);
void deinit(bool* bloom);


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
bool* init(int n){
    bool* array=new bool[n];
    for(int i=0; i<n; i++){
        array[i]=false;
    }
    return array;
}

// SB: ok
void insert(bool* bloom, int n, char c[]){
    for(int i=0; c[i]!='\0'; c++){
        if(c[i]>n){
            int vero=c[i]%n;
            bloom[vero]=true;
        }
        else{
            bloom[c[i]]=true;
        }
    }
}

// SB: ok
bool check(bool* bloom, int n, char c[]){
    bool x=true;
    for(int i=0; c[i]!='\0'; i++){
        
        if(c[i]>n){
            if(bloom[c[i]%n]!=true){
                x=false;
            }
        }
        else{
            if(bloom[c[i]]!=true){
                x=false;
            }
        }
    }
    return x;
}

// SB: ok
void deinit(bool* bloom){
    delete [] bloom;
}