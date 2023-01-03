#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(const char * num, const int maxdim);
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
	    ((n >= 'A') && (n <= 'F')) ||
	    ((n >= 'a') && (n <= 'f')));
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

long long int power(int base, int exp){
  if (exp == 0) return 1;
  return base * power(base, exp-1);
}

int get_number(const char c, const int base) {
  if (c >= '0' && c <= '9') {
    return int(c - '0');
  }
  else if (c >= 'a' && c <= 'f') {
    return 10 + int(c - 'a');
  }
  else if (c >= 'A' && c <= 'F') {
    return 10 + int(c - 'A');
  }
  else {
    return -1;
  }
}

long long int convert_aux(const char * num, const int maxdim,
			  const int base, int & dim_num, int i) {
  if (i < maxdim && num[i] == '\0') {
    dim_num = i-1;
    return 0;
  }
  int n = get_number(num[i], base);
  long long int tmp = convert_aux(num, maxdim, base, dim_num, i+1);
  return (n * power(base, dim_num - i)) + tmp;
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

long long int convert(const char * num, const int maxdim) {
  int tmp = 0;
  return convert_aux(num, maxdim, 4, tmp, 0);
}

// Inserire qui sopra la definizione della funzione convert
