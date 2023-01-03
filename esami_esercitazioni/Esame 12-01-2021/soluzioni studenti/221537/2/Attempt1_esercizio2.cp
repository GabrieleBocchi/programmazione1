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

void get_elements(char source[], int source_len, char dest1[],
    const int dest1_max_len, int &dest1_len, char dest2[],
    const int dest2_max_len, int &dest2_len);
void get_elements_helper(char source[], int source_len,
    char dest1[], const int dest1_max_len, int &dest1_len,
    char dest2[], const int dest2_max_len, int &dest2_len, int i=0);

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

void get_elements(char source[], int source_len, char dest1[],
    const int dest1_max_len, int &dest1_len, char dest2[],
    const int dest2_max_len, int &dest2_len) {
  get_elements_helper(source, source_len, dest1, dest1_max_len, dest1_len, dest2,
    dest2_max_len, dest2_len);
}

void get_elements_helper(char source[], int source_len,
    char dest1[], const int dest1_max_len, int &dest1_len,
    char dest2[], const int dest2_max_len, int &dest2_len, int i) {
  if(i < source_len) {
    char c = source[i];
    if('a' <= c && c <= 'z') {
      c -= 'a'-'A';
      if(dest1_len < dest1_max_len) {
        dest1[dest1_len] = c;
        dest1_len++;
      }
    }
    else if('0' <= c && c <= '9') {
      int val = c-'0';
      c = '0' + (9-val);
      if(dest2_len < dest2_max_len) {
        dest2[dest2_len] = c;
        dest2_len++;
      }
    }

    get_elements_helper(source, source_len, dest1, dest1_max_len, dest1_len,
      dest2, dest2_max_len, dest2_len, i+1);
  }
}
