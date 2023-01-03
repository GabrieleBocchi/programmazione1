// Giovanni: il programma non ritorna risultati corretti in alcuni casi di test.
// Sostanzialmente l'output del tuo programma è mal formattato (manda un endl)


#include <iostream>
#include <fstream>
using namespace std;

int strleng(char *a){
    int cont = 0;
    while(*a!='\0'){
        cont++;
        a++;
    }
    return cont;
}

bool controlloParole(char a[]){
    int i=0;
    int contI=0;

    while(a[i]!='\0'){

        // Giovanni: condizione non necessaria vista la descrizione dell'esercizio.
        if(a[i]!='I' && a[i]!='U' && a[i]!='M'){
            return false;
        }
        i++;
    }

    if(a[0]=='U'){
        if(a[strleng(a)-1]!='M'){
            return false;
        }
    }
    i=0;
    while(a[i]!='\0'){
        if(a[i]=='I'){
            contI++;
        }
        i++;
    }
    if(contI%2!=0){
        return false;
    }
    i=0;
    while(a[i]!='\0'){
        if(a[i]=='M' && a[i+1]=='I' && i<strleng(a)){
            return false;
        }
        i++;
    }
    return true;
}


int main(int argc, char const *argv[])
{
    if(argc!=3){
        cout<<"Errore, numero di argomenti errato!"<<endl;
        return 0;
    }

    fstream input, output;
    input.open(argv[1], ios::in);
    if(input.fail()){
        cout<<"Errore nell'apertura del file "<<argv[1]<<endl;
        return 0;
    }

    output.open(argv[2], ios::out);
    if(output.fail()){
        cout<<"Errore nell'apertura del file "<<argv[2]<<endl;
        return 0;
    }

    char  buffer[101];

    while(!input.eof()){
        input >> buffer;
        if(controlloParole(buffer)){
            // Giovanni: qui mancherebbe un endl
            output << buffer;
        }
    }

    return 0;
}
