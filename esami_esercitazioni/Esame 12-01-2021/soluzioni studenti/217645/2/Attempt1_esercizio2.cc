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

char convertInt(char num);
char convertChar(char letter);


void get_elements(char * source, int dimSource, char * arrayChar, int maxDimChar, int &dimChar,
 char * arrayInt, int maxDimInt, int &dimInt );

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

void get_elements(char * source, int dimSource, char * arrayChar, int maxDimChar, int &dimChar,
char * arrayInt, int maxDimInt, int &dimInt ){
  // MR: E' corretta, ma si poteva rendere tail recursive
  if(dimSource >= 0){
    if(source[dimSource] <= '9' && source[dimSource] >= '0'){
      get_elements(source, dimSource-1, arrayChar,maxDimChar, dimChar, arrayInt,maxDimInt,dimInt);
      if(dimInt < maxDimInt){
        arrayInt[dimInt] = convertInt(source[dimSource]);
        dimInt++;
      }

    }
    else if(source[dimSource] <= 'z' && source[dimSource] >= 'a'){
      get_elements(source, dimSource-1, arrayChar,maxDimChar, dimChar, arrayInt,maxDimInt,dimInt);
      if(dimChar < maxDimChar){
        arrayChar[dimChar] = convertChar(source[dimSource]);
        dimChar++;
      }
    }
    else{
      get_elements(source, dimSource-1, arrayChar,maxDimChar, dimChar, arrayInt,maxDimInt,dimInt);
      // MR: Non chiaro coding standard! e.g. spazi..
    }
  }
}

char convertInt(char num){
  // MR: Corretto, ma poteva essere fatta in modo più semplice, e.g. '9' - (num - '0');
  int result;
  if(num != '0'){
    result = num - (int)'1';
    // MR: Perchè cast di '1' e non di num? Entrambi sono char, o lo
    // si fa in entrambi i casi o non ha senso, anche se compilatore
    // non segnala errore!
    cout << result;
    // MR: La stampa non era richiesta!
    result = 7 - result;
  }
  else{
    result = 8;
  }

  return '1' + result;


}

char convertChar(char letter){

  int result = letter - 'a';

  cout << result;
  // MR: Stampa non richiesta!
  return result +  'A';
}
