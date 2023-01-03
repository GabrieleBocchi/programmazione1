// COMMENTI: all'interno del testo.

#include <iostream>
#include <fstream>

using namespace std;


int getLenght(char * s){
    int i =0;
  for( i = 0;s[i]!='\0';i++){

  }

    return i;

}

void copystr(char * s , const char * originale){
  for(int i= 0;originale[i]!='\0';i++){
    s[i] = originale[i];
  }
  //cout << originale originale << endl;
}


int main(int argc, char * argv [])
{
  fstream file;
  char s[100];
  char parole[100][100];
  file.open("input_A", ios::in);

  // Mancano:
  // - Controllo degli argomenti del programma argc (in genere non li usi)
  // - Apertura file di output
  // - Le dimensioni del tuo array parole dovrebbero essere [10000][101]
  //   Il codice va in segmentation fault se si prova a testarlo con file più
  //   grossi (attenzione a leggere la consegna dell'esercizio)
  // - Controllo dei file con input.fail()

  int i = 0;

  while(!file.eof()){
      file >> s;

      if(getLenght(s)%2 == 0){
          copystr(parole[i],s);
          // Bisogna aggiungere '\0' alla fine della stringa e non uno spazio
          * parole[i+1] = ' ';

      }

      i++;
  }

  // Le parole non vengono salvate nel file di output
  while(i>=0){
    if(parole[i] != "\0")
      cout <<  parole[i]  << endl;
    i--;
  }

  // Non c'è deallocazione ne chiusura degli stream
  return 0;
}
