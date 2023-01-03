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

void get_elements(int *src, int s_src,
                  int *out1, int ms_out1, int &s_out1,
                  int *out2, int ms_out2, int &s_out2) {
  // MR: Non e' accettabile come soluzione. Il testo richiedeva che
  // fosse ricorsiva! "Scrivere nel file esercizio2.cc la
  // dichiarazione e la definizione della funzione ricorsiva
  // get_elements ...". LEGGERE ATTENTAMENTE TUTTO IL TESTO! Inoltre,
  // specificato anche nel punto tre della nota.

  // scorrimento source
  s_out1 = s_out2 = 0;
  for(int i = 0; i < s_src; i++) {

    // controllo per out1
    if(i % 3 == 0 && src[i] % 2 == 0) {
      if(ms_out1 <= s_out1)
        cout << "Raggiunta lunghezza massima out_1" << endl;
      else
        out1[s_out1++] = src[i] * 2;
    }
    // controllo per out2
    else {
      if(ms_out2 <= s_out2)
        cout << "Raggiunta lunghezza massima out_2" << endl;
      else
        out2[s_out2++] = src[i] * 3;
    }
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
