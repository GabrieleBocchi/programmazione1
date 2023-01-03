#include <iostream>
#include <cstddef>

using namespace std;


void get_elements(int s[], int dim_s, int d1[], int maxdim_d1, int &dim_d1, int d2[], int maxdim_d2, int &dim_d2){
    int temp = dim_d1 + dim_d2;
    if(s[temp] != -1 && dim_d1 + dim_d2 < dim_s){
      // MR: Non chiaro il primo test (s[temp] != -1, che dalle
      // specifiche e' sempre vero. Inoltre, si potrebbe verificare il
      // caso che temp e' = dim_s e in questo caso si avrebbe accesso
      // a s[dims] che e' chiaramante fuori dei bound dell'array. Non
      // possiamo assumere che prima venga eseguito il test di < e poi il !=
        if(temp % 2 == 0 && s[temp] % 3 == 0 && dim_d1 < maxdim_d1){
            d1[dim_d1] = s[temp];
            dim_d1++;
        }
        else if(dim_d2 < maxdim_d2){
            d2[dim_d2] = s[temp];
            dim_d2++;
        }
        get_elements(s,dim_s,d1,maxdim_d1,dim_d1,d2,maxdim_d2,dim_d2);
    }
    return;
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
