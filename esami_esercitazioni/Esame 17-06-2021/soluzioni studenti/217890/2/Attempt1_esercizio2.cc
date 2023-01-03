#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert

// Inserire qui sopra la dichiarazione della funzione convert
long long int convert (char number[],int i);


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


// Inserire qui sopra la definizione della funzione convert

void convert_recursive(char number[],int maxdim,long long int &result);
long long int pow(int base, int n );

long long int convert (char number[],int maxdim){

    long long int result = 0;
    convert_recursive(number,0,result);
    return result;

}



int change_in_num(char s){
    if (s=='1')
    return 1;
    else if (s=='0')
    return 0;
    else {
        cerr << "Non tutti i numeri inseriti fanno parte del sistema decimale"<<endl;
        exit(1);
    }
}

long long int pow_recursive (int base, int n){

    if(n==0)
        return 1;
    if(n>0){
        n--;
        return base*pow(base,n);
    }
    // MR: Cosa succede se per caso n < 0?

}


void convert_recursive(char number[],int i, long long int &result) {
  // MR: Sta interpretando la stringa in modo rovesciato. Infatti 1000
  // non e' 1, ma bensi 8!
    if(number[i]!='\0'){
        int num = change_in_num(number[i]);
        result = result + (num*pow_recursive(2,i));

        i++;
        convert_recursive(number,i,result);
    }

    return;

}

long long int pow(int base, int n ) {
  // MR: COSA C'E' DI NON CHIARO IN: "La funzione converti deve essere
  // ricorsiva ed al suo interno NON ci possono essere cicli o
  // chiamate a funzioni contenenti cicli. Si può però fare uso di
  // funzioni ausiliarie da chiamare all'interno di questa funzione
  // che NON contengano cicli o che siano ricorsive."? Le sembra
  // ricorsiva? Le sembra non chimata da converti?
    int result=1;
    for (int i = 0; i<n;i++){
        result =  result*2;
    }
    return result;

}
