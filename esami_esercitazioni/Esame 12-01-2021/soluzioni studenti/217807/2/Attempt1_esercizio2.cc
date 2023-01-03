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

void get_elements(int source[], const int DIMs, int dest1[], const int DIM1, int& id1, int dest2[], const int DIM2, int& id2, int is=0) {
  if (is < DIMs) {
    int n = source[is];
    cout << n << endl;
    // MR: Stampa non richiesta
    if (is%2 == 0 && id1<DIM1 && source[is]%3 == 0) {
      dest1[id1] = n;
      id1++;
    }
    else if (id2<DIM2) {
      dest2[id2] = n;
      id2++;
    }

    get_elements(source, DIMs, dest1, DIM1, id1, dest2, DIM2, id2, is+1);
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

  get_elements(s, ms, d1, md1_s, d1_s, d2, md2_s, d2_s);

  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}
