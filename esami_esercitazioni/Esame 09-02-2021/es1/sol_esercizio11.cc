#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Costanti derivate dalla descrizione dell'esercizio
const int MAX_PAROLE = 1000;
const int MAX_LUNGHEZZA = 101;

// Funzione che converte un carattere dato in input nella versione
// lowercase. Nel caso in cui sia già minuscolo, allora ritorna il
// carattere originale
char to_lower(char carattere)
{
  if (carattere >= 'A' && carattere <= 'Z')
  {
    return (char) (carattere-'A')+'a';
  }
  return carattere;
}

// Funzione che, data una parola, il dizionario e la lunghezza del dizionario
// ritorna vero se la parola è presente all'interno del dizionario
bool cerca_parola(char * parola, char dizionario[][MAX_LUNGHEZZA],
                  int lunghezza_dizionario);

int main(int argc, char * argv [])
{

  // dizionario che contiene tutte le parole da censurare
  char dizionario[MAX_PAROLE][MAX_LUNGHEZZA];

  // Controllo se il numero degli argomenti è corretto
  if (argc != 4)
  {
    cout << "Usage: esercizio1 <input_file <vocab> <output_file>" << endl;
    exit(1);
  }

  // Creo i miei stream
  fstream input, vocab, output;
  input.open(argv[1], ios::in);
  vocab.open(argv[2], ios::in);
  output.open(argv[3], ios::out);

  // Controllo se riesco ad aprire il file di input
  if (input.fail() || vocab.fail())
  {
    cout << "Non sono riuscito ad aprire uno dei file "
         << argv[1]  << " " << argv[2] << endl;
    input.close();
    vocab.close();
    output.close();
    exit(1);
  }

  // Riempio il mio dizionario con le parole presenti nel file
  int index = 0;
  vocab >> dizionario[index];
  while(!vocab.eof())
  {
    index++;
    vocab >> dizionario[index];
  }

  // Leggo il messaggio. Se la parola è presente nel dizionario,
  // allora la converto in un insieme di X. Altrimenti passo oltre.
  char buffer[MAX_LUNGHEZZA];
  while(input >> buffer)
  {
    if (cerca_parola(buffer, dizionario, index)) {
      for (unsigned int i=0; i<strlen(buffer); i++)
      {
        output << "X";
      }
      output << " ";
    } else {
        output << buffer << " ";
    }
  }
  output << endl;

  // Chiudo gli stream
  input.close();
  vocab.close();
  output.close();

  return 0;
}

bool cerca_parola(char * parola, char dizionario[][MAX_LUNGHEZZA],
                  int lunghezza_dizionario)
{
  bool trovato = false;
  for (int i=0; i<lunghezza_dizionario && !trovato; i++)
  {

    // Analizzo le parole solo se hanno una lunghezza identica
    if (strlen(parola) == strlen(dizionario[i]))
    {

      // Controllo la parola carattere per carattere. Mi fermo se e solo
      // se i caratteri sono diversi
      bool corretta = true;
      for (unsigned int j=0; j<strlen(parola) && corretta; j++)
      {
        if (to_lower(parola[j]) != to_lower(dizionario[i][j]))
        {
          corretta = false;
        }
      }

      trovato = corretta;
    }
  }
  return trovato;
}
