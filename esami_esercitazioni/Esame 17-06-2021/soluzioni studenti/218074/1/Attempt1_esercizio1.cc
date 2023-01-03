// Giovanni: il programma non ritorna risultati corretti in alcuni casi di test.
// Le condizioni di controllo non sono corrette. Vedi commenti nel codice.
// Fare riferimento alla soluzione ufficiale per un possibile svolgimento.

#include <iostream>
#include <fstream>
using namespace std;

bool inizia_per_m(char *);
bool ultima_lettera_u(char *);
int totale_i(char *);
bool condizione_1(bool, bool);
bool condizione_2(char*);
bool condizione_3(char*);
int main(int argc, char * argv []){
  if(argc!=3){
    cerr<<"Hai inserito un numero di argomenti errato!"<<endl;
    exit(1);
  }
  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);
  if(input.fail()){
    cerr<<"Errore nell'apertura del file input"<<endl;
    exit(1);
  }
  if(output.fail()){
    cerr<<"Errore nell'apertura del file output"<<endl;
    exit(1);
  }
  char parola[101];
  while(!input.eof()){
    input>>parola;
    //cout<<parola<<endl;
    bool miu=false;
    bool prima=inizia_per_m(parola);
    bool ultima=ultima_lettera_u(parola);
    if(condizione_1(prima, ultima)==true){
      if(condizione_2(parola)==true){
        if(condizione_3(parola)==true){
          miu=true;
        }
      }
    }

    if(miu==true){
      output<<parola<<" ";
    }
  }



  input.close();
  output.close();
  return 0;
}

bool inizia_per_m(char *parola){
  return parola[0]=='M';
}

int totale_i(char *parola){
  int conta_i=0;
  for(int i=0; parola[i]!='\0'; i++){
    if(parola[i]=='I'){
      conta_i++;
    }
  }
  return conta_i;
}

// Giovanni: qui stai controllando che esista almeno un carattere
// all'interno della parola che sia uguale a U. Dovresti solo
// controllare parola[i-1] == U (una volta terminato il ciclo).
bool ultima_lettera_u(char *parola){
  bool x=false;
  int i=0;
  for(; parola[i]!='\0'; i++)
  if(parola[i]=='U'){
    x=true;
  }
  return x;
}

bool condizione_1(bool prima, bool ultima){
  bool x=true;
  if(prima==true&&ultima==false){
    x=false;
  }
  return x;
}

bool condizione_2(char *parola){
  bool x=true;
  if((totale_i(parola)%2==0)||(totale_i(parola)==0)){
    x=false;
  }
  return x;
}

bool condizione_3(char* parola){
  bool x=true;
  for(int i=0; (parola[i]!='\0') && (x==true); i++){
    if(parola[i]=='I'){
      if(parola[i+1]=='M'){
        x=false;
      }
    }
  }
  return x;
}
