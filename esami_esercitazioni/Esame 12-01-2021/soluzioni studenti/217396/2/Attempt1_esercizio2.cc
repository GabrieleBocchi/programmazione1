#include <iostream>
#include <cstddef>

using namespace std;


void get_elements(int * source, int dim_s , int * dest1, int MAX_dim_d1, int dim_d1 ,
                  int * dest2 , int MAX_dim_d2, int dim_d2 );
// MR: dim_d1 e dim_d2 NON sono passati per riferimento!


bool divis3(int *source, int i);


bool divis3(int *source, int i){
  if(i%3==0){
    if(i%2 == 0)
      // MR: NON e' indice che deve essere pari, ma il valore
      // memorizzato nella posizione
      return true;
  }
  return false;
}




void get_elements(int * source, int dim_s , int * dest1, int MAX_dim_d1, int dim_d1 , int * dest2 , int MAX_dim_d2, int dim_d2 ){
  // MR: gli array in C vanno da 0 a dim_s - 1, se accede a dim_s sta
  // eccedendo i bound dell'array. Inoltre, source NON e' scritto da
  // nessuna parte che sia terminato da -1! Il -1 e' usato solo in
  // lettura dalla funzione read_elements.  dim_d1 e dim_d2 dovevano
  // essere passati per riferimento perche' modifiche siamo propagate
  // al chiamante!
  if(source[dim_s] == -1)
    return;

  if(divis3(source , dim_s)){
    // MR: Manca controllo che dim_d1 < MAX_dim_d1
      dest1[dim_d1] = source[dim_s] *2;

      dim_d1++;
    }
  else{
    // MR: Manca controllo che dim_d2 < MAX_dim_d2
    dest2[dim_d2] = source[dim_s] * 3;

    dim_d2++;
  }
  // MR: Qui sta incrementando dim_s, quindi nella prossima chiamata
  // accede ad area di memoria che sicuramente eccede i bound
  // dell'array source
  dim_s++;

  get_elements(source,dim_s,dest1,MAX_dim_d1,dim_d1,dest2,MAX_dim_d2,dim_d2);

}




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
