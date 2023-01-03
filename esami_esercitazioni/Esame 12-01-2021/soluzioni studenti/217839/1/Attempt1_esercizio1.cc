// GDT: il programma esegue correttamente. Esistono soluzioni più semplici
// che richiedono meno "sforzo" e che sono più facilmente mantenibili (soprattutto
// visti i requisiti del testo con un numero massimo di parole). 
// Fare riferimento alla soluzione ufficiale. 

#include <iostream>
#include <fstream>
using namespace std;

#define MAX 100

struct parola{
    char caratteri[MAX];
    parola * next;
};

typedef parola * nodo;

void copia(char v1[],char v2[]);
nodo aggiungi(nodo start,char buffer[]);
bool isPari(char buffer[]);
void stampa(nodo start);
void deinit(nodo start);

int main(int argc, char * argv []){
    if(argc == 3){
        fstream fileIn,fileOut;
        fileIn.open(argv[1],ios::in);
        fileOut.open(argv[2],ios::out);
        if(!(fileIn.eof() || fileOut.eof())){
            char buffer[MAX];
            fileIn >> buffer;
            nodo start=NULL;
            while(!fileIn.eof()){
                if(isPari(buffer)){
                    start=aggiungi(start,buffer);
                }
                fileIn >> buffer;
            }
            nodo tmp = start;
            while(tmp!=NULL){
                fileOut << tmp->caratteri << " ";
                tmp=tmp->next;
            }
            stampa(start);
            cout << endl;
            deinit(start);
        }else{
            cout << "Impossibile aprire i file" << endl;
        }
        fileIn.close();
        fileOut.close();
    }else{
        cout << "Uso comando: file_in file_out" << endl;
    }
    return 0;
}

void deinit(nodo start){
    if(start!=NULL){
        deinit(start->next);
        delete start;
    }
    return;
}

void stampa(nodo start){
    if(start!=NULL){
        cout << start->caratteri << " ";
        stampa(start->next);
    }
    return;
}

bool isPari(char buffer[]){
    int tmp=0;
    while(buffer[tmp]!='\0'){
        tmp++;
    }
    bool ritorno;
    if(tmp%2==0){
        ritorno=true;
    }else{
        ritorno=false;
    }
    return ritorno;
}

void copia(char v1[],char v2[]){
    for(int i=0;i<MAX;i++){
        v1[i]=v2[i];
    }
    return;
}

nodo aggiungi(nodo start,char buffer[]){
    nodo tmp=start;
    start=new parola;
    copia(start->caratteri,buffer);
    start->next=tmp;
    return start;
}
