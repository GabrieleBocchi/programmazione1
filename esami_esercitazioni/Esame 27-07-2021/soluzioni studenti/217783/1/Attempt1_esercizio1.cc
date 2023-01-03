#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool isCodice(char *codice);

const int maxChar = 101;

int main(int argc, char * argv [])
{
  if (argc != 3) {
    cout << "Usage <./a.out> <input.txt> <output.txt>" << endl;
    exit(1);
  }

  fstream lettura, scrittura;
  char buffer[maxChar];

  lettura.open(argv[1],ios::in);
  if (lettura.fail()) {
    cout << "Errore apertura del file in lettura" << endl;
    lettura.close();
    exit(1);
  }
  
 
  int contaCod = 0;
  
  while (lettura >> buffer) {
    if (isCodice(buffer)) {
	contaCod++;
      }
  }
  
 lettura.close();
  
 scrittura.open(argv[2],ios::out);
  if (scrittura.fail()) {
    cout << "Errore apertura del file in scrittura" << endl;
    scrittura.close();
    exit(1);
  }

 scrittura << contaCod << endl;
    
 scrittura.close();
  
  
 return 0;
}

bool isCodice(char *codice) {

  bool statement = false;
  int contaGruppi = 0;
  int contatore = 0;
  int contaNum = 0;
  int contaDel = 0;

  while (codice[contatore] != '\0') {

    if (codice[contatore] >= '0' && codice[contatore] <= '9') {
      if (contaNum < 4) {
        contaNum++;
      }
    }
    else if (codice[contatore] == '-') {
      if (contaDel <3 && contaNum == 4) {
	contaNum = 0;
	contaGruppi++;
	contaDel++;
      }
    }
    contatore++;
  }

  if (contaNum == 4) {
    contaGruppi++;
  }
  
  if (contaGruppi == 4 && contaDel ==3) {
    statement = true;
  }
  
  return statement;
}
