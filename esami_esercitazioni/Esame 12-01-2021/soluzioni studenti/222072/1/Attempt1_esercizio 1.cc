#include <iostream>
#include <fstream>
using namespace std;

const int MAX_PAROLE = 10001;
const int MAX_LETTERE = 101;

int len_p (char []);
void copia (char [], char [], int dim);

int main(int argc, char * argv [3])
{
  if (argc != 3) {
    cout << "Error! \nUsage: <./a.out> <input_file> <output_file>" << endl;
    exit(0);
  }
  
  char parole [MAX_PAROLE][MAX_LETTERE];
  fstream input, output;
  input.open (argv[1], ios::in);
  if (input.fail()) {
    cout << "Errore nel caricamento del file" << endl;
    exit(0);
  }
  int contatore = 0;
  char buffer[MAX_LETTERE];
  int lunghezza_parola;
  
  while (input >> buffer) {
    lunghezza_parola = len_p (buffer);

    if (lunghezza_parola > 4) {
      copia (parole[contatore], buffer, lunghezza_parola);
      contatore ++;
    }  
  }

  input.close ();
  output.open (argv[2], ios::out);
  if (output.fail()) {
    cout << "Errore nell'utilizzo del file di output" << endl;
    exit(0);
  }
  
  for (int i = contatore-1; i >= 0; i--) {
    output << parole[i] << " ";
  }
  
  output.close();

  return 0;
}

int len_p (char parola[]) {
  int len = 0;
  for (int i = 0; parola[i] != '\0' && i < MAX_LETTERE; i++) {
    len++;
  }
  return len;
}

void copia (char a[], char b[], int dim) {
  for (int i = 0; i <= dim; i++) {
    a[i] = b[i];
  }
}
