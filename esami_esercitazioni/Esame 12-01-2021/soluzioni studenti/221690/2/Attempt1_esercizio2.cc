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

void get_element(char source[], int d_s, char dest1[], int dm_1, int& d_1, char dest2[], int dm_2, int& d_2, int i) {
  // MR: quando i = d_s - 1, lei fa ricorsione, e quando arriva qui, i
  // = d_s e accede a posizione d_s che e' fuori range. Bastava
  // mettere la condizione i < d_s qui invece che in coda! Nella
  // ricorsione si mette sempre prima condizione per evitare di
  // accedere out of bounds.
    if (source[i] >= 'a' && source[i] <= 'z' && d_1 < dm_1) {
        dest1[d_1] = source[i] - 'a' + 'A';
        d_1++;
    }
    if (source[i] >= 'A' && source[i] <= 'Z' && d_2 < dm_2) {
       dest2[d_2] = source[i] - 'A' + 'a';
       d_2++;
    }
    if (i < d_s) {
        get_element(source, d_s, dest1, dm_1, d_1, dest2, dm_2, d_2, ++i);
    }
}

void get_elements(char source[], int d_s, char dest1[], int dm_1, int& d_1, char dest2[], int dm_2, int& d_2) {
    get_element(source, d_s, dest1, dm_1, d_1, dest2, dm_2, d_2, 0);
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
