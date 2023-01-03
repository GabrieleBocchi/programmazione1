#include <iostream>
#include <cstddef>

using namespace std;

void print(const char a[], const int s, const char* prefix) {
  cout << prefix;
  for (int i = 0; i < s; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void read_elements(char s[], const int ms, int& s_s) {
  char r = '\0';
  for (s_s = 0; ((s_s < ms) && (r != '\n')); ) {
    r = cin.get();
    if ((r != '\n') && (r != ' ')) s[s_s++] = r;
  }
}

bool get_elements_recursive(char s[], int& s_s, int pos, char d1[], int md1_s, int& d1_s, char d2[], int md2_s, int& d2_s) {
  bool rtn = false;
  // MR: Non chiaro a cosa serve questo bool di ritorno!
  if (pos > s_s) {
    rtn = true;
  }
  else {
    // MR: Si poteva fare una chiamata ricorsiva solo ponendola alla
    // fine degli if.
    if (s[pos] >= 'a' && s[pos] <= 'z') {
      if (d1_s < md1_s) {
        d1[d1_s] = s[pos] + ('A' - 'a');
        d1_s++;
      }
      rtn = get_elements_recursive(s, s_s, pos + 1, d1, md1_s, d1_s, d2, md2_s, d2_s);
    }
    else if (s[pos] >= 'A' && s[pos] <= 'Z') {
      if (d2_s < md2_s) {
        d2[d2_s] = s[pos] - ('A' - 'a');
        d2_s++;
      }
      rtn = get_elements_recursive(s, s_s, pos + 1, d1, md1_s, d1_s, d2, md2_s, d2_s);
    }
    else {
      rtn = get_elements_recursive(s, s_s, pos + 1, d1, md1_s, d1_s, d2, md2_s, d2_s);
    }

  }
  return rtn;
}

void get_elements(char s[], int& s_s, char d1[], int md1_s, int& d1_s, char d2[], int md2_s, int& d2_s) {
  bool rtn = get_elements_recursive(s, s_s, 0, d1, md1_s, d1_s, d2, md2_s, d2_s);
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
