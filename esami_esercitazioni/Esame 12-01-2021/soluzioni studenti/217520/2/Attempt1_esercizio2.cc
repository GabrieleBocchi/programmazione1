#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(int *s, int s_s, int *d1, int md1_s, int &d1_s, int *d2, int md2_s, int &d2_s);

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

  //array degli elementi pari in posizioni multiple di 3
  const int md1_s = maxdim;
  int d1[md1_s];
  int d1_s = 0;

  //array con gli altri elementi
  const int md2_s = maxdim;
  int d2[md2_s];
  int d2_s = 0;

  //array iniziale
  const int ms = maxdim;
  int s[ms];
  int s_s = 0;

  read_elements(s, ms, s_s);

  //passo array, la sua dimensione massima, l'indice
  get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);

  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}

void get_elements(int *s, int s_s, int *d1, int md1_s, int &d1_s, int *d2, int md2_s, int &d2_s){

  //chiusura della funzione
  if(s_s == md1_s || s_s == md2_s){
    // MR: Errato, qui avrebbe potuto usare s_s >= d1_s + d2_s, cosi'
    // come scritto da lei non ha senso! Tenga poi conto che lei
    // incrementa s_s, che e' la dimensione dell'array s!
    return;
  }

  //se indice dell'array è multiplo di 3
  else if(s_s % 3 == 0){
    //controllo che il numero dentro sia pari

    // MR: Qui sta accedendo a s[s_s], ma gli indici degli array vanno
    // da 0 a s_s-1, e s_s e'la dimensione dell'array che non deve
    // essere cambiata, a meno che non si facciano operazioni
    // particolari per sfruttarlo nella ricorsione (Cosa che lei non
    // sta facendo)
    if(s[s_s] % 2 == 0){
      //memorizzo in d1 e incremento dimensione
      // MR: Manca controllo che d1_s < md1_s
      d1[d1_s] = 2 * s[s_s];
      d1_s++;
    }
    // MR: Se incrementa s, sta andando fuori i bound dell'array!
    s_s++;
    get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);
  }
  //array d2
  else{
    // MR: Manca controllo che d2_s < md2_s
    d2[d2_s] = 3 * s[s_s];
    d2_s++;
    // MR: Se incrementa s, sta andando fuori i bound dell'array!
    s_s++;
    get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);
  }

}
