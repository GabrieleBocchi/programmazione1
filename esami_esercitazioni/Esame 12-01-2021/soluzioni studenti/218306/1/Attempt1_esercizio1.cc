#include <iostream>
#include <fstream>

using namespace std;

void copyStr(char *to, const char *from);

int main(int argc, char *argv[]) {
  int retval = 0;

  if (argc != 3) {
    cout << "Utilizzo corretto: " << argv[0] << " <file_input> <file_output>" << endl;
    retval = 1;
  } else {
    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    if (input.fail()) {
      cout << "Errore durante l'apertura del file di input \"" << argv[1] << "\"" << endl;
      if (!output.fail()) {
        output.close();
      }
      retval = 2;
    } else if (output.fail()) {
      cout << "Impossibile scrivere sul file di output \"" << argv[2] << "\"" << endl;
      input.close();
      retval = 3;
    } else {
      char word[101];
      char **wordsToWrite = new char *[10000];
      int wordsToWriteLength = 0;

      // legge le parole
      while (input >> word) {
        // controlla se la parola ha un numero <= 4 caratteri
        bool valid = false;
        int length; // numero di caratteri + terminatore di stringa todo rename
        for (length = 0; length <= 4 && !valid; length++) {
          if (word[length] == '\0') {
            valid = true;
          }
        }

        if (valid) {
          char *copiedWord = new char[101];
          copyStr(copiedWord, word);
          wordsToWrite[wordsToWriteLength++] = copiedWord;
        }
      }
      input.close();

      // scrive le parole nel file di output e dealloca la matrice
      for (int i = wordsToWriteLength - 1; i >= 0; i--) {
        output << wordsToWrite[i] << " ";
        delete[] wordsToWrite[i];
      }
      delete[] wordsToWrite;
      output.close();

      cout << "Operazione completata con successo" << endl;
    }
  }


  return retval;
}

void copyStr(char *to, const char *from) {
  int i;
  for (i = 0; from[i] != '\0'; i++) {
    to[i] = from[i];
  }
  to[i] = '\0';
}
