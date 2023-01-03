#include<iostream>
#include<fstream>

using namespace std;

bool pari(char v[100]);

int main (int argc, char *argv[]){

    ifstream in;
    ofstream out;

    char parole [1000][100];
    char appoggio[100];
    int index=0,i=0, j=0;
    int retval=0;
    if(argc!=3){
        cout<<"\nErrore nel numero di argomenti\n";
        retval=2;
    }
    in.open(argv[1],ios::in);
    if(in.fail()){
        cout<<"\nSi è verificato un'errore nell'apertura del file di input.\n";
        retval=2;
    }
    else if (retval!=2){
        while(!in.eof()){
        
            in.get(appoggio[0]);
            i=0;
            while(appoggio[i]!=' '){
                i++;
                in.get(appoggio[i]);
            }

            if(pari(appoggio)){
                i=0;
                while(appoggio[i]!=' '){
                    parole[index][i]=appoggio[i];
                    i++;
                }
                parole[index][i]=' ';
                index++;
            }
            for(j=0;j<=i;j++){
                appoggio[j]=' ';
            }
        
        }
    }
    
    in.close();

    out.open(argv[2],ios::out);
    if(out.fail()){
        cout<<"\nSi è verificato un'errore nell'apertura del file di output\n";
        retval=2;
    }
    else if (retval!=2){
        while(index>=0){
            out<<parole[index]<<" ";
            index--;
        }
        out<<"\0";
        out.close();
    }
    

    return 0;
}

bool pari(char v[100]){
    bool ret;
    int i=0;
    while(v[i]!=' ') i++;
    if((i%2)==0) ret=true;
    else ret=false;
    return ret;
}