#include <iostream>
#include <cstddef>
using namespace std;

void print(const int a[], const int s, const char * prefix) {
  cout << prefix;
  for (int i = 0; i < s; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void read_elements(int s[], const int ms, int & s_s) {
  int r = 0;
  for (s_s = 0; ((s_s < ms) && (r != -1)); ) {
    cin >> r;
    if (r != -1) s[s_s++] = r;
  }
}

//dichiarazione della funzione
void get_elements(int source[], int inizioSource, int dest1[], int dimD1, int &inizioD1, int dest2[], int dimD2, int &inizioD2);

int main() {
  const int maxdim = 10;

  const int md1_s = maxdim;
  int d1[md1_s];
  int d1_s = 0;

  const int md2_s = maxdim;
  int d2[md2_s];
  int d2_s = 0;

  const int ms = maxdim;
  int s[ms];
  int s_s = 0;

  read_elements(s, ms, s_s);

  get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);

  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}

//definzione della funzione
void get_elements(int source[], int dimSource, int dest1[], int dimD1, int &inizioD1, int dest2[], int dimD2, int &inizioD2) {

	int indiceSource = inizioD1 + inizioD2;

	if ( indiceSource >= dimSource ){
		cout << "Dimensione corrente d1 = " << inizioD1 << "  " << "Dimensione corrente d2 = " << inizioD2 << endl;
	}
	else {

		if ((indiceSource %2 == 0) && (source[indiceSource] %3 == 0)) {
		  // MR: Manca controllo che inizioD1 sia < dimD1
			dest1[inizioD1] = source[indiceSource];
			inizioD1++;
		}
		else {
		  // MR: Manca controllo che inizioD2 sia < dimD2
			dest2[inizioD2] = source[indiceSource];
			inizioD2++;
		}
		get_elements(source, dimSource, dest1, dimD1, inizioD1, dest2, dimD2, inizioD2); //chiamata ricorsiva
	}
}
