#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long convert(char[], const unsigned int);
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
            ((n >= 'A') && (n <= 'F')) ||
            ((n >= 'a') && (n <= 'f')));
  default:
    return false;
  }
}

bool controlla(char *num, const int maxdim, const unsigned int base = 16)
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

int hexValueToInt(char val)
{
  //se >'9' è una lettera!
  if (val > '9')
    // MR: non usare i valori ascii in modo esplicito. Bastava fare
    // val - 'a' + 10, e controllare che val sia compreso tra a-f
    return val - 97 + 10;
  else
    // MR: val - '0' piu' corretto perche' indipendente dall'encoding.
    return val - 48;
}

int powRic(int base, int exp)
{
  // MR: se exp < 0 va in ricorsione potenzialmente infinita
  if (exp == 0)
    return 1;
  else
    return base * powRic(base, exp - 1);
}

void getLenghtRic(char arr[], int &index)
{
  // MR: Manca controllo index < maxdim. Se manca \0 va in ricorsione infinita
  if (arr[index] != '\0')
  {
    index += 1;
    return getLenghtRic(arr, index);
  }
  else
    return;
}

long long convertRic(char hex[], const unsigned int maxDim, int index, int ciclo)
{
  long long res = 0;
  // MR: Manca controllo che index < maxdim
  if (index >= 0)
  {
    char digit = hex[index];
    int db = hexValueToInt(digit);
    res += (db * powRic(16, ciclo)) + convertRic(hex, maxDim, index - 1, ciclo + 1);
  }
  return res;
}

// Inserire qui sotto la definizione della funzione convert
long long convert(char number[], const unsigned int maxDim)
{
  int index = 0;
  getLenghtRic(number, index);
  return convertRic(number, maxDim, index - 1, 0);
}
// Inserire qui sopra la definizione della funzione convert
