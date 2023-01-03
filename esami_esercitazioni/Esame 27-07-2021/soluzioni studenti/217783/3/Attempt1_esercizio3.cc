#include <iostream>

using namespace std;

bool* create(int n);
void add(bool* &bloom_filter, int n, char* parola);
bool control(bool* &bloom_filter, int n, char *parola);
void destroy(bool* &bloom_filter);

//ho modificato il nome delle funzioni del main per attenersi alla consegna dell'esercizio
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
bool* create(int n) {

  bool *vec = new (nothrow) bool[n];

  if (vec == NULL) {
    cout << "Errore allocazione della memoria" << endl;
    exit(1);
  }

  for (int i=0; i<n; i++) {
    vec[i] = false;
  }

  return vec;
}

// SB: ok
void destroy(bool* &bloom_filter) {
  delete[] bloom_filter;
}


void add(bool* &bloom_filter, int n, char* parola) {

  int contatore = 0;
  int charToInt; 
  
   while (parola[contatore] !='\0') {
     
     charToInt = (int)parola[contatore];

     if (bloom_filter[charToInt] == false && n > charToInt) {
       bloom_filter[charToInt] = true;
     }
     else if (n < charToInt) {
       // SB: il "%100" era solo l'esempio del testo, non la consegna. L'istruzione corretta è "charToInt % n"
       int indice = charToInt % 100;

       if (bloom_filter[indice] == false) {
	       bloom_filter[indice] = true;
       }    
     }  
     contatore++;
  }

}

bool control(bool* &bloom_filter, int n, char *parola) {

  bool statement = true;
  int contatore = 0;
  int charToInt = 0;
  
  while (parola[contatore] != '\0' && statement) {

    charToInt = (int) parola[contatore];

    if (n > charToInt) {
      if (bloom_filter[charToInt] == true) {
	statement = true;
      }
      else
	statement = false;
    }
    else if (n < charToInt) {
      // SB: il "%100" era solo l'esempio del testo, non la consegna. L'istruzione corretta è "charToInt % n"
      int indice = charToInt % 100;

      if (bloom_filter[indice] == true) {
	statement = true;
      }
      else
	statement = false;
    } 
    contatore++;
  }
  
  return statement;
}
