#include <iostream>
#include <fstream>
using namespace std;
bool lenght(char* parola);
int main(int argc, char* argv[])
{
  if (argc != 3) {
    cout << "Usage: ./a.out nome_file_input nome_file_output" << endl;
    exit(0);
  }
  else {
    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);
    if (input.fail() && output.fail()) {
      cout << "Errore apertura file " << endl;
      exit(0);
    }
    else {
      char** testo = new char* [10000];
      char* parola = new char[100];
      int indice = 0;

      while (input >> parola) {
        testo[indice] = parola;
        indice++;
        parola = new char[100];
      }
      input.close();

      for (int j = indice - 1; j >= 0; j--) {
        if (lenght(testo[j])) {
          output << testo[j] << " ";
        }
      }
      output.close();

      //Deallocazione memoria
      for (int i = 0; testo[i + 1] == NULL; i++) {
        delete[]testo[i];
      }
      delete[]testo;
      delete[]parola;
    }
  }
  return 0;
}

bool lenght(char* parola) {
  int i = 0;
  bool check = true;
  while (parola[i] != '\0') {
    i++;
    if (i > 4) {
      check = false;
    }

  }
  return check;
}