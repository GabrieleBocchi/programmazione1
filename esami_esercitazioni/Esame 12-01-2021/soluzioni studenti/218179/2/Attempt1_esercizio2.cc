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

void get_elements(char source[], int dim_s, char dest1[], int dim_d1, int &dim_d1fin, char dest2[], int dim_d2, int &dim_d2fin, int i=0){

	if(i==dim_s) return;
	// MR: Manca controllo che dim_d1fin e dim_d2fin siano minori
	// delle dimensioni dei rispettivi array
	else if(source[i] >= 'a' && source[i] <= 'z'){
		char tmp = source[i] + ('A'-'a');
		dest1[dim_d1fin] = tmp;
		dim_d1fin++;
	}
	else if(source[i] >= '0' && source[i] <= '9'){
		int a = 9-source[i];
		// MR: Manca incremento di '0', e 9 doveva essere un
		// carattere, ovvero: '9' - (source[i] - '0');
		dest2[dim_d2fin] = a;
		dim_d2fin++;
	}

	i++;
	get_elements(source, dim_s, dest1, dim_d1, dim_d1fin, dest2, dim_d2, dim_d2fin, i);

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
