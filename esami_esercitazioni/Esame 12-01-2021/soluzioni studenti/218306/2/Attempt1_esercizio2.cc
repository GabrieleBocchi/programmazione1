#include <iostream>
#include <cstddef>

using namespace std;

void print(const char a[], const int s, const char *prefix) {
  cout << prefix;
  for (int i = 0; i < s; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void read_elements(char s[], const int ms, int &s_s) {
  char r = '\0';
  for (s_s = 0; ((s_s < ms) && (r != '\n'));) {
    r = cin.get();
    if ((r != '\n') && (r != ' ')) s[s_s++] = r;
  }
}

bool isLowerAlpha(char c) {
  return (c >= 'a' && c <= 'z');
}

bool isDigit(char c) {
  return (c >= '0' && c <= '9');
}

char toUpper(char c) {
  return 'A' + c - 'a';
}

char convertDigit(char c) {
  return '9' - (c - '0');
}

void
get_elements(char *source, int readIndex, int dimSource, char *d1, int dimMaxD1, int &dimD1, char *d2, int dimMaxD2,
             int &dimD2) {
  if (readIndex < dimSource) {
    char c = source[readIndex];
    if (isLowerAlpha(c) && dimD1 < dimMaxD1) {
      d1[dimD1++] = toUpper(c);
    } else if (isDigit(c) && dimD2 < dimMaxD2) {
      d2[dimD2++] = convertDigit(c);
    }
    get_elements(source, readIndex + 1, dimSource, d1, dimMaxD1, dimD1, d2, dimMaxD2, dimD2);
  }
}

void get_elements(char *source, int dimSource, char *d1, int dimMaxD1, int &dimD1, char *d2, int dimMaxD2, int &dimD2) {
  get_elements(source, 0, dimSource, d1, dimMaxD1, dimD1, d2, dimMaxD2, dimD2);
}

// test input
// a b 0 1 A a j K 3 9

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
