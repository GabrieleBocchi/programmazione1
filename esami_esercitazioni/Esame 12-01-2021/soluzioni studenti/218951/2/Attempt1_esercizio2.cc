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
void get_elements(int [], int, int[], int, int&, int [], int, int&);
void get_elementric(int [], int, int, int[], int&, int [], int&);

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

void get_elements(int s[], int s_s, int d1[], int md1_s, int& d1_s, int d2[], int md2_s, int& d2_s){
  int dim=0;
  get_elementric(s, s_s, dim, d1, d1_s, d2,d2_s);
}

void get_elementric(int s[],int s_s, int dim, int d1[], int& d1_s, int d2[], int& d2_s){
  if(dim<s_s){
    if(dim%3==0 and s[dim]%2==0){
      // MR: Il test e' && non abbiamo visto l'operatore and
      // Manca controllo che d1_s < dimensione massima di d1
      d1[d1_s]=(s[dim]*2);
      d1_s++;
    }else{
      // Manca controllo che d2_s < dimensione massima di d2
      d2[d2_s]=(s[dim]*3);
      d2_s++;
    }
    dim++;
    get_elementric(s, s_s, dim, d1, d1_s, d2,  d2_s);
  }
}
