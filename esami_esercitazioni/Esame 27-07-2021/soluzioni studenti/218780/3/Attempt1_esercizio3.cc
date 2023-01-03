#include <iostream>

using namespace std;

// SB: i nomi delle funzioni non corrispondono alla consegna
bool* init(int n);
void insert(bool * bloom_filter, int n, char ciao[]);
bool check(bool * bloom_filter,int n, char ciao[]);
void deinit(bool * bloom_filter);

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
    bool * filter = new bool[n];
    for(int i=0;i<n;i++){
        filter[i]=0;
        cout<<0;
    }
    return filter;
}
void insert(bool * bloom_filter,int n,char ciao[]){
    int index;
    // SB: il carattere terminatore è "\0"
    for(int i=0;ciao[i]!='\n';i++){
        cout << (int)ciao[i];
        if(ciao[i]>n){
            // SB: dovrebbe essere "index = ((int) ciao[i]) % n"
            index=(int)255%ciao[i];
        }else{
            index=(int)ciao[i];
        }
        bloom_filter[index]=1;
    }
}
bool check(bool * bloom_filter,int n,char ciao[]){
    int index;
    bool val=true;
    int i=0;
    // SB: il carattere terminatore è "\0"
    while(ciao[i]!='\n'){
        if(ciao[i]>n){
            // SB: dovrebbe essere "index = ((int) ciao[i]) % n"
            index=n%ciao[i];
        }else{
            index=ciao[i];
        }
        if(bloom_filter[index]==0){
            val=false;
        }
        i++;
    }
    return val;
}

// SB: la deallocazione di un array avviene tramite l'istruzione "delete [] bloom_filter"
void deinit(bool * bloom_filter){
    for(int i=0;i<255;i++){
        delete (&bloom_filter[i]);
    }
}