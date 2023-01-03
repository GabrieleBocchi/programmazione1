#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(const char source[],
		  const int size_s,
		  char dest1[], int msize_d1, int & d1,
		  char dest2[], int msize_d2, int & d2);

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

  get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);

  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}

void get_elements_aux(const char source[],
		      const int size_s,
		      char dest1[], int msize_d1, int & d1,
		      char dest2[], int msize_d2, int & d2,
		      int i);

void get_elements(const char source[],
		  const int size_s,
		  char dest1[], int msize_d1, int & d1,
		  char dest2[], int msize_d2, int & d2) {

  get_elements_aux(source, size_s,
		   dest1, msize_d1, d1,
		   dest2, msize_d2, d2,
		   0);
}

void get_elements_aux(const char source[],
		      const int size_s,
		      char dest1[], int msize_d1, int & d1,
		      char dest2[], int msize_d2, int & d2,
		      int i) {
  if ((i < size_s) && (d1 < msize_d1) && (d2 < msize_d2)) {
    if ((source[i] >= 'a') && (source[i] <= 'z') ) {
      dest1[d1++] = (source[i] - 'a') + 'A';
    } else if ((source[i] >= 'A') && (source[i] <= 'Z')) {
      dest2[d2++] = (source[i] - 'A') + 'a';
    }
    else {
    }
    get_elements_aux(source, size_s,
		     dest1, msize_d1, d1,
		     dest2, msize_d2, d2,
		     ++i);
  }
}
