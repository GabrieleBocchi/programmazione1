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

void get_elementsRic (int s[], int & indice, int dimMax, int d1[], int & indice1, int d2[], int& indice2 ){
  if (indice< dimMax){
    cout << s[indice] << endl;
    // MR: Stampa non richiesta
    if (indice != 0 && indice%3 ==0 && s[indice]%2 ==0 ){
      // MR: Manca controllo che indice1 < dimensione massima di d1
      d1[indice1] = (s[indice]*2);
      indice1++;
      indice++;
    }
    else {
      // MR: Manca controllo che indice2 < dimensione massima di d2
      d2[indice2] = (s[indice]*3);
      indice2++;
      indice++;
    }
    get_elementsRic(s, indice, dimMax, d1, indice1, d2, indice2);
  }
}

void get_elements (int s[], int dimMax, int d1[], const int md1_s, int & indice1, int d2[], const int md2_s, int &indice2){
  int indice =0;
  get_elementsRic(s, indice, dimMax, d1, indice1, d2, indice2);
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

  get_elements(s, ms, d1, md1_s, d1_s, d2, md2_s, d2_s); //array, indice, array1, dim:max, array2, dim_max
  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}
