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

void get_elements_ric(int *s, int ds, int *d1, int dm1, int indiced1, int *d2, int dm2, int indiced2, int indice){
  // MR: indiced1 e indiced2 non sono passati per riferimento!

  // MR: Manca controllo che indice sia < ds! Infatti se chiamato con
  // indice > ds il programma va in segmentation fault!
    if(indice % 2 == 0 && s[indice] % 3 == 0){
        d1[indiced1] = s[indice];
	// MR: Manca controllo che indiced1 < dm1
        indiced1++;
        if(indice < ds-1){
            indice++;
            get_elements_ric(s, ds, d1, dm1, indiced1, d2, dm2, indiced2, indice);
        }
    }
    else{
        d2[indiced2] = s[indice];
	// MR: Manca controllo che indiced2 < dm2
        indiced2++;
        if(indice < ds-1){
            indice++;
            get_elements_ric(s, ds, d1, dm1, indiced1, d2, dm2, indiced2, indice);
        }
    }
    return;
}

void get_elements(int *s, int ds, int *d1, int dm1, int indiced1, int *d2, int dm2, int indiced2){
  // MR: indiced1 e indiced2 non sono passati per riferimento!
  int i = 0;
    get_elements_ric(s, ds ,d1,dm1, indiced1, d2, dm2, indiced2,i);
}



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
