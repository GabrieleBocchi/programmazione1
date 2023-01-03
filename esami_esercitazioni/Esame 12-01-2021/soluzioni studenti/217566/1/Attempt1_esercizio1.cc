#include <iostream>
#include <fstream>
using namespace std;

//GDT: in generale, fare riferimento alla soluzione ufficiale per lo svolgimento
//GDT: il codice compila e produce dei file. Però il loro contenuto contiene dei
// caratteri speciali (prima parola). La soluzione proposta è molto convoluta e perciò
// è anche difficile risolvere eventuali problemi.
//GDT: manca la deallocazione dell'array parola 

const int MAX_CHAR = 100;
const int MAX_PAROLE = 10000;

bool isSpecialChar(char carattere);

int main(int argc, char* argv[])
{

  if (argc != 3) {
    cout << "Parametri non idonei.\nUso: ./a.out input_A output" << endl;
    exit(0);
  }

  fstream input;
  fstream output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  if (input.fail() || output.fail()) {
    cout << "Errore apertura file." << endl;
    exit(1);
  }

  output.close();

  //GDT: una matrice avrebbe reso le cose più facili [MAX_PAROLE][MAX_CHAR]
  char buffer[MAX_PAROLE * MAX_CHAR];
  char* parole = new char[MAX_PAROLE];
  int count_parole = 0;
  //Vengono ciclate tutti i caratteri all'interno del file
  while (input.getline(buffer, MAX_PAROLE * MAX_CHAR)) {
    int inizio = 0;
    int fine = 0;
    int count_par = 0;

    do {
      if (isSpecialChar(buffer[count_par])) {
        //Se l'ultimo carattere è un '.' o ',' lo aggiunge alla parola precedente
        if (buffer[count_par] == '.' || buffer[count_par] == ',') {
          fine = count_par + 1;
        }
        else {
          fine = count_par;
        }

        int dim_parola = fine - inizio;
        //Se la parola è pari allora la aggiungo al vettore parole
        if (dim_parola % 2 == 0) {
          parole[count_parole] = ' ';
          count_parole++;
          for (int i = fine; i >= inizio; i--) {
            parole[count_parole] = buffer[i];
            count_parole++;
          }
        }
        inizio = fine + 1;
      }
      count_par++;
    } while (buffer[count_par] != '\0');
  }
  input.close();
  output.open(argv[2], ios::out);
  //Scrittura invertita delle parole su file di output
  for (int i = count_parole; i >= 0; i--) {
    output << parole[i];
  }
  output.close();

  return 0;
}
//Funzione per controllare se il carattere è un carattere speciale: ' ', '.', '\t', '\0', '\n'
bool isSpecialChar(char carattere) {
  bool rtn = false;
  if (carattere == ' ' || carattere == '.' || carattere == '\t' || carattere == '\0' || carattere == '\n') {
    rtn = true;
  }
  return rtn;
}
