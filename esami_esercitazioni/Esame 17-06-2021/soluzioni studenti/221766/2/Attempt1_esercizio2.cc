#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char number[], int maxdim);
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
  if (!controlla(number, maxdim, 16))
  { //HO AGGIUNTO 16
    cout << "Il numero deve contenere solo caratteri rispetto alla base" << endl;
    exit(1);
  }

  long long int decimal = convert(number, maxdim);

  cout << "The converted number is: " << decimal << endl;
}

// Inserire qui sotto la definizione della funzione convert
int length(char number[], int i = 0)
{
  // MR: mancao controllo che dimensione < maxdim, se manca \0 va in
  // ricorsione infinita!
  if (number[i] != '\0')
  {
    return 1 + length(number, i + 1);
  }
  return 0;
}


long long int convert_helper(char number[], int maxdim, int len, int pos)
{

  if (pos==len)
    return 0;

  char digit = number[len - pos - 1];
  long long int add = 0;
  if (digit >= '0' && digit <= '9')
  {
    add = digit - '0';
  }
  else
  {
    // MR: manca controllo che digit <= f e >= a
    add = digit - 'a' + 10;
  }
  long long int pow = 1;
  // MR: COSA NON E' CHIARO IN QUESTA FRASE "La funzione converti deve
  // essere ricorsiva ed al suo interno NON ci possono essere cicli o
  // chiamate a funzioni contenenti cicli. Si può però fare uso di
  // funzioni ausiliarie da chiamare all'interno di questa funzione
  // che NON contengano cicli o che siano ricorsive."? Mi spiace ma
  // devo dare 0!
  for (int i = 0; i < pos; i++)
  {
    pow *= 16;
  }
  return add * pow + convert_helper(number, maxdim, len, pos + 1);
}

long long int convert(char number[], int maxdim)
{
  int pos = 0;
  int len = length(number);

  return convert_helper(number, maxdim, len, pos);
}
// Inserire qui sopra la definizione della funzione convert
