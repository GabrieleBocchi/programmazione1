#include <iostream>
#include <cstddef>

using namespace std;

void extract_m3_and_mult2(int source[], int src_maxlen, int dest1[], int &len_d1, int src_i = 0)
{
  if (src_i < src_maxlen) {
    if (src_i%3 == 0 && source[src_i]%2 == 0) {
      // MR: Manca controllo che len_d1 < dimensione massima di dest1
      dest1[len_d1] = source[src_i]*2;
      len_d1++;
    }
    src_i++;

    extract_m3_and_mult2(source, src_maxlen, dest1, len_d1, src_i);
  }
}

void extract_rest_and_mult3(int source[], int src_maxlen, int dest2[], int &len_d2, int src_i = 0)
{
  if (src_i < src_maxlen) {
    if (!(src_i%3 == 0 && source[src_i]%2 == 0)) {
      // MR: Manca controllo che len_d2 < dimensione massima di dest2
      dest2[len_d2] = source[src_i]*3;
      len_d2++;
    }
    src_i++;

    extract_rest_and_mult3(source, src_maxlen, dest2, len_d2, src_i);
  }
}

void get_elements(int source[], int src_maxlen, int dest1[], int maxlen_d1, int &len_d1, int dest2[], int maxlen_d2, int &len_d2)
{
  // MR: Parzialmente corretto. Si poteva piu' semplicemente
  // considerare una unica funzione ricorsiva.
  len_d1 = 0;
  len_d2 = 0;
  extract_m3_and_mult2(source, src_maxlen, dest1, len_d1, 0);
  extract_rest_and_mult3(source, src_maxlen, dest2, len_d2, 0);
}


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
