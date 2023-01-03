#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char * n, int dim);
long long int convert_aux(char *n, int dim, int &i);
long long int pow(int number, int exp);
// Inserire qui sopra la dichiarazione della funzione convert
long long int convert(char * n, int dim)
{
    int i = 0;
    return convert_aux(n,dim,i);
}

long long int convert_aux(char *n, int dim, int &i) //Hex to Dec
{
    long long int resValue = 0;
    // MR: manca controllo che non si ecceda dimensione di n nel caso
    // in cui manchi \0
    if (n[0] != '\0')
    {
        long long int a = n[0];
        if ('0' <= a && a <= '9') //sistemo i valori di a
        {
            a = a - '0';
        }
        else
        {
	  // MR: occorrerebbe controllare che a sia compreso tra a e f
            a = a-'a'+10;
        }
        cout << "a: " << a << endl;

        resValue = convert_aux(n+1, dim, i) + a*pow(16,i);
        cout << "resValue: " << resValue << endl;
        i++;
    }
    return resValue;
}

long long int pow(int number, int exp)
{
  // MR: se exp < 0 ricorsione infinita
    int resValue = 1;
    if (exp == 0)
    {
        resValue = 1;
    }
    else
    {
        resValue = number*pow(number,exp-1);
    }
    return resValue;
}

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
	    ((n >= 'A') && (n <= 'F')) || //n <= 'D'
	    ((n >= 'a') && (n <= 'f'))); //n <= 'd'
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


// Inserire qui sopra la definizione della funzione convert
