#include <iostream>
#include <fstream>
using namespace std;

#define MAX_WORD 100

int len(char* c);
bool isPari(char* c);
bool controllaRegole(char* c);

int main(int argc, char * argv [])
{
  if(argc != 3) {
    cerr << "utilizzo del programma errato!" << endl;
    exit(1);
  }

  fstream input, output;

  input.open(argv[1], ios::in);
  if(input.fail()) {
    cerr << "errore nell'apertura del file in lettura!" << endl;
    exit(1);
  }

  output.open(argv[2], ios::out);
  if(output.fail()) {
    cerr << "errore nell'apertura del file in scrittura!" << endl;
    exit(1);
  }

  char buffer[MAX_WORD];

  while(!input.eof()) {
    input >> buffer;
    if(controllaRegole(buffer)) {
      output << buffer << endl;
    }

  }

  input.close();
  output.close();

  return 0;
}


int len(char* c) {
  int len;
  for(len = 0; c[len] != '\0'; len++);
  return len;
}

bool isPari(char* c) {
  return (len(c) % 2 == 0);
}

int countI(char* c) {
  int counter = 0;
  for(int i = 0; c[i] != '\0'; i++) {
    if(c[i] == 'I') counter++;
  }
  return counter;
}

bool controllaRegole(char* c) {
  int size = len(c);
  bool correct = true;

  if(c[0] == 'U' && c[size-1] != 'M')
    correct = false;
  
  int numI = countI(c);

  if(numI % 2 != 0 && numI != 0) {
    correct = false;
  }

  for(int i = 0; i < size; i++) {
    if(i < size-1) {
      if(c[i] == 'M' && c[i+1] == 'I')
        correct = false;
    }
  }

  return correct;
}