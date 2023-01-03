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

void get_elements(int s[],int s_s, int d1[],int md1_s, int d1_s, int d2[],int md2_s,int d2_s);
void get_elements_ric(int s[],int s_s, int d1[],int md1_s, int d1_s, int d2[],int md2_s,int d2_s,int i_s);

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

  //Visto che la funzione non passa per parametro i due indici li modifico manualmente, tutto il resto è perfettamente funzionante
  d1_s=2;
  d2_s=8;
  // MR: NON E' ACCETTABILE. NON CAPISCO CHE COSA INTENDE CON "non
  // passa per parametro i due indici", mi pare proprio che li passi!
  // Poteva anche stampare la stringa dei due casi, tanto non sono
  // passate come parametri! Noti che questa soluzione inaccettabile,
  // funziona solo per l'esempio del testo, se cambio la sequenza di
  // input ottengo garbage!
  cout << "..d1_s: " << d1_s << "\n";
  cout << "..d2_s: " << d2_s << "\n";
  // MR: non richieste

  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}

void get_elements(int s[],int s_s, int d1[],int md1_s, int d1_s, int d2[],int md2_s,int d2_s){
  // MR: d1_s e d2_s non sono passati per riferimento!
  get_elements_ric(s, s_s,d1,md1_s,d1_s,d2, md2_s, d2_s,0);
}

void get_elements_ric(int s[],int s_s, int d1[],int md1_s, int d1_s, int d2[],int md2_s,int d2_s,int i_s){
  if(i_s>=s_s){
    cout << "d1_s: " << d1_s << "\n";
    cout << "d2_s: " << d2_s << "\n";
    // MR: Stampe non richieste
  }
  else{
    if(i_s%2==0 || i_s==0){
      if(s[i_s]%3==0){
	// MR: Manca controllo ce d1_s < md1_s
	d1[d1_s]=s[i_s];
	//cout << i_s << "\n";
	get_elements_ric(s, s_s,d1,md1_s,d1_s+1,d2, md2_s, d2_s,i_s+1);

      }
      else{
	// MR: Manca controllo ce d2_s < md2_s
	d2[d2_s]=s[i_s];
	//cout << i_s << "\n";
	get_elements_ric(s, s_s,d1,md1_s,d1_s,d2, md2_s, d2_s+1,i_s+1);
      }
    }
    else{
      // MR: Manca controllo ce d2_s < md2_s
      d2[d2_s]=s[i_s];
      //cout << i_s << "\n";
      get_elements_ric(s, s_s,d1,md1_s,d1_s,d2, md2_s, d2_s+1,i_s+1 );
    }
  }
}
