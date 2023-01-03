// GDT: i file generati in output non sono corretti. L'indice per l'output avrebbe dovuto
// partire da n_parola-2. Inoltre, nell'output non devi inserire il carattere '\0', perchè si
// utilizza solo per le stringe dentro a C++, non nei file di output. La variabile testo ha inoltre
// una dimensione errata (1000 invece che 10000) e questo causa qualche errore durante i test.

#include <iostream>
#include <fstream>
using namespace std;

int conta_caratteri(char parola[]);

int main(int argc, char * argv []){
    if(argc!=3){
        cerr<<"Hai inserito un numero errato di argomenti (file input, file output)"<<endl;
        exit(0);
    }
    
    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);
    
    if(input.fail()){
        cout<<"Errore nell'apertura del file input"<<endl;
        exit(0);
    }
    
    if(output.fail()){
        cout<<"Errore nella creazione del file output"<<endl;
        exit(0);
    }
    
    char testo[1000][100];
    char parola_letta[100];
    int caratteri;
    int n_parola=0;
    while(!input.eof()){
        input>>parola_letta;
        caratteri=conta_caratteri(parola_letta);
        if(caratteri>4){
            for(int i=0; i<caratteri; i++)
                testo[n_parola][i]=parola_letta[i];
            testo[n_parola][caratteri]='\0';
            n_parola++;
        }
    }
    int j;
    for(int i=n_parola-1; i>=0; i--){
        for(j=0; testo[i][j]!='\0'; j++){
            output<<testo[i][j];
        }
        output<<'\0'<<" ";
    }
    
    input.close();
    output.close();
    return 0;
}
           

int conta_caratteri(char parola[100]){
    int contatore=0;
    for(int i=0; parola[i]!='\0'; i++){
        contatore++;
    }
    return contatore;
}
