#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char [], int, int base = 8);
long long int convert_ric(char [], int, int, int);
long long int power(int base, int exp);
int lunghezza(char word[], int index);
// Inserire qui sopra la dichiarazione della funzione convert


bool check_base(const char n, const int base) {
  switch(base) {
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

bool controlla(char * num, const int maxdim, const unsigned int base = 4) {
  for(int i = 0; ((i < maxdim) && (num[i] != '\0')); i++) {
    if (num[i] >= 'A' && num[i] <= 'Z') {
      num[i] = 'a' + (num[i] - 'A');
    }
    if (!check_base(num[i], base)) return false;
  }
  return true;
}


int main() {
  const unsigned int maxdim = 100;
  char number[maxdim];

  cout << "Inserire numero: ";
  cin >> number;
  if (!controlla(number, maxdim)) {
    cout << "Il numero deve contenere solo caratteri rispetto alla base" << endl;
    exit(1);
  }

  long long int decimal = convert(number, maxdim);

  cout << "The converted number is: " << decimal << endl;
}

// Inserire qui sotto la definizione della funzione convert
long long int convert(char number[], int maxDim, int base)
{
  int length = lunghezza(number, 0);
  cout << length << endl;
  return convert_ric(number, length, 0, base);
}

long long int convert_ric(char number[], int length, int index, int base)
{
  long long int res = 0;

  // MR: Manca controllo che index < maxdim
  if (number[index] != '\0')
  {
    // MR: Manca controllo che number[index] sia compreso tra 0 e 7
    long long int numeroInt = number[index] - '0';
    cout << numeroInt << endl;
    res = (numeroInt * power(base, length-index-1)) + convert_ric(number, length, index+1, base);
    cout << "res " << res << endl;
  }
  return res;
}

long long int power(int base, int exp)
{
  long long int res = 1;
  if (exp > 0)
  {
    res = (long long int)base * power(base, exp-1);
  }
  return res;
}

int lunghezza(char word[], int index)
{
  int lung = 0;
  if (word[index] != '\0')
  {
    lung = 1 + lunghezza(word, index+1);
  }
  return lung;
}

// Inserire qui sopra la definizione della funzione convert
