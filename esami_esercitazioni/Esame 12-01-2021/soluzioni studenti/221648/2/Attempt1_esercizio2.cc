#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(int source[], int sdim, int dest1[], int d1dim, int &dim1calc, int dest2[], int d2dim, int &dim2calc, int i = 0);

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

void get_elements(int source[], int sdim, int dest1[], int d1dim, int &dim1calc, int dest2[], int d2dim, int &dim2calc, int i){

  //controllo la condizione di terminazione
  if(i >= sdim){
    return;
  }else{

    if(i % 2 == 0 && source[i] % 3 == 0){
      //memorizzo in dest1
      // MR: Manca controllo che dim1calc < d1dim
      dest1[dim1calc] = source[i];
      dim1calc++;
    }else{
      //memorizzo in dest2
      // MR: Manca controllo che dim2calc < d2dim
      dest2[dim2calc] = source[i];
      dim2calc++;
    }

    //passo alla cella successiva
    i++;

    get_elements(source, sdim, dest1, d1dim, dim1calc, dest2, d2dim, dim2calc, i);
    return;
  }
}
