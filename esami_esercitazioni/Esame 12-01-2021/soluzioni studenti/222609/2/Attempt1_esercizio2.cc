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

bool is_condition_satisfied(int index, int element) {
  return ((index % 2 == 0 || index == 0) && element % 3 == 0);
}

int check_elements1(int source[], int dim_source, int dest1[], int x, int dest1_pointer, int dest1_maxdim) {
  if(x < dim_source) {
    if(is_condition_satisfied(x, source[x]) && dest1_pointer < dest1_maxdim) {
      dest1[dest1_pointer] = source[x];
      dest1_pointer++;
    }
    x++;
    check_elements1(source, dim_source, dest1, x, dest1_pointer, dest1_maxdim);
    // MR: Che cosa ritorna in questo caso? Manca return!
  } else {
    return dest1_pointer;
  }
}

int check_elements2(int source[], int dim_source, int dest2[], int x, int dest2_pointer, int dest2_maxdim) {
  if(x < dim_source) {
    if(!is_condition_satisfied(x, source[x]) && dest2_pointer < dest2_maxdim) {
      dest2[dest2_pointer] = source[x];
      dest2_pointer++;
    }
    x++;
    check_elements2(source, dim_source, dest2, x, dest2_pointer, dest2_maxdim);
    // MR: Che cosa ritorna in questo caso? Manca return!
  } else {
    return dest2_pointer;
  }
}

void get_elements(int source[], int dim_source, int dest1[], int dest1_maxdim, int& dest1_dim, int dest2[], int dest2_maxdim, int& dest2_dim) {
  // MR: la doppia ricorsione sembra inutile, e poteva essere fatto
  // tutto in una unica funzione. Inoltre, le dimensioni potevano
  // anche essere calcolate nella ricorsione senza usare valori di
  // ritorno, soprattutto perche' si e' dimenticato dei return!
  // Provi con g++ -Wall

  int dest1_pointer = check_elements1(source, dim_source, dest1, 0, 0, dest1_maxdim);
  int dest2_pointer = check_elements2(source, dim_source, dest2, 0, 0, dest2_maxdim);

  dest1_dim = dest1_pointer;
  dest2_dim = dest2_pointer;
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
