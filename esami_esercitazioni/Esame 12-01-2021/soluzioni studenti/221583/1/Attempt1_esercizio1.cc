#include <iostream>
#include <fstream>
using namespace std;

const int MAX_PAROLE = 10000;
const int MAX_LETTERE = 100;

int lunghezza (char parola[]);

int main(int argc, char * argv [])
{
  if (argc != 3) {
    cout << "Usage: ./a.out <input> <output>" << endl;
    exit (0);
  }
  
  fstream input, output;
  input.open(argv[1], ios::in);
  output.open (argv[2], ios::out);
  int contatore = 0;
  
  if (input.fail()) {
    cout << "Il file inserito non esiste";
    exit(0);
  }
 
  char parola [MAX_LETTERE];
  input >> parola;
  
  while (!input.eof()) {
    
    if (lunghezza(parola)%2 == 0 && contatore < MAX_PAROLE){
      output << parola << " ";
      input >> parola;
      contatore++;
    }
    else {
      input >> parola;
    }
  }

  output.close();
  input.close();
  
  return 0;
}

int lunghezza (char parola[]) {
  bool fine = false;
  int index;
  for (int i = 0; i < MAX_LETTERE && !fine; i++) {
    if (parola[i] == '\0') {
      index = i;
      fine = true;
    }
    else {
      index = -1;
    }
  }
  return index;
}
