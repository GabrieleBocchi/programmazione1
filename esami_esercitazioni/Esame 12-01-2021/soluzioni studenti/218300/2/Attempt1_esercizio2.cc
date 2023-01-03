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
void get_elements(char s[], const int s_s, char d1[], const int md1_s, int &d1_s, char d2[], const int md2_s, int &d2_s); // passo per riferimento i valori che devo cambiare, gli array sono già passati per puntatore quindi posso cambiarli
void get_elements_rec (char s[], const int s_s, char d1[], const int md1_s, int &d1_s, char d2[], const int md2_s, int &d2_s, int position);

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
void get_elements(char s[], const int s_s, char d1[], const int md1_s, int &d1_s, char d2[], const int md2_s, int &d2_s){
  d1_s=0;
  d2_s=0;
  get_elements_rec (s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, 0); // per fare la funzione ricorsiva mi serve sapere la posizione in cui sono in s
}
void get_elements_rec (char s[], const int s_s, char d1[], const int md1_s, int &d1_s, char d2[], const int md2_s, int &d2_s, int position){
  if(s_s>position){
    if (s[position]>='a' && s[position]<='z' && d1_s<md1_s){ // se la lettera e' compresa tra la a minuscola e la z minuscola allora e' minuscola
      d1[d1_s] = (s[position] + ('A' - 'a')); // faccio diventare la lettera maiuscola
      d1_s++; // ho inseritoo un nuovo elemento in d1
    }
    else if (s[position]>='A' && s[position]<='Z' && d2_s<md2_s){ // analogo all'if precedente pero' con maiuscole invece che minuscoole
      d2[d2_s] = (s[position] - ('A' - 'a'));
      d2_s++;
    }
    
    get_elements_rec (s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, position+1);
  }
}
