// Giovanni: il programma ritorna risultato errato su alcuni casi di test.
// Fare riferimento alla soluzione ufficiale per un possibile svolgimento.
// Vedere commenti nel codice.

#include <iostream>
#include <fstream>
using namespace std;

const int MAXCHAR = 100;
int lunghezza(char parola[]);
int contI(char parola[]);

int main(int argc, char * argv [])
{
  if(argc != 3){
    cout<<"errore passaggio dei parametri, utilizzare ./a.out inputfile outputfile";
    exit(0);
  }else{
    fstream in, out;
    in.open(argv[1], ios::in);
    out.open(argv[2], ios::out);
    if(in.fail()){
      cout<<"errore nell'apertura del file in input";
      exit(0);
    }else{
      char parola[100];
      int len, numeroI;
      bool corretta = true;
      while(in>>parola){
        len = lunghezza(parola);
        if(parola[0] == 'M' && parola[len-1] == 'U'){
          numeroI = contI(parola);
          if((numeroI % 2 == 1) || (numeroI == 0)){
            for(int i = 0; i < len-1 && corretta; i++){
              if(parola[i] == 'I' && parola[i+1] == 'M'){
                corretta = false;
              }
            }
            // Giovanni: questo if dovrebbe essere fuori dai precedenti if.
            // Inoltre, la variable corretta non viene resettata ad ogni iterazione.
            // Quindi, se una parola non è valida, anche tutte le altre verrano
            // considerate come non valide.
            if(corretta){
              out<<parola<<endl;
            }
          }
        }
      }
    }
    in.close();
    out.close();
  }
  return 0;
}

int lunghezza(char parola[]){
  int lun = 0;
  while(parola[lun] != '\0'){
    lun++;
  }
  return lun;
}

int contI(char parola[]){
  int cont = 0;
  for(int i = 0; parola[i] != '\0'; i++){
    if(parola[i] == 'I'){
      cont++;
    }
  }
  return cont;
}
