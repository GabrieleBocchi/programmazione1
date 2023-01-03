#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(const int source [], int dim_s, int dest1[], int max_dim_d1, int &dim_d1, int dest2[], int max_dim_d2, int &dim_d2, int ind = 0);

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

void get_elements(const int source [], int dim_s, int dest1[], int max_dim_d1, int &dim_d1, int dest2[], int max_dim_d2, int &dim_d2, int ind) {

   if (ind < dim_s) {
      if ((ind%2 == 0) && (source[ind]%3 == 0)) {
	// MR: Manca controllo che dim_d1 < max_dim_d1
	dest1[dim_d1] = source[ind];
         dim_d1++;
      }
      else {
	// MR: Manca controllo che dim_d2 < max_dim_d2
         dest2[dim_d2] = source[ind];
         dim_d2++;
      }
      get_elements (source, dim_s, dest1, max_dim_d1, dim_d1, dest2, max_dim_d2, dim_d2, ind+1);
   }
}
