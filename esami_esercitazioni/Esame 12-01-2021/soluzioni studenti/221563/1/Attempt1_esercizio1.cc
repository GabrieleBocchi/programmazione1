#include <iostream>
#include <fstream>
using namespace std;

int len(char * word) {
  int i = 0;
  while (word[i]!='\0') {
    i++;
  }
  return i;
}

int main(int argc, char * argv [])
{
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <inputFile> <outputFile>" << endl;
    exit(-1);
  }
  fstream in, out;
  in.open(argv[1], ios::in);
  if (in.fail()) {
    cout << "Failed to open " << argv[1] << endl;
    in.close();
    exit(-1);
  }
  char ** words = new char * [10002];
  words[0] = new char [101];
  int it = 0;
  while (in >> words[it]) {
    it++;
    words[it] = new char [101];
  }
  in.close();
  out.open(argv[2], ios::out);
  if (out.fail()) {
    cout << "Couldn't write on " << argv[2] << endl;
    out.close();
    exit(-1);
  }
  for (int i = it; i >= 0; i--) {
    if (len(words[i]) > 4)
      out << words[i] << " ";
  }
  for (int i = 0; i <= it; i++) {
    delete words[i];

  }
  delete [] words;
  return 0;
}
