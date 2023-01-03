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

void get_elements(int & i, char s[], const int ms, char d1[], const int md1_s, int & d1_s, char d2[], const int md2_s, int & d2_s){
  if(i < ms){
    // MR: Mancano controlli che d1_s e d2_s siano inferiori a md1_s e
    // md2_s rispettivamente.
    if((s[i] >= 'a' && s[i] <= 'z') && d1_s < md1_s){
      d1[d1_s] = s[i] + ('A' - 'a');
      d1_s ++;
    }else if((s[i] >= '0' && s[i] <= '9') && d2_s < md2_s){
      char c1 = s[i];
      char c2 = '9';
      char d = c2 - c1;
      d2[d2_s] = c1;
      d2_s ++;
    }

    i++;
    get_elements(i, s, ms, d1, md1_s, d1_s, d2, md2_s, d2_s);
  }
}

int main() {
  const int maxdim = 10;
  int i = 0;
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

  get_elements(i, s, ms, d1, md1_s, d1_s, d2, md2_s, d2_s);

  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}
