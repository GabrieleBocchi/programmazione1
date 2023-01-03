#include <iostream>
#include <cstddef>

using namespace std;

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

void get_elements(char s[], int s_s, char d1[], const int md1_s, int &d1_s, char d2[], const int md2_s, int &d2_s)
{
  char c;
  if (s_s > d1_s + d2_s)
    // MR: Non e' una condizione corretta di uscita!
  {
    cout << (d1_s + d2_s) << endl;
    cout << "d1_s: " << d1_s << endl;
    cout << "d2_s: " << d2_s << endl;
    // MR: Stampe non richieste
    int i = (d1_s + d2_s);
    // MR: Non funziona perche' se ci sono caratteri diversi da
    // A,a-Z,z come primo elemento di s, non incrementa e quindi non
    // calcola quello che dovrebbe. Inoltre, mancano controlli sul
    // fatto che i sia >=0...
    c = s[i];
    if (c >= 'a' && c <= 'z')
    {
      if ('a' < 'A')
        d1[d1_s] = 'A' + c;
      // MR: Non chiaro a cosa serva!!!
      else
        d1[d1_s] = 'A' + c - 'a';
      // MR: Perche'logica diversa da quella sotto per maiuscole?
      d1_s++;
      // MR: Mancano controlli che d1_s sia minore di md1_s
    }
    else if (c >= 'A' && c <= 'Z')
    {
      d2[d2_s] = c - 'A' + 'a';
      d2_s++;
      // MR: Mancano controlli che d2_s sia minore di md2_s
      // MR: Perche'logica diversa da quella sopra per minuscole?
    }
    else
    {
      s_s -= 1;
      // MR: Non chiara la logica!
    }
    get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);
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

  cout << "s: " << s << endl
       << "ms: " << ms << endl
       << "s_s: " << s_s << endl;

  get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);

  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");
  return 0;
}
