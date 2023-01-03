#include <iostream>
#include <cstdlib>

using namespace std;

int f(int n);

int main(int argc, char * args[]){
    if(argc!=2){
        cout<<"errore  ";
        return (-1);
    }
    // MR: Nessuno le ha chiesto di cambiare il main!
    int n=atoi(args[1]);
    cout<<endl<<"il numero di coppie pari è:"<<f(n)<<endl;

    return 0;
}

//controllo se una cifra è pari e nel caso se lo è anche la successiva e nel caso retituisco la func(n/10)+1 fino ad annullare il parametro n
int f(int n){
  // MR: Su esempio: 54211228 ritorna erroneamente 2 invece che 3,
  // infatti le coppie sono: 54 42 21 11 12 22 28 e quelle pari sono:
  // 42, 22 e 28!
    if(n>0){
        if((n%10)%2==0){
            if(((n/10)%10)%2==0){
                return 1+f(n/10);
            }
	    // MR: Che cosa ritorna in questo caso? Va in default a 0
	    // invece che ritornare f(n/10)!
        }
        else return f(n/10);
    }
    return 0;
}
