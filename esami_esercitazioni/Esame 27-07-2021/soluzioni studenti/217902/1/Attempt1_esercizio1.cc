#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool controllo(char stringa[]);

int main(int argc, char * argv []){
  if(argc != 3){
    cout<<"passaggio parametri errato, utilizza ./a.out inputfile outputfile";
    exit(0);
  }else{
    fstream in, out;
    in.open(argv[1], ios::in);
    out.open(argv[2], ios::out);
    if(in.fail() || out.fail()){
      cout<<"errore nell'apertura dei file";
      in.close();
      out.close();
      exit(0);
    }else{
      int len = 19, lenParola;
      char stringa[101];
      bool corretta;
      int contatore = 0;
      while(!in.eof()){
        in>>stringa;
        lenParola = strlen(stringa);
        if(lenParola == len){
          corretta = controllo(stringa);
          if(corretta == true){
            contatore++;
          }
        }
      }
      in.close();
      out<<contatore;
      out.close();
    }
  }
  return 0;
}

bool controllo(char stringa[]){
  bool corretta = true;

  for(int i = 0; i < 4 && corretta; i++){
    if(stringa[i] < '0' || stringa[i] > '9'){
      corretta = false;
    }
  }
  for(int i = 5; i < 9 && corretta; i++){
    if(stringa[i] < '0' || stringa[i] > '9'){
      corretta = false;
    }
  }
  for(int i = 10; i < 14 && corretta; i++){
    if(stringa[i] < '0' || stringa[i] > '9'){
      corretta = false;
    }
  }
  for(int i = 15; i < 19 && corretta; i++){
    if(stringa[i] < '0' || stringa[i] > '9'){
      corretta = false;
    }
  }
  if(stringa[4] != '-' || stringa[9] != '-' || stringa[14] != '-'){
    corretta = false;
  }
  return corretta;
}
