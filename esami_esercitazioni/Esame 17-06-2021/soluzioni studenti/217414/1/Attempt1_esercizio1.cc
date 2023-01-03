// Giovanni: alcune condizioni sono errate. Ad esempio, la condizione 1 indica che,
// se la parola inizia con la lettera U, allora deve per forza terminare con la lettera M.
// Però, se la parola non inizia con la lettera U, allora quella condizione non si
// applica. Vedi commenti nel codice.
//
// Manca anche output.close()

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_LETTERE = 100+1;

int strlen(char buffer[]){
  int ret = 0;
  while(buffer[ret] != '\0'){
    ret++;
  }
  return ret;
}

// Giovanni: di default,ret dovrebbe essere true (e dovresti cambiarlo a false
// se la condizione non è verificata). Infatti, parole come MMM sono comunque
// valide, ma la funzione check1 ritorna falso.
bool check1(char buffer[]){
  bool ret = false;
  if(buffer[0] == 'U'){
    if(buffer[strlen(buffer)-1] == 'M'){
      ret = true;
    }
  }
  return ret;
}
bool check2(char buffer[]){
  bool ret = false;
  int cont = 0;
  for (int i = 0; i < strlen(buffer); i++)
  {
    if(buffer[i] == 'I'){
      cont++;
    }
  }
  if(cont%2 == 0 || cont == 0){
    ret = true;
  }
  return ret;
}
bool check3(char buffer[]){
  bool ret = true;
  for (int i = 0; i < strlen(buffer)-1 && ret; i++)
  {
    if(buffer[i] == 'M'){
      if(buffer[i+1] == 'I'){
        ret = false;
      }
    }
  }
  return ret;
}


int main(int argc, char * argv [])
{
  if(argc == 3){
    fstream input;
    input.open(argv[1], ios::in);
    if(!input.fail()){
      fstream output;
      output.open(argv[2], ios::out);
      if(!output.fail()){
        char buffer[MAX_LETTERE];
        while(input >> buffer){
          if(check1(buffer) && (check2(buffer) && check3(buffer))){
            output << buffer << endl;
          }
        }
      }
      else{
        cout << "File di output errato!\n";
      }
    }
    else{
      cout << "File di input errato o non trovato!\n";
    }
    input.close();
  }
  else{
    cout << "Numero di file errato!\n";
  }
  return 0;
}
