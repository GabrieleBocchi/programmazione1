#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char* source, int sourceMaxLength);
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

long long int pow(int base, int exp){
  long long int ret = 1;
  if(exp>0){
    ret = pow(base, exp-1);
    ret*=base;
  }
  return ret;
}

long long int convertRecursive(char* value, int i, int& exp, int sourceMaxLength){
  int base = 16;
  long long int res=0;
  if(i>=sourceMaxLength){
    cout<<"Array not containing \\0! Terminating..."<<endl;
    exit(0);
  }
  if(value[i] != '\0'){
    res = convertRecursive(value, i+1, exp, sourceMaxLength);
    int tmp;
    if(value[i] <= '9' && value[i] >= '0'){
      tmp = value[i] - '0';
    }else{
      // MR: qui ci sarebbe da controllare che il valore sia compreso
      // tra a e f
      tmp = value[i] - 'a' + 10;
    }
    res += tmp * pow(base, exp++);
  }
  return res;
}

long long int convert(char* source, int sourceMaxLength){
  int exp=0;
  return convertRecursive(source, 0, exp, sourceMaxLength);
}

// Inserire qui sopra la definizione della funzione convert
