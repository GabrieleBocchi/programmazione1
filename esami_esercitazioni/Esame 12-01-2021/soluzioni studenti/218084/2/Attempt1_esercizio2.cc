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

void get_elements(int source[], int dim_source, int dest1[], int dim_max_dest1, int &dim_dest1, int dest2[], int dim_max_dest2, int &dim_dest2);
void get_elements_ricorsiva_dest1(int source[], int dim_source, int dest1[], int dim_max_dest1, int &dim_dest1, int indice_source, int indice_dest);
void get_elements_ricorsiva_dest2(int source[], int dim_source, int dest2[], int dim_max_dest2, int &dim_dest2, int indice_source, int indice_dest);


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


void get_elements(int source[], int dim_source, int dest1[], int dim_max_dest1, int &dim_dest1, int dest2[], int dim_max_dest2, int &dim_dest2){
  get_elements_ricorsiva_dest1(source, dim_source, dest1, dim_max_dest1, dim_dest1, 0, 0);
  get_elements_ricorsiva_dest2(source, dim_source, dest2, dim_max_dest2, dim_dest2, 0, 0);
  // MR: Si e' complicato la vita facendo due ricorsioni, oltre ad
  // essere molto inefficiente, perche' nella seconda ha invertito
  // condizione della prima, ha ripetuto due volte lo stesso errore!
  // Indice_dest e'inutile. Poteva tranquillamente usare
  // dim_dest1/dim_dest2
}

void get_elements_ricorsiva_dest1(int source[], int dim_source, int dest1[], int dim_max_dest1, int &dim_dest1, int indice_source, int indice_dest){
  if (indice_source < dim_source){
    if (indice_source%2 == 0 and source[indice_source]%3 == 0){
      // MR: Manca controllo che indice_dest sia < dim_max_dest1
      dest1[indice_dest] = source[indice_source];
      dim_dest1 = indice_dest+1;
      get_elements_ricorsiva_dest1(source, dim_max_dest1, dest1, dim_max_dest1, dim_dest1, indice_source+1, indice_dest+1);
    }
    else{
      get_elements_ricorsiva_dest1(source, dim_max_dest1, dest1, dim_max_dest1, dim_dest1, indice_source+1, indice_dest);
    }
  }
}

void get_elements_ricorsiva_dest2(int source[], int dim_source, int dest2[], int dim_max_dest2, int &dim_dest2, int indice_source, int indice_dest){
  if (indice_source < dim_source){
    if (!(indice_source%2 == 0 and source[indice_source]%3 == 0)){
      // MR: Manca controllo che indice_dest sia < dim_max_dest2
      dest2[indice_dest] = source[indice_source];
      dim_dest2 = indice_dest+1;
      get_elements_ricorsiva_dest2(source, dim_max_dest2, dest2, dim_max_dest2, dim_dest2, indice_source+1, indice_dest+1);
    }
    else{
      get_elements_ricorsiva_dest2(source, dim_max_dest2, dest2, dim_max_dest2, dim_dest2, indice_source+1, indice_dest);
    }
  }
}
