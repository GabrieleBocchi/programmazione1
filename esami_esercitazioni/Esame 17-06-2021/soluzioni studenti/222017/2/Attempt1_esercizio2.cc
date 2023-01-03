#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert

long long int convert(char * num, int dim);
long long int recursive(char *num, int len, int power);
int strlen(char *num, int index = 0);
int val(char num);
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

long long int convert(char * num, int dim){
  int len = strlen(num);
  return recursive(num, len-1, 1);
}

long long int recursive(char *num, int len, int power){
  // MR: Qui sarebbe stato opportuno verificare che len < maxDim
  if (len < 0){
    return 0;
  }else{
    return (val(num[len]) * power) + recursive(num,len-1,power*2);
  }
}

int val(char num){
  if (num == '0' || num == '1'){
    return (int) num - '0';
  }
  cout << "Input number contains number not in Base 2" << endl;
  exit(1);
}

int strlen(char * num,int index){
  // MR: Qui sarebbe stato opportuno anche verificare che index < maxdim!
  if (num[index] != '\0'){
        index++;
        return strlen(num, index);
    }else{
        return index;
    }
}

// Inserire qui sopra la definizione della funzione convert
