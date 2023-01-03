#include <iostream>

using namespace std;

int length(char *s, int i)
{
    // MR: Manca controllo che i < maxdim
    int res;
    if (s[i] != '\0')
    {
        i++;
        res = length(s, i);
    }
    else
    {
        res = i;
    }
    return res;
}

long int pow_(int n, int m, int res)
{
  long int result;
  if (m == 0)
  {
    result = res;
  }
  else
  {
    res *= n;
    m--;
    result = pow_(n, m, res);
  }
  return result;
}

long int pow(int n, int m)
{
  return pow_(n, m, 1);
}

long long int convert_(char *s, int size, int count, long long int res);

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char *s, int size);
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

bool controlla(char *num, const int maxdim, const unsigned int base = 8)
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
long long int convert(char *s, int size)
{
  int count = 0;
  long long int res = 0;
  size = length(s,0);
  return convert_(s, size-1, count, res);
}
long long int convert_(char *s, int size, int count, long long int res)
{
  long long int result;
  if (size < 0)
    result = res;
  else
  {
    // MR: mancano controlli che s[size] sia 0...7
    res += (long long int)(s[size] - '0') * pow(8, count);
    count++;
    size--;
    result = convert_(s,size,count,res);
  }
  return result;
}
// Inserire qui sopra la definizione della funzione convert
