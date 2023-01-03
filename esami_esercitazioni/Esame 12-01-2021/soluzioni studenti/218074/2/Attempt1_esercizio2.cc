#include <iostream>
#include <cstddef>

using namespace std;
void get_elements(int s[], int s_s, int d1[], const int md1_s, int &d1_s, int d2[], const int md2_s, int &d2_s);
void get_elements_ric(int s[], int s_s, int d1[], const int md1_s, int &d1_s, int d2[], const int md2_s, int &d2_s, int i);
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
void get_elements(int s[], int s_s, int d1[], const int md1_s, int &d1_s, int d2[], const int md2_s, int &d2_s){
    get_elements_ric(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, 0);
};

void get_elements_ric(int s[], int s_s, int d1[], const int md1_s, int &d1_s, int d2[], const int md2_s, int &d2_s, int i){
    if (i < s_s)  {
        if(i % 2 == 0 && s[i] % 3 == 0){
	  // MR: Manca controllo che d1_s sia < md1_s
            d1[d1_s]=s[i];
            d1_s++;
        }
        else {
	  // MR: Manca controllo che d2_s sia < md2_s
            d2[d2_s] = s[i];
            cout << d2[d2_s];
	    // MR: Stampa non richiesta
            d2_s++;
        }
        get_elements_ric(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, i+1);
    }
}
