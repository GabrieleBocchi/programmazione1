#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_CHAR = 101;
const int DIM = 19; // 4 + 1 + 4 + 1 + 4 + 1 + 4
// n n n n - n n n n - n n n n - n n n n 

bool controlla_parola(const char *word);

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    cout << "Numero di paramentri errato" << endl;
    exit(1);
  }
  else
  {
    fstream in, out;
    char parola[MAX_CHAR];
    int tot = 0;

    in.open(argv[1], ios::in);
    if (in.fail())
    {
      cout << "Errore apertura file input" << endl;
      in.close();
      exit(1);
    }
    else
    {
      while (in >> parola)
      {
        if (controlla_parola(parola))
          tot++;
      }
      in.close();
      out.open(argv[2], ios::out);
      if (out.fail())
      {
        cout << "Errore apertura file output" << endl;
        out.close();
        exit(1);
      }
      else
      {
        out << tot;
        out.close();
      }
    }
  }
  return 0;
}

bool controlla_parola(const char *word)
{
  bool res = true;
  int ln = strlen(word);
  if (ln != DIM)
    res = false;
  else
  {
    for (int i = 0; i < ln && res; i++)
    {
      // n n n n - n n n n - n  n  n  n  -  n  n  n  n
      // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
      if (i == 4 || i == 9 || i == 14)
      {
        if (word[i] != '-')
          res = false;
      }
      else if (!(word[i] >= '0' && word[i] <= '9'))
        res = false;
    }
  }
  return res;
}