#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(char * source, const int dim_source, char * dest1, const int dimMaxDest1, int & dimDest1, char * dest2, const int dimMaxDest2, int & dimDest2);
void save_elements(char * source, int index, const int dim_source, char * dest1, const int dimMaxDest1, int & dimDest1, char * dest2, const int dimMaxDest2, int & dimDest2);
bool is_lower(char c);
bool is_upper(char c);
char upper(char c);
char lower(char c);

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

void get_elements(char * source, const int dim_source, char * dest1, const int dimMaxDest1, int & dimDest1, char * dest2, const int dimMaxDest2, int & dimDest2) {
  save_elements(source, 0, dim_source, dest1, dimMaxDest1, dimDest1, dest2, dimMaxDest2, dimDest2);
}

void save_elements(char * source, int index, const int dim_source, char * dest1, const int dimMaxDest1, int & dimDest1, char * dest2, const int dimMaxDest2, int & dimDest2) {
  if(index < dim_source) {
    if(is_lower(source[index]) && dimDest1 < dimMaxDest1) {
      dest1[dimDest1] = upper(source[index]);
      dimDest1++;
    } else if(is_upper(source[index]) && dimDest2 < dimMaxDest2) {
      dest2[dimDest2] = lower(source[index]);
      dimDest2++;
    }
    index++;
    save_elements(source, index, dim_source, dest1, dimMaxDest1, dimDest1, dest2, dimMaxDest2, dimDest2);
  }
}

bool is_lower(char c) {
  bool ret = false;
  if(c >= 'a' && c <= 'z')
    ret = true;
  return ret;
}

bool is_upper(char c) {
  bool ret = false;
  if(c >= 'A' && c <= 'Z')
    ret = true;
  return ret;
}

char upper(char c) {
  return (is_lower(c) ? c + ('A' - 'a') : c);
}

char lower(char c) {
  return (is_upper(c) ? c + ('a' - 'A') : c);
}