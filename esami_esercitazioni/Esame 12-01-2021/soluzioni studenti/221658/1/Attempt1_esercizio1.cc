// GDT: attenzione che nella funzione copyString ti dimentichi // di aggiungere il terminatore '\0' una volta terminata la copia
// della stringa. Una stringa per essere valida necessita del terminatore! 

#include <iostream>
#include <fstream>
using namespace std;

void copyString(char [], char [][101], int);
int len(char []);

int main(int argc, char * argv [])
{

  const int MAXSIZE = 100;
  char buffer [MAXSIZE + 1];
  char parole [10000][MAXSIZE + 1];


  if(argc != 3){
    cout << "Usage: <inputFile> <outputFile>" << endl;
    exit(0);
  }

  fstream in, out;
  in.open(argv[1], ios::in);

  if(in.fail()){
    cout << "Errore in apertura del file" << endl;
    exit(0);
  }

  in >> buffer;
  int index = 0;
  int length;
  int nParole = 0;

  while(!in.eof()){
    length = len(buffer);

    if(length % 2 == 0){

      copyString(buffer, parole, index);
      nParole ++;
      index ++;
    }
    in >> buffer;
  }

  in.close();

  out.open(argv[2], ios::app);

  if(out.fail()){
    cout << "Errore creazione file di output!" << endl;
    exit(0);
  }

  for(int j = nParole - 1; j >= 0; j--){
    out << parole[j] << " ";
  }

  out.close();

  return 0;
}

void copyString(char stringa[], char parole[][101], int index){
  
  int i = 0;
  char c = stringa[i];

  while(c != '\0'){
    parole[index][i] = c;
    i++;
    c = stringa[i];
  }
}

int len(char parola []){

  int length = 0;
  int i = 0; 
  char c = parola[i];

  while(c != '\0'){
    length ++;
    i ++;
    c = parola[i];
  }

  return length;
}
