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

void get_elements_r(char s[],int rs, int s_s, char  d1[], int md1_s, int &d1_s, char d2[], int md2_s, int &d2_s){
  // MR: COntrollo che rs sia minore di s_s deve essere fatto qui,
  // altrimenti potrebbe accedere a memoria non consentita.
  char c = s[rs];
  // MR: Mancano controlli che d1_s e d2_s siano minori dei rispettivi
  // valori massimi
  if(c>='a' && c<='z') {
    //ho una lettera minuscola
    int shift ='a'-'A';
    c -= shift; //diventa maiuscola
    d1[d1_s] = c;
    d1_s++;
  }
  else if(c>='0' && c<='9'){
    int n = (c-'0')%10;
    c = 9-n+'0';
    d2[d2_s] = c;
    d2_s++;
  }

  if(rs < (s_s-1)){
    // MR: In questo modo ignora l'ultimo carattere se e' una lettera
    // minuscola o un numero!
    get_elements_r(s,rs+1, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);
  }
}

void get_elements(char s[], int s_s, char  d1[], int md1_s, int &d1_s, char d2[], int md2_s, int &d2_s){
  get_elements_r(s,0, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);
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
