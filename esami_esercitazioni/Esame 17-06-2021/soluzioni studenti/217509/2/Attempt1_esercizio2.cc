#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char* number, int size);
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
	    ((n >= 'a') && (n <= 'f')));
  default:
    return false;
  }
}

bool controlla(char * num, const int maxdim, const unsigned int base = 16) {
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

int hex_to_dec(char c)
{
  // MR: Ok ma si dovrebbe controllare che altro valore sia compreso
  // tra a e f!
  if((c >= '0') && (c <= '9'))
    return c-'0';
  else
    return 10 + c-'a';
}

int strlen(char* string)
{
  if(*string == '\0')
    return 0;
  else
    return 1+strlen(string+1);
}

long long int convert_1(char* start, char* end, long long power)
{
  if(start > end)
    return 0;
  else
    return power * hex_to_dec(*end) + convert_1(start, end-1, power*16);
}

long long int convert(char* number, int size)
{
  return convert_1(number, &number[strlen(number)-1], 1);
}

// Inserire qui sopra la definizione della funzione convert
