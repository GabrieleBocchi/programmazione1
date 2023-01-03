#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(int s[],int s_s,int d1[],int md1_s,int d1_s,int d2[],int md2_s,int d2_s);

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


void get_elements(int s[],int s_s,int d1[],int md1_s,int d1_s,int d2[],int md2_s,int d2_s)
{
  int dimMax=s_s;
  int numero;
  int dimAttuale1;
  int dimAttuale2;


  int n=s[dimMax]%2;

  if(n==0 && s[dimMax]%3==0)
	{
	  numero=s[s_s]*2;
	  d1[s_s]=numero;
	  cout<<d1[s_s]<<" ";
	}
  else
	{
	  numero=s[s_s]*3;
	  d2[s_s]=numero;
	  cout<<d2[s_s]<<" ";
	}

  // MR: NON ACCETTABILE. L'esercizio richiedeva "Scrivere nel file
  // esercizio2.cc la dichiarazione e la definizione della funzione
  // ricorsiva get_elements che..." e nel terzo punto della nota "La
  // funzione get_elements deve essere ricorsiva ed al suo interno non
  // ci possono essere cicli o chiamate a funzioni contenenti
  // cicli. Si può però fare uso di eventuali funzioni ricorsive
  // ausiliarie all’interno di questa funzione.". Consiglio di leggere
  // con attenzione TUTTO il testo!
  do
	{
	  get_elements(s,--s_s,d1,++md1_s,d1_s,d2,++md2_s,d2_s);
	}while(s_s!=(dimMax-1));


  dimAttuale1=10-md1_s;
  dimAttuale2=10-md2_s;

  cout<<"\nla dimensione del vettore 1 e': "<<dimAttuale1<<endl;
  cout<<"\nla dimensione del vettore 2 e': "<<dimAttuale2<<endl;

}
