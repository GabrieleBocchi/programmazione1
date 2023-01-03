#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzione(int numero);
// Scrivere qui sopra la dichiarazione e definizione della funzione "funzione"
int numero_inverso(int numero);
int n_elemento_numero(int numero, int cifra);
long long int pow(int base, int exp);
int numero_cifre(int numero);

int main(int argc, char ** argv) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <positivenum> " << std::endl;
    exit(1);
  }
  int n = atoi(argv[1]);
  std::cout << "The read string is: " << argv[1] << std::endl;
  std::cout << "The converted value is: " << n << std::endl;
  std::cout << "function("<< n << ") = " << funzione(n) << std::endl;
}

int funzione(int numero) {
  // MR: Soluzione con logica complicata (inutilmente) ma corretta!
    numero = numero_inverso(numero);
    int cifra_1 = numero%10;
    int numero_2 = numero/10;
    int cifra_2 = numero_2%10;
    if (numero==0) return 0;
    if (cifra_1%2==1 && cifra_2%2==1) return funzione(numero/10) + 1;
    else return funzione(numero/10);
}

int numero_inverso(int numero) {
    int cifre = numero_cifre(numero);
    if (numero==0) return 0;
    return ((numero%10*pow(10,--cifre))+numero_inverso(numero/10));
}

int n_elemento_numero(int numero, int cifra) {
    if (cifra==1) return numero%10;
    return n_elemento_numero(numero/10,--cifra);
}

long long int pow(int base, int exp) {
  if (exp == 0) return 1;
  return base * pow(base, exp-1);
}

int numero_cifre(int numero) {
    return (numero>=10) ? 1 + numero_cifre(numero/10) : 1;
}
