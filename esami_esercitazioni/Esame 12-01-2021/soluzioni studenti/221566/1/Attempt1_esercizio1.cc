#include <iostream>
#include <fstream>
using namespace std;

bool testword(char *a);

int main(int argc, char *argv[])
{
  const int MAX_WORD = 10000;
  const int MAX_CHAR = 100;

  fstream in, out;

  char **allfile = new char *[MAX_WORD];

  char parola[MAX_CHAR];

  in.open(argv[1], ios::in);
  if (in.fail())
  {
    cout << "Errore in appertura int" << endl;
    exit(-1);
  }

  in >> parola;

  int word_count = 0;
  while (!in.eof())
  {

    allfile[word_count] = new char[MAX_CHAR];

    in >> allfile[word_count];

    word_count++;
  }

  out.open(argv[2], ios::out);
  if (in.fail())
  {
    cout << "Errore in appertura out" << endl;
    exit(-1);
  }

  for (int i = word_count-1; 0 < i; i--)
  {
    if (testword(allfile[i]))
    {
      out << allfile[i] << " ";
    }
  }

  in.close();
  out.close();

  return 0;
}

bool testword(char* word)
{
  bool res = true;
  for (int j = 0; j < 100; j++)
  {
    if (((word[j] == ' ') && (j < 2)))
    {
      res = false;
    }
  }
  return res;
}
