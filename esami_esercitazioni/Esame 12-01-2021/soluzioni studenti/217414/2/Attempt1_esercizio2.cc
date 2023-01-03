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

void get_elements(int s[], int s_s, int d1[], int md1_s, int &d1_s, int d2[], int md2_s, int &d2_s);
void get_elements_ric(int s[], int s_s, int d1[], int md1_s, int &d1_s, int d2[], int md2_s, int &d2_s, int i);

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

void get_elements(int s[], int s_s, int d1[], int md1_s, int &d1_s, int d2[], int md2_s, int &d2_s)
{
  get_elements_ric(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, 0);
}

void get_elements_ric(int s[], int s_s, int d1[], int md1_s, int &d1_s, int d2[], int md2_s, int &d2_s, int i)
{
  if (i < s_s && i < md1_s && i < md2_s)
  {
    if (i % 2 == 0 && i % 3 == 0)
      // MR: Qui era da considerare s[i] % 3 == 0 non i % 3 ==
      // 0. Consiglio di leggere bene il testo e/o in dubbio chiedere
      // chiarimenti. Se lo prova anche su esempio del testo, vede che
      // l'output che ottiene e' diverso, quindi doveva essere ovvio
      // che c'era qualcosa che non andava. Peccato, perche' resto dei
      // controlli era corretto.
    {
      d1[d1_s] = s[i];
      d1_s++;
    }
    else
    {
      d2[d2_s] = s[i];
      d2_s++;
    }
    i++;
    get_elements_ric(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, i);
  }
}
