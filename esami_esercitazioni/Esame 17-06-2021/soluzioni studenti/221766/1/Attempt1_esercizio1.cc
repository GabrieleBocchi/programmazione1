#include <iostream>
#include <fstream>
using namespace std;

const int DIM_PAROLA = 101;

int length(char parola[], int i = 0)
{
  if (parola[i] == '\0')
  {
    return 0;
  }
  return 1 + length(parola, i + 1);
}

int count_letter(char parola[], char lettera, int i = 0)
{
  if (parola[i] == '\0')
  {
    return 0;
  }
  if (parola[i] == lettera)
  {
    return 1 + count_letter(parola, lettera, i + 1);
  }
  return count_letter(parola, lettera, i + 1);
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    cout << "Usage: ./a.out parole.txt risultato.txt" << endl;
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

  while (my_in >> parola)
  {
    int len = length(parola);
    if (parola[0] == 'M' && parola[len - 1] != 'U')
    {
      my_out << parola << endl;
    }

    else if (!(count_letter(parola, 'I') == 0 || count_letter(parola, 'I') % 2 != 0))
    {
      my_out << parola << endl;
    }
    else
    {
      bool valida = true;
      for (int i = 0; i < len - 1 && valida; i++)
      {
        if (parola[i] == 'I' && parola[i + 1] == 'M')
        {
          valida = false;
        }
      }

      if (!valida)
      {
        my_out << parola << endl;
      }
    }
  }

  my_in.close();
  my_out.close();
  return 0;
}