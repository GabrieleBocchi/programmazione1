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
    if ((r != '\n') && (r != ' '))
     s[s_s++] = r;
  }
}

int converti(char num){
  // MR: Corretto ma più semplice fatto come: '9' - (num - '0');
  char ris;
  if(num=='0'){
    ris = '9';
  }
  else if(num=='1'){
    ris = '8';
  }
  else if(num=='2'){
    ris = '7';
  }
  else if(num=='3'){
    ris = '6';
  }
  else if(num=='4'){
    ris = '5';
  }
  else if(num=='5'){
    ris = '4';
  }
  else if(num=='6'){
    ris = '3';
  }
  else if(num=='7'){
    ris = '2';
  }
  else if(num=='8'){
    ris = '1';
  }
  else if(num=='9'){
    ris = '0';
  }

  return ris;
}


void get_elements_ric(char s[], int s_s, char d1[], int md1_s, int& d1_s, char d2[], int md2_s, int& d2_s, int i){
  if(i<s_s){
    if(s[i] >= 'a' and s[i]<= 'z'){
      d1[d1_s] = s[i];
      d1[d1_s] = d1[d1_s] + ('A' - 'a');
      // MR: Qui avrebbe potuto scrivere d1[d1_s] = s[i] + ('A' -
      // 'a'); evitando una scrittura ed una lettura, che sono costose
      // perchè accessi memoria costano, vedrà in corso di calcolatori.
      d1_s++;
    }
    if(s[i] >= '0' and s[i] <= '9'){
      d2[d2_s] = s[i];
      d2[d2_s] = converti(d2[d2_s]);
      //MR: Stesso commento del ramo precedente
      d2_s++;
    }

    get_elements_ric(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, i+1);
  }
}

void get_elements(char s[], int s_s, char d1[], int md1_s, int& d1_s, char d2[], int md2_s, int& d2_s){
  int i=0;
  // MR: Avrebbe potuto passare direttamente 0 senza definire una
  // variabile.
  get_elements_ric(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, i);
}

int main() {
  const int maxdim = 10;

  const int md1_s = maxdim;     //dimensione massima dest1
  char d1[md1_s];               //array dest1
  int d1_s = 0;                 //dimensione da calcolare dest1

  const int md2_s = maxdim;     //dimensione massima dest1
  char d2[md2_s];               //array dest2
  int d2_s = 0;                 //dimensione da calcolare dest1

  const int ms = maxdim;        //dimensione massima array source
  char s[ms];                   //array source
  int s_s = 0;                  //dimensioni array source

  read_elements(s, ms, s_s);        //prende i caratteri e li mette su s

  get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);

  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}
