#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

// Lunghezza massima delle stringhe
const int MAX_LUNGHEZZA=101;

// Funzione che controlla se la sequenze è corretta
bool controlla_sequenza(char * sequenza);

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

  // Leggo il testo.
  int sequenze=0;
  char buffer[MAX_LUNGHEZZA];
  while(input >> buffer)
  {
    if (controlla_sequenza(buffer)) {
        sequenze++;
    }
  }

  // Stampo nel file in output il numero di sequenze
  output << sequenze << endl;

  // Chiudo gli stream
  input.close();
  output.close();

  return 0;
}

bool controlla_sequenza(char * sequenza)
{
  int lunghezza = strlen(sequenza);
  bool corretta = true;

  // Se la parola ha una lunghezza diversa da 16
  // possiamo subito tornare falso.
  if (lunghezza != 16)
  {
    return false;
  }

  for (int i=0; i<lunghezza && corretta; i++)
  {
      if (i < 4)
      {
        // Dobbiamo controllare che i primi 4 caratteri siano lettere maiuscole
        if (!(sequenza[i] >= 'A' && sequenza[i] <= 'Z'))
        {
          corretta = false;
        }
      } else {
        // Controlliamo che i restanti caratteri siano numeri
        if (!(sequenza[i] >= '0' && sequenza[i] <= '9'))
        {
          corretta = false;
        }
      }
  }

  cout << endl;

  return corretta;
}
