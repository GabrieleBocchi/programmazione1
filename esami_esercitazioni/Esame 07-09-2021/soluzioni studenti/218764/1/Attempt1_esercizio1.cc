// GDT: il codice non riporta il risultato corretto in alcuni casi di test.
// Vedi commenti nel codice

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char * argv [])
{
  const int MAX_PAROLA=200;

  if(argc!=3){
    cout << "Sono richiesti file input e output" << endl;
  }else{
    fstream input, output;
    input.open(argv[1],ios::in);
    output.open(argv[2],ios::out);

    if(input.fail() || output.fail()){
      input.close();
      output.close();
      cout << "Errore nell'apertura dei file" << endl;
    }else{

      char* buffer=new char[MAX_PAROLA];
      input >> buffer;

      if(buffer[0]>='a' && buffer[0]<='z'){
        buffer[0]+='A'-'a';
      }

      // GDT: manca inserire nell'output la prima parola
      // output << buffer << " ";

      while(input >> buffer){

        bool punteggiatura=false;

        for(int i=0;i<MAX_PAROLA;i++){
          if(buffer[i]==',' || buffer[i]=='.' || buffer[i]==';'){
            punteggiatura=true;
          }

          // GDT: se la parola ha già la lettera maiuscola, punteggiatura
          // non viene resettato a false, quindi causando modifiche a parole
          // successive.
          if(punteggiatura && buffer[i]>='a' && buffer[i]<='z'){
            buffer[i]-='A'-'a';
            punteggiatura=false;
          }

        }
      output << buffer << " ";

      }
      input.close();
      output.close();
      // GDT: manca la deallocazione di buffer
    }

  }
  return 0;
}
