#include <iostream>
#include <cstddef>

using namespace std;

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

void prendiElementi(char source[], int dimSource, char * dest1, int dim1, int & dimCalc1, char * dest2, int dim2, int & dimCalc2, int indice) {
  // MR: Mancanon controlli che indice sia minore di dimSource, e che
  // dimCalc1 e dimCalc2 siano minori della rispettiva dimensione
  // massima
  char cc = source[indice]; //carattere corrente
  if (cc >= 'A' && cc <= 'Z') {
    dest1[dimCalc1] = cc; // MR: Manca conversione in minuscolo
    dimCalc1++;
  } else if (cc >= 'a' && cc <= 'z') {
    dest2[dimCalc2] = cc; // MR: Manca conversione in maiuscolo
    dimCalc2++;
  } else if (cc == '\0') {
    // MR: Non era specificato che l'array fosse una stringa. Si
    // diceva di ignorare altri caratteri, ma procedendo, quindi se
    // per caso ci fosse stato tale carattere occorreva ignorarlo e
    // procedere con i successivi.
    return;
  }

  indice++;
  prendiElementi(source, dimSource, dest1, dim1, dimCalc1, dest2, dim2, dimCalc2, indice);
}

void get_elements(char source[], int dimSource, char * dest1, int dim1, int & dimCalc1, char * dest2, int dim2, int & dimCalc2) {
  prendiElementi(source, dimSource, dest1, dim1, dimCalc1, dest2, dim2, dimCalc2, 0);
}

int main() {
  const int maxdim = 10;

  const int md1_s = maxdim;
  char d1[md1_s];
  int d1_s = 0;

  const int md2_s = maxdim;
  char d2[md2_s];
  int d2_s = 0;

  const int ms = maxdim;
  char s[ms];
  int s_s = 0;

  read_elements(s, ms, s_s);

  get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);

  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}
