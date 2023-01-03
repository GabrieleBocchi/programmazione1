#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char *s, int dim);
// Inserire qui sopra la dichiarazione della funzione convert

//qui inserisco le dichiarazioni delle eventuali funzioni di supporto
long long int pow(int base, int exp);
//int length(char *s, int i);       //la lunghezza è passata come input

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

bool controlla(char *num, const int maxdim, const unsigned int base = 4)
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

long long int convert(char *s, int dim)
{
  int base = 4;
  int tmp = 0;
  int index = 0;
  long long int result = 0;
  if (s[index] == '\0')
  {
    return 0;
  }
  else
  {
    // MR: Qui s[index] e' un carattere con codifica ascii, non puo'
    // prendere valore e moltiplicarlo, deve prima convertire
    // carattere in numero! '0' != 0, ..., '3' != 3,
    tmp = s[index] * pow(base, dim - index - 1);
    index++;
    result += tmp;
    // MR: Qui va in ricorsione infinita non modicando mai ne' s ne' dim!
    return convert(s, dim);
  }
}

// Inserire qui sopra la definizione della funzione convert

//qui definisco le funzioni di supporto
long long int pow(int base, int exp)
{
  if (exp == 0)
  {
    return 1;
  }
  else
  {
    return base * pow(base, exp - 1);
  }
}

/*int length(char *s, int i)
{

  if (s[i] != '\0')
  {
    i++;
    return length(s, i);
  }
  return i;
} */
