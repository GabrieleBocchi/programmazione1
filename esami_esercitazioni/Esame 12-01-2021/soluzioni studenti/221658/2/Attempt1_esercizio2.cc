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

void get_elements(char [], int, char [], int, int &, char [], int, int &);
void get_elements_ric(char [], int, char [], int &, char[], int &, int);

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

void get_elements(char s[], int dims, char dest1 [], int maxDim1, int & dim1, char dest2 [], int maxDim2, int & dim2){

  get_elements_ric(s, dims, dest1, dim1, dest2, dim2, 0);

}

void get_elements_ric(char s [], int dims, char d1 [], int & dim1, char d2 [], int & dim2, int index){

  if(index != dims){
    // MR: Dovrebbe controllare che index sia maggiore o uguale a 0, e
    // che sia minore stretto di dims. Se per caso viene chiamato con
    // un valore di index > dims il suo programma accede a memoria non
    // del programma e va in seg fault. Inoltre, qui non viene
    // minimante tenuta in considerazione la dimensione di d1 e
    // d2. Nell'esempio del main sono uguali a dim, ma non era
    // specificato da nessuna parte che avessero la stessa dimensione
    // nel testo.
    int delta = 'A' - 'a';

    if((s[index] >= 'a') && (s[index] <= 'z')){
      d1[dim1] = s[index] + delta;
      dim1 ++;
      index ++;
      get_elements_ric(s, dims, d1, dim1, d2, dim2, index);
    }
    else if((s[index] >= '0') && (s[index] <= '9')){
      int n = int(s[index]);
      int m = '9' - n;
      d2[dim2] = char('0' + m);
      dim2 ++;
      index ++;
      get_elements_ric(s, dims, d1, dim1, d2, dim2, index);
    }
    else{
      index ++;
      get_elements_ric(s, dims, d1, dim1, d2, dim2, index);

    }
    // MR: Avrebbo potuto avere una sola chiamata ricorsiva in coda
    // spostandola alla fine.
  }
}
