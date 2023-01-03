#include <iostream>
#include <cstddef>

using namespace std;

void print(const char a[], const int s, const char * prefix) {
  cout << prefix;
  for (int i = 0; i < s; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void read_elements(char s[], const int ms, int & s_s) {
  char r = '\0';
  for (s_s = 0; ((s_s < ms) && (r != '\n')); ) {
    r = cin.get();
    if ((r != '\n') && (r != ' ')) s[s_s++] = r;
  }
}

void get_elements( char s[], int s_s, char d1[], const int md1_s, int &d1_s, char d2[], const int md2_s, int &d2_s );

char toOpposite( char c ){
  char c_opposite;
  if( c >= 'A' && c <= 'Z' ){
    c_opposite = ( c - 'A' + 'a' );
  }else if( c >= 'a' && c <= 'z' ) {
    c_opposite = ( c - 'a' + 'A' );
  }
  return c_opposite;
}

bool isUpLetter( char c ){
  return ( c >= 'A' && c <= 'Z' );
}

bool isLowerLetter( char c ){
  return ( c >= 'a' && c <= 'z' );
}

int main() {
  const int maxdim = 10;

  const int md1_s = maxdim;
  char d1[md1_s];
  int d1_s = 0;

  const int md2_s = maxdim;
  char d2[md2_s];
  int d2_s = 0;

  const int ms = maxdim;
  char s[ms];
  int s_s = 0;

  read_elements(s, ms, s_s);

  get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);

  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}

void get_elements( char s[], int s_s, char d1[], const int md1_s, int &d1_s, char d2[], const int md2_s, int &d2_s ){
  // MR: Peccato che non rispetti l'ordine in cui compaiono, infatti
  // lei inverte scorre da N-1 a 0 l'array e riempie nell'ordine in
  // cui trova i caratteri, ma il testo diceva di preservare ordine!
  // Infatti anche se lo prova con l'esempio del testo vede che
  // l'ordine e' invertito. Non lo considero nullo, perche' a parte
  // questo problema (che non e' da poco) la logica di gestione
  // ricorsione sembra averla capita! Le consiglio di leggere con
  // attenzione il testo! "le memorizza nell'ordine in cui compaiono
  // nell'array"
  if( s_s > 0 ){
    char c  = s[ s_s-1 ];
    if( isUpLetter( c ) ){
      c = toOpposite( c );
      if( d2_s < md2_s ){
        d2[ d2_s ] = c;
        d2_s += 1;
      }
    }else if( isLowerLetter( c ) ){
      c = toOpposite( c );
      if( d1_s < md1_s ){
        d1[ d1_s ] = c;
        d1_s += 1;
      }
    }
    get_elements( s, s_s-1, d1, md1_s, d1_s, d2, md2_s, d2_s );
  }
}
