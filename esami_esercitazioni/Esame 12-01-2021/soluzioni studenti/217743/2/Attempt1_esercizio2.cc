#include <iostream>
#include <cstddef>

using namespace std;

char num(char &num)
// MR: Perchè passaggio per riferimento? Poteva essere fatta in modo
// più efficiente con '9' - (num - '0');
{
  // MR: Che cosa ritorna se num non e' carattere numerico? res e' non
  // inizializzato.
  char res;
  if (num == '0')
  {
    res = '9';
  }
  else if (num == '1')
  {
    res = '8';
  }
  else if (num == '2')
  {
    res = '7';
  }
  else if (num == '3')
  {
    res = '6';
  }

  else if (num == '4')
  {
    res = '5';
  }
  else if (num == '5')
  {
    res = '4';
  }
  else if (num == '6')
  {
    res = '3';
  }

  else if (num == '7')
  {
    res = '2';
  }

  else if (num == '8')
  {
    res = '1';
  }

  else if (num == '9')
  {
    res = '0';
  }
  return res;
}

void get_elements1(int i, char source[], int dimS, char dest1[], int dimMax1, int &d1s, char dest2[], int dimMax2, int &d2s);

char upper(char a)
{
  a = a - 'a' + 'A';
  return a;
}

void get_elements(char source[], int dimS, char dest1[], int dimMax1, int &d1s, char dest2[], int dimMax2, int &d2s)
{
  d1s = 0;
  d2s = 0;
  get_elements1(0, source, dimS, dest1, dimMax1, d1s, dest2, dimMax2, d2s);
}

void get_elements1(int i, char source[], int dimS, char dest1[], int dimMax1, int &d1s, char dest2[], int dimMax2, int &d2s)
{

  if (i >= dimS)
  {
    return;
  }
  else
  {
    if ('a' <= source[i] && source[i] <= 'z')
    {
      dest1[d1s] = upper(source[i]);
      d1s += 1;
      get_elements1(i + 1, source, dimS, dest1, dimMax1, d1s, dest2, dimMax2, d2s);
    }
    else if (source[i] >= '0' && source[i] <= '9')
    {
      dest2[d2s] = num(source[i]);
      d2s += 1;
      get_elements1(i + 1, source, dimS, dest1, dimMax1, d1s, dest2, dimMax2, d2s);
    }
    // MR: Cosa succede se metto un carattere di punteggiatura? La
    // specifica dice di ignorarlo, ma in questo modo lei ignora tutto
    // quello che segue, e quindi la soluzione non è completamente
    // corretta.
  }
}

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
