#include <iostream>
#include <cstddef>

using namespace std;

void rec(int s[], int s_s, int d1[], int md1_s, int d1_s, int d2[], int md2_s, int d2_s, int pos, int index1, int index2, int start)
{
  if (start < s_s)
  {
    if (pos % 3 == 0)
      // MR: Qui condizione e' sbagliata. pos%3 && s[start] % 2 == 0,
      // deve essere indice multiplo di 3 e con valore pari!
    {
      // MR: Manca controllo che index1 < md1_s
      d1[index1] = 2 * s[pos];
      index1++;
      d1_s++;
    }
    else if ((s[start] % 2) != 0)
    {
      // MR: Manca controllo che index2 < md2_s
      d2[index2] = 3 * s[pos];
      index2++;
      d2_s++;
    }

    rec(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, pos + 1, index1, index2, start + 1);
  }
}

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

void get_elements(int s[], int s_s, int d1[], int md1_s, int d1_s, int d2[], int md2_s, int d2_s)
{
  rec(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, 0, 0, 0, 0);
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
