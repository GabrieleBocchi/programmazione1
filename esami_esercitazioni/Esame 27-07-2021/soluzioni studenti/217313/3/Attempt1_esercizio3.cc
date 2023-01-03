#include <iostream>

using namespace std;

bool *create(int n);
void insert(bool *&bloom_filter, int n, char array[]);
bool control(bool *bloom_filter, int n, char array[]);
void deinit(bool * bloom_filter);

int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool* bloom_filter = create(n);

    char ciao[] = { 'c', 'i', 'a', 'o', '\0' };     
    insert(bloom_filter, n, ciao);
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

    deinit(bloom_filter);

    return 0;
}

// SB: ok
bool *create(int n){
  bool *array=new bool[n];
  for(int i=0; i<n; i++){
    array[i]=false;
  }
  return array;
}

// SB: ok
void insert(bool *&bloom_filter, int dim, char a[]){
  for(int i=0; a[i]!='\0'; i++){
    int n=int(a[i]);
    if(n>dim){
      if(bloom_filter[n%dim]!=true){
        bloom_filter[n%dim]=true;
      }
    }
    else{
      if(bloom_filter[n]!=true){
        bloom_filter[n]=true;
      }
    }
  }
}

// SB: ok
bool control(bool *bloom_filter, int dim, char a[]){
  bool ris=true;
  for(int i=0; a[i]!='\0' && ris==true; i++){
    int n=int(a[i]);
    if(n>dim){
      n=n%dim;
    }
    if(bloom_filter[n]==false){
      ris=false;
    }
  }
  return ris;
}

// SB: ok
void deinit(bool * bloom_filter){
  delete[] bloom_filter;
}
