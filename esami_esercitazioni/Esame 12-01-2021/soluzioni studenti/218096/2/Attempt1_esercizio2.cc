#include <iostream>
#include <cstddef>

using namespace std;

void print(const int a[], const int s, const char * prefix) {
  cout << prefix;
  for (int i = 0; i < s; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void read_elements(int s[], const int ms, int & s_s) {
  int r = 0;
  for (s_s = 0; ((s_s < ms) && (r != -1)); ) {
    cin >> r;
    if (r != -1) s[s_s++] = r;
  }
}

void help_get_elements(int* source, int source_len, int index, int* dest1, int max_d1_len, int& dest1_len,int* dest2, int max_d2_len, int& dest2_len){
  // MR: il test corretto e' index < source_len. Infatti se chiamo con
  // index > source_len il programma va in seg fault
  if( index != source_len ){              // controllo di non essere alla fine

    if( index%3 == 0 && source[index]%2 == 0 ){     // controllo se il posto e' multiplo di 3 e il numero pari

      if( dest1_len < max_d1_len )                  // controllo di avere ancora spazio in dest1
        dest1[dest1_len++] = source[index] * 2;

    } else {

      if( dest2_len < max_d2_len )                  // controllo di avere ancora spazio in dest1
        dest2[dest2_len++] = source[index] * 3;

    }

    help_get_elements(source, source_len, index+1, dest1, max_d1_len, dest1_len, dest2, max_d2_len, dest2_len);

  }
}

void get_elements(int* source, int source_len, int* dest1, int max_d1_len, int& dest1_len,int* dest2, int max_d2_len, int& dest2_len){

  help_get_elements(source, source_len, 0, dest1, max_d1_len, dest1_len, dest2, max_d2_len, dest2_len);     // richiamo la funzione di appoggio

}

int main() {
  const int maxdim = 10;

  const int md1_s = maxdim;
  int d1[md1_s];
  int d1_s = 0;

  const int md2_s = maxdim;
  int d2[md2_s];
  int d2_s = 0;

  const int ms = maxdim;
  int s[ms];
  int s_s = 0;

  read_elements(s, ms, s_s);

  get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);
  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}
