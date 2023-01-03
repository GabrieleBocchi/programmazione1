#include <iostream>

using namespace std;

// SB: i nomi delle funzioni non corrispondono alla consegna
bool * init(int n);
void insert(bool * bloo_filter, int n, char * string);
bool check(bool * bloom_filter, int n, char * string);
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
  bool * array = new bool[n];
  for(int i = 0; i<n; i++){
    array[i] = false;
  }
  return array;
}

// SB: ok
void insert(bool * bloom_filter, int n, char * string){
  int i= 0;
  while(string[i] != '\0'){
    int indice = string[i] % n;
    bloom_filter[indice] = true;
    i++;
  }
}

// SB: manca "i++;" all'interno del ciclo while 
// e l'istruzione di ritorno dovrebbe essere "return res;"
bool check(bool * bloom_filter, int n, char * string){
  bool res = true;
  int i = 0;
  while(string[i] != '\0'){
    int indice = string[i] % n;
    if(bloom_filter[indice] == false){
      res = false;
    }
  }
  return false;
}

// SB: ok
void deinit(bool * bloom_filter){
  delete[] bloom_filter;
}
