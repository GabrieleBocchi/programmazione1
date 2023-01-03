#include <iostream>
#include <fstream>
using namespace std;

const int MAX_PAROLE = 10000;
const int MAX_CARATTERI = 100 + 1;
const int MAX_CARATTERI_DA_COPIARE = 4 + 1;

int conta_caratteri(char * parola);

int main(int argc, char * argv [])
{
  if (argc < 3) {
    cout << "Utilizzo: " << argv[0] << " <file_input> <file_output>" << endl;
  } else {
    fstream input;
    input.open(argv[1], ios::in);

    if (input.is_open()) {
      char parole[MAX_PAROLE][MAX_CARATTERI_DA_COPIARE];
      char buffer[MAX_CARATTERI];

      int contatore_parole = 0;
      
      input >> buffer;
      while (!input.eof() && contatore_parole < MAX_PAROLE) {
	int numero_caratteri = conta_caratteri(buffer);

	if (numero_caratteri < MAX_CARATTERI_DA_COPIARE) {
	  for (int i = 0; i < numero_caratteri; i++) {
	    parole[contatore_parole][i] = buffer[i];
	  }
	  contatore_parole++;
	}

	input >> buffer;
      }
      input.close();

      fstream output;
      output.open(argv[2], ios::out);

      if (output.is_open()) {
	for (int i = contatore_parole - 1; i >= 0; i--) {
	  output << parole[i] << " ";
	}
	output << endl;

	output.close();
      } else {
	cout << "Errore nell'apertura del file di output" << endl;
      }
    } else {
      cout << "Errore nell'apertura del file di input" << endl;
    }
  }
  
  return 0;
}

int conta_caratteri(char * parola) {
  int risultato = 0;
  while (parola[risultato] != '\0') {
    risultato++;
  }
  return risultato;
}
