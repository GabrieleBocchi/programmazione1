#include <iostream>
#include <cstdlib>
using namespace std;



// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzione(int n);
int potenza(int n, int exp);
void solve(int n, char* a, int diff, int i=0);
void sol1(int n, char* a, int &i);
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


void solve(int n, char* a, int diff, int i){
    if(funzione(n)==1){
        a[i] = n+diff;
    }
    else if(funzione(n)>0){
        a[i] = n/(potenza(10,funzione(n)-1)) + diff;

        if(funzione(n)-1 != n%((potenza(10,funzione(n)-1)))){
            int nzeri = funzione(n)-1 - funzione(n%(potenza(10,funzione(n)-1)));
            sol1(nzeri, a, i);
        }

        solve(n%potenza(10,funzione(n)-1), a, diff, ++i);
    }
    else return;
}

void sol1(int n, char* a, int &i){
    if(n>0){
        i++;
        a[i] = '0';
        sol1(n-1,a,i);
    }
    else return;
}



int funzione(int n){
  //MR: Questa funzione non fa quello richiesto nel testo! Infatti
  //anche per gli esempi del testo da risposte errate!

  // MR: Strano che ci siano nomi di funzioni non utilizzate che sono
  // analoghe a quelle di Grilli Filippo, e.g. solve, sol1, potenza !
    int ans = 0;
    if(n>=1){
      if (n%2){
        n/=10;
        return 1 + funzione(n);
      }
      // MR: Che cosa ritorna se si finisce qui? Manca almeno un
      // return!
    }
    else return 0;
}

int potenza(int n, int exp){
  if(exp==0)
  {
    return 1;
  }
  else
  {
    return n*potenza(n, exp-1);
  }

}
