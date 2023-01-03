#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(int source[], int dim_source, int dest1[], int max_dim_dest1, int & dim_dest1, int dest2[], int max_dim_dest2, int & dim_dest2);
void get_elements_ric(int source[], int dim_source, int dest1[], int max_dim_dest1, int & dim_dest1, int dest2[], int max_dim_dest2, int & dim_dest2, int i);

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

void get_elements(int source[], int dim_source, int dest1[], int max_dim_dest1, int & dim_dest1, int dest2[], int max_dim_dest2, int & dim_dest2) {
  get_elements_ric(source, dim_source, dest1, max_dim_dest1, dim_dest1, dest2, max_dim_dest2, dim_dest2, 0);
}

void get_elements_ric(int source[], int dim_source, int dest1[], int max_dim_dest1, int & dim_dest1, int dest2[], int max_dim_dest2, int & dim_dest2, int i) {

  if (i < dim_source) {
    if (i%3==0 && source[i]%2 == 0) {
      // MR: Manca controllo che dim_dest1 < max_dim_dest1
      dest1[dim_dest1] = source[i]*2;
      dim_dest1++;
    } else {
      // MR: Manca controllo che dim_dest2 < max_dim_dest2
      dest2[dim_dest2] = source[i]*3;
      dim_dest2++;
    }
    get_elements_ric(source, dim_source, dest1, max_dim_dest1, dim_dest1, dest2, max_dim_dest2, dim_dest2, i+1);

  }
}
