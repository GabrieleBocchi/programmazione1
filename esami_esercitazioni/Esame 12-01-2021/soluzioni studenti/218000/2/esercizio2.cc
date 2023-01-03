#include <iostream>
#include <cstddef>

using namespace std;

void print(const char a[], const int s, const char * prefix) {
  cout << prefix;
  for (int i = 0; i < s; i++) {
    cout << (char) a[i] << " ";
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

void get_elements(char source[], int dimS, char dest1[], int maxD1, int clcD1, char dest2[], int maxD2, int clcD2)
// MR: clcD1 e clcD2 non sono passati per riferimento, quindi non sono
// propagati al chiamante, come invece richiesto dal testo.
{
  bool found = false;
  // MR: Questa variabile sembr ainutile.
  if((source[dimS] <= 'z') && (source[dimS] >= 'a'))
    //MR: Sta scorrendo l'array source in modo inverso, quindi i
    //caratteri in dest1 e dest2 vengono inseriti nel modo sbagliato
    //rispetto a quello richiesto. Inoltre, alla prima chiamata sta
    //accedendo a una posizione dell'array scorretta. Gli indici di un
    //array di dimS elementi vanno da 0 a dimS - 1. Inoltre,
    //nell'ultima chiamata, dimS e' -1, e quindi ancora peggio!
    {
      if(clcD1 < maxD1)
	{
	  dest1[clcD1] = (source[dimS] - 'a') + 'A';
	  get_elements(source, dimS-1, dest1, maxD1, clcD1 + 1, dest2, maxD2, clcD2);
	  found = true;
	}
    }
  else if((source[dimS] <= '9') && (source[dimS] >= '0'))
    {
      if(clcD2 < maxD2)
	{
	  dest2[clcD2] = '9' - source[dimS];
	  // MR: Questo non è sufficiente, manca
	  // aggiunta di '0': '9' - (source[i] - '0');
	  get_elements(source, dimS-1, dest1, maxD1, clcD1, dest2, maxD2, clcD2 + 1);
	  found = true;
	}
    }

  if((!(clcD1 < maxD1) && !(clcD2 < maxD2)) || dimS < 0)
    {
      found = true;
    }

  if(!found)
    {
      get_elements(source, dimS-1, dest1, maxD1, clcD1, dest2, maxD2, clcD2);
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
