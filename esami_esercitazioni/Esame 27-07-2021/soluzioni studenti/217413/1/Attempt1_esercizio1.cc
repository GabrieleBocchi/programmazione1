// GDT: il programma non da il risultato corretto nei casi di test.
// Fare riferimento alla soluzione ufficiale per lo svolgimento.
// Vedere commenti nel codice.

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_LUNGHEZZA = 101;

char to_upper(char carattere);

bool controllo_codice_fiscale(char * parola);

int main(int argc, char * argv [])
{
  if (argc != 3) {
    cout << "Uso: ./a.out input.txt output.txt" << endl;
    exit(1);
  }

  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  if (input.fail() || output.fail()) {
    cout << "Non sono riuscito ad aprire uno dei file " << argv[1]  << " " << argv[2] << endl;
    input.close();
    output.close();
    exit(1);
  }

  char buffer[MAX_LUNGHEZZA];
  int contatore = 0;
  while(input >> buffer) {
    if (controllo_codice_fiscale(buffer)) {
      output << buffer << endl;
      ++contatore;
    }
  }

  cout << contatore << endl;

  input.close();
  output.close();

  return 0;
}

// GDT: si assumevano come codici corretti quelli composti da lettere maiuscole.
// Codici composti da lettere minuscole erano da considerarsi errati. Nel testo
// dell'esercizio non era scritto di considerare il tutto case insensitive.
char to_upper(char carattere) {
    if (carattere >= 'a' && carattere <= 'z') return (char) (carattere-'a')+'A';
    return carattere;
}

// GDT: la funzione non controlla che la parola sia lunga 16 caratteri.
// La funzione poteva essere benissimo scritta con dei cicli for e/o altri
// accorgimenti. La duplicazione di codice e gli if innestati non sono esattamente
// il massimo per la programmazione. Fai riferimento alle soluzioni ufficiali
// per una versione alternativa.
bool controllo_codice_fiscale(char * parola) {

  int lunghezza_parola = strlen(parola);
  bool corretta = true;
  int conta_codici_fiscali = 0;

  // Controllo che la parola sia formato solo da 16 caratteri

  char prima_lettera = parola[0];
  char seconda_lettera = parola[1];
  char terza_lettera = parola[2];
  char quarta_lettera = parola[3];

  // GDT: non capisco l'utilizzo della funzione to_upper. Non bastava semplicemente
  // controllare che la lettera sia tra i caratteri A e Z??
  // Controllo i primi quattro caratteri
  if (prima_lettera == to_upper(prima_lettera)) {
    if (seconda_lettera == to_upper(seconda_lettera)) {
      if (terza_lettera == to_upper(terza_lettera)) {
        if (quarta_lettera == to_upper(quarta_lettera)) {
          corretta = true;
        } else corretta = false;
      } else corretta = false;
    } else corretta = false;
  } else corretta = false;

  char primo_numero = parola[4];
  char secondo_numero = parola[5];
  char terzo_numero = parola[6];
  char quarto_numero = parola[7];
  char quinto_numero = parola[8];
  char sesto_numero = parola[9];
  char settimo_numero = parola[10];
  char ottavo_numero = parola[11];

  // Controllo che gli 8 caratteri successivi siano tutti numeri
  switch(primo_numero) {
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    corretta = true; break;
    default: corretta = false; break;
  }
  switch(secondo_numero) {
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    corretta = true; break;
    default: corretta = false; break;
  }
  switch(terzo_numero) {
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    corretta = true; break;
    default: corretta = false; break;
  }
  switch(quarto_numero) {
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    corretta = true; break;
    default: corretta = false; break;
  }
  switch(quinto_numero) {
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    corretta = true; break;
    default: corretta = false; break;
  }
  switch(sesto_numero) {
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    corretta = true; break;
    default: corretta = false; break;
  }
  switch(settimo_numero) {
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    corretta = true; break;
    default: corretta = false; break;
  }
  switch(ottavo_numero) {
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    corretta = true; conta_codici_fiscali++; break;
    default: corretta = false; break;
  }

  return conta_codici_fiscali;
}
