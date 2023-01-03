#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(const char[], const int, char[], const int, int &, char[], const int, int &);
void get_elements_ric(const char[], const int, char[], const int, int &, char[], const int, int &, int);
bool isLower(const char);
bool isUpper(const char);
char toLower(char);
char toUpper(char);

void print(const char a[], const int s, const char *prefix)
{
  cout << prefix;
  for (int i = 0; i < s; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}

void read_elements(char s[], const int ms, int &s_s)
{
  char r = '\0';
  for (s_s = 0; ((s_s < ms) && (r != '\n'));)
  {
    r = cin.get();
    if ((r != '\n') && (r != ' '))
      s[s_s++] = r;
  }
}

int main()
{
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

void get_elements(const char src[], const int dim_src, char dest1[], const int maxdim_dest1, int &dim_dest1, char dest2[], const int maxdim_dest2, int &dim_dest2)
{
  get_elements_ric(src, dim_src, dest1, maxdim_dest1, dim_dest1, dest2, maxdim_dest2, dim_dest2, 0);
}

void get_elements_ric(const char src[], const int dim_src, char dest1[], const int maxdim_dest1, int &dim_dest1, char dest2[], const int maxdim_dest2, int &dim_dest2, int i)
{
  if ((i >= dim_src) || (dim_dest1 >= maxdim_dest1 && dim_dest2 >= maxdim_dest2))
    return;

  if (isLower(src[i]) && dim_dest1 < maxdim_dest1)
  {
    dest1[dim_dest1] = toUpper(src[i]);
    dim_dest1++;
  }
  else if (isUpper(src[i]) && dim_dest2 < maxdim_dest2)
  {
    dest2[dim_dest2] = toLower(src[i]);
    dim_dest2++;
  }

  get_elements_ric(src, dim_src, dest1, maxdim_dest1, dim_dest1, dest2, maxdim_dest2, dim_dest2, i + 1);
}

bool isLower(const char letter)
{
  return (letter >= 'a' && letter <= 'z');
}

bool isUpper(const char letter)
{
  return (letter >= 'A' && letter <= 'Z');
}

char toLower(char letter)
{
  if (isUpper(letter))
    letter = 'a' + (letter - 'A');

  return letter;
}

char toUpper(char letter)
{
  if (isLower(letter))
    letter = 'A' + (letter - 'a');

  return letter;
}
