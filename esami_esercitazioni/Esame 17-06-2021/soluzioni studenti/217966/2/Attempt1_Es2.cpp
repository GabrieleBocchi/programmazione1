#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char number[], int dim);
// Inserire qui sopra la dichiarazione della funzione convert

void rovescia(char number[], char aux[], int dim, int &i);
int dimArray(char number[], int dim, int lenght);
long long int converti(char number[], int dim, int i);
int pow(int b, int e);


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
  // MR: Qui avrebbe dovuto cambiare in base = 2
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


long long int convert(char number[], int dim){

    int i=0,lenght=0;
    char aux[dim];
    // MR: Inefficiente perche' duplica memoria, ma corretto
    lenght = dimArray(number, dim, lenght);
    rovescia(number, aux, lenght, i);
    //cout <<aux;
    i=0;
    return converti(aux, lenght, i);

}


// Inserire qui sopra la definizione della funzione convert

int dimArray(char number[], int dim, int lenght){

    if(number[lenght] != '\0'){
        return dimArray(number, dim, lenght+1);
        cout <<lenght <<endl;
    }
    return lenght;

}


void rovescia(char number[], char aux[], int dim, int &i){      //Inverto array

    if(i <= (dim)/2){

        aux[i] = number[dim-1-i];
        aux[dim-1-i] = number[i];
        i++;
        rovescia(number, aux, dim, i);

    }

}

int pow(int base, int exp){

    if(exp > 0){
        return base * pow(base, exp-1);
    }
    return 1;

}

long long int converti(char number[], int dim, int i){

    int ris=0;
    if(i<dim){
      //cout <<"ris" <<ris <<endl;

      // MR: Qui invece che 48 avrebbe dovuto usare carattere asci
      // corrispondente allo '0'! Non controllando che i valori siano
      // 1/0 se per caso da in input 201 ottiene 9 invece che
      // segnalare errore
      return ris= ris + ((number[i]-48)*pow(2,i)) + converti(number,dim,i+1);

    }
    return 0;

}
