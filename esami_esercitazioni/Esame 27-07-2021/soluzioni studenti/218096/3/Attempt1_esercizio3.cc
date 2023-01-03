#include <iostream>

using namespace std;

bool* init(int n);
void insert(bool* filter, int n, char* s);
bool check(bool* filter, int n, char* s);
void deinit(bool* filter);


void setToFalse(bool* v, int n){
    for(int i=0;i<n;i++){
        v[i]=false;
    }
}

bool isVoid(bool* v, int n){
    for(int i=0;i<n;i++){
        if(v[i])
            return false;
    }
    return true;
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

// SB: ok
bool* init(int n){
    bool* filter;
    filter = new (nothrow)bool[n];
    if(filter!=NULL){
        setToFalse(filter,n);
    }
    return filter;
}

// SB: ok, anche se il codice potrebbe essere reso più leggibile usando l'operatore [] 
void insert(bool* filter, int n, char* s){
    for(;*s!='\0';s++){
        int i = *s%n;
        filter[i] = true;
    }
}

// SB: il codice non funziona quando il bloom filter contiene più di un elemento
// (provare ad inserire due parole nel bloom filter, ogni invocazione di "check"
// ritornerà "false").
bool check(bool* filter, int n, char* s){
    if(*s == '\0')
        return isVoid(filter,n);

    int i = *s%n;
    bool tmp;

    if(!filter[i])
        return false;

    filter[i] = false;
    tmp = check(filter,n,s+1);
    filter[i] = true;
    return tmp;
}

// SB: ok
void deinit(bool* filter){
    delete[] filter;
}