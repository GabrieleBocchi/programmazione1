#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(char s[], int & s_s, char d1[], const int md1_s, int & d1_s, char d2[], const int md2_s, int & d2_s, int i){
  int daA='A'-'a';
  char t;
  // MR: queste variabili si potevano evitare inserendo direttamente
  // il codice dove usate, e usando direttamente s[i].
  if(i<s_s){
    // MR: Manca controllo che d1_s sia < md1_s
    t=s[i];
    if(t>='a' && t<='z'){
      t=t+daA;
      d1[d1_s]=t;
      d1_s++;
    }
    else if(t>='0' && t<='9'){
      // MR: Corretto ma si poteva fare in modo piu' compatto con '9'
      // - (s[i] - '0');
      switch (t){
      case '0':
        t='9';
        break;
      case '1':
        t='8';
        break;
      case '2':
        t='7';
        break;
      case '3':
        t='6';
        break;
      case '4':
        t='5';
        break;
      case '5':
        t='4';
        break;
      case '6':
        t='3';
        break;
      case '7':
        t='2';
        break;
      case '8':
        t='1';
        break;
      case '9':
        t='0';
        break;
      }
      d2[d2_s]=t;
      d2_s++;
    }

    i++;

    get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, i);
  }
}

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

  get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, 0);

  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}
