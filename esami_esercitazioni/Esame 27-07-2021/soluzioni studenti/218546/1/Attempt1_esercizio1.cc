#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_LENGTH = 100;

bool isCodice(char * c);

int main(int argc, char * argv [])
{

  if(argc != 3) {
    cout << "usage: ./a.out <file input> <file output>" << endl;
    exit(1);
  } else {

    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    if(input.fail()) {
      cout << "errore nell'apertura del file " << argv[1] << endl;
      input.close();
      output.close();
      exit(1);
    }

    int counter = 0;
    char buffer[MAX_LENGTH];
    while(input >> buffer) {
      if(isCodice(buffer)) {
        counter++;
      }
    }
    output << counter << endl;

    input.close();
    output.close();

  }

  return 0;
}


bool isCodice(char * c) {
  bool ret = true;

  if(strlen(c) != 16) {
    ret = false;
  } else {
    
    for(int i=0; i<12; i++) {
      if(c[i] < '0' || c[i] > '9')
        ret = false;
    }
    for(int i = 12; i < 16 && ret; i++) {
      if(c[i] < 'A' || c[i] > 'Z')
      ret = false;
    }
  }

  return ret;
}