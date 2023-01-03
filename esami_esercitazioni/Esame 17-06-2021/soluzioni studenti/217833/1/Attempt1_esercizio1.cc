// Giovanni: il programma non ritorna risultati corretti in alcuni casi di test.
// Le condizioni di controllo non sono corrette. Vedi commenti nel codice.
// Fare riferimento alla soluzione ufficiale per un possibile svolgimento.
//
// Il programma inoltre assume un numero massimo di parole. Invece, dovrebbe
// poter funzionare in teoria anche con un numero illimitato.

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv []){
  const int max = 1000;
  if (argc != 3){
    cout << "Numero di argomenti errato!" << endl;
    exit(1);
  }

  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  if(input.fail()){
    cout << "Errore nell'apertura del file" << endl;
    input.close();
    output.close();
    exit(1);
  }

  char buffer[max][100];
  int index = 0;
  input >> buffer[index++];
  while(input >> buffer[index++]){}

  for(int i = 0; i < index; i++){
    bool valido = true, fine = false;
    int conta_i = 0;

    // Giovanni: in questo caso, solo le parole che iniziano per M sono considerate
    // appartenenti a MIU. Però, parole come UUUU sono altrettanto valide.
    if(buffer[i][0] == 'M'){
      for(int j = 1; (j < 99) && valido && !fine; j++){
        if((buffer[i][j] != 'M') && (buffer[i][j] != 'U') && (buffer[i][j] != 'I')){
            fine = true;
        }
        if(buffer[i][j] == 'I'){
          conta_i++;
        } else if ((buffer[i][j] == 'M') && buffer[i][j-1] == 'I') valido = false;
      }
    } else valido = false;
    if((conta_i != 0) && (conta_i % 2 != 1)){
      valido = false;
    }
    if(valido){
      output << buffer[i] << endl;
    }
  }

  cout << "Andata a buon fine!" << endl;

  input.close();
  output.close();

  return 0;
}
