// GDT: inizializzare sempre le variabili. La variabile lunghezza_parola non è garantito
// che venga settata a zero come prima cosa (infatti il tuo codice va in segmentation fault
// ogni tanto).  
// Inoltre, il codice non rispetta la consegna dell'esercizio. Infatti, viene richiesto di copiare
// tutte quelle parole con lunghezza maggiore e/o uguale a quattro. Nel tuo codice, vengono solo
// copiate le parole con lunghezza uguale a quattro.

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv [])
{
  if(argc != 3) {
    cout << "Errore sintassi <input> <output> " << endl;
    exit(0);
  }
  
  fstream input, output;

  input.open(argv[1], ios::in);

  if(input.fail()) {
    cout << "Errore stream input" << endl;
    exit(0);
  }

  char ** matrice = new char*[10000];

  for(int i = 0; i < 10000; i++) {
    matrice[i] = new char[101];
  }

  output.open(argv[2], ios::out);

  if(output.fail()) {
    cout << "Errore stream output" << endl;
  }
  

  int i = 0;
  
  while(input >> matrice[i]) {
    i++;
  }

  for(int j = i - 1; j >= 0; j--) {
    int lunghezza_parola;
    while(lunghezza_parola < 4 && matrice[j][lunghezza_parola] != '\0') {
      lunghezza_parola++;
    }
    if(lunghezza_parola == 4) {
      output << matrice[j] << " ";
    }
  }

  input.close();
  output.close();
  
   for(int j = 0; j < 10000; j++) {
     delete [] matrice[j];
   }
   delete matrice;
 
  return 0;
}
