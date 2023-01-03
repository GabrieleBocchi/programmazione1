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

void get_elements( char* s, int indS, char* d1, int maxD1, int& dim1, char* d2, int maxD2, int& dim2 );

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

void get_elements( char* s, int dimS, char* d1, int maxD1, int& dim1, char* d2, int maxD2, int& dim2 ){
	if( dimS > 0 ){
		get_elements(s,dimS-1,d1,maxD1,dim1,d2,maxD2,dim2);	
	}
	char buf = s[dimS-1];
		
	if( buf >= 'a' && buf <= 'z' && dim1 < maxD1 )
		d1[dim1++] = buf + ('A'-'a');
	else if ( buf >= '0' && buf <= '9' && dim2 < maxD2 )
		d2[dim2++] = ('9' - buf)	+ '0';	

}
