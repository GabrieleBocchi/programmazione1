#include <iostream>

using namespace std;


bool * create(int n);
bool control(bool * filter, int n, char * w);
void add(bool * filter,int n,char * w);
void destroy(bool * filter);
int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool* bloom_filter = create(n);

    char ciao[] = { 'c', 'i', 'a', 'o', '\0' };     
    add(bloom_filter, n, ciao);
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

    destroy(bloom_filter);

    return 0;
}

// SB: ok
bool * create(int n){
    bool * filter = new bool[n];
    for(int i=0; i<n; i++){
        filter[i] = false;
    }
    return filter;
}

// SB: ok
void destroy(bool * filter){
    delete[] filter;
}

// SB: ok
void add(bool * filter, int n, char * w){
    for(int i=0; w[i]!='\0'; i++){
        int index = int(w[i]);
        
        if(index >= n)
            index = index%n;

        if(filter[index] == false)
            filter[index] = true;
    }
}

// SB: ok
bool control(bool * filter, int n, char * w){
    bool res = true;
    for(int i=0; w[i]!='\0' && res; i++){
        int index = int(w[i]);
        if(index  >= n)
            index = index%n;
        if(filter[index] == false)
            res = false;    
    }
    return res;
}