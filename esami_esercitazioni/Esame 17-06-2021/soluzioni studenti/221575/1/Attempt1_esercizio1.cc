// Giovanni: il codice ritorna output errati nei casi di test utilizzati per
// la valutazione. Questo capita poichè la funzione controlla_parola ritorna
// true se e solo se le tre condizioni sono verificate. Però, esistono parole
// come UUUU che appartengono comunque a MIU, anche se alcune delle regole non
// si applicano.

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_CARATTERI = 101;

bool controlla_parola(char parola[]);
int strlen (char parola[]);
int conta_I(char parola[]);
bool controlla_postI (char parola[]);

int main(int argc, char * argv [])
{

  // controlli sull'input
  if (argc != 3) {
    cout << "Usare a.out input.txt output.txt" << endl;
    exit(0);
  }

  // apertura stream di input e output
  fstream input;
  fstream output;

  input.open(argv[1], ios::in);
  if (input.fail()) {
    cout << "input_file inesistente" << endl;
    exit(0);
  }

  output.open(argv[2], ios::out);
  if (output.fail()) {
    cout << "file output protetto da scrittrua" << endl;
    exit(0);
  }

  // con un ciclo controllo parola per parola e se NON è  MIU la scrivo in output
  char parola_corrente[MAX_CARATTERI];
  while (input >> parola_corrente) {
    if (controlla_parola(parola_corrente) == false) {
      output << parola_corrente << '\n';
    }
  }

  // chiudo gli stream
  input.close();
  output.close();

  return 0;
}


bool controlla_parola(char parola[]) {

  bool corretta1 = false;
  bool corretta2 = false;
  bool corretta3 = false;
  int len = strlen(parola);

  // controllo le diverse condizioni una per una
  if (parola[0] == 'M' && parola[len-1] == 'U') {
    corretta1 = true;
  }

  if (conta_I(parola) == 0 || conta_I(parola) % 2 == 1) {
    corretta2 = true;
  }

  if (controlla_postI(parola) == true) {
    corretta3 = true;
  }

  // se sono tutte verificate ritorno che la parola appartinene al sistema MIU
  return (corretta1 && corretta2 && corretta3);
}

// calcola la lunghezza, utile per altre funzioni
int strlen (char parola[]) {
  int contatore = 0;
  while (parola[contatore] != '\0') {
    contatore++;
  }
  return contatore;
}

// conta le I di una parola
int conta_I(char parola[]) {
  int contatore = 0;
  int i = 0;
  while (parola[i] != '\0') {
    if (parola[i] == 'I') {
      contatore++;
    }
    i++;
  }
  return contatore;
}

// controlla la lettera dopo la I
bool controlla_postI (char parola[]) {
  bool ok = true;
  int i = 0;
  while (parola[i] != '\0') {
    if (parola[i] == 'I') {
      if (parola[i+1] == 'M') {
        ok = false;
      }
    }
    i++;
  }
  return ok;
}
