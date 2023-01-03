#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(const char number[], int maxdim, int pos=0);
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
                    ((n >= 'a') && (n <= 'f'))); // EDIT ERA <=d
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
    if (!controlla(number, maxdim, 16)) {
        cout << "Il numero deve contenere solo caratteri rispetto alla base" << endl;
        exit(1);
    }

    long long int decimal = convert(number, maxdim);

    cout << "The converted number is: " << decimal << endl;
}


int strlen(const char str[]){
  // MR: COSA NON E' CHIARO IN QUESTA FRASE: "La funzione converti
  // deve essere ricorsiva ed al suo interno NON ci possono essere
  // cicli o chiamate a funzioni contenenti cicli. Si può però fare
  // uso di funzioni ausiliarie da chiamare all'interno di questa
  // funzione che NON contengano cicli o che siano ricorsive."?
    int i = 0;
    while(str[i] != '\0')i++;
    return i;
}
// Inserire qui sotto la definizione della funzione convert
long long int convert(const char number[], int maxdim, int pos){
    long long int res = 0;
    if (pos != strlen(number)) {

        char digit = number[strlen(number) - pos - 1];
	// MR: Manca controllo per verificare che i valori siano
	// compresi tra a e f nel caso non sia un digit!
        int add = digit >= '0' && digit <= '9' ? digit - '0' : digit - 'a' + 10;
        res = 16 * convert(number, maxdim, pos + 1) + add;
    }
    return res;

}

// Inserire qui sopra la definizione della funzione convert
