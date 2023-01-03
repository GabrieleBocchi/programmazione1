#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int ncifre(int n);
int potenza(int n, int exp);
// MR: Strano che ci siano nomi di funzioni non utilizzate che sono
// analoghe a quelle di Dauti Andriano, e.g. solve, sol1, potenza !
void solve(int n, int* a,int i=0);
void sol1(int n, int* a, int &i);
int numerocoppie(int* a, int i, int n);

int funzione(int n){
  // MR: Cosa succede se il numero e' negativo? ncifre torna 0, e
  // quindi cerca di allocare un array di size -1!
    int* a = new int[ncifre(n)-1];
    int conta = 0;

    solve(n,a, 0);
    int numcifre = ncifre(n);
    conta = numerocoppie(a, conta, numcifre);
    // MR: Dove e' deallocato a?
    return conta;
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

int numerocoppie(int* a, int i, int n)
{
    if(i<n-1)
    {

        if(a[i] % 2 == 1 && a[(i+1)]%2 == 1)
        {
            return 1+numerocoppie(a, ++i, n);
        }
        else
        {
            return numerocoppie(a, ++i, n);
        }
    }
    return 0;
}

void solve(int n, int* a, int i){
  // MR: Soluzione estremanente inefficiente! Chiama ncifre(),
  // funzione ricorsiva moltissime volte! Lo scopo di questa funzione
  // se non erro e' di convertire intero in array di cifre 0-9... cosa
  // che si poteva evitare agendo direttamente sul numero!
    if(ncifre(n)==1){
      // MR: Manca controllo che i sia minore di size di a!
        a[i] = n;
    }
    else if(ncifre(n)>0){
        a[i] = n/(potenza(10,ncifre(n)-1));

        if(ncifre(n)-1 != ncifre(n%(potenza(10,ncifre(n)-1)))){
            int nzeri = ncifre(n)-1 - ncifre(n%(potenza(10,ncifre(n)-1)));
            sol1(nzeri, a, i);
        }

        solve(n%potenza(10,ncifre(n)-1), a, ++i);
    }
    else return;
}

void sol1(int n, int* a, int &i){
    if(n>0){
        i++;
        a[i] = 0;
        sol1(n-1,a,i);
    }
    else return;
}

int ncifre(int n){
    int ans = 0;
    if(n>=1){
        n/=10;
        return 1 + ncifre(n);
    }
    else return 0;
}

int potenza(int n, int exp){
    if(exp>1){
        return n*potenza(n,exp-1);
    }
    else return n;
}
