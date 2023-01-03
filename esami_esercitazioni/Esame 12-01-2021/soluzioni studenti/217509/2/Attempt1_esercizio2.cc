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

void get_elements(int s[], int s_s, int d1[], int md1_s,
  int& d1_s, int d2[], int md2_s, int& d2_s, int current = 0){

  if(current < s_s){
    if((current % 2) == 0 || (current % 3) == 0){
      //MR: era da considerare s[current] % 3 == 0, inoltre nel testo
      //la condizione era un "AND" e non un "OR". "Elementi che si
      //trovano in posizione pari E che sono multipli di 3" inteso gli
      //elementi non la posizione.
      if(d1_s < md1_s){
        d1[d1_s] = s[current];
        d1_s += 1;
      }
      get_elements(s, s_s, d1, md1_s,
        d1_s, d2, md2_s, d2_s, current+1);
    }
    else{
      if(d2_s < md2_s){
        d2[d2_s] = s[current];
        d2_s += 1;
      }
      get_elements(s, s_s, d1, md1_s,
        d1_s, d2, md2_s, d2_s, current+1);
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
