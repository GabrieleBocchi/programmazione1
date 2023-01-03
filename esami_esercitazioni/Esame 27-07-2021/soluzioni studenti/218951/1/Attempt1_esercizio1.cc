#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void func(fstream & in, fstream& out);
bool check(char parola[]);

int main(int argc, char * args[]){
    if(argc!=3){
        cout<<"errore  "<<endl;
        return (-1);
    }

    fstream in, out;
    in.open(args[1],ios::in);
    out.open(args[2],ios::out);

    if(!in.fail() and !out.fail()){
        func(in, out);
    }

    in.close();
    out.close();
    return 0;   
}

//funzione principale che tiene conto in un counter delle parola valide rispetto alla consegna
void func(fstream & in, fstream& out){
    char parola[100];
    int counter=0;
    while(!in.eof()){
        in>>parola;
        if(check(parola))counter++;
    }
    out<<counter;
}

//funzione ausiliarira che controlla se il parametro rispetta le condizioni
bool check(char parola[]){
    bool flag=true;
    int i=0;
    //cout<<"c  ";
    for(;parola[i]!='\0';i++);
    if(i!=16) flag = false;
    if(strlen(parola)!=16)flag= false;
    for(int p=0;p<12 and flag;p++){
        if(parola[0]>'9' or parola[0]<'0')flag=false;
    }
    for(int g=12;g<16 and flag;g++){
        if(parola[12]>'Z' or parola[12]<'A')flag=false;
    }
    return flag;
}