// GDT: questa soluzione mi piace anche di più di quella ufficiale!
// Come unica cosa, nella funzione strlength() dovresti inizializzare il valore di int a zero. Infatti, la variabile i ha un valore indeterminato (che potrebbe essere diverso da zero).

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_WORDS = 10000;
const int MAX_LENGTH = 101;

int strlength(const char[]);

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    cout << "Usage: ./a.out <input_file> <output_file>" << endl;
    exit(1);
  }

  fstream inStream, outStream;
  inStream.open(argv[1], ios::in);
  outStream.open(argv[2], ios::out);

  if (inStream.fail())
  {
    cout << "Error opening input file" << endl;
    exit(1);
  }

  if (outStream.fail())
  {
    cout << "Error opening/creating output file" << endl;
    exit(1);
  }

  int i = 0;
  char words[MAX_WORDS][MAX_LENGTH];

  while (inStream >> words[i] && i < MAX_WORDS)
  {
    if (strlength(words[i]) <= 4)
      i++;
  }

  for (int j = i - 1; j >= 0; j--)
  {
    outStream << words[j] << " ";
  }

  inStream.close();
  outStream.close();

  return 0;
}

int strlength(const char word[])
{
  int i;
  while (word[i] != '\0')
    i++;

  return i;
}
