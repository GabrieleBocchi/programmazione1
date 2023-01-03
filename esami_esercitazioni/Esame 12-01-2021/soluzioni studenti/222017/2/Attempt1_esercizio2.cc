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


void ricorsiva(char s[], int s_s, char d1[], int md1_s, int & d1_s, char d2[], int md2_s, int & d2_s, int diff, int index){
  // MR: Questo codice non va in ricorsione quando il carattere nella
  // posizione index non e' compreso in a-z o A-Z, e quindi quando
  // succede ignora parte dell'array di input.
  if (index < s_s){
    if (s[index] >= 'a' && s[index] <= 'z'){
      // MR: Manca controllo che d1_s sia < md1_s
      d1[d1_s] = s[index] + diff;
      d1_s++;
      ricorsiva(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, diff, index+1);
    }else if(s[index] >= 'A' && s[index] <= 'Z'){
      // MR: Manca controllo che d2_s sia < md2_s
      d2[d2_s] = s[index] - diff;
      d2_s++;
      ricorsiva(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, diff, index+1);
    }
  }
}

void get_elements(char s[], int s_s, char d1[], int md1_s, int & d1_s, char d2[], int md2_s, int & d2_s){
  int index = 0;
  int diff = 'A'-'a';
  ricorsiva(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, diff, index);
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
