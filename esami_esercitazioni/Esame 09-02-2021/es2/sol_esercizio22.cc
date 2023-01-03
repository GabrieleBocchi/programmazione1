#include <iostream>
#include <cstddef>

using namespace std;

// Inserire qui la dichiarazione di get_elements
void get_elements(const char source[],
		  const int size_s,
		  char * & dest1, int & d1,
		  char * & dest2, int & d2);

void print(const char a[], const int s, const char * prefix) {
  cout << prefix;
  for (int i = 0; i < s; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void read_elements(char s[], const int ms, int & s_s) {
  char r = '\0';
  for (s_s = 0; ((s_s < ms) && (r != '\n')); ) {
    r = cin.get();
    if ((r != '\n') && (r != ' ')) s[s_s++] = r;
  }
}

int main() {
  const int maxdim = 10;

  char * d1;
  int d1_s = 0;

  char * d2;
  int d2_s = 0;

  const int ms = maxdim;
  char s[ms];
  int s_s = 0;

  read_elements(s, ms, s_s);
  print(s, s_s, "Source = ");

  get_elements(s, s_s, d1, d1_s, d2, d2_s);

  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

  delete [] d1;
  delete [] d2;
}

// Inserire qui la definizione di get_elements e di eventuali altre
// funzioni ausiliarie
void get_elements_aux(const char source[],
		      const int size_s, int i,
		      char * & dest1, int & d1,
		      char * & dest2, int & d2);

void get_elements(const char source[],
		  const int size_s,
		  char * & dest1, int & d1,
		  char * & dest2, int & d2) {
  d1 = 0; d2 = 0;
  get_elements_aux(source, size_s, 0, dest1, d1, dest2, d2);
}

void get_elements_aux(const char source[],
		      const int size_s, int i,
		      char * & dest1, int & d1,
		      char * & dest2, int & d2) {
  if (i >= size_s) { // caso base
    // Quando i >= size_s, allora ho finito di analizzare s, e conosco
    // le dimensioni d1 e d2 che devono avere rispettivamente gli
    // array dest1 e dest2 da allocare dinamicamente, e quindi li
    // posso quindi allocare.
    dest1 = new char [d1];
    dest2 = new char [d2];
  } else {
    if ((source[i] >= 'A') && (source[i] <= 'Z') ) {
      int p = d1++; // Salvo la posizione dove inserire il carattere
		    // ed incremento d1. Chiamo poi ricorsivamente la
		    // funzione con il nuovo valore di d1, per
		    // indicare che mi servono almeno d1 posizioni per
		    // dest1. NB: Non posso chiamare ricorsivamente
		    // con ++d1 perche' passaggio per riferimento.
      get_elements_aux(source, size_s, i+1, // Uso i+1 invece che ++i
					    // per non fare side
					    // effect su i, ed evitare
					    // che dopo devo usare
					    // source[i-1]
		       dest1, d1, dest2, d2);
      // A questo punto dest1 e' allocato e ci posso scrivere nella
      // posizione salvata. NB: Non posso usare d1 perche' dopo
      // chiamata ricorsiva ha un valore che corrisponde alla
      // dimensione dell'array allocato dinamicamente dest1.
      dest1[p] = 'a' - (source[i] - 'Z');
    } else if ((source[i] >= 'a') && (source[i] <= 'z')) {
      int p = d2++; // Salvo la posizione dove inserire il carattere
		    // ed incremento d2. Chiamo poi ricorsivamente la
		    // funzione con il nuovo valore di d2, per
		    // indicare che mi servono almeno d2 posizioni per
		    // dest1. NB: Non posso chiamare ricorsivamente
		    // con ++d2 perche' passaggio per riferimento.
      get_elements_aux(source, size_s, i+1, // Uso i+1 invece che ++i
					    // per non fare side
					    // effect su i, ed evitare
					    // che dopo devo usare
					    // source[i-1]
		       dest1, d1, dest2, d2);
      // A questo punto dest2 e' allocato e ci posso scrivere nella
      // posizione salvata. NB: Non posso usare d2 perche' dopo
      // chiamata ricorsiva ha un valore che corrisponde alla
      // dimensione dell'array allocato dinamicamente dest2.
      dest2[p] = 'A' - (source[i] - 'z');
    }
    else {
      // Se nessuna delle condizioni sopra e' verificata, occorre fare
      // ricorsione incrementando i, in modo da ignorare il carattere.
      get_elements_aux(source, size_s, ++i,
		       dest1, d1, dest2, d2);
    }
  }
}
