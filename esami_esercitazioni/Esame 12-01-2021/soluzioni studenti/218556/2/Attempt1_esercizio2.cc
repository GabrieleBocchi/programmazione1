#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(int s[], int s_dim, int *dest1, int maxDest1, int &dimDest1, int *dest2, int maxDest2, int &dimDest2);

void print(const int a[], const int s, const char *prefix)
{
  cout << prefix;
  for (int i = 0; i < s; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}

void read_elements(int s[], const int ms, int &s_s)
{
  int r = 0;
  for (s_s = 0; ((s_s < ms) && (r != -1));)
  {
    cin >> r;
    if (r != -1)
      s[s_s++] = r;
  }
}

void get_elements(int s[], int s_dim, int *dest1, int maxDest1, int &dimDest1, int *dest2, int maxDest2, int &dimDest2)
{
  int i = dimDest1 + dimDest2;

  // MR: Manca controllo che i sia < s_dim infatti da nessuna parte e'
  // scritto che dimDest2 e dimDest1 sono a 0 inizialmente!
  if (s[i] % 3 == 0 && i % 2 == 0)
  {
    // MR: Manca controllo che dimDest1 < maxDest1
    dest1[dimDest1] = s[i];
    cout << dest1[dimDest1] << endl;
    dimDest1++;
  }
  else
  {
    // MR: Manca controllo che dimDest2 < maxDest2
    dest2[dimDest2] = s[i];
    dimDest2++;
  }

  if (s_dim > i + 1)
    // MR: La condizione fa all'inizio non qui per evitare accedere
    // memoria erronea!
  {
    get_elements(s, s_dim, dest1, maxDest1, dimDest1, dest2, maxDest2, dimDest2);
  }
}

int main()
{
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
