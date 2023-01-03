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

char toUpper(char carattere){
   return carattere+('A'-'a');
}

void read_elements(char s[], const int ms, int & s_s) {
  char r = '\0';
  for (s_s = 0; ((s_s < ms) && (r != '\n')); ) {

    r = cin.get();
    if ((r != '\n') && (r != ' ')) s[s_s++] = r;

  }

}
void  get_elements(char s[], int s_s,char d1[],int md1_s, int &d1_s,char d2[], int md2_s, int &d2_s, int i) {
  // MR: Il controllo che i sia ninore di s_s deve essere fatto
  // qui. Infatti se chiamo la funzione specificando per i un valore
  // >= di s_s, cosa che posso fare, il suo codice accede a memoria
  // non valida per il programma.
  if (s[i]>='a' && s[i]<='z')
  {

    d1[d1_s]=toUpper(s[i]);
    d1_s++;
  }else if (s[i]>='0' && s[i]<='9')
  {
    int temp;
    temp=s[i]-'0';
    temp=(temp-9)*-1;
    d2[d2_s]=temp+'0';
    // MR: Molto piu' semplice '9' - (s[i] - '0');
    d2_s++;
  }else{

  }
  // MR: L'indentazione e il coding standard sono un po'
  // discutibili. Veda tutto sto spazio qui sotto.


  i++;

  if (i<s_s)
  {
   get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s,i);
  }else{}



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
  cout<<s[s_s]<<endl;
  int i=0;
  get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, i);


  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}
