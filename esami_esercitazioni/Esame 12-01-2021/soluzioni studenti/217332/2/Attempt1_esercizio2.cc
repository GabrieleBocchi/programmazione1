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

void get_elements(char * s, int sdim, char * d1, int maxd1dim, int &d1dim, char * d2, int maxd2dim, int &d2dim);
void get_elements_rec(char * s, int sdim, char * d1, int maxd1dim, int &d1dim, char * d2, int maxd2dim, int &d2dim, int i);

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

//DEFINIZIONE DELLA FUNZIONE

void get_elements(char * s, int sdim, char * d1, int maxd1dim, int &d1dim, char * d2, int maxd2dim, int &d2dim){
    get_elements_rec(s,sdim,d1,maxd1dim,d1dim,d2,maxd2dim,d2dim,0);
}
void get_elements_rec(char * s, int sdim, char * d1, int maxd1dim, int &d1dim, char * d2, int maxd2dim, int &d2dim, int i){
    if(i < sdim){
        if(s[i]<='Z' && s[i]>='A'){
            if(d2dim < maxd2dim){
                d2[d2dim] = s[i] - ('A' - 'a');
                d2dim++;
            }
        }else if(s[i]<='z' && s[i]>='a'){
            if(d1dim < maxd1dim){
                d1[d1dim] = s[i] + ('A' - 'a');
                d1dim++;
            }
        }
        get_elements_rec(s,sdim,d1,maxd1dim,d1dim,d2,maxd2dim,d2dim,i+1);
    }else{
      // MR: Questo e' sbagliato! Scrive in posizione maxd1dim e
      // maxd2dim, gli indici vanno da 0 a N-1 dove N e' dimensione
      // array. Inoltre, non era richiesto che il terminatore fosse '\0'
        d2[d2dim] = '\0';
        d1[d1dim] = '\0';
    }
}
