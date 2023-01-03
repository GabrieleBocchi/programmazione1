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

void minuscole(char source[], int dim, int index, char destination[], int dim_dest){
  // MR: dim_dest non e' passato per riferimento!
    char car;

    if(index<dim){

        if (source[index] >= 'a' && source[index] <= 'z'){

            car = source[index];
            car = (car - 'a') + 'A';
            destination[dim_dest] = car;
	    // MR: Manca controllo che dim_dest sia minore di sua dim
	    // massima.
            cout << dim_dest << " " << destination[dim_dest] << endl;
            minuscole(source, dim, index + 1, destination, dim_dest + 1);
        }else{
            minuscole(source, dim, index + 1, destination, dim_dest);
        }
    }
}

void maiuscole(char source[], int dim, char destination[], int index, int dim_dest){
  // MR: dim_dest non e' passato per riferimento!
    char car;
    if (index < dim){
        if (source[index] >= 'A' && source[index] <='Z'){
            car = source[index];
            car = (car - 'A') + 'a';
            destination[dim_dest] = car;
	    // MR: Manca controllo che dim_dest sia minore di sua dim
	    // massima.
            cout << dim_dest << " " << destination[dim_dest] << endl;
            maiuscole(source, dim, destination, index + 1, dim_dest + 1);
        }else{
            maiuscole(source, dim, destination, index + 1, dim_dest);
        }
    }
}

void get_elements(char source[], int dim_source, char d1[], int dim_maxd1,int dim_d1, char d2[], int dim_maxd2, int dim_d2){
  // MR: dim_d2 e dim_d1 non sono passate per riferimento! Inutile
  // fare due chiamate ricorsive, si poteva fare con una sola gestendo
  // i due casi.
    minuscole(source, dim_source, 0 , d1, dim_d1);
    maiuscole(source, dim_source, d2, 0, dim_d2);
    // MR: Nn e' chiaro perche' le due funzioni hanno segnature
    // diverse... i.e. posizione dell'array che devono riempire.
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
