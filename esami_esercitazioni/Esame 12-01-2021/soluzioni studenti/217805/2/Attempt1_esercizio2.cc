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

void get_elements(int * source, int source_dim, int * dest1, int dest1_max_dim, int &dest1_dim, int * dest2, int dest2_max_dim, int &dest2_dim);
void get_elements_aux(int * source, int source_dim, int * dest1, int dest1_max_dim, int &dest1_dim, int * dest2, int dest2_max_dim, int &dest2_dim, int index);

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

void get_elements(int * source, int source_dim, int * dest1, int dest1_max_dim, int &dest1_dim, int * dest2, int dest2_max_dim, int &dest2_dim) {
  dest1_dim = 0;
  dest2_dim = 0;
  get_elements_aux(source, source_dim, dest1, dest1_max_dim, dest1_dim, dest2, dest2_max_dim, dest2_dim, 0);
}

void get_elements_aux(int * source, int source_dim, int * dest1, int dest1_max_dim, int &dest1_dim, int * dest2, int dest2_max_dim, int &dest2_dim, int index) {
  if (index < source_dim && dest1_dim < dest1_max_dim && dest2_dim < dest2_max_dim) {
    if (index % 2 == 0 && source[index] % 3 == 0) {
      dest1[dest1_dim++] = source[index];
    } else {
      dest2[dest2_dim++] = source[index];
    }
    get_elements_aux(source, source_dim, dest1, dest1_max_dim, dest1_dim, dest2, dest2_max_dim, dest2_dim, index + 1);
  }
}
