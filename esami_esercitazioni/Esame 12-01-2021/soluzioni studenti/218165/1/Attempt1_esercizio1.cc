#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv [])
{
  if (argc != 3) {
    cerr << "Usato: <input> <output>" << endl;
  } else {
    fstream fin, fout;
    fin.open(argv[1], ios::in);
    fout.open(argv[2], ios::out);

    if (fin.fail()) {
      cerr << "Non posso aprire il file di input." << endl;
    } else if (fout.fail()) {
      cerr << "Non posso scrivere sul file di output." << endl;
    } else {
      int max_parole = 10000, max_len = 100;
      char* parola;
      char* parole[max_parole];
      
      parola = new char[max_len + 1];
      int i = 0, len = 0;
      while (fin >> parola) {
        len = 0;
        while (parola[len] != '\0') {
          len++;
        }
        if (len % 2 == 0) {
          parole[i] = parola;
          i++;
          parola = new char[max_len + 1];
        }
      }
      delete parola;

      for (i--; i >= 0; i--) {
        fout << parole[i] << " ";
        delete parole[i];
      }

      fin.close();
      fout.close();

    }
  }

  return 0;
}
