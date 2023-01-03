// GDT: il codice non riporta il risultato corretto in alcuni casi di test.
// Vedi commenti nel codice
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Funzione Principale
void soluzione(char * parola);

// Funzione Ausiliaria
bool controllo_alternatore(char * parola);

int main(int argc, char * argv [])
{
  // Controllo se il numero degli argomenti è corretto
  if (argc != 3) {
    cout << "Usage: esercizio1 <input_file> <output_file>" << endl;
    exit(1);
  }

  // Creo i miei stream
  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  // Controllo se riesco ad aprire il file di input
  if (input.fail() || output.fail()) {
    cout << "Non sono riuscito ad aprire uno dei file " << argv[1]  << " " << argv[2] << endl;
    input.close();
    output.close();
    exit(1);
  }

  char buffer[101];

  // GDT: la variabile viene settata, però non viene usata.
  bool salto;

  while(input >> buffer) {

    // GDT: non utilizzi salto in questo caso. Manca la logica che utilizza
    // la variabile salto per dare la soluzione.

    // Se è presente un salto attivo
    soluzione(buffer);



    // se la parola contine i caratteri speciali, si prepara a salta alla prossima parola
    if (controllo_alternatore(buffer)) salto = true;
    else salto = false;

    cout << buffer << " - " << salto << endl;
    output << buffer << endl;

  }

  return 0;
}

void soluzione(char * parola) {
  int lunghezza = strlen(parola);
  for (int i=0; i<lunghezza; i++) {
    if (i==0 && !(parola[0] >= 'A' && parola[0] <= 'Z')) parola[i] = (parola[i]-'a')+'A';
  }
}

bool controllo_alternatore(char * parola) {
  int lunghezza = strlen(parola);
  bool corretta = true;
  if (parola[lunghezza-1]==',' || parola[lunghezza-1]==':' || parola[lunghezza-1]==';') {
    return corretta;
  } else return corretta = false;
}
