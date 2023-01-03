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

void get_elements(char s[],int s_s, char d1[], int md1_s,int & d1_s,char d2[], int md2_s,int & d2_s,int i){
  if(i < s_s){
    if(s[i] <= 'z' && s[i] >= 'a'){
      if(md1_s > d1_s){
	d1[d1_s] = s[i] - 32;
	// MR: Assunzione che ci sia 32 tra a e z e'corretto solo
	// sotto assunzioni sulla codifica. Meglio: (s[i] - 'a') + 'A'
	d1_s++;
      }
    }else{
     if(d2_s < md2_s){
      d2[d2_s] = (s[i]-57)*(-1);;
      // MR: Qui la conversione e' sbagliata!
      // Quella corretta è '9' - (s[i] - '0');
	d2_s++;
      }
    }
    i++;
    get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s,i);
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

  get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s,0);

  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}
