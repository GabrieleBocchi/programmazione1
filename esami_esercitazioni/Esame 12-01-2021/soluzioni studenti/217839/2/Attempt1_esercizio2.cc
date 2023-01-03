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

void get_elements(int array_source[],const int dim_source,int array_dest1[],int dim_dest1_max,int & dim_dest1,int array_dest2[],const int dim_dest2_max,int & dim_dest2);
void get_elements_rec(int array_source[],const int dim_source,int array_dest1[],int dim_dest1_max,int & dim_dest1,int array_dest2[],const int dim_dest2_max,int & dim_dest2,int pos);

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

void get_elements(int array_source[],const int dim_source,int array_dest1[],int dim_dest1_max,int & dim_dest1,int array_dest2[],const int dim_dest2_max,int & dim_dest2){
    get_elements_rec(array_source, dim_source, array_dest1, dim_dest1_max, dim_dest1, array_dest2, dim_dest2_max, dim_dest2,0);
}

void get_elements_rec(int array_source[],const int dim_source,int array_dest1[],int dim_dest1_max,int & dim_dest1,int array_dest2[],const int dim_dest2_max,int & dim_dest2,int pos){
    if(dim_source>pos){
        cout << "Posizione: " << pos+1 << " - Valore: " << array_source[pos] << endl;
	// MR: Stampe non richieste
        if((pos+1)%3==0 && (pos+1)>=3 && array_source[pos]%2==0){
	  // MR: Non capisco perchè c'e' +1,
            cout << "Valore In D1" << endl;
	// MR: Stampe non richieste
	    // MR: Manca controllo che dim_dest1 < dim_dest1_max
            array_dest1[dim_dest1]=(array_source[pos]*2);
            dim_dest1++;
        }else{
            cout << "Valore In D2" << endl;
	// MR: Stampe non richieste
	    // MR: Manca controllo che dim_dest2 < dim_dest2_max
            array_dest2[dim_dest2]=(array_source[pos]*3);
            dim_dest2++;
        }
        pos++;
        get_elements_rec(array_source, dim_source, array_dest1, dim_dest1_max, dim_dest1, array_dest2, dim_dest2_max, dim_dest2,pos);
    }
    return;
}
