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

void get_elements(int array[], int dim_array, int d1[], int  md1_s, int& d1_s, int d2[], int md2_s, int& d2_s) {
  // MR: Era espressamente richiesto che la funzione fosse ricorsiva.
  // "Scrivere nel file esercizio2.cc la dichiarazione e la
  // definizione della funzzione ricorsiva get_elements ...". Mi
  // spiace, ma anche se output corretto non posso considerarla
  // giusta!
  for(int i = 0; i < dim_array; i++) {
    if(i % 2 == 0 && array[i] % 3 == 0 && d1_s < md1_s && array[i] != -1) {
      d1[d1_s] = array[i];
      d1_s++;
    }
    else if(d2_s < md2_s && array[i] != -1){
      d2[d2_s] = array[i];
      d2_s++;
    }
  }
}

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
