#include <iostream>

using namespace std;

bool * init (int n);
void destroy(bool * bloom_filter);
void add(bool * bloom_filter, int n, char ciao[]);
int mycast(char a);
bool check( bool * bloom_filter, int n, char parola[]);

int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool* bloom_filter = init(n);

    char ciao[] = { 'c', 'i', 'a', 'o', '\0' };     
    add(bloom_filter, n, ciao);
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

    destroy(bloom_filter);

    return 0;
}

// SB: ok
bool * init (int n){
    bool * tmp = new bool[n];
    // SB: meglio evitare di porre istruzione condizionale e corpo nella stessa riga
    for(int i=0;i<n;i++)tmp[i]=false;
    return tmp;
}

// SB: ok
void destroy(bool * bloom_filter){
    delete [] bloom_filter;
}

// SB: ok
void add(bool * bloom_filter, int n, char ciao[]){
    for(int i=0;ciao[i]!='\0';i++){
        int index=mycast(ciao[i]);
        cout<<index<<"  ";
        // SB: meglio evitare di porre istruzione condizionale e corpo nella stessa riga
        if(bloom_filter[index%n]==false)bloom_filter[index%n]=true;
    }
}

// SB: poteva bastare un "(int) a"
int mycast(char a){
   return 0 + a;
}

// SB: ok
bool check( bool * bloom_filter, int n, char parola[]){
    bool flag=true;
    for(int i=0;parola[i]!='\0' and flag;i++){
        int index=mycast(parola[i]);
        // SB: meglio evitare di porre istruzione condizionale e corpo nella stessa riga
        if(bloom_filter[index%n]==false)flag=false;
    }
    return flag;
}
