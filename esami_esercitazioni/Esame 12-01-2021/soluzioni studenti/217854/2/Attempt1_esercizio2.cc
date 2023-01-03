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

void get_elements_aux(int s[], const int dim_s, int dest1[], const int dim_dest1, int calc_dest1, int dest2[], const int dim_dest2, int calc_dest2, int index) {
  // MR: calc_dest1 e calc_dest2 non sono passati per riferimento!
  if (index == dim_s)
    // MR: Se uno passa un index > dim_s allora entra in loop infinito!
    return;
  else {
    if(s[index] % 2 == 0 && s[index] % 3 == 0) {
      // MR: Qui era index % 2 non s[index] % 2
      dest1[calc_dest1] = s[index];
      get_elements_aux(s, dim_s, dest1, dim_dest1, calc_dest1+1, dest2, dim_dest2, calc_dest2, index+1);
      // MR: Non sta modificando calc_dest1 per poi usarlo fuori come
      // richiesto nel testo!
    } else {
      dest2[calc_dest2] = s[index];
      get_elements_aux(s, dim_s, dest1, dim_dest1, calc_dest1, dest2, dim_dest2, calc_dest2+1, index+1);
      // MR: Non sta modificando calc_dest2 per poi usarlo fuori come
      // richiesto nel testo!
    }
  }
}

void get_elements(int s[], const int dim_s, int dest1[], const int dim_dest1, int calc_dest1, int dest2[], const int dim_dest2, int calc_dest2) {
  get_elements_aux(s, dim_s, dest1, dim_dest1, calc_dest1, dest2, dim_dest2, calc_dest2, 0);
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
