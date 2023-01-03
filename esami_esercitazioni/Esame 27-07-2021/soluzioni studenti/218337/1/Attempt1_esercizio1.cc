// GDT: il programma non da il risultato corretto nei casi di test.
// Fare riferimento alla soluzione ufficiale per lo svolgimento.
// Vedere commenti nel codice.

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char * argv [])
{
    fstream input, output;

    if(argc != 3){
        cout << "usage: ./a.out input output" << endl;
    }else{
        input.open(argv[1], ios::in);
        output.open(argv[2], ios::out);

        bool search = false;
        int i = 1;
        int count = 0;
        char carattereCorrente;

        // GDT: La logica di controllo è un po' convoluta. Era forse più conveniente
        // leggere un'intera parola invece che procedere carattere per carattere.
        // Fare riferimento alla soluzione per uno svolgimento diverso.
        while(input >> carattereCorrente){
            if((carattereCorrente >= '0' && carattereCorrente <= '9') || search){

                if(i == 19 && (carattereCorrente >= '0' && carattereCorrente <= '9')){
                    i = 1;
                    search = false;
                    cout << carattereCorrente << endl;
                    count++;
                }
                else if(i % 5 == 0){
                    if(carattereCorrente == '-'){
                        i++;
                        search = true;
                        cout << carattereCorrente;
                    }else{
                        i = 0;
                        search = false;
                    }
                }
                else{
                    if(carattereCorrente >= '0' && carattereCorrente <= '9'){
                        i++;
                        search = true;
                        cout << carattereCorrente;
                    }else{
                        i = 0;
                        search = false;
                    }
                }
            }
        }

        output << "Le stringhe formato NNNN-NNNN-NNNN-NNNN sono: " << count << endl;

        input.close();
        output.close();
    }

    return 0;
}
