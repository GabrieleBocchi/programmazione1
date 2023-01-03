#include <iostream>
#include <cstdlib>

using namespace std;

int f(int n);
int mypow(int i, int b);
int myatoi(char a[]);

int main(int argc, char * args[]){
    if(argc!=2){
        cout<<"errore  ";
        return (-1);
    }
    //int n=atoi(args[1]);
    // MR: What's the purpose of chaning this? It was not required!
    int n=myatoi(args[1]);
    cout<<n<<endl;
    // MR: Qui ha cambiato il main per fare tornare i conti!
    cout<<endl<<"il numero di coppie pari è:"<<f(n)-1<<endl;

    return 0;
}

//controllo se una cifra è pari e nel caso se lo è anche la successiva e nel caso retituisco la func(n/10)+1 fino ad annullare il parametro n
int f(int n){
  // MR: Su esempio: 54211228 ritorna erroneamente 0 invece che 3,
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

int myatoi(char a[]){
    int n=0;
    cout<<a<<endl;
    for(int i=0;a[i]!='\0';i++){
        cout<<a[i]-'0';
        n+=(a[i]-'0')*mypow(i, 10);
    }
    return n;
}

int mypow(int i, int b){
    if(i>0){
        return b*mypow(i-1,b);
    }
    return 1;
}
