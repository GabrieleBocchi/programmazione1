// GDT: il programma non da il risultato corretto nei casi di test.
// Le condizioni dei vari if dovrebbero essere degli OR. Infatti, la sequenza
// deve essere scartata se i suoi caratteri o sono minori di A o maggiori di Z.
// Non è possibile che un singolo carattere sia contemporaneamente maggiore di A
// e minore di Z.
// Manca la chiusura degli stream.
// Fare riferimento alla soluzione ufficiale per lo svolgimento.

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool trovaCodice(char parola[]){
  bool controllo = false;
  int indice = 0;
  if(strlen(parola) != 19)
    return controllo;
  else{
    //primo blocco
    while(indice < 4){
      if(parola[indice] < 'A' && parola[indice] > 'Z'){
        return controllo;
      }
      indice++;
    }
    if(parola[indice] != '-'){
      return controllo;
    }
    indice++;
    //secondo blocco
    while(indice < 9){
      if(parola[indice] < 'A' && parola[indice] > 'Z')
        return controllo;
      indice++;
    }
    if(parola[indice] != '-'){
      return controllo;
    }
    indice++;
    //terzo blocco
    while(indice < 14){
      if(parola[indice] < 'A' && parola[indice] > 'Z'){
        return controllo;
      }
      indice++;
    }
    if(parola[indice] != '-'){
      return controllo;
    }
    indice++;
    //ultimo blocco
    for(int i = 0; i < 4; i++){
      if(parola[indice] < 'A' && parola[indice] > 'Z'){
        return controllo;
      }
      indice++;
    }
    controllo = true;
  }
  return controllo;
}

int main(int argc, char * argv [])
{
  if(argc != 3){
    cout<<"Usage: ./a.out <input.txt> <output.txt>"<<endl;
    exit(1);
  }
  else{
    //apro gli stream
    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);
    //controllo non ci siano errori nell'apertura
    if(input.fail()){
      cout<<"Errore nell'apertura del file!"<<endl;
      input.close();
      output.close();
      exit(2);
    }
    else{
      int contatore = 0;
      char buffer[101];

      input >> buffer;
      while(!input.eof()){
        if(trovaCodice(buffer)){
          contatore++;
        }
        input >> buffer;
      }
      output << contatore;
    }
  }
  return 0;
}
