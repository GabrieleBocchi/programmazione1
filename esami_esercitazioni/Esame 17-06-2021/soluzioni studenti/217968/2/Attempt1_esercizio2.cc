#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
int strlen (char str[], const int & maxdim, int i=0)
{
  int retval;
  if (str[i]=='\0' || i>=maxdim) retval=0;
  else retval = 1+strlen(str, maxdim, i+1);
  return retval;
}
void convert1(char source[], const int & dim, long long int & n, int i)
{
  if (i < dim)
  {
    // MR: Manca controllo che source[i] sia compreso tra 0 e 7
    n += (source[i] - '0') * (1 << ((dim - 1 - i)*3));
    convert1(source, dim, n, i+1);
  }
}
long long int convert(char source[], int maxdim)
{
  long long int n = 0;
  int dim = strlen(source, maxdim);
  convert1(source, dim, n, 0);
  return n;
} //RICORSIVA!

// Inserire qui sopra la dichiarazione della funzione convert


bool check_base(const char n, const int base) {
  switch(base) {
  case 2:
    return ((n == '0') || (n == '1'));
  case 4:
    return ((n >= '0') && (n <= '3'));
  case 8:
    return ((n >= '0') && (n <= '7'));
  case 16:
    return (((n >= '0') && (n <= '9')) ||
	    ((n >= 'A') && (n <= 'D')) ||
	    ((n >= 'a') && (n <= 'd')));
  default:
    return false;
  }
}

bool controlla(char * num, const int maxdim, const unsigned int base = 8) {
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


// Inserire qui sopra la definizione della funzione convert
