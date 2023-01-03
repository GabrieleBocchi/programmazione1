#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int DIM_PAROLA = 101;

bool is_allowed(char simbolo)
{
  return simbolo >= 'A' && simbolo <= 'Z';
}

bool valid_word(char s[], int start, int end)
{
  bool valid = true;
  if (start < 0 || end <= start)
  {
    valid = false;
  }

  for (int i = start; i < end && valid; i++)
  {
    if (!is_allowed(s[i]))
    {
      valid = false;
    }
  }

  return valid;
}

bool check(char s[])
{
  int len_code = 19;

  bool valid = true;
  if (strlen(s) != len_code)
  {
    valid = false;
  }

  int i = 0;
  while (i < len_code && valid)
  {
    if (!valid_word(s, i, i + 4))
    {
      valid = false;
    }
    i += 4;

    if (i < len_code && s[i] != '-')
    {
      valid = false;
    }
    i++; // salta il trattino
  }

  return valid;
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    cout << "Usage: ./a.out input.txt output.txt" << endl;
    exit(1);
  }
  fstream my_in, my_out;
  my_in.open(argv[1], ios::in);
  my_out.open(argv[2], ios::out);

  if (my_in.fail())
  {
    cout << "Non sono riuscito ad aprire il file " << argv[1] << endl;
    my_in.close();
    my_out.close();
    exit(1);
  }

  char parola[DIM_PAROLA];
  int res = 0;
  while (my_in >> parola)
  {
    if (check(parola))
    {
      res++;
    }
  }

  my_out << res << endl;

  my_in.close();
  my_out.close();
  return 0;
}
