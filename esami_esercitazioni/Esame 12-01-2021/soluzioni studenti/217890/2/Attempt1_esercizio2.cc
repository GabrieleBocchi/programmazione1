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

void get_elements(char source[],int i, char *dest1, int dim_dest1, int &i_dest1, char *dest2, int dim_dest2, int &i_dest2) {

  if(i<10){

    if(source[i]>='a' && source[i]<='z'){
      dest1[i_dest1]=source[i];
      i_dest1++;
    }

    if(source[i]>='A' && source[i]<='Z'){
      dest2[i_dest2]=source[i];
      i_dest2++;
    }
    i++;
    get_elements(source,i,dest1, dim_dest1, i_dest1, dest2, dim_dest2, i_dest2);
  }
  return;
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
