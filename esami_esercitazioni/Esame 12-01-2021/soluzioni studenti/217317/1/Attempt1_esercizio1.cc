#include<iostream>
#include<fstream>
using namespace std;

int lunghezza(char m[10000][100],int x);

int main(int argc, char *argv[]){
    if(argc!=3){
        cout<<"ERRORE\n";
    }
    else{
        fstream input,output;
        input.open(argv[1],ios::in);
        output.open(argv[2],ios::out);
        if(input.fail() || output.fail()){
            cout<<"ERRORE\n";
        }
        else{
            char matrice[10000][100],c;
            input.get(c);
            int i=0;
            for(;i<10000 && !input.eof();++i){
                for(int j=0;j<100 && c!='\0';++j){
                    matrice[i][j]=c;
                    input.get(c);
                }
            }
            for(;i>0;i=i-1){
                for(int j=0;j<100 && matrice[i][j]!='\0';j++){
                    if(lunghezza(matrice,i)<=4){
                       output<<char(matrice[i][j]);
                    }
                }
            }
        }
        input.close();
        output.close();
    }
}

int lunghezza(char m[10000][100],int x){
    int l=0;
    for(int j=0;m[x][j]!='\0';++j){
        ++l;
    }
    return l;
}