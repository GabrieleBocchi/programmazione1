#include <iostream>
#include <cstddef>

using namespace std;

const int DIFF = 'a' - 'A';

void convert_num (char & n)
{
  // MR: Più efficiente se fatto come '9' - (n - '0');
  switch (n)
  {
    case '0': n = '9'; break;
    case '1': n = '8'; break;
    case '2': n = '7'; break;
    case '3': n = '6'; break;
    case '4': n = '5'; break;
    case '5': n = '4'; break;
    case '6': n = '3'; break;
    case '7': n = '2'; break;
    case '8': n = '1'; break;
    case '9': n = '0';
  }
}

void toupper (char & c)
{
  c -= DIFF;
}

void get_elements(const char src[], const int & src_dim, char dest1[], const int & dest1_mdim, int & dest1_dim, char dest2[], const int & dest2_mdim, int & dest2_dim, int i=0)
{
  if (i<src_dim)
  {
    if (src[i] >= 'a' && src[i] <= 'z')
    {
      if (dest1_dim >= dest1_mdim)
      {
        cout << "Array dest1 pieno!\n";
      }

      else
      {
        dest1[dest1_dim] = src[i];
        toupper (dest1[dest1_dim]);
        dest1_dim++;
      }
    }

    else if (src[i] >= '0' && src[i] <= '9')
    {
      if (dest2_dim >= dest2_mdim)
      {
        cout << "Array dest2 pieno!\n"; //I due controlli per gli array dest1 e dest2 sono inutili (stesso maxdim di array source) ma inserisco comunque per completezza
      }

      else
      {
        dest2[dest2_dim] = src[i];
        convert_num (dest2[dest2_dim]);
        dest2_dim++;
      }
    }

    get_elements (src, src_dim, dest1, dest1_mdim, dest1_dim,  dest2,  dest2_mdim, dest2_dim, i+1);
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
