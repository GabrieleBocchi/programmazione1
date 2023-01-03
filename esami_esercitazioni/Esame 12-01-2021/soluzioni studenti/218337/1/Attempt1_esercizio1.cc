//Libreria per la gestione di input e output
#include <iostream>
//Libreria per la gestione degli stream di input e output da file
#include <fstream>

using namespace std;

int main(int argc, char * argv[]) {

    if (argc != 3){
        cout << "Usage: ./a.out <inputFile> <outputFile>" << endl;
    }else{
        char carattereCorrente;

        fstream input;
        input.open(argv[1], ios::in);
        
        fstream output;
        output.open(argv[2], ios::out);

        if (input.fail()){
            cout << "Il file non esiste!" << endl;
        }else{
            input >> noskipws;
            int counter = 0;
            int tot = 0;
            char parola[100];

            while (input >> carattereCorrente){
                parola[0]= '\0';

                if(carattereCorrente != ' ' && carattereCorrente != '\n'){
                    parola[counter] = carattereCorrente;
                    counter ++;
                }else{
                    if((counter % 2) == 1){
                        tot++;
                        for(int i = 0; i < counter; i++){
                            output << parola[i];
                        }
                        output << endl;
                    }
                    counter = 0;
                }
            }
            if((counter % 2) == 1){
                tot ++;
                for(int i = 0; i < counter; i++){
                    output << parola[i];
                }
                output << endl;
            }

            input.close();
            output.close();
        }
    }
}