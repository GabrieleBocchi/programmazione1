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
void get_elements_ric(char s[], int s_s, char d1[], int md1_s, int d1_s, char d2[], int md2_s, int d2_s,int i);
// MR: d1_s e d2_s non sono passati per riferimento come richiesto nel
// testo.
void get_elements(char s[], int s_s, char d1[], int md1_s, int d1_s, char d2[], int md2_s, int d2_s);
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
void get_elements(char s[], int s_s, char d1[], int md1_s, int d1_s, char d2[], int md2_s, int d2_s){
    get_elements_ric( s,  s_s,  d1,  md1_s,  d1_s,  d2,  md2_s,  d2_s, 0);
}
void get_elements_ric(char s[], int s_s, char d1[], int md1_s, int d1_s, char d2[], int md2_s, int d2_s,int i){
  // MR: d1_s e d2_s non passati per riferimento. Inoltre nessun
  // controllo che i sia minore di s_s e che la dimensione sia minore
  // di md1_s e md2_s, quindi potrebbe accedere ad area di memoria non
  // facente parte del programma.
  // Coding standard (indentazione pessima)
    if(i==s_s){
        return;
            }
    else {
    if(s[i]<='z' && s[i] >= 'a'){
         d1[i]=s[i]+('A'-'a');
	 // MR: qui dovrebbe scrivere in d1_s ed incrementarlo
     }
     if(s[i]<='Z' && s[i] >= 'A'){
         d2[i]=s[i]+('A'-'a');
	 // MR: qui dovrebbe scrivere in d2_s ed incrementarlo,
	 // inoltre non converte in minuscola!

}

    }
get_elements_ric( s,  s_s,  d1,  md1_s,  d1_s,  d2,  md2_s,  d2_s, i+1);
}
