#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(int source[], int dim_source, int dest1[], int mdim_dest1, int& calc_dest1, int dest2[], int mdim_dest2, int& calc_dest2){
  // MR: Va bene usare aritmetica dei puntatori, anche se non
  // richiesto, a patto che la si usi correttamente!
  if(dim_source >= 0){
    if((dim_source-1)%2 == 0){
      if(*source%3 == 0){
	*dest1 = *source;
	calc_dest1++;
	// MR: NON STA CONTROLLANDO CHE dest1 non ecceda la sua dimensione
	dest1 += sizeof(int);
	// MR: Qui si sta spostando di 4 posizioni e non di 1!!!
	source += sizeof(int);
	// MR: Qui si sta spostando di 4 posizioni e non di 1!!!
	get_elements(source, --dim_source, dest1, mdim_dest1, calc_dest1, dest2, mdim_dest2, calc_dest2);
      }else{
	*dest2 = *source;
	calc_dest2++;
	dest2 += sizeof(int);
	// MR: Qui si sta spostando di 4 posizioni e non di 1!!!
	source += sizeof(int);
	// MR: Qui si sta spostando di 4 posizioni e non di 1!!!
	get_elements(source, --dim_source, dest1, mdim_dest1, calc_dest1, dest2, mdim_dest2, calc_dest2);
      }
    }else{
      *dest2 = *source;
      calc_dest2++;
      // MR: NON STA CONTROLLANDO CHE dest2 non ecceda la sua dimensione
      dest2 += sizeof(int);
      // MR: Qui si sta spostando di 4 posizioni e non di 1!!! Avrebbe
      // dovuto incrementare di 1, cosi' come in tutti gli altri casi
      // simili.
      source += sizeof(int);
      // MR: Qui si sta spostando di 4 posizioni e non di 1!!!
      get_elements(source, --dim_source, dest1, mdim_dest1, calc_dest1, dest2, mdim_dest2, calc_dest2);
    }
  }
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
