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

void get_elements(int source[], int dim_source, int dest1[], int dim_dest1, int &dim_calcolo1, int dest2[], int dim_dest2, int &dim_calcolo2);
void get_elements_rico(int source[], int dim_source, int index_source, int dest1[], int dim_dest1, int &dim_calcolo1, int dest2[], int dim_dest2, int &dim_calcolo2);

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

void get_elements(int source[], int dim_source, int dest1[], int dim_dest1, int &dim_calcolo1, int dest2[], int dim_dest2, int &dim_calcolo2) {
  int index_source = 0;
  get_elements_rico(source, dim_source, index_source, dest1, dim_dest1, dim_calcolo1, dest2, dim_dest2, dim_calcolo2);
}

void get_elements_rico(int source[], int dim_source, int index_source, int dest1[], int dim_dest1, int &dim_calcolo1, int dest2[], int dim_dest2, int &dim_calcolo2) {
  // MR: Il controllo deve essere index_source < dim_source onde
  // evitare ricorsioni infinite se per caso uno chiama funzione con
  // index_source > dim_source
  if (index_source != dim_source) {
    if ((index_source % 2) == 0 && (source[index_source] % 3) == 0 ) {
      // MR: Manca controllo che dim_calcolo1 < dim_dest1
      dest1[dim_calcolo1] = source[index_source];
      dim_calcolo1 ++;
    } else {
      // MR: Manca controllo che dim_calcolo2 < dim_dest2
      dest2[dim_calcolo2] = source[index_source];
      dim_calcolo2 ++;
    }
    get_elements_rico(source, dim_source, index_source + 1, dest1, dim_dest1, dim_calcolo1, dest2, dim_dest2, dim_calcolo2);
  }
}
