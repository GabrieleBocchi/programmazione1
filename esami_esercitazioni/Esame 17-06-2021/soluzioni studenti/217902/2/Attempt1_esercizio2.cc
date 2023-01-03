#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char number[], unsigned int maxdim);

long long int convertiRic(char number[], unsigned int maxdim, int i);
// Inserire qui sopra la dichiarazione della funzione convert
int pot(int base, int esp);

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
long long int convert(char number[], unsigned int maxdim){
  return convertiRic(number, maxdim, 0);
}

long long int convertiRic(char number[], unsigned int maxdim, int i){
  // MR: Array interpretato in modo errato. 0001 e' visto come 4096
  // invece che come 1. Dualmente 1000 e' visto come 1 invece che 4096.
  // Manca controllo che 0 <= i < maxdim
  if(number[i] == '\0'){
    return 0;
  }else{
    int num;
    switch (number[i])
    {
      // MR: si poteva fare in modo piu' efficace con aritmetica dei
      // char: (number[i] - '0' se >=0 <= 9, number[i] - 'a' + 10 se   >= a <= f
      case '0':{num = 0; break;}
      case '1':{num = 1; break;}
      case '2':{num = 2; break;}
      case '3':{num = 3; break;}
      case '4':{num = 4; break;}
      case '5':{num = 5; break;}
      case '6':{num = 6; break;}
      case '7':{num = 7; break;}
      case '8':{num = 8; break;}
      case '9':{num = 9; break;}
      case 'a':{num = 10; break;}
      case 'b':{num = 11; break;}
      case 'c':{num = 12; break;}
      case 'd':{num = 13; break;}
      case 'e':{num = 14; break;}
      case 'f':{num = 15; break;}
    default:
      break;
    }
    cout<<num<<endl;
    return convertiRic(number, maxdim, i+1) + (num * pot(16,i));
  }
}

// Inserire qui sopra la definizione della funzione convert
int pot(int base, int esp){
  // MR: potenziale ricorsione infinita se exp < 0
  if(esp == 1){
    return base;
  }else if(esp == 0) {
    return 1;
  }else{
    return pot(base, esp-1) * base;
  }
}
