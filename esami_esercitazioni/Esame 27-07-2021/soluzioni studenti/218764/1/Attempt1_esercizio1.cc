// GDT: il codice non da il risultato corretto per alcuni casi di test.
// Fare riferimeno alla soluzione ufficiale per un possibile svolgimento.
// vedere commenti nel codice.

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char * argv []){
    if(argc!=3){
        cout << "Errore nel numero di input" << endl;
    }else{
        cout << "Numero corretto di input, procedo ;" << endl;
        fstream input,output;
        input.open(argv[1],ios::in);
        output.open(argv[2],ios::out);
        if(input.fail() || output.fail()){
            cout << "Errore apertura file" << endl;
        }else{
            int contaCF=0;
            const int maxLettere=101;
            char buffer[maxLettere];
            while(input >> buffer){

                if(strlen(buffer)==16){
                    int i=0;
                    bool cf=true;
                    while(i<12 && cf){
                        // GDT: l'idea del controllo è corretta. Solo che devi
                        // fare il confronto tra caratteri, quindi '0' e '9'.
                        if(buffer[i]>=0 && buffer[i]<=9 ){
                            cf=true;
                        }else{
                            cf=false;
                        }
                        i++;
                    }

                    int j=12;
                    while(j<16 && cf) {
                        if(buffer[j]>='A' && buffer[j]<='Z'){
                            cf=true;
                        }else{
                            cf=false;
                        }
                      // GDT: manca j++
                    }

                    if(cf){
                        contaCF++;
                    }

                    cout << contaCF << endl;;
                }

            }
            cout << "risultato inserito nel file" << endl;
            output << contaCF << endl;

            input.close();
            output.close();
        }

    }
    return 0;
}
