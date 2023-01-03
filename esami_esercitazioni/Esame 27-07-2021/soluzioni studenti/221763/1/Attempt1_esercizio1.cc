#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


bool controllaSequenza(char* buffer) {
  int i = 0;
  bool retval = true;
  while (buffer[i] != '\0') {
    if ((buffer[i] >= 'A' && buffer[i] <= 'Z')) {
      i++;
    }
    else if (buffer[i] == '-' && (i == 4 || i == 9 || i == 14)) {
      i++;
    }
    else {
      return false;
    }
  }
  return retval;
}

int main(int argc, char* argv[])
{
  if (argc != 3) {
    cout << "Errore esecuzione programma: file mancanti" << endl;
    exit(1);
  }
  else {
    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);
    if (input.fail() || output.fail()) {
      cout << "Errore apertura file" << endl;
      exit(1);
    }
    else {
      int nCodici = 0;
      char* buffer = new char[100];
      input.getline(buffer, 100);
      while (input >> buffer) {
        if (controllaSequenza(buffer)) {
          nCodici++;
        }
        char* temp = buffer;
        buffer = new char[100];
        delete temp;
      }
      output << nCodici;

      delete buffer;
      input.close();
      output.close();
    }
  }

  return 0;
}
