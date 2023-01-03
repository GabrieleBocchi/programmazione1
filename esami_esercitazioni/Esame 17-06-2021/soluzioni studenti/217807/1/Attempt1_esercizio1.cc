#include <iostream>
#include <fstream>
using namespace std;

int lunghezza(char parola[]) {
  int res = 0;
  
  while (parola[res] != '\0') {
    res++;
  }
  
  return res;
}

int contaI (char parola[]) {
  int res = 0;

  for (int i=0; parola[i] != '\0'; i++) {
    if (parola[i] == 'I') {
      res++;
    }
  }

  return res;
}

bool controllaMI (char parola[]) {
  bool res = true;

  if (parola[1] != '\0') {
    
    for (int i=0; parola[i+1] != '\0' && res; i++) {
      
      if (parola[i] == 'M' && parola[i+1] == 'I') {
	res = false;
      }
      
    }
    
  }

  return res;
}

int main(int argc, char** argv) {
  const int MAXCHAR = 100;

  
  if (argc != 3) {
    cerr << "Usage: <a.out> <input.txt> <output.txt>" << endl;
    exit(1);
  }

  fstream input, output;

  input.open(argv[1], ios::in);

  if (input.fail()) {
    cerr << "Errore in lettura" << endl;
    exit(2);
  }

  output.open(argv[2], ios::out);

  if (output.fail()) {
    cerr << "Errore in scrittura" << endl;
    exit(3);
  }

  char parola[MAXCHAR];

  while (input >> parola) {
    bool ok = true;

    if (parola[0] == 'U' &&
	parola[lunghezza(parola)-1] != 'M') {
      ok = false;
    }
    else {
      int numI = contaI(parola);

      if (numI != 0 && numI%2 != 0) {
	ok = false;
      }
      else {
	ok = controllaMI(parola);
      }
    }

    if (ok) {
      output << parola << endl;
    }
  }

  output.close();
  input.close();

  return 0;

}
