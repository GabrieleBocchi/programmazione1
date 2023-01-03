#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(char source[], int dim_source, char dest1[], int maxdim_dest1, int &dim_dest1, char dest2[], int maxdim_dest2, int &dim_dest2){

  int i=dim_dest1+dim_dest2;
  //cout <<"i: " <<i <<endl;

  if(i<dim_source){
    // MR: potrebbe funzionare solo nel caso che
    // ci fossero maiuscole e minuscole. Se ci sono numeri sicuramente
    // non funziona.

    // MR: Se primo carattere e' una punteggiatura entra in ricorsione
    // infinita, cosi' come se e' una a o una A o una z o una z
    char c=source[i];

    if(c>'a' && c<'z'){
      // MR: Nel caso sarebbe >= a e <= z altrimenti scarta la a e la z!
      c=(char)(c-('a'-'A'));
      //cout <<"c: " <<c <<endl;
      dest1[dim_dest1]=c;
      //cout <<dest1[dim_dest1];
      //cout <<dest1;
      dim_dest1++;
    }
    else if(c>'A' && c<'Z'){
      // MR: Nel caso sarebbe >= A e <= Z altrimenti scarta la A e la Z!
      c=(char)(c+('a'-'A'));
      //cout <<c;
      dest2[dim_dest2]=c;
      //cout <<dest2;
      dim_dest2++;
    }

    get_elements(source, dim_source, dest1, maxdim_dest1, dim_dest1, dest2, maxdim_dest2, dim_dest2);

  }
  else
  {
    return;
  }

}

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

  /*char c='a';
  cout <<(char)(c-32);*/

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
