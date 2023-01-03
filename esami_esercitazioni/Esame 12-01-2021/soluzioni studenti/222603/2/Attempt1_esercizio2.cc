#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(char s[], int & s_s,char d1[],int md1_s,int d1_s,char d2[],int md2_s,int d2_s);

void get_elementsric(char s[], int & s_s,char d1[],int md1_s,int d1_s,char d2[],int md2_s,int d2_s, int i);

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


void get_elements(char s[], int & s_s,char d1[],int md1_s,int d1_s,char d2[],int md2_s,int d2_s){
  get_elementsric (s, s_s, d1, md1_s, d1_s+1, d2, md2_s, d2_s, 0) ;
}

void get_elementsric(char s[], int & s_s,char d1[],int md1_s,int d1_s,char d2[],int md2_s,int d2_s, int i){
  if(i > md1_s){
    return;
  } else if((s[d1_s] >= 'a' && s[d1_s] <= 'z') && (i<=md1_s)){
      d1[d1_s] = s[d1_s]-('A'-'a') ;
      get_elementsric (s, s_s, d1, md1_s, d1_s+1, d2, md2_s, d2_s, i++) ;

    } else if((s[d1_s]>='A' && s[d1_s]<='Z') && (i<=md1_s)) {

      d2[d2_s] = s[d2_s]-('a'-'A') ;
      get_elementsric (s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s+1, i++) ;
        
      } else {
        get_elementsric (s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, i++) ;
      }
    
}