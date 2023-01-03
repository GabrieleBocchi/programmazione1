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

void get_elements (int s[], const int ms, int dest1[], const int md1, int& dim1, int dest2[], const int md2, int& dim2, int i, int p, int d )
{
	if ( i < ms )
	{
	    if ( i%3 == 0 && s[i]%2 == 0 && dim1 <= md1)
	       {
             dest1[p]=2*s[i];
	         dim1++;
		     p++;
	       }
	    else if ( dim2 <= md2 )
	       {
		     dest2[d]=3*s[i];
		     dim2++;
		     d++;
	       }
	    i++;
	    get_elements ( s, ms, dest1, md1, dim1, dest2, md2, dim2, i, p, d );
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

  get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, 0);
  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}
