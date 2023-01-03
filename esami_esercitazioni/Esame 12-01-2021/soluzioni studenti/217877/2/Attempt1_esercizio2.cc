#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(char* source, int dim_source, char* dest1, int max_dest1, int &dim_dest1, char* dest2, int max_dest2, int &dim_dest2, int i = 0);


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


void get_elements(char* source, int dim_source, char* dest1, int max_dest1, int &dim_dest1, char* dest2, int max_dest2, int &dim_dest2, int i){
  if(source[i]!='\n' && i <= dim_source){
    // MR: Qui avrebbe dovuto usare i < dim_source in quanto un array
    // di dimensione N ha indici che vanno da 0 a N-1.
    if(source[i] >= 'a' && source[i] <= 'z' && dim_dest1 < max_dest1){
      dest1[dim_dest1] = source[i] - 32;
      // MR: Qui si fa erronea assunzione sulla codifica dei
      // caratteri! E' corretto per caso! Modo corretto indipendente
      // dalla codifica e': (source[i] - 'a') + 'A';
      dim_dest1++;
    }
    if(source[i] >= '0' && source[i] <= '9' && dim_dest2 < max_dest2){
      // MR: Corretto ma più semplice se fatto con '9' - (source[i] - '0');
      switch(source[i]){
      case '0':
	dest2[dim_dest2] = '9';
	break;
      case '1':
	dest2[dim_dest2] = '8';
	break;
      case '2':
	dest2[dim_dest2] = '7';
	break;
      case '3':
	dest2[dim_dest2] = '6';
	break;
      case '4':
	dest2[dim_dest2] = '5';
	break;
      case '5':
	dest2[dim_dest2] = '4';
	break;
      case '6':
	dest2[dim_dest2] = '3';
	break;
      case '7':
	dest2[dim_dest2] = '2';
	break;
      case '8':
	dest2[dim_dest2] = '1';
	break;
      case '9':
	dest2[dim_dest2] = '0';
	break;
      }
      dim_dest2++;
    }
    get_elements(source, dim_source, dest1, max_dest1, dim_dest1, dest2, max_dest2, dim_dest2, i+1);
  }


}
