#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(const char* source, int dim_source, char* dest1, int dim1_max, int &dim1, char* dest2, int dim2_max, int &dim2);
void rec_get_elements(const char* source, const int dim_source, char* dest1, int dim1_max, int &dim1, char* dest2, int dim2_max, int &dim2, int index);


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

void rec_get_elements(const char* source, const int dim_source, char* dest1, int dim1_max, int &dim1, char* dest2, int dim2_max, int &dim2, int index) {
  if (index < dim_source) {
    if (source[index] >= 'a' && source[index] <= 'z') {
      if (dim1 < dim1_max) {
        dest1[dim1] = source[index] - 'a' + 'A';
        dim1++;
      }
    } else if (source[index] >= 'A' && source[index] <= 'Z') {
      if (dim2 < dim2_max) {
        dest2[dim2] = source[index] - 'A' + 'a';
        dim2++;
      }
    }

    rec_get_elements(source, dim_source, dest1, dim1_max, dim1, dest2, dim2_max, dim2, index + 1);
  }
}

void get_elements(const char* source, int dim_source, char* dest1, int dim1_max, int &dim1, char* dest2, int dim2_max, int &dim2) {
  dim1 = dim2 = 0;
  rec_get_elements(source, dim_source, dest1, dim1_max, dim1, dest2, dim2_max, dim2, 0);
}