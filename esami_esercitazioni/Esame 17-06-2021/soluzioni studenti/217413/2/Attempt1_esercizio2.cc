#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char * source, int dim);
// Inserire qui sopra la dichiarazione della funzione convert

long long int convert_to_dec(char * numero, double result, int contatore);


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
  // MR: Qui la base era da cambiare in 2, altrimenti se fa parsing di
  // numeri >=2 potrebbe ottenere risultati sbagliati
  for(int i = 0; ((i < maxdim) && (num[i] != '\0')); i++) {
    if (num[i] >= 'A' && num[i] <= 'Z') {
      num[i] = 'a' + (num[i] - 'A');
    }
    if (!check_base(num[i], base)) return false;
  }
  return true;
}

int strlen(char parola[]);
double pow(double numero, int esponente);
int binaryToDecimal(long long int n);



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

  // Debug

}

// Inserire qui sotto la definizione della funzione convert
long long int convert(char * source, int dim) {
  // MR: dim non usato!
  double risultato = 0;
  int contatore = 0, resto = 0;
  return convert_to_dec(source, risultato, contatore);
}
// Inserire qui sopra la definizione della funzione convert

long long int convert_to_dec(char * numero, double result, int contatore) {
  // MR: Non e' chiara la logica con cui vuole risolvere il problema!
  // Qui numero[contatore] e' un carattere!, strlen() ritorna
  // lunghezza della stringa numero!
  if (numero[contatore] == strlen(numero)) return 0;
  // MR: Non chiara logica, cosa intende con numero[contatore]%10 e numero[contatore]/10?
  // MR: Inoltre, anche con esempi del testo si ottengono dei valori assurdi!
  else return result += numero[contatore]%10 + 2*convert_to_dec(numero, numero[contatore++]/10, contatore);
}

int strlen(char parola[]) {
    int contatore = 0;
    // MR: COSA C'E' DI NON CHIARO IN "La funzione converti deve essere ricorsiva ed al suo interno NON ci possono essere cicli o chiamate a funzioni contenenti cicli. Si può però fare uso di funzioni ausiliarie da chiamare all'interno di questa funzione che NON contengano cicli o che siano ricorsive."?
    while(parola[contatore] != '\0') contatore++;
    return contatore;
}

double pow(double numero, int esponente) {
    // MR: COSA C'E' DI NON CHIARO IN "La funzione converti deve essere ricorsiva ed al suo interno NON ci possono essere cicli o chiamate a funzioni contenenti cicli. Si può però fare uso di funzioni ausiliarie da chiamare all'interno di questa funzione che NON contengano cicli o che siano ricorsive."?
    double risultato = 1;
    while (esponente != 0) {
        risultato *= numero;
        --esponente;
    }
    return risultato;
}

int binaryToDecimal(long long int n) {
  // MR: A cosa serve?
    if(n==0) return 0;
    else return (n%10 + 2*binaryToDecimal(n/10));
}
