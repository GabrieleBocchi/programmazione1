#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char num[], int maxdim);

// Inserire qui sopra la dichiarazione della funzione convert
long long int convert_ric(char num[],int i,int len, int maxdim, long long int ris);


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

//funzione ricorsiva per calcolare un esponenziale
long long int exp(int base, int esp){
  if (esp == 0)return 1;
  if (esp == 1)return base;
  return base*exp(base,esp-1);
 }

//funzione per calcolare la lunghezza dell'array
int strlen(char num[], int j){
  // MR: Manca controllo che j sia < maxdim
  if(num[j] == '\0'){
    return j;
  }else{
    // MR: che cosa si ritorna in questo caso? return is missing!
    strlen(num,j+1);
  }
}

//funzione per invertire un carattere nel corrispettivo numero
int converti_carattere(char a){
  // MR: Molto inefficiente: 'a' - '0' era sufficiente!
  switch(a){
    case '0':
      return 0;
    case '1':
      return 1;
    case '2':
      return 2;
    case '3':
      return 3;
    case '4':
      return 4;
    case '5':
      return 5;
    case '6':
      return 6;
    case '7':
      return 7;
  }
  // MR: Cosa ritorna in questo caso?
}

// Inserire qui sotto la definizione della funzione convert
long long int convert(char num[],int maxdim){
  int len = strlen(num,0);
  // MR: per caso funziona perche' ultimo valore sullo stack in strlen
  // e´ il valore della lunghezza, ma e' solo un caso. Devo
  // penalizzare perche' questo e' un problema!
  int i = 0;
  long long int ris = 0;
  convert_ric(num, i, len-1, maxdim, ris);
}

// Inserire qui sopra la definizione della funzione convert
long long int convert_ric(char num[],int i, int len, int maxdim, long long int ris){
  if(num[0] == '\0'){
    return 0;
  }else if(num[i] == '\0'){
    return ris;
  }else{
    long long int temp = exp(8,i);
    int temp1 = converti_carattere(num[len]);
    ris += temp1 * temp;
    convert_ric(num,i+1,len-1,maxdim,ris);
  }
}
