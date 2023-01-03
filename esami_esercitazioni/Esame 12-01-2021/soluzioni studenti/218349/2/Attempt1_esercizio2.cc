#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(char source[], int dim_source, char d1[], int max_d1, int &i_d1, char d2[], int max_d2, int &i_d2);
void get_elements_rec(char source[], int dim_source, int i_source, char d1[], int max_d1, int &i_d1, char d2[], int max_d2, int &i_d2);

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

void get_elements(char source[], int dim_source, char d1[], int max_d1, int &i_d1, char d2[], int max_d2, int &i_d2){
  get_elements_rec(source, dim_source, 0, d1, max_d1, i_d1, d2, max_d2, i_d2);
}

void get_elements_rec(char source[], int dim_source, int i_source, char d1[], int max_d1, int &i_d1, char d2[], int max_d2, int &i_d2){
  if(i_source<dim_source){

    if(i_d1<max_d1 && source[i_source]>='a' && source[i_source]<='z'){
      d1[i_d1] = source[i_source]-32;
      i_d1++;
      cout << i_d1 << endl;
      // MR: Questa stampa non era richiesta
    }
    else if(i_d2<max_d2 && source[i_source]>='0' && source[i_source]<='9'){
      //int n=(9-(source[i_source]-'0'))+48;
      int n=57-(source[i_source]-'0');
      // Qui c'e' assunzione che '9' sia 57. Avrebbe dovuto usare '9'.
      d2[i_d2] = n;
      i_d2++;
    }
    get_elements_rec(source, dim_source, i_source+1, d1, max_d1, i_d1, d2, max_d2, i_d2);
  }
}
