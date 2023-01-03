#include <iostream>
#include <cstddef>

using namespace std;
int convertidest1(char source[], int dimsource, char dest1[], int i, int j, int maxd1, int ret);
int convertidest2(char source[], int dimsource, char dest2[], int i, int j, int maxd2_s, int ret);

void get_elements(char source[], int dimsource, char dest1[],
		  int maxd1, int dest1_calcola, char dest2[], int maxd2_s, int dest2_calcola)
// MR: dest1_calcola e dest2_calcola non sono passati per riferimento!
{
  int i = 0;
  int j = 0;
  cout << "prova";
  // MR: Stampa non richiesta
  dest1_calcola = convertidest1(source, dimsource, dest1, i, j, maxd1, 1);
  i = j = 0;
  dest2_calcola = convertidest2(source, dimsource, dest2, i, j, maxd2_s, 1);
}

int convertidest1(char source[], int dimsource, char dest1[], int i, int j, int maxd1, int ret)
{
  if((j < dimsource) || (j > maxd1))
    // MR: Se j > maxd1 possibile accedere a memoria non del programma.
    {
      if(source[i] >= 'a' && source[i] <= 'z')
	{
	  int add = 'A'-'a';
	  dest1[i] = source[i] + add;
	  i++;
	}
      j++;
      return ret + convertidest1(source, dimsource, dest1, i, j, maxd1, ret);
    }
  else
    {
      return ret;
    }
  // MR: Questa funzione ritorna sempre dimsource + 1
}

int convertidest2(char source[], int dimsource, char dest2[], int i, int j, int maxd2_s, int ret)
{
  if((j < dimsource) || (j > maxd2_s))
    {
      if(source[i] >= 'A' && source[i] <= 'Z')
	{
	  int add = 'A'-'a';
	  dest2[i] = source[i] - add;
	  i++;
	}
      j++;
      return ret + convertidest1(source, dimsource, dest2, i, j, maxd2_s, ret);
    }
  else
    {
      return ret;
      // MR: Questa funzione ritorna sempre dimsource + 1
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
