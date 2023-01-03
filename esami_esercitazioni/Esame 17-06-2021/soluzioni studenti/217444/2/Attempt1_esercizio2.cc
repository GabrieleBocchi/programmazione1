#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char *number, unsigned int maxdim);
void lunghezza_stringa(char *number, int *len, int i);
void potenza(int base, int exp, int *result);
void convert_recursive(char *number, unsigned int maxdim, long long int *res, int index, int power);
// Inserire qui sopra la dichiarazione della funzione convert

bool check_base(const char n, const int base)
{
  switch (base)
  {
  case 2:
    return ((n == '0') || (n == '1'));
  case 4:
    return ((n >= '0') && (n <= '3'));
  case 8:
    return ((n >= '0') && (n <= '8'));
  case 16:
    return (((n >= '0') && (n <= '9')) ||
            ((n >= 'A') && (n <= 'D')) ||
            ((n >= 'a') && (n <= 'd')));
  default:
    return false;
  }
}

bool controlla(char *num, const int maxdim, const unsigned int base = 2)
{
  for (int i = 0; ((i < maxdim) && (num[i] != '\0')); i++)
  {
    if (num[i] >= 'A' && num[i] <= 'Z')
    {
      num[i] = 'a' + (num[i] - 'A');
    }
    if (!check_base(num[i], base))
      return false;
  }
  return true;
}

int main()
{
  const unsigned int maxdim = 100;
  char number[maxdim];

  cout << "Inserire numero: ";
  cin >> number;
  if (!controlla(number, maxdim))
  {
    cout << "Il numero deve contenere solo caratteri rispetto alla base" << endl;
    exit(1);
  }

  long long int decimal = convert(number, maxdim);

  cout << "The converted number is: " << decimal << endl;
}

// Inserire qui sotto la definizione della funzione convert

long long int convert(char *number, unsigned int maxdim)
{
  int len = 0;
  long long int res = 0;
  lunghezza_stringa(number, &len, 0);
  convert_recursive(number, maxdim, &res, 0, len - 1);

  return res;
}

void lunghezza_stringa(char *number, int *len, int i)
{
  // MR: len poteva passarlo per riferimento visto che il C++ lo
  // consente, ma anche come puntatore va bene!

  // MR: Manca controllo che i sia minore di maxdim. Ok che per come
  // chiamata non puo' succedere, ma e' sempre meglio fare questi
  // controlli. Soprattutto se number non e' terminato con \0
  if (number[i] != '\0')
  {
    *len += 1;
    lunghezza_stringa(number, len, i + 1);
  }
}

void potenza(int base, int exp, int *result)
{
  // MR: Anche qui avrebbe potuto usare il passaggio per riferimento
  if (exp > 1)
  {
    *result *= base;
    potenza(base, exp - 1, result);
  }
}

void convert_recursive(char *number, unsigned int maxdim, long long int *res, int index, int power)
{
  char tmp;
  int value;

  if (number[index] != '\0')
  {
    tmp = number[power];

    switch (tmp)
    {
    case '0':
      value = 0;
      break;
    case '1':
      value = 1;
      break;
    default:
      cerr << "Errore inaspettato" << endl;
      break;
    }

    if (index == 0)
    {
      *res += value;
    }
    else
    {
      int tmp_potenza = 2;
      potenza(2, index, &tmp_potenza);
      *res += tmp_potenza * value;
    }

    convert_recursive(number, maxdim, res, index + 1, power - 1);
  }
}

// Inserire qui sopra la definizione della funzione convert
