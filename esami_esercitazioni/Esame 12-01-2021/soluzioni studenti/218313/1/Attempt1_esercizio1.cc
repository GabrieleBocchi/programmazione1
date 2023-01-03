// GDT: fare riferimento alla soluzione ufficiale per un possibile svolgimento.
// Il codice da errore in alcuni casi di test e non fornisce la soluzione corretta.

#include <iostream>
#include <fstream>
using namespace std;

bool carattereSeparatore(char carattere);
int lunghezzaParola(char parola[]);
void scrivi(fstream * output, char parola[], int lunghezza);
void pulisciArray(char parola[]);

int main(int argc, char * argv []) {
  int returnValue = 0;
  if(argc != 3) {
    cout << "Errore, specificare il file di input e output" << endl;
    returnValue = 1;
  } else {
    fstream input, output;

    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    if(input.fail()) {
      //Se non riesco a leggere il fiel
      cout << "Errore nella lettura del file" << endl;
      returnValue = 2;
    } else {
      //se riesco a leggere il file
      int indice = 0;
      char parola[100];
      char lettera;

      while(!input.eof()) {
        cout << indice;
        //scorro il file
        input >> noskipws >> lettera;
        cout << " " << lettera << endl;
        if(carattereSeparatore(lettera)) {
          parola[indice] = '\0';
          //Se trovo un carattere separatore
          int parolaLength = lunghezzaParola(parola);
          if(parolaLength > 0 && parolaLength <= 4) {
            //scrivo su file se la parola è nei limiti prestabiliti
            for(int i = 0; i < parolaLength; i++) {
              output << parola[i];
            }
            
            output << " ";
          } 
          //Preparo l'array per un'altra parola
          pulisciArray(parola);
        } else {
          //se non trovo un carattere separatore allora aggiungo una lettera alla parola
          parola[indice] = lettera;
        }

        indice++;
      } 
    }
  }
  

  return returnValue;
}

bool carattereSeparatore(char c) {
  return (c == ',' || c == '.' || c == ' ' || c == '\n' || c == '\0' || c == '\t'); 
}

int lunghezzaParola(char parola[]) {
  int i;
  bool fine = false;
  for(i = 0; i < 100 && !fine; i++) {
    if(parola[i] == '\0') {
      fine = true;
    }
  }

  cout << "Lunghezzza" << i << endl;
  return i-1;
}

void pulisciArray(char parola[]) {
  for(int i = 0; i < 100; i++) {
    parola[i] = '$';
  }
}
