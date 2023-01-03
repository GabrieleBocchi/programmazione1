#include <iostream>
#include <cstddef>

using namespace std;

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

void to_upper_case (char & c){
  c += 'A' - 'a';
}
void to_lower_case (char & c){
  c += 'a' - 'A';
}
void get_elements_ric(int INDEX, char * s, int & s_s, char * d1, const int md1_s, int & d1_s, char * d2, const int md2_s, int & d2_s){
  // MR: Non chiaro a cosa serva s_s e perche' sia passato per
  // riferimento. Inoltre, mancano controlli che d1_s e d2_s siano
  // minori stretti della dimensione massima di d1 e d2.
  if(INDEX < md1_s){
    // MR: Qui errato dovrebbe confrontare INDEX con s_s, ma siccome
    // lo incrementa ad ogni chiamata sarebbe stato peggio. Qui sta
    // erroneamente assumendo che tutti gli array hanno stessa
    // dimensione (nell'esempio di main e' cosi, ma non era scritto
    // nel testo, e quindi non poteva assumerlo. Se fosse stato cosi',
    // avrei passato un solo argomento!
    if(s[INDEX] >= 'a' && s[INDEX] <= 'z'){
      d1[d1_s] = s[INDEX];
      to_upper_case(d1[d1_s]);

      d1_s++;
      s_s++;
    }
    else if (s[INDEX] >= 'A' && s[INDEX] <= 'Z'){
      d2[d2_s] = s[INDEX];
      to_lower_case(d2[d2_s]);

      d2_s++;
      s_s++;
    }

    get_elements_ric(INDEX+1, s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);
  }
}

void get_elements(char * s, int & s_s, char * d1, const int md1_s, int & d1_s, char * d2, const int md2_s, int & d2_s){
  // MR: Non era richiesto che s_s fosse modificato. Inoltre,
  // modificandolo crea problemi alle altre funzioni chiamate nel main
  // che usano s_s per tenere in conto della dimensione di s, e che
  // quindi a causa di suo errore accedono a memoria spuria!
  get_elements_ric(0, s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);
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
