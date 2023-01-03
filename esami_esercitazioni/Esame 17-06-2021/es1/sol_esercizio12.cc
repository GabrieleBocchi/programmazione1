#include <iostream>
#include <fstream>
using namespace std;

// Costanti derivate dalla descrizione dell'esercizio
const int MAX_LUNGHEZZA = 101;

// Ritorna la lunghezza di una parola
int strlen(char * parola);

// Funzione che controlla se la parola è corretta
bool controlla_parola(char * parola);

int main(int argc, char * argv [])
{

  // Controllo se il numero degli argomenti è corretto
  if (argc != 3)
  {
    cout << "Usage: esercizio1 <input_file> <output_file>" << endl;
    exit(1);
  }

  // Creo i miei stream
  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  // Controllo se riesco ad aprire il file di input
  if (input.fail() || output.fail())
  {
    cout << "Non sono riuscito ad aprire uno dei file "
         << argv[1]  << " " << argv[2] << endl;
    input.close();
    output.close();
    exit(1);
  }

  // Leggo il testo. Se la parola è corretta allora la salvo all'interno
  // del file in output.
  char buffer[MAX_LUNGHEZZA];
  while(input >> buffer)
  {
    if (!controlla_parola(buffer)) {
        output << buffer << endl;
    }
  }

  // Chiudo gli stream
  input.close();
  output.close();

  return 0;
}

bool controlla_parola(char * parola)
{
  int lunghezza_parola = strlen(parola);
  bool corretta = true;

  int totale_lettera = 0;

  // Controllo la regola 1
  if (parola[0] == 'M')
  {
    corretta = (parola[lunghezza_parola-1] == 'U');
  }

  for (int i=0; i<lunghezza_parola && corretta; i++) {

    // Conto il totale di lettere I (regola 2)
    if (parola[i] == 'I') {
      totale_lettera += 1;
    }

    // Controllo regola 3
    if (parola[i] == 'I') {
      if (i+1 <= lunghezza_parola) {
        corretta = (parola[i+1] != 'M');
      }
    }

  }

  // Controllo regola 2. Inoltre, anche i controlli precedenti devono
  // aver dato risultato positivo
  return corretta && (totale_lettera % 2 == 1 || totale_lettera == 0);

}

int strlen(char * parola) {
  int lunghezza;
  for (lunghezza=0; parola[lunghezza] != '\0'; lunghezza++) {}
  return lunghezza;
}
