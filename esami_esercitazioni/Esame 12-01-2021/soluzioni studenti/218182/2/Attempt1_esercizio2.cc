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

void get_dispari(int s[], int s_s, int d1[], int &d1_s, int d2[], int &d2_s, int &pos);

void get_pari(int s[], int s_s, int d1[], int &d1_s, int d2[], int &d2_s, int &pos);

void get_elements(int s[], int s_s, int d1[], int md1_s, int &d1_s, int d2[], int md2_s, int &d2_s);

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

void get_elements(int s[], int s_s, int d1[], int md1_s, int &d1_s, int d2[], int md2_s, int &d2_s)
{
  int pos=0;
  get_pari(s, s_s, d1, d1_s, d2, d2_s, pos);
}

void get_pari(int s[], int s_s, int d1[], int &d1_s, int d2[], int &d2_s, int &pos)
// MR: Non chiaro perche' ultimo elemento passato per
// riferimento. Questa soluzione benche' corretta (in parte) poteva
// essere risolta senza ricorrere a mutua ricorsione.
{
  if (pos<s_s)
    {
      if (s[pos]%3==0)
	{
	  // MR: Nessun cotrollo che d1_s sia < della sua max dim!
	  d1[d1_s]=s[pos];
	  d1_s++;
	}
      else
	{
	  // MR: Nessun cotrollo che d2_s sia < della sua max dim!
	  d2[d2_s]=s[pos];
	  d2_s++;
	}
      pos++;
      get_dispari(s, s_s, d1, d1_s, d2, d2_s, pos);
    }
}

void get_dispari(int s[], int s_s, int d1[], int &d1_s, int d2[], int &d2_s, int &pos)
{
// MR: Non chiaro perche' ultimo elemento passato per
// riferimento.
  if (pos<s_s)
    {
      // MR: Nessun cotrollo che d2_s sia < della sua max dim!
      d2[d2_s]=s[pos];
      d2_s++;
      pos++;
      get_pari(s, s_s, d1, d1_s, d2, d2_s, pos);
    }
}
