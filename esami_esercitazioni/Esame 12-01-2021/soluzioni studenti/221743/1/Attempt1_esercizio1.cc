#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv [])
{

  if (argc != 3) {

    cout << "Usage: ./a.out <file_input> <file_output>";
    exit(0);
  }

  fstream input;

  input.open(argv[1], ios::in);

  if (input.fail()) {

    cout << "Il file di input non esiste.";
    exit(0);
  }
  
  char ** buffer;
  buffer = new char*[1000];

  char carattere;
  int num_car = 0;
  int i = 0;
  char parola[100];
  while (input.get(carattere)) {
    
    if ((carattere != ' ') && (carattere != '\n') && (carattere != '\t')) {
      parola[num_car] = carattere;
      num_car++;
    }
    else {
      if ((num_car % 2) == 0) {
        cout << parola;
        buffer[i] = parola;
        i++;
        num_car = 0;
      }
    }
  }

  fstream output;
  output.open(argv[2], ios::out);

  for (int j = i; j >= 0; j--) {

    output >> buffer[j];
  }

  input.close();
  output.close();

  return 0;
}
