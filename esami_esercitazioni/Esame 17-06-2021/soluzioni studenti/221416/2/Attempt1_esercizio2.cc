#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char numero[], int maxdim);
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

  // PER TEST VELOCI

  // char *source = "1101";
  // int i;
  // for (i = 0; i < source[i] != '\0'; i++)
  // {
  //   number[i] = source[i];
  // }
  // number[++i] = '\0';

  // FINE TEST
  if (!controlla(number, maxdim))
  {
    cout << "Il numero deve contenere solo caratteri rispetto alla base" << endl;
    exit(1);
  }

  long long int decimal = convert(number, maxdim);

  cout << "The converted number is: " << decimal << endl;
}

// Inserire qui sotto la definizione della funzione convert
void converti_ric(char *v, int maxdim, long long int &res)
{
  if (*v == '\0' || maxdim == 0)
  {
    return;
  }
  int q = *v - '0'; // MR cosa succede con 'a' ... 'f'?
  res *= 2; // MR: Perche' moltiplicare per 2?
  res += q; // MR: cosa significa sommare q?
  converti_ric(v + 1, maxdim - 1, res);
}

long long int convert(char numero[], int maxdim)
{
  long long int res = 0;
  converti_ric(numero, maxdim, res);
  return res;
}

// Inserire qui sopra la definizione della funzione convert
