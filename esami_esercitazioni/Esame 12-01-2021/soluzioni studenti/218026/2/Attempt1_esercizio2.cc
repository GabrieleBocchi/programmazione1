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

void get_elements(int* source, int &dim_source,
  int* dest1, const int max_dim_dest1, int &calc_dim_dest1,
  int* dest2, const int max_dim_dest2, int &calc_dim_dest2);

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

void get_elements(int* source, int &dim_source,
  int* dest1, const int max_dim_dest1, int &calc_dim_dest1,
  int* dest2, const int max_dim_dest2, int &calc_dim_dest2) {
  // MR: NON ACCETTABILE. L'esercizio richiedeva "Scrivere nel file
  // esercizio2.cc la dichiarazione e la definizione della funzione
  // ricorsiva get_elements che..." e nel terzo punto della nota "La
  // funzione get_elements deve essere ricorsiva ed al suo interno non
  // ci possono essere cicli o chiamate a funzioni contenenti
  // cicli. Si può però fare uso di eventuali funzioni ricorsive
  // ausiliarie all’interno di questa funzione.". Consiglio di leggere
  // con attenzione TUTTO il testo!

    calc_dim_dest1 = 0;
    calc_dim_dest2 = 0;

    for (int i = 0; i < dim_source; i++) {
      if ((i % 3 == 0) && (source[i] % 2 == 0) && (calc_dim_dest1 < max_dim_dest1)) {
        dest1[calc_dim_dest1] = source[i] * 2;
        calc_dim_dest1++;
      }
      else if (calc_dim_dest2 < max_dim_dest2){
        dest2[calc_dim_dest2] = source[i] * 3;
        calc_dim_dest2++;
      }
    }

  }
