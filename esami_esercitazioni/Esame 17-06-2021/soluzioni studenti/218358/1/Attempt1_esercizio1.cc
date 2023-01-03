// Giovanni: il programma ritorna risultato errato su alcuni casi di test.
// Fare riferimento alla soluzione ufficiale per un possibile svolgimento.
// Vedere commenti nel codice.

#include <iostream>
#include <fstream>

using namespace std;
static int MAXDIM = 100;

bool verificaParola(char parola[]);
bool cond0(char parola[]);
bool cond1(char parola[]);
bool cond2(char parola[]);
bool cond3(char parola[]);

int main(int argc, char * argv[]){
   if(argc != 3){
       cout<<"usage: ./a.out inputFile outputFile";
       exit(1);
   }
   fstream input;
   fstream output;

   input.open(argv[1],ios::in);
   output.open(argv[2],ios::out);

   if(input.fail() || output.fail()){
       cout<<"Uno o più file non sono accessibili, verifica e riprova";
       exit(1);
   }
   char stream[MAXDIM];
   while(!input.eof()){
       if(input>>stream){
           if(!verificaParola(stream)){
               output<<stream<<endl;
           }
       }
   }

   input.close();
   output.close();
}

bool verificaParola(char parola[]){
    return cond0(parola) && cond1(parola) && cond2(parola) && cond3(parola);
}

// Giovanni: condizione non necessaria vista la descrizione dell'esercizio
bool cond0(char parola[]){ //verifica che la parola contenga solo caratteri validi
    bool returnValue = true;
    int p = 0;
    while (returnValue && p<MAXDIM && parola[p] != '\0'){
        if(parola[p] != 'U' && parola[p] != 'I' && parola[p] != 'M') returnValue = false;
        p++;
    }
    return returnValue;
}

// Giovanni: questo controllo è errato. Se la parola comincia con lettere diverse
// da U, può essere comunque valida. La condizione infatti dice "Se la parola inizia
// con la lettera U...", non specifica che deve iniziare SEMPRE con la lettera U.
bool cond1(char parola[]){
    bool returnValue = true;
    int p = 0;
    if(parola[p] != '\0' && parola[p] == 'U') returnValue = false;
     while (!returnValue && p<MAXDIM -1  && parola[p] != '\0'){ //cerco solo se necessario
        if(parola[p+1] == '\0' && parola[p] == 'M') returnValue = true;
        p++;
    }
    return returnValue;
}

bool cond2(char parola[]){
    int cont = 0;
    int p = 0;
    while (p<MAXDIM && parola[p] != '\0'){
        if(parola[p] == 'I') cont ++;
        p++;
    }
    return (p == 0 || p%2==0);
}

bool cond3(char parola[]){
    bool returnValue = true;
    int p = 0;
    while (returnValue && p<MAXDIM -1  && parola[p+1] != '\0'){ //mi fermo alla penutima parola per poter fare sempre parola[p+1]
        if(parola[p] == 'M' && parola[p+1] == 'I') returnValue = false;
        p++;
    }
    return returnValue;
}
