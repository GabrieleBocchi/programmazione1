#include <iostream>
#include <cstddef>

using namespace std;

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

void get_elements(int s[], int &dim_s, int dest1[], int dim_Max_dest1, int &dim_dest1, int dest2[], int dim_Max_dest2, int &dim_dest2);
void CreaArray(int i_s, int s[], int &dim_s, int dest1[], int dim_Max_dest1, int &dim_dest1, int dest2[], int dim_Max_dest2, int &dim_dest2);

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

void get_elements(int s[], int &dim_s, int dest1[], int dim_Max_dest1, int &dim_dest1, int dest2[], int dim_Max_dest2, int &dim_dest2)
{
  CreaArray(0, s, dim_s, dest1, dim_Max_dest1, dim_dest1, dest2, dim_Max_dest2, dim_dest2);
}

void CreaArray(int i_s, int s[], int &dim_s, int dest1[], int dim_Max_dest1, int &dim_dest1, int dest2[], int dim_Max_dest2, int &dim_dest2)
{
  if (i_s < dim_s)
  {
    if (i_s % 2 == 0 && s[i_s] % 3 == 0)
    {
      if (dim_dest1 < dim_Max_dest1)
      {
        dest1[dim_dest1] = s[i_s];
        dim_dest1++;
      }
    }
    else
    {
      if (dim_dest2 < dim_Max_dest2)
      {
        dest2[dim_dest2] = s[i_s];
        dim_dest2++;
      }
    }
    i_s++;
    CreaArray(i_s, s, dim_s, dest1, dim_Max_dest1, dim_dest1, dest2, dim_Max_dest2, dim_dest2);
  }
}