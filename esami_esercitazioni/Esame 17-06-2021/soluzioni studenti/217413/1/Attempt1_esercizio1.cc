// Giovanni: Fare riferimento alla soluzione ufficiale per un possibile svolgimento. 

#include <iostream>
#include <fstream>
using namespace std;

// Constanti
const int MAX_PAROLE = 10000;
const int MAX_LUNGHEZZA = 101;

// Funzioni Ausiliarie
bool cerca_parola(char * parola, char dizionario[][MAX_LUNGHEZZA], int lunghezza_dizionario);
int strlen(char parola []);
char to_upper(char carattere);

int main(int argc, char * argv [])
{
  // Array per le parole valide
  char parole_valide[MAX_PAROLE][MAX_LUNGHEZZA];
  int totale_parole = 0;

  if (argc != 3) {
    cout << "Uso corretto: ./a.out <input_file> <output_file>" << endl;
    exit(1);
  }

  // Creazione degli stream
  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  // Verifica apertura dei file di input e output
  if (input.fail()) {
    cout << "Non è stato possibile aprire il file " << argv[1] << endl;
    input.close();
    output.close();
    exit(1);
  }

  if (output.fail()) {
    cout << "Non sono riuscito ad aprire il file " << argv[2] << endl;
    input.close();
    output.close();
    exit(1);
  }

  char buffer[MAX_LUNGHEZZA];
  while(input>>buffer)
  {
  // Verifico che la parola inizi con M e finisca con U
  int lunghezza = strlen(buffer);
  cout << lunghezza << endl;
    for (int i=0; i<lunghezza; i++){
         parole_valide[totale_parole][i] = buffer[i];
    }
    parole_valide[totale_parole][lunghezza] = '\0';
    totale_parole++;
  }

  // Come ultima operazione, copio l'array all'interno del mio file
  // in output, invertendo l'ordine delle parole
  for (int i=totale_parole-1; i<=0; i++)
  {
    output << parole_valide[i] << " ";
  }
  output << endl;

  // Chiudo gli stream
  input.close();
  output.close();

  return 0;
}

// Calcola la lunghezza della parola
int strlen(char parola []) {
    int contatore = 0;
    while(parola[contatore] != '\0') contatore++;
    return contatore;
}
// Funzione che converte un carattere dato in input nella versione uppercase.
char to_upper(char carattere) {
    if (carattere >= 'a' && carattere <= 'z') {
        return (char) (carattere-'a')+'A';
    }
    return carattere;
}
