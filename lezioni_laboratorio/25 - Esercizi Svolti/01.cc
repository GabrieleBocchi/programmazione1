#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char * argv []) {

  if (argc != 2) {
    cout << "./a.out <file>" << endl;
    exit(1);
  }

  ifstream input;
  input.open(argv[1], ios::in);
  if (input.fail()) {
    cout << "L'apertura del file è fallita" << endl;
    exit(1);
  }

  int sequenze = 0;
  int gruppi_cifre = 0;

  char buffer[256];

  while(input >> buffer) {

    int cifre = 0;
    for (int i=0; i<strlen(buffer); i++) {
      if (buffer[i] <= '9' && buffer[i] >= '0') {
        cifre += 1;
      }
    }

    if (cifre == 4 && strlen(buffer) == 4) {
      gruppi_cifre += 1;
    } else {
      if (gruppi_cifre == 4) {
        sequenze++;
      }
      gruppi_cifre = 0;
    }

  }

  if (gruppi_cifre == 4) {
    sequenze++;
  }

  cout << sequenze << endl;

  return 0;
}
