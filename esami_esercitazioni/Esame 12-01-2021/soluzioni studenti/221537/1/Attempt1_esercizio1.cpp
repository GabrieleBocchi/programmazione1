#include <iostream>
#include <fstream>
using namespace std;

const int MAX_WORDS = 10000;
const int MAX_WORD_LEN = 100 + 1;

bool caratteriSonoPari(char* string);

int main(int argc, char * argv [])
{
  if(argc < 3) {
    cout << "Sintassi: ./a.out <file-in> <file-out>" << endl;
  } else {
    char* finPath = argv[1];
    char* foutPath = argv[2];
    fstream fin, fout;
    fin.open(finPath, ios::in);
    fout.open(foutPath, ios::out);
    if(fin.fail() || fout.fail()) {
      cout << "Errore di I/O" << endl;
    } else {

      char fileContents[MAX_WORDS][MAX_WORD_LEN];
      int words = 0;
      fin >> fileContents[words];
      words++;
      while(!fin.eof() && words < MAX_WORDS) {
        fin >> fileContents[words];
        words++;
      }

      for(int i = words-1; i >= 0; i--) {
        if(caratteriSonoPari(fileContents[i])) {
          fout << fileContents[i] << " ";
        }
      }

    }
    fin.close();
    fout.close();
  }
  return 0;
}

bool caratteriSonoPari(char* string) {
  int i = 0;
  while(string[i] != '\0') i++;
  return (i+1)%2 && i != 0;
}
