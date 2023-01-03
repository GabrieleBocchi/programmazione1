#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(int * source, const int &dimSource, int * dest1, const int &dimMaxDest1, int &dimCalcDest1, int * dest2, const int &dimMaxDest2, int &dimCalcDest2);

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

void do_get_elements(int pos, int * source, const int &dimSource, int * dest1, const int &dimMaxDest1, int &dimCalcDest1, int * dest2, const int &dimMaxDest2, int &dimCalcDest2){
  if(pos < dimSource)
  {
    if(!(pos % 3) && !(*source % 2))
    {
      if(dimCalcDest1<dimMaxDest1)
        dest1[dimCalcDest1++] = (*source) * 2;
    }
    else
    {
      if(dimCalcDest2<dimMaxDest2)
        dest2[dimCalcDest2++] = (*source) * 3;
    }
  }

  if(pos+1 < dimSource)
    // MR: Poteva mettere la chiamata ricorsiva come ultima istruzione
    // del blocco che codifica l'if(pos < dimSource) e sarebbe stato
    // piu' pulito.
    do_get_elements(++pos, &source[1], dimSource, dest1, dimMaxDest1, dimCalcDest1, dest2, dimMaxDest2, dimCalcDest2);
}

void get_elements(int * source, const int &dimSource, int * dest1, const int &dimMaxDest1, int &dimCalcDest1, int * dest2, const int &dimMaxDest2, int &dimCalcDest2){
    do_get_elements(0, source, dimSource, dest1, dimMaxDest1, dimCalcDest1, dest2, dimMaxDest2, dimCalcDest2);
}
