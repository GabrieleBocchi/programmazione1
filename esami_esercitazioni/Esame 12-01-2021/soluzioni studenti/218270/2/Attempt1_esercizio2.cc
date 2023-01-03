#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(int * s, int s_s, int * d1, int md1_s, int d1_s, int * d2, int md2_s, int d2_s) {
  // Manca passaggio per riferimento di d1_s e d2_s.
  if (s_s<md2_s) {
    // MR: Questo test e' sbagliato! Gia' nell'esempio s_s e' uguale a
    // md2_s = md1_s, avrebbe dovuto usare un argomento di appoggio
    // per scorrere l'array.
    if (s_s==0 || (s_s%2)==0 || (s[s_s]%3)==0) {
      // MR: La condizione e' sbagliata rispetto a quanto specificato
      // nel testo ("elementi che sono in posizione pari E che sono
      // multipli di 3", notare la E che sta per AND e non per
      // or). Inoltre, mancano controlli che d1_s < md1_s
      d1[d1_s]=s[s_s];
    }
    else {
      // MR: Mancano controlli che d2_s < md2_s
      d2[d2_s]=s[s_s];
    }
    // MR: Qui incrementa s_s e quindi le chiamate successive fanno
    // accesso ad area di memoria spuria e fuori dei bound di s!
    get_elements(s, s_s+1, d1, md1_s, d1_s+1, d2, md2_s+1, d2_s);
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
