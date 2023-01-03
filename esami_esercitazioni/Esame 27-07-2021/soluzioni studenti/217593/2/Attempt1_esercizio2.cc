#include <iostream>
#include <cstdlib>

using namespace std;

int intlen(int n){
    if(n == 0){
        return 0;
    }else{
        return 1+intlen(n/10);
    }
}

int strlen(char * s){
    if(*s == '\0'){
        return 0;
    }else{
        return 1+strlen(s+1);
    }
}


void get_digits(int n, char* s, int i){
    if(n>=10){
        get_digits(n/10, s, i-1);
    }
    int d = n % 10;
    s[i] = (char)( d +'0' );

}

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
void funzione_helper(char* str, int i, int& x){
  // MR: Avrebbe potuto calcolare strlen di str una sola volra, e
  // usare il valore invece di clacolarlo ad ogni ricorsione.
    if(i+1 != strlen(str)){
        if(str[i] != str[i+1]) x++;
        funzione_helper(str, i+1, x);
    }
}
int funzione(int n){
    int res = 0;
    if(n>=0){
      // MR: Avrebbe potuto calcolare intlen una sola volta e
      // memorizzando risultato in variabile locale, invece che
      // calcolarlo 2 volte (visto che costosa e ripete molte volte
      // stessa operazione in modo inutile, anche se corretto).
      // MR: La soluzione e' corretta ma inefficiente.
        char* str = new char[intlen(n)];
        get_digits(n, str, intlen(n)-1);
        funzione_helper(str, 0, res);
	// MR: Manca deallocazione di str!
    }
    return res;


}
// Scrivere qui sopra la dichiarazione e definizione della funzione "funzione"

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
