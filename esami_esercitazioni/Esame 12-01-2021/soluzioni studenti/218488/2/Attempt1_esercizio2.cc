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

void get_elements(char* s, int s_s, char* d1, const int md1_s, int &d1_s, char* d2, const int md2_s, int &d2_s){
  if(s_s < 0){
    return;
  }
  if( *s >= 'a' && *s <= 'z' && d1_s < md1_s){
    d1[d1_s] = (*s-'a')+'A';
    d1_s++;
  }
  if( *s >= 'A' && *s <= 'Z' && d2_s < md2_s){
    d2[d2_s] = (*s-'A')+'a';
    d2_s++;
  }
  return get_elements(s+1, --s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);
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
