#include <iostream>
#include <fstream>
using namespace std;

const int NPAR = 10000;
const int NLEN = 100 + 1;

int get_len(char[]);
char *copy(char str[], int ln);

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    cout << "Numero di parametri errati" << endl;
    return -1;
  }
  else
  {
    fstream in, out;
    char word[NLEN];
    char **text;
    int dimtxt = 0;
    int index = 0;

    text = new char *[NPAR];
    in.open(argv[1], ios::in);

    if (!in.fail())
    {
      in >> word;
      while (!in.eof())
      {
        int ln = get_len(word);
        if (ln <= 4)
        {
          text[index] = copy(word, ln);
          index++;
        }

        in >> word;
      }

      in.close();
      out.open(argv[2], ios::out);
      if (!out.fail())
      {
        for (int i = index - 1; i >= 0; i--)
          out << text[i] << endl;
      }
      else
      {
        cout << "File output problem" << endl;
        return -1;
      }
      out.close();
    }
    else
    {
      cout << "File input problem" << endl;
      return -1;
    }

    for(int i = 0; i < NPAR; i++)
      delete[] text[i];
    delete[] text;
    return 0;
  }
}
int get_len(char s[])
{
  int ln = 0;
  while (s[ln] != '\0')
  {
    ln++;
  }
  return ln;
}

char *copy(char str[], int ln)
{
  char *res = new char[ln + 1];
  for (int i = 0; i < ln; i++)
    res[i] = str[i];
  return res;
}