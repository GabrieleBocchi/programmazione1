#include <iostream>
#include <cstddef>

using namespace std;

void print(const int a[], const int s, const char * prefix) {
  cout << prefix;
  for (int i = 0; i < s; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void read_elements(int s[], const int ms, int & s_s) {
  int r = 0;
  for (s_s = 0; ((s_s < ms) && (r != -1)); ) {
    cin >> r;
    if (r != -1) s[s_s++] = r;
  }
}

void get_elements(int s[], int s_s, int d1[], int md1_s, int &d1_s, int d2[], int md2_s, int &d2_s);
void get_elementsRic(int s[], int s_s, int indice_s, int d1[], int md1_s, int &d1_s, int indice1, int d2[], int md2_s, int &d2_s, int indice2);

int main() {
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
  get_elementsRic(s, s_s, 0, d1, md1_s, d1_s, 0, d2, md2_s, d2_s, 0);
}

void get_elementsRic(int s[], int s_s, int indice_s, int d1[], int md1_s, int &d1_s, int indice1, int d2[], int md2_s, int &d2_s, int indice2)
{
 if(indice_s < s_s)
    {
      if((indice_s == 0 || (indice_s%2)==0) && (s[indice_s]%3) == 0)
	{
	  // MR: Manca controllo che indice1 < md1_s, inoltre non
	  // chiaro perche' non usare direttamente d1_s.
	  d1[indice1] = s[indice_s];
	  d1_s++;
	  // La denotazione di indice_s++ corrisponde a indice_s prima
	  // di incremento! Similmente per indice1++. Quindi entra in
	  // loop infinito!
	  get_elementsRic(s, s_s, indice_s++, d1, md1_s, d1_s, indice1++, d2, md2_s, d2_s, indice2);
	}
      else
	{
	  // MR: Manca controllo che indice2 < md2_s, inoltre non
	  // chiaro perche' non usare direttamente d2_s.
	  d2[indice2] = s[indice_s];
	  d2_s++;
	  // La denotazione di indice_s++ corrisponde a indice_s prima
	  // di incremento! Similmente per indice2++. Quindi entra in
	  // loop infinito!
	  get_elementsRic(s, s_s, indice_s++, d1, md1_s, d1_s, indice1, d2, md2_s, d2_s, indice2++);
	}
    }
}
