#include <iostream>
#include <fstream>
using namespace std;

int lunghezza_stringa(const char *parola);
int numero_caratteri(const char *parola, char c);
bool iniziale_m(const char *parola);
bool controllo_numero_i(const char *parola);
bool controllo_car_successivo_a_i(const char *parola);

const int MAX_LEN = 100 + 1;

int main(int argc, char *argv[])
{

  if (argc != 3)
  {
    cerr << "Utilizzo: <./a.out> <file_output> <file_input>" << endl;
    exit(1);
  }

  fstream input, output;

  input.open(argv[1], ios::in);
  if (input.fail())
  {
    cerr << "Errore nell'apertura file input" << endl;
    exit(2);
  }

  output.open(argv[2], ios::out);
  if (output.fail())
  {
    cerr << "Errore nell'apertura file_output" << endl;
    exit(3);
  }

  char parola[MAX_LEN];

  while (input >> parola)
  {
    // Includiamo solo quelle che NON soddisfano almeno un criterio.
    if (!iniziale_m(parola) || !controllo_numero_i(parola) || !controllo_car_successivo_a_i(parola))
    {
      output << parola << "\n";
    }
  }

  input.close();
  output.close();

  return 0;
}

// FUNCTIONS
int lunghezza_stringa(const char *parola)
{
  int res = 0;
  while (parola[res] != '\0')
  {
    res++;
  }
  return res;
}

int numero_caratteri(const char *parola, char c)
{
  int res = 0;
  for (int i = 0; parola[i] != '\0'; i++)
  {
    if (parola[i] == c)
      res++;
  }
  return res;
}

bool iniziale_m(const char *parola)
{
  bool res = true;
  if (parola[0] == 'M')
  {
    if (parola[(lunghezza_stringa(parola) - 1)] != 'U')
      res = false;
  }
  return res;
}

bool controllo_numero_i(const char *parola)
{
  bool res = false;
  char i = 'I';
  int numero_i = numero_caratteri(parola, i);
  if (((numero_i % 2) == 1) || numero_i == 0)
    res = true;
  return res;
}

bool controllo_car_successivo_a_i(const char *parola)
{
  bool res = true;
  int len = lunghezza_stringa(parola);

  // Escludiamo l'ultimo carattere perche' non
  // puo' avere un carattere successivo
  for (int i = 0; i < len - 1 && res; i++)
  {
    if (parola[i] == 'I')
      if (parola[i + 1] == 'M')
        res = false;
  }
  return res;
}
