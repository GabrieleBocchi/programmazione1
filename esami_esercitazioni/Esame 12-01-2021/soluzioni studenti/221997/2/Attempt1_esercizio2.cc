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

void get_elements_ric(int* source, int dimS, int* dest1, int dmax1, int &dim1, int* dest2, int dmax2, int &dim2, int indice){

  if(indice < dimS){
    cout<< "entrato" <<indice<<endl;
    if( indice%2 == 0 && source[indice]%3 == 0 ){

      dest1[dim1] = source[indice];
      dim1++;
      return get_elements_ric(source, dimS, dest1, dmax1, dim1, dest2, dmax2, dim2, indice+1);
    }
    else{

      dest2[dim2] = source[indice];
      dim2++;
      return get_elements_ric(source, dimS, dest1, dmax1, dim1, dest2, dmax2, dim2, indice+1);
    }
  }
  else
    return;
}

void get_elements(int* source, int dimS, int* dest1, int dmax1, int &dim1, int* dest2, int dmax2, int &dim2){
  get_elements_ric(source, dimS, dest1, dmax1, dim1, dest2, dmax2, dim2, 0);
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
