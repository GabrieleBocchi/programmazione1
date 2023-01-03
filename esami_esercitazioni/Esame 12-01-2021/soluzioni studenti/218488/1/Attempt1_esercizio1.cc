#include <iostream>
#include <fstream>
using namespace std;

int conta(char* parola);
bool leggi(char* file_input, char parole[][100], int &indice);
bool copia(char* file_output, char parole[][100], int indice);

int main(int argc, char * argv [])
{
  if (argc < 3){
    cerr << "Errore. Usage: *.out <file_input> <file_output>";
    return 1;
  }
  char parole[1000][100];
  int indice = 0;
  if (!leggi(argv[1], parole, indice))
    return 1;

  if (!copia(argv[2], parole, indice-1))
    return 1;

  return 0;
}

int conta(char* parola){
  int i = 0;
  while (parola[i] != '\0'){
    i++;
  }
  return i;
}

bool leggi(char* file_input, char parole[][100], int &indice){
  fstream input;
  input.open(file_input, ios::in);
  if (input.fail()){
    cerr << "Il file di input non esiste / non e' utilizzabile.";
    return false;
  }
  while (input >> parole[indice]){
    indice++;
  }
  input.close();
  return true;
}

bool copia(char* file_output, char parole[][100], int indice){
  fstream output;
  output.open(file_output, ios::out);
  if (output.fail()){
    cerr << "Si è verificato un problema con il file di output.";
    return false;
  }
  while (indice >= 0){
    if (conta(parole[indice]) > 4){
      output << parole[indice] << " ";
    }
    indice--;
  }
  output.close();
  return true;
}