#include <iostream>
#include <cstddef>

using namespace std;

void print(const int a[], const int s, const char * prefix) {
  cout << prefix;
  for (int i = 0; i < s; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void read_elements(int s[], const int ms, int & s_s) {
  int r = 0;
  for (s_s = 0; ((s_s < ms) && (r != -1)); ) {
    cin >> r;
    if (r != -1) s[s_s++] = r;
  }
}

void get_elements(int source[], int s_s, int d1[], int max_d1s, int & d1_s, int d2[], int max_d2s, int & d2_s, int i=0, int j=0, int k=0);

int main() {
  const int maxdim = 10;

  const int md1_s = maxdim;
  int d1[md1_s];
  int d1_s = 0;

  const int md2_s = maxdim;
  int d2[md2_s];
  int d2_s = 0;

  const int ms = maxdim;
  int s[ms];
  int s_s = 0;

  read_elements(s, ms, s_s);

  get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);

  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}


void get_elements(int source[], int s_s, int d1[], int max_d1s, int & d1_s, int d2[], int max_d2s, int & d2_s, int i, int j, int k) {
  // MR: Avrebbe potuto usare direttametne d1_s e d2_s senza usare i e
  // j, e solo k.

  //get_elements sfrutta 3 contatori: i per l'array source, j per l'array d1 e k per l'array d2.
  //i valori di j e k vengono ad ogni chiamata della funzione salvati nei valori passati per
  //riferimento d1_s e d2_s (incrementati di 1 per permettere la stampa dell'ultimo valore).
  if (i<s_s) {
    if ((i%2==0 && source[i]%3==0) || (i==0 && source[i]%3==0)) {
      // MR: Manca controllo che j < max_d1s
      d1[j] = source[i];
      d1_s = j+1;
      get_elements(source, s_s, d1, max_d1s, d1_s, d2, max_d2s, d2_s, i+1, j+1, k);
    }
    else {
      // MR: Manca controllo che k < max_d1s
      d2[k] = source[i];
      d2_s = k+1;
      get_elements(source, s_s, d1, max_d1s, d1_s, d2, max_d2s, d2_s, i+1, j, k+1);
    }
  }
}
