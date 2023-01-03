#include <iostream>

using namespace std;

// SB: codice non indentato
bool* create(int n){

// SB: "new bool" crea un singolo valore booleano, non un array (vedi soluzione)
bool* root=new bool;
root[0]=false;
int i=1;
// SB: un array di valori va creato con una singola istruzione, non bisogna creare ogni singola cella
while(i<n){
    bool *a=new bool;
    *a=false;
    a=root-i;

    i++;
}
root[n]=NULL;

return root;
}

// SB: codice non indentato
void add(bool bf[],int n,char arr[]){


// SB: "i<n" è una condizione errata, non sono state fatte 
// assunzioni sulla lunghezza della stringa da inserire
for(int i=0;i<n&&arr[i]!='\0';i++){
        int tem;
    if(arr[i]>n){
        tem=int(arr[i])%n;
    }
else{tem=int(arr[i]);}
    bf[tem]=true;

}

return;
}

// SB: codice non indentato
bool control(bool bf[],int n,char arr[]){

bool con=true;

// SB: "i<n" è una condizione errata, non sono state fatte 
// assunzioni sulla lunghezza della stringa da controllare
for(int i=0;i<n&&con&&arr[i]!='\0';i++){
     int tem;
    if(arr[i]>n){
        tem=int(arr[i])%n;
    }
else{tem=int(arr[i]);}



    con=bf[tem];

}

return con;
}

// SB: codice non indentato
// SB: un array di valori va deallocato con una singola istruzione, non bisogna deallocare ogni singola cella 
void destroy(bool root[]){

bool* rem;
while(root!=NULL){

rem=root;
root=root+1;

    delete rem;

}

}


int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale n=255
    int n = 255;

    bool* bloom_filter = create(n);

    char ciao[] = { 'c', 'i', 'a', 'o', '\0' };
    add(bloom_filter, n, ciao);
    cout << "Ho inserito la parola 'ciao' nel bloom filter" << endl;

    if (control(bloom_filter, n, ciao)) {
        cout << "La parola 'ciao' � presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'ciao' NON � presente nel bloom filter " << endl;
    }

    char volo[] = { 'v', 'o', 'l', 'o', '\0' };
    if (control(bloom_filter, n, volo)) {
        cout << "La parola 'volo' � presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'volo' NON � presente nel bloom filter " << endl;
    }
    // SB: Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    char coio[] = { 'c', 'o', 'i', 'o', '\0' };
    if (control(bloom_filter, n, coio)) {
        cout << "La parola 'coio' � presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'coio' NON � presente nel bloom filter " << endl;
    }


    destroy(bloom_filter);

    return 0;
}
